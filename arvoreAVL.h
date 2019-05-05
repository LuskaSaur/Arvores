#ifndef ARVOREAVL_H
#define ARVOREAVL_H

typedef struct avlNo {
       
     int info;                // Informação contida no nó

     

     struct avlNo *esq;      // Aponta para o filho da esquerda 
     struct avlNo *dir;      // Aponta para o filho da direita
} avlNo;

typedef struct avlArvore {
       
     avlNo *raiz;            // Raiz da árvore

} avlArvore;



tree * iniciaArv ( ); //incia arvore
avlNo * iniciaNo (int valor); //inicia no
int alturaAvl(avlNo *node); //altura do no
int fatorBal(avlNo *node); //verifica fator de balanceamento
avlNo *rotacaoEsquerda (avlNo *node); //rotacao p esquerda simples
avlNo *rotacaoEsquerdaDupla (avlNo *node);// rotacao p esquerda fupla
avlNo *rotacaoDireita (avlNo *node); //rotacao p direita simples
avlNo *rotacaoDireitaDupla (avlNo *node);//rotacao p esquerda dupla
avlNo * balancear_node (avlNo *  node);// balanceia no
void balancearArv (arvoreAVL *  tree);//balanceia arvore
void inserir (arvoreAVL * tree, int valor); //inserir na arvore
avlNo * encontrarValor (arvoreAVL * tree, int valor); //pega valor retorna null se nao encontra



#endif
