#include <iostream>
#include <string>
#include "include/convert.hpp"
#include "include/printCC.hpp"
#include "include/structure.hpp"

#define NOIR        30
#define ROUGE       31
#define VERT        32
#define JAUNE       33
#define BLEU        34
#define MAGENTA     35
#define CYAN        36
#define BLANC       37
#define GRIS        90
#define ROUGE_C     91
#define VERT_C      92
#define JAUNE_C     93
#define BLEU_C      94
#define MAGENTA_C   95
#define CYAN_C      96
#define BLANC_C     97

int main() {
    boutImageRGB bout;
    bout.tab[0][0].rouge = 255;
    bout.tab[0][0].vert = 0;
    bout.tab[0][0].bleu = 0;

    bout.tab[0][1].rouge = 50;
    bout.tab[0][1].vert = 205;
    bout.tab[0][1].bleu = 50;

    bout.tab[1][0].rouge = 135;
    bout.tab[1][0].vert = 206;
    bout.tab[1][0].bleu = 235;

    bout.tab[1][1].rouge = 255;
    bout.tab[1][1].vert = 215;
    bout.tab[1][1].bleu = 0;

    printBout(cboutImageRGBtoANSI(bout));
    return 0;
}
