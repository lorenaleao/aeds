#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
#define max(A,B) ((A>=B) ? (A):(B))

enum bool {false=0, true};

int s, ppl, p=0, sandwiches[MAX], i;

int verifica(int m){


	int somaNumPedacos = 0;
	for(i = 0; i < s; i++){

		somaNumPedacos += sandwiches[i]/m;
		if(somaNumPedacos >= ppl) return true;
	}
	return false;
}

int buscabinaria(int x){

    int inicio=1, fim = x, meio, sol=0;
    while(inicio<=fim){

        meio = (inicio+fim)/2;
        if(verifica(meio)==1){
            sol = max(meio, sol);
            inicio = meio+1;
        }
        else fim = meio-1;
    }
    return sol;
}


int main()
{

    do
    {
        scanf("%d", &ppl);
        fflush(stdin);
        scanf("%d", &s);
        fflush(stdin);
        for (i=0; i<s; i++)
        {
            scanf("%d", &sandwiches[i]);
            p = max(p, sandwiches[i]);
        }
        printf("%d\n", buscabinaria(p));


    } while(s!=0&&ppl!=0);

    return 0;
}