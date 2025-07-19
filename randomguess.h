#ifndef RANDOMGUESS_H
#define RANDOMGUESS_H

#include "qpixmap.h"
#include <vector>

extern bool DEBUG_MODE;

class randomGuess
{
public:
    randomGuess();
    QPixmap roll();
    bool guess(std::string name);
    static int guess_id;
    std::string get_character(int id);
private:
    std::string low_case(std::string name);
    static inline const std::vector<std::string> character_list {
        "izuna","kazusa","aru","eimi","haruna","hifumi","hina","hoshino","iori",
        "maki","neru","izumi","shiroko","shun","sumire","tsurugi","aris","midori",
        "cherino","yuzu","azusa","koharu","azusaswimsuit","hinaswimsuit",
        "ioriswimsuit","shirokocycling","shunsmall","nerubunny","karinbunny",
        "asunabunny","natsu","chinatsuhotspring","arunewyear","mutsukinewyear",
        "wakamo","mimori","ui","hinata","marina","miyako","miyu","tsukuyo",
        "misaki","atsuko","wakamoswimsuit","nonomiswimsuit","hoshinoswimsuit",
        "izunaswimsuit","chiseswimsuit","saori","kokona","utahacheersquad","noa",
        "yuukatrack","maritrack","shigure","serinachristmas","harunanewyear",
        "mine","mika","megu","sakurako","toki","koyuki","kayokonewyear","kaho",
        "arismaid","tokibunny","reisa","rumi","mina","miyakoswimsuit",
        "sakiswimsuit","uiswimsuit","hanakoswimsuit","meru","kotoricheersquad",
        "ichika","kasumi","misakamikoto","shokuhoumisaki","yukari","renge",
        "kikyou","kotamacamp","harecamp","hinadress","akodress","kayokodress",
        "arudress","umika","kazusaband","yoshimiband","kirara","momoimaid",
        "midorimaid","kannaswimsuit","moeswimsuit","hoshinoarmed","shirokoterror",
        "saoriswimsuit","hiyoriswimsuit","marinaqipao","reijo","maripopidol",
        "sakurakopopidol","chiaki","yuukapajamas","noapajamas","seia",
        "neruuniform","asunaschool","senacasual","juriparttimejob","rei","saoridress",
        "hikari","nozomi","nagusa","natsuband","yukariswimsuit","akane","chise","akari",
        "hasumi","nonomi","kayoko","mutsuki","junko","serika","tsubaki","yuuka","momoi",
        "kirino","momiji","rengeswimsuit","haruka","asuna","kotori","suzumi","pina",
        "tsurugiswimsuit","izumiswimsuit","tomoe","fubuki","michiru","hibikicheersquad",
        "hasumitrack","junkonewyear","koharuswimsuit","ibuki","airiband","minepopidol",
        "aoba","hibiki","karin","saya","mashiro","mashiroswimsuit","hifumiswimsuit",
        "sayacasual","hatsunemiku","ako","cherinohotspring","nodokahotspring",
        "serikanewyear","sena","chihiro","saki","kaede","iroha","hiyori","moe",
        "akanebunny","himari","hanaechristmas","fuukanewyear","kanna","nagisa",
        "harukanewyear","minori","shirokoswimsuit","hinataswimsuit",
        "mimoriswimsuit","harunatrack","shigurehotspring","eimiswimsuit","makoto",
        "akarinewyear","tsubakiguide","serikaswimsuit","fubukiswimsuit","tomoeqipao",
        "kisaki","satsuki","rio","makicamp","izuminewyear","sumireparttimejob","pinaguide",
        "niya","kikyouswimsuit","airi","fuuka","hanae","hare","utaha","ayane","shizuko",
        "hanako","mari","chinatsu","kotama","juri","serina","shimiko","yoshimi","nodoka",
        "ayaneswimsuit","shizukoswimsuit","yuzumaid","miyuswimsuit","satenruiko",
        "kirinoswimsuit","atsukoswimsuit","karinschool"
    };
    QPixmap scale(const QPixmap &image);
    QPixmap crop(const QPixmap &image);
};
QImage upscale(QImage image);
#endif // RANDOMGUESS_H
