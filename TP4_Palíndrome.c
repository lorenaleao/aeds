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
