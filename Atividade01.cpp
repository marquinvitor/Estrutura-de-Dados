#define atividade "1"
#define nome "Marcos Vitor Souza Freire"
#define matricula "552355"

// AS FUNÇÕES A SEGUIR DEVEM SER
//  IMPLEMENTADAS USANDO RECURSIVIDADE.
//  FUNÇÕES AUXILIATES PODEM SER
//  USADAS DESDE QUE SEJAM TAMBÉM RECURSIVAS.

// 1
// calcula o mdc de dois inteiros dados.
int mdc(int a, int b)
{
    if (b == 0)
        return a;
    return mdc(b, a % b);
}

// 2
// Carregar no vetor M de tamanho
// n os n primeiros primos.começando em 2
// Note que o argumento de entrada M é saída neste problema.
bool ePrimo(int num, int i = 2)
{
    if (num <= 2)return (num == 2) ? true : false;
    if (num % i == 0)return false;
    if (i * i > num)return true;
    return ePrimo(num, i + 1);
}

void loadPrimeVet(int v[], int n, int i = 2, int contador = 0)
{
    if (n == contador)return;

    if (ePrimo(i))
    {
        v[contador] = i;
        loadPrimeVet(v, n, i + 1, contador + 1);
    }
    else
    {
        loadPrimeVet(v, n, i + 1, contador);
    }
}

void loadPrimeVec(int M[], int n)
{
    int i = 2;
    int contador = 0;
    loadPrimeVet(M, n, i, contador);
}

