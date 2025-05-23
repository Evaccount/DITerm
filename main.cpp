#include <iostream>
#include <string>

#include <opencv4/opencv2/opencv.hpp>
#include "include/convert.hpp"
#include "include/printCC.hpp"
#include "include/structure.hpp"
#include "include/readImage.hpp"

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
    cv::Mat image = cv::imread("../test.bmp");
    if (image.empty()){
        std::cout << "erreur chargement image ma gueule\n";
        return -1;
    }
    readImage(&image);

    return 0;
}
