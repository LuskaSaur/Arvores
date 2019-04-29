#ifndef ArvABP_H
#define ArvABP_H

typedef struct Arvore
{
    int dado
    struct Arvore *sae
    struct Arvore *sad
}Arvore;


void criarArvAle(Arvore *arv,tam);// cria avore com valores aleatórios
void inserir(Arvore *arv, int dado);// inserir na arvore
int buscarnaArv(Arvore *arv, int chave);// busca em arvore
int verifArv(Arvore *arv);// verifica se a arvore está vazia
void mostrarArvemPre_Ordem(Arvore *arv);// Mostra Pré-Ordem
void mostrarArvemPos_Ordem(Arvore *arv);// Mostra Pós-Ordem
void mostrarArvemOrdem(Arvore *arv);// Mostra em-ordem
int alturaArv(Arvore *arv); // Retorna a Altura da Arvore
