#include <queue>
#include <iostream>

using namespace std;

#define atividade "06"
#define nome "Marcos Vitor Souza Freire"
#define matricula "552355"

void alternativeRadixsort(int u[], int n, int d)
{
  queue<int> buckets[2];

  for (int bit = 0; bit < d * 3.32193; bit++)
  {
    for (int i = 0; i < n; ++i)
    {
      int x = (u[i] >> bit) & 1;
      buckets[x].push(u[i]);
    }

    int i = 0;

    while (!buckets[0].empty())
    {
      u[i++] = buckets[0].front();
      buckets[0].pop();
    }
    while (!buckets[1].empty())
    {
      u[i++] = buckets[1].front();
      buckets[1].pop();
    }
  }
  /* implementar ordenação por raiz, utilizando apenas dois buckets
int u[]:vetor de entrada
int n: comprimento de u
int d: numero maximo de digitos
observação: as entradas sao formadas por numeros inteiros positivos
*/
}