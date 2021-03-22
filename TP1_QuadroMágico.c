/*
Quadro Mágico
Disponível a partir de: terça, 6 Set 2016, 06:00
Número máximo de arquivos: 1
Tamanho máximo de arquivo carregado: 512 KiB
Tipo de trabalho: Trabalho individual
Quadro Mágico

DATA DE ENTREGA: 16/09/2016 (Entregas após esta data serão penalizadas)
Nome do arquivo fonte na linguagem C ANSI.
Você deve anexar o arquivo código-fonte ao invés de um arquivo compactado. Exemplo: quadro.c

Senhor Mário é conhecido mundialmente pela fabricação de quadros mágicos de dimensões 3X3. Um quadro é chamado mágico quando a soma dos elementos de uma determinada linha, coluna ou diagonal é sempre igual. Infelizmente, assaltantes invadiram recentemente a oficina do Sr. Mário e roubaram alguns dos números de seus quadros mágicos. Felizmente os meliantes não conseguiram roubar mais do que um número de cada quadro. Desesperado, pois devia entregar os quadros naquele dia, o Sr. Mário veio procurar a sua ajuda para tentar completar os quadros com os números faltantes.
Tarefa

Escreva um programa que, dado um quadro com algum número faltando, marcado com o algarismo zero, determine qual era o quadro mágico original. 
Entrada

A entrada contém um único conjunto de testes, que deve ser lido do dispositivo de entrada padrão (normalmente o teclado). A entrada contém três linhas, cada uma contendo três inteiros N(0 <= N <= 1000). O número zero representa o número roubado.
Saída

Seu programa deve imprimir, na saída padrão, três linhas, cada uma contendo três inteiros, descrevendo a configuração original do quadro mágico.

Exemplo 1

Entrada

4 9 2
3 0 7
8 1 6

Saída

4 9 2
3 5 7
8 1 6

Exemplo 2

Entrada

6 12 12
16 10 0
8 8 14

Saída

6 12 12
16 10 4
8 8 14

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int quadro[3][3];
    int linha, coluna;
    int dimMat=3; /* Dimensão da Matriz */
    int somaLinha1, somaLinha2, somaLinha3, numFalta;

    /* leitura dos dados */
    for(linha=0; linha<dimMat; linha++)
        for(coluna=0; coluna<dimMat; coluna++)
        {
          scanf("%d", &quadro[linha][coluna]);
        }

    /* comparando as somas de cada linha*/

    somaLinha1 = quadro[0][0]+quadro[0][1]+quadro[0][2];
    somaLinha2 = quadro[1][0]+quadro[1][1]+quadro[1][2];
    somaLinha3 = quadro[2][0]+quadro[2][1]+quadro[2][2];

    if (somaLinha1==somaLinha2)
        numFalta = somaLinha1-somaLinha3;

    if (somaLinha1==somaLinha3)
        numFalta = somaLinha1-somaLinha2;

    if (somaLinha2==somaLinha3)
        numFalta = somaLinha2-somaLinha1;

    /*verificando onde está o zero e substituindo pelo número correto*/

    for(linha=0; linha<dimMat; linha++)
        for(coluna=0; coluna<dimMat; coluna++)
        {
            if(quadro[linha][coluna]==0)
                quadro[linha][coluna]=numFalta;
        }

    /* impressão do quadro na tela */
    for(linha=0; linha<dimMat; linha++)
    {
        for(coluna=0; coluna<dimMat; coluna++)
            printf("%3d\n", quadro[linha][coluna]);
        printf("\n");
    }

    return 0;
}
