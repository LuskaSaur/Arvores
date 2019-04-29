#include <stdio.h>
#include <stdlib.h>
#include "ArvABP.h"

Arvore* criarArv(){
    return NULL;
}

void criarArvAle(Arvore *arv,int tam){
    if(arv == NULL){
        criarArvAle(criarArv(),tam);
    }else{
        clock_t t;
        srand((unsigned)time(t));
        for(int i = 0;i<tam;i++)
        dado = rand()%tam+1);
        inserir(arv,dado);
    }
}
void inserir(Arvore *arv, int dado){ 
    Arvore aux = arv;
    if(!aux){
        aux = (Arvore *)malloc(sizeof(Arvore));
        aux->sae = NULL;
        aux->sad = NULL;
        aux->dado = dado;
    }
    if(dado > aux->dado){
        inserir(aux->sad,dado);
    }else{
        inserir(aux->sae,dado);
    }
}

int buscarnaArv(Arvore *arv, int chave){
    if(!arv){
        return 0;
    }
    if(arv->dado == chave){
        return 1;
    }else{
        if(chave > arv->dado){
            buscarnaArv(arv->sad,chave);
        }else{
            buscarnaArv(arv->sae,chave);
        }
    }    
}
int verifArv(Arvore *arv){
    return arv == NULL;
}
void mostrarArvemOrdem(Arvore *arv){
    if(!arv){
        mostrarArv(arv->sae);
        printf("%d",arv->dado);
        mostrarArv(arv->sad);
    }
}

void mostrarArvemPre_Ordem(Arvore *arv){
    if(!arv){
        printf("%d",arv->dado);
        mostrarArv(arv->sae);
        mostrarArv(arv->sad);
    }
}

void mostrarArvemPos_Ordem(Arvore *arv){
    if(!arv){
        mostrarArv(arv->sae);
        mostrarArv(arv->sad);
        printf("%d",arv->dado);
    }
}

int alturaArv(Arvore *arv){
    if(!arv){
        return 0;
    }
    int ae = alturaArv(arv->esq);
    int ad = alturaArv(arv->dir);
    if(ae>ad){
        return ae+1;
    }else{
        return ad+1;
    }
}
