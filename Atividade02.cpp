#include <math.h>

#define atividade "2"  
#define nome "Marcos Vitor Souza Freire" 
#define matricula "552355"

/*
Seja uma classe que representa um ponto no plano dada por,.  
*/

class ponto {
    float x; // abcissa
    float y; // ordenada
public:
    ponto (int _x, int _y)  // constrói ponto
    {  
        x = _x;
        y = _y;   
        // cria  ponto dadas coordenadas
    }
    ponto () {
         x = 0;
         y = 0;// alternativa de criação de ponto
         // para construir um ponto (0,0) 
     }
     float dist (const ponto& p) {
            // determina a distância do ponto
            // à este passaso como argumeto.
            float distancia = pow(p.x - x, 2) + pow(p.y - y, 2);
            return sqrt(distancia);
        }
        float& X() {
               // retorna referência 
               // da abcissa 
               return x;
        }
        float Y() {
             // Retorna referência para
             // a ordenada
             return y;
         }
         

};

/* Implemente as funções a seguir usando a classe anterior */

float reta(ponto& p, ponto& q) {
    // retorna coeficiente angular da reta 
    // que passa por p e 
    return(q.Y() - p.Y())/ (q.X() - p.X());
}

float minDist(const ponto& p, ponto kust[], int n) {
   // retorna a menor distância entre p e os // pontos da lista list dada de 
   // comprimento n.  

    float menorD = kust[0].dist(p);

    for(int i = 0 ; i < n ; i++){
        float dis = kust[i].dist(p); 

        if(dis < menorD){
            menorD = dis;
        }
    }
    return menorD;
}