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
