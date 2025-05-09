#include <iostream>
#include <string>
#include "../include/printCC.hpp"
#include "../include/structure.hpp"

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

#define HAUT 1
#define BAS 2

void printTwoPixel(int colorHaut, int colorBas){
    std::string ansiCode = "\033[";
    std::string pixelHaut = getstrColor(colorHaut, HAUT);
    std::string pixelBas = getstrColor(colorBas, BAS);
    std::string character = "▀";
    std::string reset = "\033[0m";
    // Code ANSI pour le texte noir et le fond rouge
    std::cout << ansiCode + pixelHaut << ansiCode + pixelBas << character << reset;
}

std::string getstrColor(int color, int pos){
    if (pos == 2){
        color = color + 10;
    }
    else if (pos != 1){
        std::cout << "ERREUR !\n";
    }

    return std::to_string(color) + "m";
}
