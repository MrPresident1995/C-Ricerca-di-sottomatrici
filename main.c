#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 2
#define MAX 100

int esecuzione(FILE* fp_in1, FILE* fp_in2);

int main()
{
    FILE* fp_in1;
    FILE* fp_in2;
    int risultato;
    char nome1[MAX];
    char nome2[MAX];

    //INIZIALIZZAZIONE
    printf("Digitare il nome del file contenente la matrice 1: ");
    scanf("%s", nome1);
    printf("Digitare il nome del file contenente la matrice 2: ");
    scanf("%*c%s", nome2);

    //CONTROLLO FILE
    fp_in1= fopen(nome1, "r");
    fp_in2= fopen(nome2, "r");
    if((fp_in1==NULL)||(fp_in2==NULL))
    {
        printf("ERRORE APERTURA FILE");
        return -2;
    }

    risultato= esecuzione(fp_in1, fp_in2);
    printf("\n\nLa prima matrice contiene la seconda matrice %d volte", risultato);

    //CHIUSURA
    fclose(fp_in1);
    fclose(fp_in2);
    return 0;
}

int esecuzione(FILE* fp_in1, FILE* fp_in2)
{
    int i;
    int o;
    int k;
    int l;
    int cont;
    int uguale;
    int matrice1[N][N];
    int matrice2[M][M];

    //LETTURA MATRICE
    for(i=0; i<N; i++)
    {
        for(o=0; o<N; o++)
            fscanf(fp_in1, "%d", &matrice1[i][o]);
    }
    for(i=0; i<M; i++)
    {
        for(o=0; o<M; o++)
            fscanf(fp_in2, "%d", &matrice2[i][o]);
    }

    //CONFRONTO
    cont= 0;
    for(i=0; i<N; i++)
    {
        for(o=0; o<N; o++)
        {
            k= 0;
            l= 0;
            if(matrice1[i][o]==matrice2[0][0]) //RICERCA SOMIGLIANZA
            {
                uguale= 1;
                while((uguale==1)&&(k<M))
                {
                    if(matrice1[i][o]!=matrice2[k][l])
                        uguale= 0;
                    if((o>=N)&&(l<M))
                        uguale= 0;
                    else
                    {
                        i++;
                        k++;
                        o= 0;
                        l= 0;
                    }
                    if((i>=N)&&(k<M))
                        uguale= 0;
                    o++;
                    l++;
                }
            }
            if(uguale==1)
            {
                cont++;
                uguale= 0;
            }
        }
    }
    return cont;
}
