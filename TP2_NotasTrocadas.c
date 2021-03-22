/*
Notas Trocadas
Disponível a partir de: terça, 13 Set 2016, 22:00
Número máximo de arquivos: 1
Tamanho máximo de arquivo carregado: 512 KiB
Tipo de trabalho: Trabalho individual
Notas Trocadas

DATA DE ENTREGA: 23/09/2016 (Entregas após esta data serão penalizadas)
Nome do arquivo fonte na linguagem C ANSI.
Você deve anexar o arquivo código-fonte ao invés de um arquivo compactado. Exemplo: troco.c

As Ilhas DCClands formam um reino independente nos mares do Atlântico. Como é um reino recente, a sociedade é muito influenciada pela informática. A moeda oficial é o Bit; existem notas de B$ 100,00, B$ 50,00, B$20,00, B$10,00, B$5,00 e B$1,00. Você foi contratado(a) para ajudar na programação dos caixas automáticos de um grande banco das Ilhas DCClands.
Tarefa

Os caixas eletrônicos das Ilhas DCClands operam com todos os tipos de notas disponíveis, mantendo um estoque de cédulas para cada valor (B$ 100,00, B$ 50,00, B$20,00, B$10,00, B$5,00 e B$1,00). Os clientes do banco utilizam os caixas eletrônicos para efetuar retiradas de um certo número inteiro de Bits.

Sua tarefa é escrever um programa que, dado o valor de Bits desejado pelo cliente, determine o número de cada uma das notas necessário para totalizar esse valor, de modo a minimizar a quantidade de cédulas entregues. Por exemplo, se o cliente deseja retirar B$50,00, basta entregar uma única nota de cinquenta Bits. Se o cliente deseja retirar B$72,00, é necessário entregar uma nota de B$50,00, uma de B$20,00 e duas de B$1,00.

Entrada

A entrada é composta de vários conjuntos de teste. Cada conjunto de teste é composto por uma única linha, que contém um número inteiro positivo V, que indica o valor solicitado pelo cliente. O final da entrada é indicado por V = 0.

Saída

Para cada conjunto de teste da entrada seu programa deve produzir três linhas na saída. A primeira linha deve conter um identificador do conjunto de teste, no formato “Teste n”, onde n é numerado a partir de 1. Na segunda linha devem aparecer quatro inteiros H, I, J, K , L e M que representam o resultado encontrado pelo seu programa: H indica o número de cédulas de B$100,00,  I indica o número de cédulas de B$50,00, J indica o número de cédulas de B$20,00,  K indica o número de cédulas de B$10,00, L indica o número de cédulas de B$5,00 e M indica o número de cédulas de B$1,00. A terceira linha deve ser deixada em branco. A grafia mostrada no Exemplo de Saída, abaixo, deve ser seguida rigorosamente.

Exemplo:

Entrada:

1
72
0

Saída:

Teste 1
0 0 0 0 0 1

Teste 2
0 1 1 0 0 2

Restrições:

0 <= V <= 1.000.000.000 (V = 0 apenas para indicar o fim da entrada)
*/

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
