#include <iostream>

#define atividade "04"
#define nome "Marcos Vitor Souza Freire"
#define matricula "552355"
using namespace std;
// 1

class vetor
{
   int *u;   // ponteiro para vetoe
   int size; // tamanho do vetor
public:
   vetor(int n, int arr[])
   {
      u = new int[n];
      size = n;
      for (int i = 0; i < n; i++)
      {
         u[i] = arr[i];
      }
   }

   vetor(int n)
   {
      u = new int[n];
      size = n;
   }

   ~vetor() { delete[] u; }

   int &operator[](int k) { return u[k]; }
   int len() { return size; }

   void rdm(int nTamanho)
   {
      int *newU = new int[nTamanho];
      for (int i = 0; i < size && i < nTamanho; i++)
      {
         newU[i] = u[i];
      }
      delete[] u;
      u = newU;
      size = nTamanho;
   }
};

int calcularTotal(vetor U[], int n)
{
   int total = 0;
   for (int i = 0; i < n; i++)
   {
      total += U[i].len();
   }
   return total;
}

int encontrarMenor(vetor U[], int n)
{
   int minIdx = -1;
   int minVal = 99999999;

   for (int i = 0; i < n; i++)
   {
      if (U[i].len() > 0 && U[i][0] < minVal)
      {
         minVal = U[i][0];
         minIdx = i;
      }
   }
   return minIdx;
}

vetor mergeAll(vetor U[], int n)
{
   /*
    Esta função funde os n vetores na entrada U
    num vetor de saída . Note que se os vetores
    em U são ordenados então o vetor de saída
    também o será. Porém mantenha em mente
    que as entradas em U NÃO são necessariamente
    ordenadas nos casos de testes.
    */
   int total = calcularTotal(U, n);

   vetor result(total);
   int resultIndex = 0;

   while (resultIndex < total)
   {
      int minIdx = encontrarMenor(U, n);
      int minVal = U[minIdx][0];

      result[resultIndex++] = minVal;

      if (minIdx != -1)
      {
         for (int j = 0; j < U[minIdx].len() - 1; j++)
         {
            U[minIdx][j] = U[minIdx][j + 1];
         }
         U[minIdx].rdm(U[minIdx].len() - 1);
      }
   }

   return result;
}

int main()
{
   int arr1[] = {6, 8, 5};
   int arr2[] = {3, 2, 1};
   int arr3[] = {4, 0, 9};

   vetor v1(3, arr1);
   vetor v2(3, arr2);
   vetor v3(3, arr3);

   vetor U[] = {v1, v2, v3};

   vetor merged = mergeAll(U, 3);

   cout << "Vetor resultante após merge e sort: ";
   for (int i = 0; i < merged.len(); i++)
   {
      cout << merged[i] << " ";
   }
   cout << endl;

   return 0;
}