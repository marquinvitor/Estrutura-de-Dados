#include <fstream>
#include <cmath>
#include <iostream>

#define atividade "3"  
#define nome "Marcos vitor Souza Freire " 
#define matricula "552355"

namespace aluno {

/*
Representa uma fração reduzida, ou seja, numerador e denominador são primos entre si.  
*/


class frac {
   int num;
   int den;

   static int mdc(int a, int b) {
       if (b == 0)
        return a;
    return mdc(b, a % b);
   }

public:

    frac(int n=0, int d=1) {  
       // configura operador == 
       num = n;
       den = d;
   }
   // Operadores 
   bool operator>(frac& frac) {
        // configura operador >
       if(((float)num/den) > ((float)frac.getNum() / frac.getDen())){
        return true;
       }
       return false;
   }
   bool operator==(frac& frac) {
        // configura operador ==
        if(((float)num/den) == ((float)frac.getNum() / frac.getDen())){
            return true;
        }
        return false;
   }
   frac operator+(frac& fracao) {
        // soma
        int a = fracao.getNum() * den + fracao.getDen() * num;
        int b = fracao.getDen() * den;

        int mdcValue = mdc(a,b);
        
        a = a / mdcValue;
        b = b / mdcValue;

         return frac(a,b);
    }     
   int getNum() { return num; }    
   int getDen() { return den; } 
};

frac* loadFracs(char* fileFracs) {
/* 
Retorna frações num arquivo e as coloca em um vetor alocaso dinamicamente. 

O conteúdo de tais arquivos segue o formato do esquema a seguir,

-----------
4           | -> 4 frações
1   2       | -> fração 1/2
3   5       | -> fração 1/5
2   9       ! -> fração 2/9 
7   11      ! -> fração 7/11
-------------
*/
    std::ofstream arquivoSaida;
    frac* fracoes = (frac*)malloc(sizeof(frac) * 16);
    int numerador, denominador;
    int contadorFracoes = 0;

    arquivoSaida.open("fracoes.txt");

    for (int i = 0, contador = 0; fileFracs[i] != '\0'; i++)
    {
        if (!(fileFracs[i] >= 48 && fileFracs[i] <= 57))
            continue;
        if (contador == 0)
        {
            for (; fileFracs[i] >= 48 && fileFracs[i] <= 57; i++)
            {
                arquivoSaida << fileFracs[i]; // TODO
            }
            arquivoSaida << std::endl;
            contador++;

            continue;
        }
        if (contador % 2 != 0)
        {
            arquivoSaida << fileFracs[i];
            int j, tamanho = 0;
            for (j = i + 1; fileFracs[j] >= 48 && fileFracs[j] <= 57; j++, tamanho++)
            {
                arquivoSaida << fileFracs[j]; // TODO
            }

            numerador = pow(10, tamanho) * (fileFracs[i] - '0');

            while (tamanho != 0)
            {
                tamanho--;

                numerador += pow(10, tamanho) * (fileFracs[i + 1] - '0');
                i++;
            }

            arquivoSaida << '\t';
        }
        else
        {
            arquivoSaida << fileFracs[i];
            int j, tamanho = 0;
            for (j = i + 1; fileFracs[j] >= 48 && fileFracs[j] <= 57; j++, tamanho++)
            {
                arquivoSaida << fileFracs[j]; // TODO
            }

            denominador = pow(10, tamanho) * (fileFracs[i] - '0');

            while (tamanho != 0)
            {
                tamanho--;

                denominador += pow(10, tamanho) * (fileFracs[i + 1] - '0');
                i++;
            }
            arquivoSaida << std::endl;
            *(fracoes + contadorFracoes) = frac(numerador, denominador);
            contadorFracoes++;
        }
        contador++;
    }

    arquivoSaida.close();

    return fracoes; 
}

frac sumFracs(frac fracs[], int n) {
  /* 
   Retorna soma de frações do vetor de entrada. 
*/
    frac soma(0,1);

    for(int i = 0 ; i < n ; i++){
        soma = soma.operator+(fracs[i]);        
    }
    return soma;
}

void sortFracs(frac fracs[], int n) {
    /*
       ordena vetor de drações de entrada. Note que um ponteiro do vetor real é passado como argumento. O tamanho passaso  do vetor é dado por n.   
    */
   int cont = 0;

   while (cont != n){
    for(int i = cont ; i < n ; i++){
        if(fracs[0 + cont].operator>(fracs[i]) && i != 0){
            frac aux = fracs[0 + cont];
            fracs[0 + cont] = fracs[i];
            fracs[i] = aux;
        }
    }
    cont++;
   }
}

}