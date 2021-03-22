#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(int argc, char *argv[])
{
    int numduelos, ii, jj, kk, tam1, tam2, pont1=0, pont2=0, pontesq, pontdir, tam_str1, tam_str2;
    int pontaux=0, pontaux2=0, count1=0, count2=0, count3=0, count=0, i=0, j=0, dif, dif_abs;
    char palavraesq[20], palavradir[20], str1[20], str2[20];

    scanf("%d", &numduelos);

    for(ii=0; ii<numduelos; ii++)
    {
        scanf("%s", palavraesq);
        scanf("%s", palavradir);
        tam1 = strlen(palavraesq);
        tam2 = strlen(palavradir);
        if (tam1>=tam2) {strcpy(str1, palavraesq); strcpy(str2, palavradir);}
        else {strcpy(str1, palavradir); strcpy(str2, palavraesq);}
        tam_str1 = strlen(str1);
        tam_str2 = strlen(str2);

        int *quantletras_str1 = (int*)malloc (tam_str1*(sizeof(int)));
        int *quantletras_str2 = (int*)malloc (tam_str2*(sizeof(int)));
        int *valorletra_str1 = (int*)malloc (tam_str1*(sizeof(int)));
        int *valorletra_str2 = (int*)malloc (tam_str2*(sizeof(int)));

        for(jj=0; str1[jj]!='\0'; jj++)
        {
            for (kk=jj-1; kk>=0; kk--)
            {
                count1++;
                if(str1[jj]!=str1[kk]) count2++;
            }
            
            if (count1==count2)
            {
                for(kk=0; str1[kk]!='\0'; kk++)
                {
                    if(str1[jj]==str1[kk])
                    {
                        count++;
                    }
                }
                quantletras_str1[i] = count;
                valorletra_str1[i] = str1[jj];
                i++;
                count=0;
            }
            count1=0;
            count2=0;
        }

        for(jj=0; str2[jj]!='\0'; jj++)
        {
            for (kk=jj-1; kk>=0; kk--)
            {
                count1++;
                if(str2[jj]!=str2[kk]) count3++;
            }

            if (count1==count3)
            {
                for(kk=0; str2[kk]!='\0'; kk++)
                {
                    if(str2[jj]==str2[kk])
                    {
                        count++;
                    }
                }
                quantletras_str2[j] = count;
                valorletra_str2[j] = str2[jj];
                j++;
                count=0;
            }
            count1=0;
            count3=0;
        }

        for(jj=0; jj<tam_str1; jj++)
        {
            for(kk=0; kk<tam_str2; kk++)
            {
                if(valorletra_str1[jj]==valorletra_str2[kk])
                {
                    if(quantletras_str1[jj]!=quantletras_str2[kk])
                    {
                        dif = quantletras_str1[jj]-quantletras_str2[kk];
                        dif_abs = abs(dif);
                        if(quantletras_str1[jj]>quantletras_str2[kk]) pont1 = pont1 + dif_abs*valorletra_str1[jj];
                        else pont2 = pont2 + dif_abs*valorletra_str1[jj];
                    }
                    break;
                }
            }
        }
        for(jj=0; str1[jj]!='\0'; jj++)
        {
            for(kk=0; str2[kk]!='\0'; kk++)
            {
                if (str1[jj]!=str2[kk])
                {
                    pontaux = pontaux + str1[jj];
                }
            }
            if (pontaux==tam_str2*str1[jj])
                {
                    pontaux = pontaux/tam_str2;
                    pont1 = pont1 + pontaux;
                    pontaux = 0;
                }
                else
                {
                    pontaux = 0;
                    pont1 = pont1 + pontaux;
                }
        }
        for(kk=0; str2[kk]!='\0'; kk++)
        {
            for(jj=0; str1[jj]!='\0'; jj++)
            {
               if (str2[kk]!=str1[jj])
                {
                    pontaux2 = pontaux2 + str2[kk];
                }
            }
            if (pontaux2==tam_str1*str2[kk])
                {
                    pontaux2 = pontaux2/tam_str1;
                    pont2 = pont2 + pontaux2;
                    pontaux2 = 0;
                }
                else
                {
                    pontaux2 = 0;
                    pont2 = pont2 + pontaux2;
                }
        }
        if (tam1>=tam2) {pontesq = pont1; pontdir = pont2;}
        else {pontesq = pont2; pontdir = pont1;}
        printf("Duelo %d\npontos esquerda: %d\npontos direita: %d\n", ii+1, pontesq, pontdir);
        if(pontesq>pontdir) printf("%s (esquerda) ganha\n", palavraesq);
        else if(pontdir>pontesq) printf("%s (direita) ganha\n", palavradir);
        else printf("houve um empate\n");
        pont1=0; pont2=0; pontesq=0; pontdir=0; i=0; j=0;
     }

    return 0;
}
