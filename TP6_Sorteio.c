#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_TAM 21


int main(int argc, char *argv[]) {

     int n, k, i, j;

     do
     {
       scanf("%d", &n);
       scanf("%d", &k);
       char nomes[n][NOME_TAM], temp[NOME_TAM];

       for (i=0; i<n; i++)
       {
         scanf("%s", nomes[i]);
       }

       for(j=0; j<n; j++)
        {
            for(i=0; i<n; i++)
            {
                if(strcmp(nomes[j], nomes[i]) < 0)
                {
                    strcpy(temp, nomes[j]);
                    strcpy(nomes[j], nomes[i]);
                    strcpy(nomes[i], temp);
                }
            }
        }

       if (n!=0&&k!=0) printf("%s\n", nomes[k-1]);
       


     } while (n!=0&&k!=0);


    return 0;
}