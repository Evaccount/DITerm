#ifndef STRUCTURE
#define STRUCTURE

struct pixelRGB{
    int rouge;
    int vert;
    int bleu;
};

struct boutImageRGB {
    pixelRGB tab[2][2];
};

struct boutImageANSI {
    int tab[2][2];
};

#endif //STRUCTURE
