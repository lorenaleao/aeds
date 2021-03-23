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
