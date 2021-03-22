#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int valor[1000], contador=0, n, H, I, J, K, L, M;
    int r1, r2, r3, r4, r5;

    for(n=0; n<1000; n++)
    {
        scanf("%d", &valor[n]);
        if (valor[n]==0) {break;}
        else contador++;
    }

    for(n=0; n<contador; n++)
    {   r1 = valor[n]%100;
        r2 = r1%50;
        r3 = r2%20;
        r4 = r3%10;
        r5 = r4%5;

        H = valor[n]/100;
        I = r1/50;
        J = r2/20;
        K = r3/10;
        L = r4/5;
        M = r5;
        printf("Teste %d\n%d %d %d %d %d %d\n\n", n+1, H, I, J, K, L, M);
    }

    return 0;
}
