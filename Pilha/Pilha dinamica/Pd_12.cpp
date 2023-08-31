/*Receba uma Lista estática e inverta a ordem do itens da lista utilizando uma Pilha Dinâmica.*/

#define INICIOARRANJO 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTAM 10

typedef int TipoApontadorLista;
typedef struct TipoCelula *TipoApontador; 

typedef struct { 
    char chave; 
}TipoItem;
 
struct TipoLista{
	TipoItem itens[MAXTAM];
	TipoApontadorLista primeiro, ultimo;
};

// Estrutura Pilha est?tica



typedef struct TipoCelula *TipoApontador; 

typedef struct TipoCelula { 
	TipoItem Item; 
	TipoApontador Prox; 
} TipoCelula; 

typedef struct { 
	TipoApontador  Fundo, Topo; 
	int Tamanho; 
} TipoPilha;


void Cria_Lista_Vazia(TipoLista *lista){
	lista->primeiro= INICIOARRANJO;
	lista->ultimo= lista->primeiro;
}

int Verifica_l_Vazia(TipoLista lista){
	return(lista.primeiro==lista.ultimo);
}

void Insere(TipoItem x, TipoLista *lista){
	if(lista->ultimo>MAXTAM){
	    printf("***LISTA CHEIA!***");
	}
	else{
		lista->itens[lista->ultimo-1]=x;
		lista->ultimo++;
	}
}

void Retira(TipoApontadorLista p, TipoLista *lista, TipoItem *item){
	int i;
	if(Verifica_l_Vazia(*lista) || p>=lista->ultimo){
		printf("***POSICAO INEXISTENTE!***");
	}
	else{
		*item = lista->itens[p-1];
		lista->ultimo--;
		for(i=p;i<lista->ultimo;i++){
			lista->itens[i-1]=lista->itens[i];
		}
		
	}
}

void Imprime(TipoLista lista){
	int i;
	for(i=lista.primeiro-1;i<=lista.ultimo-2;i++){
			printf("\n\n %c", lista.itens[i].chave);
			
		}
}




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

void InverteLista(TipoLista *lista, TipoPilha *pilha){
	
	TipoItem item;
	int i;
	
	for(i=lista->primeiro-1;i<=lista->ultimo-1;i++){
			Retira(lista->primeiro, lista, &item);
			Empilha(item, pilha);
			i=lista->primeiro-1;
		}
		while(!Vazia(*pilha)){
			Desempilha(pilha, &item);
			Insere(item, lista);
		}
}

main(){
	TipoItem item;
	TipoPilha pilha;
	TipoLista lista;
	
	FPVazia(&pilha);
	Cria_Lista_Vazia(&lista);
	
	
	item.chave='a'; Insere(item, &lista);		
	item.chave='b'; Insere(item, &lista);		
	item.chave='c'; Insere(item, &lista);		
	item.chave='d'; Insere(item, &lista);
	item.chave='e'; Insere(item, &lista);		
	item.chave='f'; Insere(item, &lista);		
	item.chave='g'; Insere(item, &lista);		
	item.chave='h'; Insere(item, &lista);
	
	Imprime(lista);
	printf("\n\n");
	
	InverteLista(&lista, &pilha);
	
	
	Imprime(lista);
	printf("\n\n");
}

