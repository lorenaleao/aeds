/*
Autorama
Número máximo de arquivos: 1
Tipo de trabalho: Trabalho individual
Autorama

DATA DE ENTREGA: 04/10/2016 (Entregas após esta data serão penalizadas)
Nome do arquivo fonte na linguagem C ANSI.
Você deve anexar o arquivo código-fonte ao invés de um arquivo compactado. Exemplo: autorama.c

Descrição

Em uma pista de autorama, a marcação de tempo é feita com sensores (chamados de postos de checagem) que fazem leitura da passagem de cada cada carrinho pelo ponto onde o sensor está instalado. Durante uma corrida, os carrinhos devem passar pelos postos de checagem na ordem pré-estabelecida, ou seja, primeiro no posto de checagem 1, depois no 2, até o último posto de checagem, quando ele deve retornar ao posto de checagem 1 para completar uma volta. Entretanto, às vezes, quando os carrinhos saem da pista os competidores os recolocam mais à frente na pista, pulando alguns postos de checagem. Nesse caso, todas as passagens daquele carrinho por postos de checagem devem ser ignoradas até que ele passe pelo posto de checagem correto.

A posição de um carrinho na corrida é determinada pelo número de postos de checagem que ele passou na ordem correta. Caso dois carrinhos tenham passado pelo mesmo número de postos de checagem, a ordem utilizada é a ordem cronológica, ou seja, está mais à frente o carrinho que passou pelo último posto de checagem primeiro.

Tarefa

Sua tarefa nesse trabalho prático consiste em, dado uma lista de leituras feitas pelos sensores, determinar a classificação dos carrinhos na corrida.

Entrada

A entrada contém um único conjunto de testes. A primeira linha da entrada contêm três inteiros, K, N e M. K representa o número de postos de checagem (1 <= K <= 100); N, o número de carrinhos (1 <= N <= 100) e M o número de leituras feitas pelos sensores (1 <= M <= 10.000). Os carrinhos são identificados por inteiros de 1 a N e os postos de checagem por inteiros de 1 a K. As M linhas seguintes contêm cada uma dois inteiros X e Y, separados por espaço. Eles indicam que o carrinho número X (1 <= X <= N) passou pelo posto de checagem Y (1 <= Y <= K). Os eventos são apresentados na ordem cronológica. Sempre é possível determinar a classificação de todos os pilotos com os dados fornecidos.

Saída

Seu programa deve imprimir uma linha contendo N inteiros, sendo que o i-ésimo inteiro representa o carrinho que ocupa a posição i na corrida. Ou seja, o primeiro inteiro é o que ocupa o primeiro lugar, o segundo inteiro é o carrinho que ocupa o segundo lugar, e assim por diante.

Exemplo

Entrada 1

3 3 6
3 1
1 1
2 1
3 2
3 3
2 2

Saída 1

3 2 1

Entrada 1

2 2 5
2 1
2 1
1 1
2 1
1 2

Saída 1

1 2
*/
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
