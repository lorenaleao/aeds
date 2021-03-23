/*
Monopólio Bancário
Número máximo de arquivos: 1
Tipo de trabalho: Trabalho individual
Monopólio Bancário

DATA DE ENTREGA: 16/10/2016 (Entregas após esta data serão penalizadas)

Nome do arquivo fonte na linguagem C++.
Você deve anexar o arquivo código-fonte ao invés de um arquivo compactado. Exemplo: monopolio.cpp

Introdução

A informatização dos sistemas bancários permitiu grandes economias de tempo e dinheiro, permitindo que vários tipos de transações financeiras pudessem ser realizadas pela Internet. Para possibilitar isso, cada banco recebeu um código bancário, que é um número utilizado pelos sistemas de computador para identificar cada banco.

Quando um banco decide comprar outro, ocorre o que se chama uma fusão: os dois bancos tornam-se um só banco. Para manter compatibilidade com os sistemas eletrônicos dos bancos, qualquer um dos códigos dos antigos bancos pode ser usado para se referir ao novo banco.

Com a crise econômica internacional, as fusões entre bancos têm sido cada vez mais comuns; por isso, muitas  vezes é difícil decidir se dois códigos bancários na realidade se referem ao mesmo banco (devido aos dois bancos terem se fundido, diretamente ou não).

Tarefas

Escreva um programa que, dada uma série de fusões entre bancos, responde a várias consultas perguntando se dois códigos bancários se referem ao mesmo banco.

Entrada

A primeira linha da entrada contém dois inteiros N e K, indicando o número de bancos e o número de operações efetuadas (1 <= N  <= 100.000, 1 <= K <= 100.000). Os códigos de cada um dos N bancos, inicialmente, são os inteiros de 1 até N.

Cada uma das K linhas seguintes descreve ou uma fusão entre bancos ou uma consulta.

    Uma fusão é descrita na entrada como uma linha que começa com o caractere ‘F’, um espaço, e dois códigos bancários, que se referem aos dois bancos que estão sofrendo a fusão, separados por um espaço em branco;
    Uma consulta é descrita na entrada como uma linha que começa com o caractere ‘C’, um espaço, e os dois códigos a serem consultados, separados por um espaço em branco. Os códigos bancários consultados são sempre distintos.

As fusões são sempre realizadas entre bancos diferentes, e todos os códigos bancários fornecidos na entrada são válidos. A leitura da entrada deve parar quando N = 0 e K = 0.

Exemplo de Entrada

3 5
C 1 2
F 1 2
C 1 2
F 1 3
C 1 3
4 5
F 1 2
F 2 3
C 1 3
F 2 4
C 1 4
4 4
F 1 2
F 3 4
F 1 3
C 2 4
0 0

Saída

Seu programa deve imprimir uma linha para cada consulta na entrada. Caso os dois códigos bancários consultados se refiram ao mesmo banco, imprima uma linha contendo o caractere ‘S’; caso contrário, imprima uma linha contendo apenas o caractere ‘N’. Ao final das K consultas, imprima uma linha em branco. Não é necessário identificar cada saída com ‘Teste i’.

Exemplo de Saída

N
S

S

S
S

S
(esta saída corresponde ao exemplo de entrada acima)
*/
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
   int n, k, i, j, q, banco1, banco2, temp, count=0;
   char operacao;

   do
   {
      cin >> n >> k;
      int *bancos = new int [n];
      char *saida = new char [k];
      for (q=0; q<n; q++)
       {
          bancos[q]=q+1;
       }
      for (i=0; i<k; i++)
      {
          cin >> operacao >> banco1 >> banco2;

          if(operacao=='C'&&bancos[banco1-1]==bancos[banco2-1])
          {
            saida[count]='S';
                 count++;
          }

          else if(operacao=='C'&&bancos[banco1-1]!=bancos[banco2-1])
          {
            saida[count]='N';
                 count++;
          }

          else if(operacao=='F')
          {
            temp = bancos[banco2-1];
            for (j=0; j<n; j++)
            {
              if(temp==bancos[j])
              {
                bancos[j] = bancos[banco1-1];
              }
            }
          }
      }

      for(i=0; i<(count); i++)
      {
        cout << saida[i] << endl;
      }
      cout << endl;
      count=0;
      delete[] bancos;
      delete[] saida;

   } while (n!=0&&k!=0);

    return 0;
}
