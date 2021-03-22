/*
Palíndrome

DATA DE ENTREGA: 30/09/2016 (Entregas após esta data serão penalizadas)
Nome do arquivo fonte na linguagem C ANSI.
Você deve anexar o arquivo código-fonte ao invés de um arquivo compactado. Exemplo: palim.c

Descrição

Uma cadeia de caracteres é chamada de palíndrome se seqüência de caracteres da esquerda para a direita é igual à seqüência de caracteres da direita para a esquerda (uma outra definição é que o primeiro caractere da cadeia deve ser igual ao último caractere, o segundo caractere seja igual ao penúltimo caractere, o terceiro caractere seja igual ao antepenúltimo caractere, e assim por diante). Por exemplo, as cadeias de caracteres ‘mim’, ‘axxa’ e ‘ananaganana’ são exemplos de palíndromes.

Palavras podem ser combinadas para formar uma palavra palíndrome. Por exemplo, as palavras ‘aki’ e ‘ika’, quando analisadas sozinhas, não são palíndromes, porém a combinação das duas (‘akiika’) resulta em uma palavra palíndrome.

Tarefa

Dada sempre três palavras, escreva um programa que determine elas ou alguma combinação delas formam uma palavra palíndrome. Deve-se realizar a combinação das palavras mantendo a ordem de entrada das mesmas, ou seja, as combinações que devem ser avaliadas são as seguintes: 

s1
s2
s3
s1s2
s1s3
s2s3
s1s2s3

Entrada

A entrada é constituída de um conjunto de três palavras, s1, s2 e s3. O programa deve sempre ler três palavras, e só deve parar de ler a entrada quando s1=*. Obs: Ao ler a última entrada, o seu programa DEVERÁ fazer uma leitura normal de três palavras, ou seja, leitura de s1, s2 e s3, porém seu programa irá avaliar somente s1=* para finalizar, logo, os valores de s2 e s3 na última leitura não serão importantes.

Saída

Para cada conjunto da entrada seu programa deve produzir três linhas na saída. A primeira linha deve conter um identificador do conjunto de teste, no formato “Teste n”, onde n é numerado a partir de 1. A segunda linha deve conter, caso haja, todas as palavras e seus conjuntos (uniões) que formam uma palavra palíndrome separadas por um espaço em branco. A terceira linha deve ser deixada em branco. O formato mostrado no exemplo de saída abaixo deve ser seguido rigorosamente.

Exemplo

Entrada

ipd lll dpi
ara rrr ara
rvh vek hvr
lxr brf byc
dcn lll gkc
* qwee wqeq

Saída

Teste 1
lll ipddpi ipdllldpi

Teste 2
ara rrr ara araara ararrrara

Teste 3
rvhhvr

Teste 4


Teste 5
lll

(esta saída corresponde ao exemplo de entrada acima)

Restrições

    0 <= s1 <= 100 (s1 = * apenas para indicar o fim da entrada)
    0 <= s2 <= 100
    0 <= s3 <= 100

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char s1[100], str1[100], s2[100], str2[100], s3[100], str3[100], str1e2[200], str1e3[200], str2e3[200], str12e3[300];
    int count=0, ii, kk, nn, qq, ss, uu, ww, tam1, tam2, tam3, tam7, tam8, tam9, tam10;

    do
    {
        scanf("%s%s%s", s1, s2, s3);
        if (s1[0]=='*') break;
        count++;
        tam1 = strlen(s1);
        tam2 = strlen(s2);
        tam3 = strlen(s3);
        strcpy(str1, s1);
        strcpy(str2, s2);
        strcpy(str3, s3);

        for (ii=0; ii<tam1; ii++)
        {
            if(s1[ii]!=s1[tam1-ii-1]) s1[0]='\0';
        }
        for (kk=0; kk<tam2; kk++)
        {
             if(s2[kk]!=s2[tam2-kk-1]) s2[0]='\0';
        }
        for (nn=0; nn<tam3; nn++)
        {
            if(s3[nn]!=s3[tam3-nn-1]) s3[0]='\0';
        }

        strcpy(str1e2, str1);
        strcat(str1e2, str2);

        tam7 = tam1+tam2;

        for (qq=0; qq<tam7; qq++)
        {
             if(str1e2[qq]!=str1e2[tam7-qq-1]) str1e2[0]='\0';
        }

        strcpy(str1e3, str1);
        strcat(str1e3, str3);

        tam8 = tam1+tam3;

        for (ss=0; ss<tam8; ss++)
        {
             if(str1e3[ss]!=str1e3[tam8-ss-1]) str1e3[0]='\0';
        }

        strcpy(str2e3, str2);
        strcat(str2e3, str3);

        tam9 = tam2+tam3;

        for (uu=0; uu<tam9; uu++)
        {
             if(str2e3[uu]!=str2e3[tam9-uu-1]) str2e3[0]='\0';
        }

        strcpy(str12e3, str1);
        strcat(str12e3, str2);
        strcat(str12e3, str3);

        tam10 = tam1+tam2+tam3;

        for (ww=0; ww<tam10; ww++)
        {
             if(str12e3[ww]!=str12e3[tam10-ww-1]) str12e3[0]='\0';
        }
        printf("Teste %d\n", count);
        if(s1[0]!='\0') printf("%s ", s1);
        if(s2[0]!='\0') printf("%s ", s2);
        if(s3[0]!='\0') printf("%s ", s3);
        if(str1e2[0]!='\0') printf("%s ", str1e2);
        if(str1e3[0]!='\0') printf("%s ", str1e3);
        if(str2e3[0]!='\0') printf("%s ", str2e3);
        if(str12e3[0]!='\0') printf("%s ", str12e3);
        printf("\n\n");

    } while(s1[0]!='*');
    return 0;
}
