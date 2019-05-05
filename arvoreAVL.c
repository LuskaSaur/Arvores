#include "arvoreAVL.c"
#include <stdlib.h>
#include <stdio.h>

tree * iniciaArv ( )
{
	arvoreAVL * tree = NULL;

	if ( ( tree = malloc ( sizeof ( arvoreAVL ) ) ) == NULL )
	{
		return NULL;
	}

	tree->raiz = NULL;

	return tree;
}

avlNo * iniciaNo ( int valor )
{
	avlNo * node;

	node = malloc ( sizeof ( avlNo) );
	if ( node == NULL )
	{
		system ( "pause" );
	}

	node->esq = NULL;
	node->dir = NULL;
	node->valor = valor;

	return node;
}


int alturaAvl(avlNo *node){
	int altura_esq = 0;
	int altura_dir = 0;

	if ( node->esq )
		altura_esq = alturaAvl ( node->esq );

	if ( node->dir )
		altura_dir = alturaAvl ( node->dir );

	return max ( altura_dir, altura_esq ) + 1;
}


int fatorBal(avlNo *node){
	int fator = 0;

	if ( node->esq )
		fator += alturaAvl ( node_->esq );

	if ( node->dir )
		fator -= alturaAvl ( node->dir );

	return fator;

}



avlNo *rotacaoEsquerda ( avlNo *node ){
	avlNo * temp = node;
	avlNo * esq = temp->esq;

	temp->esq = esq->dir;
	esq->dir = temp;

	return esq;
}

avlNo *rotacaoEsquerdaDupla ( avlNo *node ){
	avlNo *  temp = node;
	avlNo * esq = temp->esq;
	avlNo * dir = esq->dir;

	temp->esq = dir->dir;
	esq->dir = dir->esq;
	dir->esq = esq;
	dir->dir = temp;

	return dir;
}

avlNo *rotacaoDireita ( avlNo *node ){
	avlNo * temp = node;
	avlNo * dir = temp->dir;

	temp->dir = dir->esq;
	dir->esq = temp;

	return dir;
}

avlNo *rotacaoDireitaDupla (avlNo *node){
	avlNo * temp = node;
	avlNo * dir = temp->dir;
	avlNo * esq = dir->esq;

	temp->dir = esq->esq;
	dir->esq = esq->dir;
	esq->dir = dir;
	esq->esq = temp;

	return esq;
	
}



avlNo * balancear_node (avlNo *  node){
	avlNo * node_balanceado = NULL;

	if ( node->esq )
		node->esq = balancear_node ( node->esq );

	if ( node->dir )
		node->dir = balancear_node ( node->dir );

	int fator = fatorBal ( node );

	if ( fator >= 2 )
	{

		if ( fatorBal ( node->esq ) <= -1 )
			node_balanceado = rotacaoEsquerdaDupla ( node );
		else
			node_balanceado =rotacaoEsquerda ( node );

	}
	else if ( fator <= -2 )
	{
		/* pesando pra direita */

		if ( fatorBal ( node->dir ) >= 1 )
			node_balanceado = rotacaoDireitaDupla ( node );
		else
			node_balanceado = rotacaoDireita( node );

	}
	else
	{
		node_balanceado = node;
	}

	return node_balanceado;
}


void balancearArv (arvoreAVL *  tree){
	avlNo * novaRaiz = NULL;

	novaRaiz = balancear_node ( tree->raiz );

	if ( novaRaiz != tree->raiz )
	{
		tree->raiz = novaRaiz;
	}
}


void inserir ( arvoreAVL * tree, int valor ){
	avlNo * novo_node = NULL;
	avlNo * prox = NULL;
	avlNo * ult = NULL;

	if ( tree->raiz == NULL )
	{
		novo_node = iniciaNo ( valor );
		tree->raiz = novo_node;
	}
	else
	{
		prox = tree->raiz;

		while ( prox != NULL )
		{
			ult = prox;

			if ( valor < prox->valor )
			{
				prox = prox->esq;

			}
			else if ( valor > prox->valor )
			{
				prox = prox->dir;
			}
			else if ( valor == prox->valor )
			{
				return;
			}
		}

		novo_node = iniciaNo ( valor );

		if ( valor < ult->valor )
			ult->esq = novo_node;

		if ( valor > ult->valor )
			ult->dir = novo_node;

	}

	balancearArv ( tree );
}


avlNo * encontrarValor (arvoreAVL * tree, int valor){
	avlNo * atual = tree->raiz;

	while ( atual && atual->valor != valor )
	{
		if ( valor > atual->valor )
			atual = atual->dir;
		else
			atual = atual->esq;
	}

	return atual;
}
