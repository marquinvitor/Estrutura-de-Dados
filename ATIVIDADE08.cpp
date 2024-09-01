#include <iostream>

// Atividade 08,Álgebra Linear

#define atividade "8"
#define nome "Marcos Vitor Souza Freire"
#define matricula "552355"
using namespace std;

struct node
{
  int key;
  node *left;
  node *right;
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

