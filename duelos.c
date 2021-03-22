/*
Duelo
Disponível a partir de: quinta, 15 Set 2016, 15:00
Número máximo de arquivos: 1
Tamanho máximo de arquivo carregado: 512 KiB
Tipo de trabalho: Trabalho individual

Duelo

DATA DE ENTREGA: 25/09/2016 (Entregas após esta data serão penalizadas)
Nome do arquivo fonte na linguagem C ANSI.
Você deve anexar o arquivo código-fonte ao invés de um arquivo compactado. Exemplo: duelo.c

Descrição

A ideia dessa tarefa é implementar um jogo de duelos como os que ocorriam no velho oeste americano. Para quem nunca ouviu falar, num duelo duas pessoas param de frente uma para a outra e atiram, quem acertar o outro ganha. Porém, nesse jogo os duelistas irão atirar com palavras. Ao atirar as palavras, todas as letras que são iguais se anulam e apenas as letras que não são comuns entre as palavras acertam o adversário. 

Tarefa

Seu desafio é criar um programa que dadas duas palavras, você deve eliminar as letras em comuns na taxa de 1 para 1 e produzir o conjunto de letras que sobram após a colisão entre as duas palavras. Com o conjunto de letras restantes, some o valor do código ASCII de cada letra restante para obter a pontuação final. Ao fim a palavra com o maior número de pontos é a vencedora.

Entrada

Um inteiro N referindo ao número de duelos que ocorrerão. As demais linhas são compostas por duas palavras separadas por apenas um espaço em branco definindo o atirador do lado esquerdo e o atirador do lado direito.

Saída

A pontuação de cada uma das palavras seguidas pela indicação do vencedor. O vencedor é definido pela seguinte frase: “palavra” (esquerda || direita) ganha. Em caso de empate deve ser impresso : houve um empate.

Exemplo

Entrada

4
cama camarao
gato rato
critico otimo
dunia bupia

Saída

Duelo 1
pontos esquerda: 0
pontos direita: 322
"camarao" (direita) ganha

Duelo 2
pontos esquerda: 103
pontos direita: 114
"rato" (direita) ganha

Duelo 3
pontos esquerda: 417
pontos direita: 220
"critico" (esquerda) ganha

Duelo 4
pontos esquerda: 210
pontos direita: 210
houve um empate

Restrições

    Será aceito apenas duas palavras separadas por um caractere de espaço.
    Cada caractere de uma palavra será comparado a apenas um caractere na outra palavra. Ou seja, ao comparar uma letra “a” com uma palavra contendo duas letras “a” o saldo final é de uma letra “a”. “a” - “aa” = “a”
    As palavras não contêm acentos ou letras maiúsculas. 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(int argc, char *argv[])
{
    int numduelos, ii, jj, kk, tam1, tam2, pont1=0, pont2=0, pontesq, pontdir, tam_str1, tam_str2;
    int pontaux=0, pontaux2=0, count1=0, count2=0, count3=0, count=0, i=0, j=0, dif, dif_abs;
    char palavraesq[20], palavradir[20], str1[20], str2[20];

    scanf("%d", &numduelos);

    for(ii=0; ii<numduelos; ii++)
    {
        scanf("%s", palavraesq);
        scanf("%s", palavradir);
        tam1 = strlen(palavraesq);
        tam2 = strlen(palavradir);
        if (tam1>=tam2) {strcpy(str1, palavraesq); strcpy(str2, palavradir);}
        else {strcpy(str1, palavradir); strcpy(str2, palavraesq);}
        tam_str1 = strlen(str1);
        tam_str2 = strlen(str2);

        int *quantletras_str1 = (int*)malloc (tam_str1*(sizeof(int)));
        int *quantletras_str2 = (int*)malloc (tam_str2*(sizeof(int)));
        int *valorletra_str1 = (int*)malloc (tam_str1*(sizeof(int)));
        int *valorletra_str2 = (int*)malloc (tam_str2*(sizeof(int)));

        for(jj=0; str1[jj]!='\0'; jj++)
        {
            for (kk=jj-1; kk>=0; kk--)
            {
                count1++;
                if(str1[jj]!=str1[kk]) count2++;
            }
            
            if (count1==count2)
            {
                for(kk=0; str1[kk]!='\0'; kk++)
                {
                    if(str1[jj]==str1[kk])
                    {
                        count++;
                    }
                }
                quantletras_str1[i] = count;
                valorletra_str1[i] = str1[jj];
                i++;
                count=0;
            }
            count1=0;
            count2=0;
        }

        for(jj=0; str2[jj]!='\0'; jj++)
        {
            for (kk=jj-1; kk>=0; kk--)
            {
                count1++;
                if(str2[jj]!=str2[kk]) count3++;
            }

            if (count1==count3)
            {
                for(kk=0; str2[kk]!='\0'; kk++)
                {
                    if(str2[jj]==str2[kk])
                    {
                        count++;
                    }
                }
                quantletras_str2[j] = count;
                valorletra_str2[j] = str2[jj];
                j++;
                count=0;
            }
            count1=0;
            count3=0;
        }

        for(jj=0; jj<tam_str1; jj++)
        {
            for(kk=0; kk<tam_str2; kk++)
            {
                if(valorletra_str1[jj]==valorletra_str2[kk])
                {
                    if(quantletras_str1[jj]!=quantletras_str2[kk])
                    {
                        dif = quantletras_str1[jj]-quantletras_str2[kk];
                        dif_abs = abs(dif);
                        if(quantletras_str1[jj]>quantletras_str2[kk]) pont1 = pont1 + dif_abs*valorletra_str1[jj];
                        else pont2 = pont2 + dif_abs*valorletra_str1[jj];
                    }
                    break;
                }
            }
        }
        for(jj=0; str1[jj]!='\0'; jj++)
        {
            for(kk=0; str2[kk]!='\0'; kk++)
            {
                if (str1[jj]!=str2[kk])
                {
                    pontaux = pontaux + str1[jj];
                }
            }
            if (pontaux==tam_str2*str1[jj])
                {
                    pontaux = pontaux/tam_str2;
                    pont1 = pont1 + pontaux;
                    pontaux = 0;
                }
                else
                {
                    pontaux = 0;
                    pont1 = pont1 + pontaux;
                }
        }
        for(kk=0; str2[kk]!='\0'; kk++)
        {
            for(jj=0; str1[jj]!='\0'; jj++)
            {
               if (str2[kk]!=str1[jj])
                {
                    pontaux2 = pontaux2 + str2[kk];
                }
            }
            if (pontaux2==tam_str1*str2[kk])
                {
                    pontaux2 = pontaux2/tam_str1;
                    pont2 = pont2 + pontaux2;
                    pontaux2 = 0;
                }
                else
                {
                    pontaux2 = 0;
                    pont2 = pont2 + pontaux2;
                }
        }
        if (tam1>=tam2) {pontesq = pont1; pontdir = pont2;}
        else {pontesq = pont2; pontdir = pont1;}
        printf("Duelo %d\npontos esquerda: %d\npontos direita: %d\n", ii+1, pontesq, pontdir);
        if(pontesq>pontdir) printf("%s (esquerda) ganha\n", palavraesq);
        else if(pontdir>pontesq) printf("%s (direita) ganha\n", palavradir);
        else printf("houve um empate\n");
        pont1=0; pont2=0; pontesq=0; pontdir=0; i=0; j=0;
     }

    return 0;
}
