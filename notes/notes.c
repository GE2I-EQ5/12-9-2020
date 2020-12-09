#include <stdio.h>
#include <math.h>


double notes[28] = {
    12.5, 15.0, 18.0,  9.5, 10.0, 11.5, 10.0,  9.0,  7.0, 12.0,
    14.0, 13.5,  5.5, 10.0, 15.0, 18.0, 19.0, 12.0, 14.5, 13.0,
    20.0,  9.5,  9.5, 10.0, 12.0,  2.0, 11.0,  7.0, };

int main(void)
{
    double min, max, moyenne, ecartype, medianne;
    int i;

    /*Calcul du min (resultat 2)*/
    min=notes[0];
    for(i=1; i<28; i++)
    {
      if(notes[i] < min)
      {
        min = notes[i];
      }
    }
    //printf("%f\n", min); //Affichage du résultat


    /*Calcul du max (resultat 20)*/
    max = notes[0];
    for(i=1; i<28; i++)
    {
      if(notes[i] > max)
      {
        max = notes[i];
      }
    }
    //printf("%f\n", max); //Affichage du résultat


    /*Calcul de la moyenne (resultat 11.79)*/
    for(i=0; i<28; i++)
    {
      moyenne += notes[i];
    }
    moyenne = moyenne / 28;
    //printf("%f\n", moyenne); //Affichage du résultat



    /*Calcul de l'ecartype (resultat 4.09)*/
    for(i=0; i<28; i++)
    {
      ecartype += powf(notes[i] - moyenne,2);
    }
    ecartype = sqrtf(ecartype/27);
    //printf("%f\n", ecartype);


    /*Calcul de la medianne (resultat 11.75)*/
    //Méthode : succesivement enlever un min et un max
    double c; //variable tampon
    int j,k;

    for(i=1; i<28; i++) //1 à 28
    {
      for(j=0; j<27; j++) //0 à 27
      {
        if (notes[j] > notes[j+1])
        {
          c = notes[j]; // permet de trier par ordre croissant
          notes[j] = notes[j+1];
          notes[j+1] = c;
        }
      }

    }
    for(k=0; k<28; k++)
    {
      printf("%f\n", notes[k]);
    }
    medianne = (notes[14] + notes[13]) / 2 ;
    printf("Medianne : %f\n", medianne);

    return 0;
}
