/*
Sorteio
Número máximo de arquivos: 1
Tipo de trabalho: Trabalho individual
Sorteio

DATA DE ENTREGA: 06/10/2016 (Entregas após esta data serão penalizadas)
Nome do arquivo fonte na linguagem C ANSI.
Você deve anexar o arquivo código-fonte ao invés de um arquivo compactado. Exemplo: sorteio.c

Tia Maria é uma respeitada professora e tem vários alunos. Em sua última aula, ela prometeu que iria sortear um aluno para ganhar um bônus especial na nota final: ela colocou N pedaços de papel numerados de 1 a N em um saquinho e sorteou um determinado número K; o aluno premiado foi o K-ésimo aluno na lista de chamada.

O problema é que a Tia MAria esqueceu o diário de classe, então ela não tem como saber qual número corresponde a qual aluno. Ela sabe os nomes de todos os alunos, e que os números deles, de 1 até N, são atribuídos de acordo com a ordem alfabética, mas os alunos dela estão muito ansiosos e querem logo saber quem foi o vencedor.

Dado os nomes dos alunos da Tia Maria e o número sorteado, determine o nome do aluno que deve receber o bônus.

Tarefa

Dado os nomes dos alunos da Tia Maria e o número sorteado, determine o nome do aluno que deve receber o bônus.

Entrada

A primeira linha contém dois inteiros N e K separados por um espaço em branco (1 ≤ K ≤ N ≤ 100). Cada uma das N linhas seguintes contém uma cadeia de caracteres de tamanho mínimo 1 e máximo 20 representando os nomes dos alunos. Os nomes são compostos apenas por letras minúsculas de 'a' a 'z'.

Saída

Seu programa deve imprimir uma única linha, contendo o nome do aluno que deve receber o bônus

Exemplo

Entrada

5 1
maria
joao
carlos
vanessa
jose
5 5
maria
joao
carlos
vanessa
jose
5 3
maria
joao
carlos
vanessa
jose

Saída

carlos

vanessa

jose
*/
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
