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
