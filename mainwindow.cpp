#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "randomguess.h"
#include <memory>
#include <QMessageBox>


bool DEBUG_MODE = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , random(std::make_unique<randomGuess>())
{
    ui->setupUi(this);
    load_new_guess();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_enter_clicked()
{
    QString userInput = ui->guessInput->text();
    std::string user_guess = userInput.toStdString();

    if(!DEBUG_MODE){
    if (random->guess(user_guess)) {
        QMessageBox::information(this, "Correct", "You guessed it!");

        ui->guessInput->setText("");
        load_new_guess();
    } else {
        QMessageBox::warning(this, "Try Again", "Wrong guess.");

    }
    } else{
        random->guess_id++;
        load_new_guess();
    }

}
void MainWindow::load_new_guess()
{
    QImage image = upscale(random->roll().toImage());
    ui->guess->setFixedSize(image.size());
    ui->guess->setScaledContents(true);
    ui->guess->setPixmap(QPixmap::fromImage(image));
    if(DEBUG_MODE) this->setWindowTitle(QString::fromStdString(random->get_character(random->guess_id)));
}
