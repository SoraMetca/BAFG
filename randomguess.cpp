#include "randomguess.h"
#include <random>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <algorithm>

int randomGuess::guess_id = 0;

randomGuess::randomGuess() {

}
QPixmap randomGuess::roll(){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> number(0,character_list.size() - 1);
    if(!DEBUG_MODE) guess_id = number(mt);
    const QString path = QString(":/resources/%1.png")
                             .arg(QString::fromStdString(character_list[guess_id]));
    return crop(scale(QPixmap{path}));
}
QPixmap randomGuess::scale(const QPixmap& image){
    return image.scaled(550,550, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}
QPixmap randomGuess::crop(const QPixmap& image){

    static const int w = 250;
    static const int h = 150;

    int x = (image.width()  - w) / 2;
    int y =  image.height() - h;
    //exceptions, adding offset
    if(character_list[guess_id]=="azusaswimsuit") x+=75;
    if(character_list[guess_id]=="tsubaki") x-=100,y-=75;
    if(character_list[guess_id]=="izumiswimsuit") y-=75,x+=40;
    if(character_list[guess_id]=="tsurugi") x-=75,y-=75;
    if(character_list[guess_id]=="himari") x-=60,y-=40;
    if(character_list[guess_id]=="utaha") x-=50;
    if(character_list[guess_id]=="shimiko") x-=75;

    return image.copy(x, y, w, h);
}
std::string randomGuess::low_case(std::string name) {
    name.erase(
        std::remove_if(name.begin(), name.end(),
                       [](unsigned char c) {
                           return std::isspace(c)
                           || c == '-'
                               || c == '*'
                               || c == '('
                               || c == ')';
                       }),
        name.end());

    std::transform(name.begin(), name.end(), name.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    return name;
}
bool randomGuess::guess(std::string name)
{
    return low_case(std::move(name)) ==
           character_list[guess_id];
}
QImage upscale(QImage image)
{
    cv::Mat mat(image.height(), image.width(),
                CV_8UC4,
                const_cast<uchar*>(image.bits()),
                image.bytesPerLine());
    cv::Mat rgba;
    cv::cvtColor(mat, rgba, cv::COLOR_BGRA2RGBA);
    cv::Mat upscaled;
    cv::resize(rgba, upscaled, cv::Size(550, 550), 0, 0, cv::INTER_LANCZOS4);
    QImage result(upscaled.cols,
                  upscaled.rows,
                  QImage::Format_RGBA8888);
    std::memcpy(result.bits(),
                upscaled.data,
                static_cast<size_t>(upscaled.total() * upscaled.elemSize()));
    return result;
}
std::string randomGuess::get_character(int id){
    return character_list[id];
}
