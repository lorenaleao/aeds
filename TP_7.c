#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, k, secaoDivisao, soma1=0, soma2=0;
    do
    {
       scanf("%d", &n);
       int *secoes = (int*)malloc (n*(sizeof(int)));
       
       for (i=0; i<n; i++)
       {
          scanf("%d", &secoes[i]);
       }
       
       for(k=1; k<n; k++)
       {
          soma2 = soma2 + secoes[k];
       }
       
       for (i=0; i<(n-1); i++)
       {
          soma1 = soma1 + secoes[i];
          if(soma1==soma2) break;
          soma2 = soma2 - secoes[i+1];
       }
        secaoDivisao = i+1;
        printf("%d\n", secaoDivisao);
    } while(n!=0);

    return 0;
}
