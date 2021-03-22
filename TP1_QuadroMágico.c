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
