/*
Entrega de Pacotes
Número máximo de arquivos: 1
Tipo de trabalho: Trabalho individual
Entrega de Pacotes

DATA DE ENTREGA: 30/10/2016 (Entregas após esta data serão penalizadas)

Nome do arquivo fonte na linguagem ANSI C.
Você deve anexar o arquivo código-fonte ao invés de um arquivo compactado. Exemplo: entregas.c

Introdução

Um entregador de encomendas é o responsável por entregar os pacotes na rua do Senhor Rodolgo. Por política da empresa, os pacotes devem ser entregues na mesma ordem que foram enviados, mesmo que essa não seja a forma mais rápida. Cansado de subir e descer aquela rua tantas vezes, nosso amigo quer mostrar à empresa quanto tempo ele leva para entregar os pacotes, na tentativa de derrubar essa política.

A rua do senhor Rodolfo tem N casas. Naturalmente, as casas são numeradas de forma ordenada (não necessariamente por números consecutivos). Como as casas possuem aproximadamente o mesmo tamanho, você pode assumir que o entregador leva uma unidade de tempo constante para caminhar de uma casa até a casa imediatamente vizinha.

Há M pacotes para essa rua, que devem ser entregues na mesma ordem em que chegaram. Cada encomenda contém o número da casa onde deve ser entregue. Escreva um programa que determine quanto tempo o entregador levará para entregar todas os pacotes, assumindo que quando o tempo começa a contar, ele está na primeira casa (a de menor número), e o tempo termina de contar quando todas os pacotes foram entregues (mesmo que o carteiro não esteja de volta na primeira casa). Você pode desprezar o tempo para colocar o pacote na caixa de correio (ou seja, se ele só tiver um pacote, para a primeira casa, a resposta para o problema é zero).
Entrada

A primeira linha contém dois inteiros, N e M, respectivamente o número de casas e o número de entregas. A segunda linha contém N inteiros em ordem estritamente crescente, indicando os números das casas. A terceira linha contém M inteiros indicando os números das casas onde os pacotes devem ser entregues, na ordem dada na entrada.
Saída

Seu programa deve produzir uma única linha, contendo um único inteiro, o tempo que o entregador levará para entregar todas os pacotes na ordem correta, assumindo que ele começa na casa de menor número.
Restrições

• 1 ≤ N ≤ 45.000 e 1 ≤ M ≤ 45.000
• O número de cada casa é um inteiro entre 1 e 1.000.000.000
Informação sobre a pontuação

• Para um subconjunto dos casos de teste totalizando 30 pontos, 1 ≤ N ≤ 1000 e 1 ≤ M ≤ 1000

Exemplos

Entrada #1

5 5
1 5 10 20 40
10 20 10 40 1

Saída #1

10

Entrada #2

3 4
50 80 100
80 80 100 50

Saída #2

4
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ii, jj, n, m, casas[45000], entregas[45000], tempo=0, aux=0;
        
    scanf("%d", &n);
    scanf("%d", &m);
    for (ii=0; ii<n; ii++)
    {
        scanf("%d", &casas[ii]);
    }
    for (jj=0; jj<m; jj++)
    {
        scanf("%d", &entregas[jj]);
    }
    for (jj=0; jj<m; jj++)
    {
        for (ii=aux; ii<n;)
        {
            if (entregas[jj]!=casas[ii])
            {
                tempo=tempo+1;
            }
            else
            {
                aux=ii; 
                break;
            }
            if(entregas[jj]<casas[ii]) ii--;
            if(entregas[jj]>casas[ii]) ii++;
        }
    }
    printf("%d\n", tempo);
    aux=0;
    tempo=0;
    return 0;
}
