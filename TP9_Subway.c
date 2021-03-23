/*
Fastfood Subway
Número máximo de arquivos: 1
Tipo de trabalho: Trabalho individual
Fast-food Subway

DATA DE ENTREGA: 22/10/2016 (Entregas após esta data serão penalizadas)

Nome do arquivo fonte na linguagem ANSI C.
Você deve anexar o arquivo código-fonte ao invés de um arquivo compactado. Exemplo: subway.c
Introdução

Pão a metro é um tipo de sanduíche gigante da rede de restaurantes Subway® que é uma excelente opção de lanche para torneios de programação, embora a experiência já tenha mostrado que o oferecimento de sanduíches pode gerar reclamação dos competidores. Outro grande problema é que algumas pessoas são mais gulosas que outras e, dessa maneira, acabam pegando pedaços maiores que os pedaços dos outros. Durante um evento no DCC, a coordenação estava pensando em providenciar pão a metro para os competidores, porém tais problemas os fizeram recuar na idéia.

Embora a idéia tenha sido momentaneamente abandonada, uma idéia simples surgiu: cortar previamente o pão em fatias de tamanho iguais e distribuí-las entre as pessoas. O único problema com tal idéia é que se o número de pessoas for muito grande, fica impraticável ter apenas um pão. Por exemplo, se quisermos que 1.000 pessoas recebam 20 centímetros de sanduíche, seria necessário um sanduíche de 20.000 centímetros, ou 200 metros!

Alguém levantou a seguinte hipótese: se houvessem N pessoas e fossem encomendados K sanduíches de empresas diferentes, cada qual com uma determinada metragem m (tamanho) M_i (1 ≤ i ≤ K), seria possível retirar desses pães N fatias de mesmo tamanho, possivelmente sobrando partes não utilizadas. A questão seria: qual o tamanho inteiro máximo que essas fatias poderão ter?

Por exemplo, se tivermos K = 4, com os tamanhos (em centímetros) M_1 = 120, M_2 = 89, M_3 = 230 e M_4 = 177 e N = 10, podemos retirar N fatias iguais de tamanho máximo 57, pois assim conseguimos 2 fatias no primeiro pão, 1 no segundo, 4 no terceiro e 3 no quarto, totalizando as 10 fatias necessárias. Se tentarmos cortar fatias de tamanho 58, só será possível obter fatias do terceiro pão, totalizando 9 e, portanto, 57 é realmente o melhor que podemos obter. Note que não podemos usar duas ou mais fatias menores de diferentes pães para formarmos uma fatia do tamanho selecionado. (fica ria muito deselegante dar um lanche recortado às pessoas).

Tarefa

Escreva um programa que, dados os tamanhos de pão disponíveis (em centímetros) e a quantidade de pessoas a serem atendidas, retorne o tamanho inteiro máximo (em centímetros) da fatia que pode ser cortada de maneira a atender todas as pessoas. Use funções para modularizar o seu código e facilitar a compreensão de outras pessoas.

Entrada

A entrada é constituída de 3 linhas. A primeira linha da entrada contém um inteiro N que indica a quantidade pessoas (0 ≤ N ≤ 10.000 e N=0 para indicar fim da entrada). A segunda linha contém um inteiro K (1 ≤ K ≤ 10.000 e K=0 para indicar fim da entrada) que é a quantidade de sanduíches disponível. Na terceira linha há K inteiros M (1 ≤ M ≤ 10.000) separados por um espaço em branco representando o tamanho de cada pão.

Exemplo de entrada

10
4
120 89 230 177
3
2
45 85
7
7
100 98 99 505 102 97 101
0 0

Saída

Seu programa deve imprimir, na saída padrão, uma única linha, contendo o tamanho inteiro máximo da fatia que pode ser cortada.

Exemplo de saída

57

42

101

(esta saída corresponde ao exemplo de entrada acima)
*/
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
