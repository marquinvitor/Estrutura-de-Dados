#include <iostream>

#define atividade "07"
#define nome "Marcos Vitor Souza Freire"
#define matricula "552355"

using namespace std;

/*
Seja um BIGnUMBER um inteiro positivo ou zero representado por uma lista encadeada. Cada dígito ocupa um nó da estrutura. A significância dos algarismos é de menor para maior a partir da raiz. Por exemplo, o número 1234 é armazenado pela lista:

|-> 4 -> 3 -> 2 -> 1

Onde |-> representa o ponteiro da raiz e -> outras conexões entre nós. Implemente bigNumber no modelo de classe a seguir,
*/

class bigNumber
{
    struct nodo
    {
        int digit;
        nodo *next;
    };
    nodo *pt;

public:
    bigNumber(int x)
    { /* cria um novo bigNumber distribuindo os dígitos de x na lista encadeada. */
        pt = nullptr;
        nodo **digAtual = &pt;
        if (x == 0)
        {
            *digAtual = new nodo();
            (*digAtual)->digit = 0;
            (*digAtual)->next = nullptr;
        }
        else
        {
            while (x > 0)
            {
                *digAtual = new nodo();
                (*digAtual)->digit = x % 10;
                x /= 10;
                digAtual = &((*digAtual)->next);
            }
        }
    }

    bigNumber()
    { /* inicia um bigNumber com valor zero */
        pt = new nodo;
        pt->digit = 0;
        pt->next = nullptr;
    }

    int toInt()
    {
        int result = 0;
        int place = 1;
        nodo *digAtual = pt;

        while (digAtual != nullptr)
        {
            result += digAtual->digit * place;
            place *= 10;
            digAtual = digAtual->next;
        }

        return result;
    }

    void operator+=(int x)
    { /* soma x a um bigNumber */
        int newVal = toInt() + x;
        *this = bigNumber(newVal);
    }

    void operator*=(int x)
    { /* multiplica x a um bigNumber */
        int newVal = toInt() * x;
        *this = bigNumber(newVal);
    }

    void operator+=(bigNumber &bn)
    { /* soma bigNumber a outro */
        int newVal = this->toInt() + bn.toInt();
        *this = bigNumber(newVal);
    }

    void operator*=(bigNumber &bn)
    { /* multiplica bigNumber a outro */
        int newVal = this->toInt() * bn.toInt();
        *this = bigNumber(newVal);
    }

    bool operator==(bigNumber &bn)
    { /* compara bigNumbers */
        return this->toInt() == bn.toInt();
    }
};