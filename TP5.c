#include <stdio.h>
#include <stdlib.h>

struct carrinho {
  int postos;
  int tempo;
  int numero;
};

int compara (const void *x, const void *y) {
  struct carrinho *a, *b;
  a = (struct carrinho *) x;
  b = (struct carrinho *) y;
  if ((*a).postos != (*b).postos) return ((*b).postos - (*a).postos);
  else return ((*a).tempo - (*b).tempo);
}

int main()
{
    int numpostos, numcarros, numleituras, carro, posto, ii;
    struct carrinho automovel[100+1];

    scanf("%d%d%d", &numpostos, &numcarros, &numleituras);


    for (ii = 1; ii <= numcarros; ii++ ) {
    automovel[ii].postos = 0;
    automovel[ii].tempo = -1;
    automovel[ii].numero = ii;
  }
    for (ii=0; ii<numleituras; ii++)
    {
        scanf("%d %d", &carro, &posto );
        if (posto == ((automovel[carro].postos % numpostos) + 1))
        {
            automovel[carro].postos ++;
            automovel[carro].tempo = ii;
        }

    }

    qsort(automovel + 1, numcarros, sizeof(struct carrinho), compara);

    for (ii = 1; ii <= numcarros; ii++ )
        printf( "%d ", automovel[ii].numero);

    return 0;
}
