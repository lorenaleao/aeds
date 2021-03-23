/*
Conflito Hatfield-McCoy
Número máximo de arquivos: 1
Tipo de trabalho: Trabalho individual
Conflito Hatfield-McCoy

DATA DE ENTREGA: 16/10/2016 (Entregas após esta data serão penalizadas)

Nome do arquivo fonte na linguagem C++.
Você deve anexar o arquivo código-fonte ao invés de um arquivo compactado. Exemplo: conflito.cpp

Introdução

Os Hatfield e os McCoy travaram uma guerra durante 50 anos. O motivo da guerra era o tamanho do território do terreno de cada família. Pelo bem das próximas gerações, os governantes resolveram fazer um tratado para finalizar a guerra. O tratado consiste em fazer um divisão justa, e certamente contínua, do território. Eles resolveram pedir sua ajuda para calcular o ponto de divisão do território. Depois de tantos anos de guerra, as famílias não podem lhe pagar uma viagem para ver previamente o território que será dividido. Ao invés disso, eles prepararam uma lista a1, a2,..., aN de inteiros que indicam o tamanho de cada seção do território. A seção a1 é vizinha da seção a2 que por sua vez é vizinha da seção a3 e assim por diante. Os governantes querem uma divisão em uma seção k de tal forma que a1 + a_2 + ... + a_k =  a_{k+1} + a_{k+2} + ... +  a_N.

Tarefas

Sua tarefa é dada uma lista de inteiros positivos a_1, a_2,..., a_N, determinar a seção k tal que soma dos comprimentos das seções a 1 até a k é igual a soma dos comprimentos das seções a k+1 até a N.

Entrada

A primeira linha da entrada contém um inteiro N indicando o número de seções do território. A segunda linha da entrada contém N inteiros a_1, a_2,..., a_N separados por um único espaço que indicam os comprimentos das seções. A leitura deve parar quando N=0.
Exemplo de Entrada

4
5 3 2 10

9
2 8 2 8 4 4 4 4 4
        
0

Saída

Seu programa deve imprimir duas linhas: uma contendo um inteiro que indica a seção do território onde acontecerá a divisão e outra em branco (somente para separação).
Exemplo de Saída

3
4
(esta saída corresponde ao exemplo de entrada acima)

Restrições

1 <= N <= 10^5 (N=0, indica fim de entrada)
1 <= a_i <= 100, para i = 1, 2, ..., N
*/
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
