/*Receba uma pilha e remova os itens com chave ‘c’ da pilha utilizando uma pilha auxiliar. Utilize
somente as funções de manipulação empilha e desempilha.*/

#include<stdio.h>
#include<stdlib.h>
#define MAXTAM 5
// Estrutura Pilha est?tica
typedef struct { 
    char chave; 
}TipoItem; 

typedef struct TipoCelula *TipoApontador; 

typedef struct TipoCelula { 
	TipoItem Item; 
	TipoApontador Prox; 
} TipoCelula; 

typedef struct { 
	TipoApontador  Fundo, Topo; 
	int Tamanho; 
} TipoPilha;

// Fun??es de manipula??o da pilha din?mica

void FPVazia(TipoPilha *Pilha) { 
	Pilha ->Topo=(TipoApontador) malloc(sizeof(TipoCelula)); 
	Pilha ->Fundo = Pilha ->Topo; 
	Pilha ->Topo->Prox = NULL; 
	Pilha ->Tamanho = 0; 
}

int Vazia(TipoPilha Pilha) {
	return ( Pilha .Topo == Pilha .Fundo) ; 
}

void Empilha(TipoItem x, TipoPilha *Pilha) { 
	TipoApontador Aux; 
	Aux = (TipoApontador) malloc(sizeof(TipoCelula)); 
	Pilha ->Topo->Item = x; 
	Aux->Prox = Pilha ->Topo; 
	Pilha ->Topo = Aux; 	
	Pilha ->Tamanho++; 
}

void Desempilha(TipoPilha *Pilha , TipoItem *Item) {
	TipoApontador q; 
	if (Vazia( *Pilha ) ) { 
		printf ( "Erro : lista vazia\n" ) ; 	return; 
	} 
	q = Pilha ->Topo; 
	Pilha ->Topo = q ->Prox; 
	*Item = q ->Prox->Item; 
	free(q) ;
	Pilha ->Tamanho--; 
}

int Tamanho(TipoPilha Pilha) { 
	return ( Pilha .Tamanho) ; 
}

void exibePilha(TipoPilha pilha){
	TipoApontador aux=pilha.Topo->Prox;
	while(aux!=NULL){
		printf("\n%c", aux->Item.chave);
		aux=aux->Prox;
	}
}

TipoApontador busca(TipoPilha pilha, TipoItem item){
	TipoApontador aux=pilha.Topo->Prox;
	while(aux!=NULL){
		if(aux->Item.chave==item.chave)
			return aux;
		aux=aux->Prox;		
	}
	return NULL;
}


void RetiraItem(TipoPilha *pilha){
	
	TipoItem item;
	TipoPilha aux;
	FPVazia(&aux);
	
	while(!Vazia(*pilha)){
		Desempilha(pilha, &item);
		if(item.chave!='c'){
			Empilha(item, &aux);
		}
	}
	while(!Vazia(aux)){
		Desempilha(&aux, &item);
		Empilha(item, pilha);
	}
}

main(){
	TipoItem item;
	TipoPilha pilha;
	FPVazia(&pilha);
	
	item.chave='a'; Empilha(item, &pilha);		
	item.chave='b'; Empilha(item, &pilha);		
	item.chave='c'; Empilha(item, &pilha);	
	item.chave='d'; Empilha(item, &pilha);		
	item.chave='e'; Empilha(item, &pilha);		
	item.chave='c'; Empilha(item, &pilha);		
	
	exibePilha(pilha);
	printf("\n\n");
	
	RetiraItem(&pilha);
	
	printf("\n\n");
	exibePilha(pilha);

}
