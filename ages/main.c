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


int main()
{
  int i;
  int j;
  int bas = 10;
  int haut = 20;
  int compteur = 0;

    static int ages[100] = {
        20, 21, 18, 35, 28, 41, 52, 72, 34, 94,
        34, 23, 25, 31, 30, 45, 40, 28, 50, 52,
        53, 49, 47, 25, 18, 17, 62, 75, 56, 57,
        47, 43, 49, 25, 30, 31, 34, 54, 28, 18,
        31, 42, 50, 52, 61, 19, 22, 40, 71, 23,
        24, 25, 51, 45, 44, 23, 28, 29, 18, 30,
        33, 36, 41, 37, 24, 31, 42, 45, 72, 61,
        23, 20, 18, 32, 34, 35, 62, 44, 47, 37,
        35, 45, 45, 47, 34, 24, 29, 27, 30, 31,
        29, 63, 45, 41, 40, 34, 28, 29, 20, 18,
    };

    int tranches[10] = {0}; //Dans la tranche 0

    for(j=1; j<10; j++) //Aller de la tranche 1 à 9
    {
      compteur = 0; // remettre le compteur à 0

      for(i=0; i<100; i++) //Parcourir les ages des 100 personnes
      {
        if(ages[i] >= bas && ages[i] < haut) //Vérifier la condition pour rentrer dans une tranche
        {
          compteur++; //ajouter 1 au compteur si condition vraie
        }
      }
      tranches[j] = compteur; //la valeur du compteur =  nombre de personne dans la tranche donnée
      printf("%d\n", tranches[j]); //Affichage du nb de gens par tranche
      bas +=10; //Variation des tranches
      haut +=10; //Variation des tranches
    }
    dessinerHistogramme(tranches, 10); //Afficher histogramme
    return 0;
}
