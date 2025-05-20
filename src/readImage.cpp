#include "../include/readImage.hpp"


void readImage(cv::Mat *image){
    boutImageRGB curseur;
    for(int u = 0 ; u < image->rows ; u = u + 2){
        for(int c = 0 ; c < image->cols ; c = c + 2){
            cv::Vec3b pixel = image->at<cv::Vec3b>(u, c);
            curseur.tab[0][0].rouge = pixel[2];
            curseur.tab[0][0].vert = pixel[1];  // X 0
            curseur.tab[0][0].bleu = pixel[0];  // 0 0

            if (c + 1 <= image->cols){
                cv::Vec3b pixel = image->at<cv::Vec3b>(u, c + 1);
                curseur.tab[1][0].rouge = pixel[2];
                curseur.tab[1][0].vert = pixel[1];  // 0 X
                curseur.tab[1][0].bleu = pixel[0];  // 0 0
            }
            else{
                curseur.tab[1][0].rouge = -1;
            }

            if (u + 1 <= image->rows){
                cv::Vec3b pixel = image->at<cv::Vec3b>(u + 1, c);
                curseur.tab[0][1].rouge = pixel[2];
                curseur.tab[0][1].vert = pixel[1];  // 0 0
                curseur.tab[0][1].bleu = pixel[0];  // X 0
            }
            else{
                curseur.tab[0][1].rouge = -1;
            }

            if (c + 1 <= image->cols && u + 1 <= image->rows){
                cv::Vec3b pixel = image->at<cv::Vec3b>(u + 1, c + 1);
                curseur.tab[1][1].rouge = pixel[2];
                curseur.tab[1][1].vert = pixel[1];  // 0 0
                curseur.tab[1][1].bleu = pixel[0];  // 0 X
            }
            else{
                curseur.tab[1][1].rouge = -1;
            }

            printBout(cboutImageRGBtoANSI(curseur));
        }
        std::cout << std::endl;
    }
}
