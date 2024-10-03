#include <iostream>

// Atividade 08, Álgebra Linear

#define atividade "8"
#define nome "Marcos Vitor Souza Freire"
#define matricula "552355"
using namespace std;

struct node
{
    int key;
    int ball;
    node *left;
    node *right;

    node() : key(0), ball(0), left(nullptr), right(nullptr) {}
};

node *inserir(node *root, int key)
{
    if (root == nullptr)
    {
        root = new node();
        root->key = key;
        root->left = root->right = nullptr;
        return root;
    }

    if (key > root->key)
        root->right = inserir(root->right, key);

    else
    {
        root->left = inserir(root->left, key);
    }
    return root;
}

node *loadTree(int *u, int n)
{
    /*
    monta árvore a partir
    da inseção consecutiva de chaves do vetor u.
    */
    node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        root = inserir(root, u[i]);
    }
    return root;
}

void percorrer(node *root, int *u, int &i)
{
    if (root == nullptr)
    {
        return;
    }

    percorrer(root->left, u, i);

    u[i++] = root->key;

    percorrer(root->right, u, i);
}

void loadVec(node *root, int u[], int n)
{
    /*
    varre árvore enraizada em root  usando percurso em ordem simétrica e coloca cada chave visitada progressivamente em u  na ordem de visitação da árvore. u.
    */
    int i = 0;
    percorrer(root, u, i);
    return;
}

int height(node *root)
{
    /*
  determina a altura de uma arvore em raizada em root.
  a altura de uma arvore é a distancia em nodos da raiz ate a nodo de maior desendencia.
  a arvore vazia tem altura 0 e arvores com um nodo tem altura 1.
  */
    if (root == nullptr)
    {
        return 0;
    }
    int hEsquerda = height(root->left);
    int hDireita = height(root->right);
    return 1 + max(hEsquerda, hDireita);
}

void calc_balls(node *root)
{
    /*
  determina o fator de balanciamento da raiz root.
  o fator de balanciamento ball de um nodo é a diferença
  entre as alturas de suas subarvores hDireita e hEsquerda
  preencha todos os campos de todos os nodos da arvore em raizada em root
  */
    if (root == nullptr)
    {
        return;
    }

    int hEsquerda = height(root->left);
    int hDireita = height(root->right);

    root->ball = hDireita - hEsquerda;
    calc_balls(root->left);
    calc_balls(root->right);
}

