/*
Tablete de Chocolate
Número máximo de arquivos: 1
Tipo de trabalho: Trabalho individual
Tablete de Chocolate

DATA DE ENTREGA: 30/10/2016 (Entregas após esta data serão penalizadas)

Nome do arquivo fonte na linguagem ANSI C.
Você deve anexar o arquivo código-fonte ao invés de um arquivo compactado. Exemplo: chocolate.c

Introdução

Vô Tião comprou um tablete de chocolate para suas duas netas Daiane e Beatriz. O tablete é composto de N linhas e N colunas de quadrados, onde N é sempre um número par. Em exatamente dois quadrados, que podem estar em qualquer posição no tablete, há uma figurinha colada. Vô Tião gostaria de dar dois pedaços de tamanhos iguais, um para cada neta, cada pedaço contendo uma figurinha. Mais precisamente, ele gostaria de dividir o tablete bem na metade, com um único corte vertical ou horizontal, deixando uma figurinha em cada pedaço.

A figura, disponível na url www.ABC.com, mostra dois exemplos. O tablete da esquerda, com N = 4, vô Tião pode dividir na metade com um corte horizontal, e cada metade contém uma figurinha. Mas o tablete da direita, com N = 6, ele não consegue dividir em dois pedaços iguais, separando as figurinhas, com um único corte horizontal ou vertical.

Tarefa

Dados N e as posições das duas figurinhas, seu programa deve dizer se é, ou não, possível dividir o tablete em dois pedaços de tamanhos iguais, com um único corte horizontal ou vertical, deixando uma figurinha em cada pedaço.

Entrada

A primeira linha da entrada contém um inteiro N, representando as dimensões do tablete (número de linhas e de colunas). A segunda linha contém dois inteiros X1 e Y1, representando as coordenadas da primeira figurinha. A terceira linha contém dois inteiros X2 e Y2, representando as coordenadas da segunda figurinha.

Saída

Seu programa deve imprimir apenas uma linha contendo um único caractere: “S”, caso seja possível dividir o tablete em pedaços iguais com um único corte horizontal ou vertical, separando as figurinhas, ou “N” caso não seja possível.
Restrições

• 2 ≤ N ≤ 1000, N é sempre par;
• 1 ≤ X1, Y1, X2, Y2 ≤ N.
Exemplos

Entrada

4
1 2
4 2

Saída

S

Entrada

6
3 4
2 6

Saída

N
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x1, y1, x2, y2, half;

    scanf("%d", &n);
    scanf("%d", &x1);
    scanf("%d", &y1);
    scanf("%d", &x2);
    scanf("%d", &y2);

    half = n/2;
    if((y1<=half&&y2<=half)||(y1>half&&y2>half))
    {
        if((x1<=half&&x2<=half)||(x1>half&&x2>half)) printf("%c", 'N');
        else printf("%c", 'S');
    }
    else printf("%c", 'S');
    return 0;
}
