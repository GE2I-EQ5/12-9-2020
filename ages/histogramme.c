#include <stdio.h>
#include <string.h>


void dessinerHistogramme(int donnees[], int taille){
    FILE *file = fopen("histogramme.txt", "w");
    int max = donnees[0];
    for(int i = 1; i < taille; i++){
        if (donnees[i] > max) max = donnees[i];
    }
    for(int i = max; i >= 0; i--){
        char strLine[5*taille + 5];
        if (i%5==0){
            sprintf(strLine, "%3d+", i);
        }else{
            sprintf(strLine, "   |");
        }
        for(int j = 0; j < taille; j++){
            if (donnees[j] == i + 1){
                char buff[6];
                sprintf(buff, "|%3d|", i + 1);
                strcat(strLine, buff);
            }else if (donnees[j] > i){
                strcat(strLine, "|   |");
            }else if (donnees[j] == i){
                strcat(strLine, "+---+");
            }else{
                strcat(strLine, "   " "  ");
            }
        }
        fprintf(file, "%s\n", strLine);
    }
    char strLine[5*taille + 5];
    sprintf(strLine, "--");
    for(int j = 0; j <= taille; j++){
        strcat(strLine, "--+--");
    }
    fprintf(file, "%s\n", strLine);
    sprintf(strLine, "  ");
    for(int j = 0; j <= taille; j++){
        char buff[6];
        sprintf(buff, "%3d  ", j*10);
        strcat(strLine, buff);
    }
    fprintf(file, "%s\n", strLine);
    fclose(file);
}
