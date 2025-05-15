#include "../include/convert.hpp"
#include "../include/structure.hpp"
#include <cmath>
#include <cstdlib>

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

boutImageANSI cboutImageRGBtoANSI(boutImageRGB bout){
    boutImageANSI resultat;
    for(int x ; x < 2 ; x++){
        for(int y ; y < 2 ; y++){
            resultat.tab[x][y] = RGBtoANSI(bout.tab[x][y]);
        }
    }
    return resultat;
}

int RGBtoANSI(pixelRGB pixel){
    float diffRouge[15];
    float diffVert[15];
    float diffBleu[15];

    int tableau[15][4] =
    {   {0, 0, 0, NOIR},        {255, 0, 0, ROUGE},
        {0, 255, 0, VERT},      {255, 255, 0, JAUNE},
        {0, 0, 255, BLEU},      {255, 0, 255, MAGENTA},
        {0, 255, 255, CYAN},    {255, 255, 255, BLANC},
        {192, 192, 192, GRIS},  {255, 102, 102, ROUGE_C},
        {102, 255, 102, VERT_C},{255, 255, 102, JAUNE_C},
        {102, 102, 255, BLEU_C},{255, 102, 255, MAGENTA_C},
        {102, 255, 255, CYAN_C}
    };
    float rapprochement[15][2] =
    {
        {0, NOIR},      {0, ROUGE},
        {0, VERT},      {0, JAUNE},
        {0, BLEU},      {0, MAGENTA},
        {0, CYAN},      {0, BLANC},
        {0, GRIS},      {0, ROUGE_C},
        {0, VERT_C},    {0, JAUNE_C},
        {0, BLEU_C},    {0, MAGENTA_C},
        {0, CYAN_C}
    };

    //calculer a quelle point notre couleur a de difference avec celle que l'on a deja en ANSI
    for(int i = 0 ; i < 15 ; i++){
        diffRouge[i] = std::abs(pixel.rouge - tableau[i][0]);
        diffVert[i] = std::abs(pixel.vert - tableau[i][1]);
        diffBleu[i] = std::abs(pixel.bleu - tableau[i][2]);

        rapprochement[i][0] = (diffRouge[i] + diffVert[i] + diffBleu[i]) / 3;
    }

    //trouver quelle couleur ANSI a le moins de difference avec notre couleur
    float min = rapprochement[0][0];
    int k = 0;
    for(int i = 1 ; i < 15 ; i++){
        if (min > rapprochement[i][0]){
            min = rapprochement[i][0];
            k = i;
        }
    }

    return (int)rapprochement[k][1];
}
