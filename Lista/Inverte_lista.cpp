#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTAM 1000

/* Estrutura de Dados Lista Dinâmica*/
struct TipoItem{
	char letra;
};

typedef struct TipoCelula *TipoApontador;

struct TipoCelula {
	TipoItem Item ;
	TipoApontador Prox;
};

struct TipoLista{
	TipoApontador Primeiro , 		
		Ultimo ;
};


/* Funções de manipulação da Lista Dinâmica*/
void FLVazia(TipoLista *Lista){
	Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula)) ;
	Lista->Ultimo = Lista->Primeiro ; 
	Lista->Primeiro->Prox = NULL ;
}

int Vazia(TipoLista Lista){
		return(Lista.Primeiro == Lista.Ultimo);
}

void Insere (TipoItem x , TipoLista * Lista ){
	Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
	Lista->Ultimo = Lista->Ultimo->Prox;
	Lista->Ultimo->Item = x ;
	Lista->Ultimo->Prox = NULL ;
}

void Imprime(TipoLista Lista){
	TipoApontador Aux;
	Aux = Lista.Primeiro->Prox;
	while (Aux != NULL){
		printf("%c\n" , Aux->Item.letra);
		Aux = Aux->Prox ;
	}
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item) {
	TipoApontador q;
	if(Vazia(*Lista) || p==NULL || p->Prox == NULL){ 
		printf("Erro : Lista vazia ou posicao nao existe \n"); return ;
	}
	q = p->Prox; *Item = q->Item; p->Prox = q->Prox;
	if (p->Prox == NULL) 
		Lista->Ultimo = p;
	free (q) ;
}

void Retira_p(TipoApontador p, TipoLista *Lista, TipoItem *Item) {
    TipoApontador q;

    if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
        printf("Erro: posicao nao existe\n");
        return;
    }

    q = p->Prox;
    *Item = q->Item;
    p->Prox = q->Prox;

    if (p->Prox == NULL) {
        Lista->Ultimo = p;
    }

    free(q);
}

//Estrutura de uma pilha estatica
typedef int TipoApontadorPilha;
 
typedef struct{
    TipoItem Item[MAXTAM ] ;
    TipoApontadorPilha topo;
}TipoPilha;

//Funções que manipula uma pilha
void FPVazia(TipoPilha *pilha){
    pilha ->topo = 0;
}//Faz pilha vazia

int Vazia(TipoPilha pilha){
    return (pilha.topo == 0);
}//Verifica pilha vazia

void Empilha(TipoItem x, TipoPilha *pilha){
    if (pilha ->topo == MAXTAM)
        printf ( "Erro : pilha esta cheia\n" );
    else {
        pilha ->topo++;
        pilha->Item[pilha->topo-1] = x ;
    }
}//Insere elemento na pilha

void Desempilha(TipoPilha *pilha , TipoItem *Item){
    if (Vazia(*pilha))
        printf ( "Erro : pilha esta vazia\n" );
    else {
        *Item = pilha->Item[pilha->topo-1];
        pilha ->topo--;
    }
} //Retira elemento da pilha

void Imprime(TipoPilha pilha){
	int i;
	if (Vazia(pilha))
        printf ( "Erro : pilha esta vazia\n" );
    else{
    	for(i=pilha.topo-1;i>=0;i--){
    	    printf("\n%d - %c",i , pilha.Item[i].letra);	
		}	
	}
}// Exibi a pilha

int Tamanho(TipoPilha pilha){
    return (pilha.topo) ;
}

void Inverte_string(TipoPilha *pilha, TipoLista *lista){
	TipoItem item;
	TipoApontador Aux, p;

	Aux = lista->Primeiro->Prox;
	/*while (Aux!=NULL){
		Empilha(Aux->Item, pilha);
		//p=Aux;
		//Retira_p(Aux, lista, &item);
		Aux = Aux->Prox ;	
	}*/
	Aux = lista->Primeiro->Prox;
    while (lista->Primeiro->Prox != NULL) {
   	    Retira_p(Aux, lista, &item);
        Aux = lista->Primeiro->Prox;
        
    }
/* 	while (!Vazia(*pilha)) {
        Desempilha(pilha, &item);
        Insere(item, lista);
    }*/
	
}

void Inverte(TipoLista *Lista, TipoPilha *Pilha) {
    TipoItem item;
    TipoApontador aux;

    aux = Lista->Primeiro->Prox;
    while (aux != NULL) {
        Empilha(aux->Item, Pilha);
        aux = aux->Prox;
    }

    FLVazia(Lista);
    while (!Vazia(*Pilha)) {
        Desempilha(Pilha, &item);
        Insere(item, Lista);
    }
}

main(){
	TipoLista lista;
	TipoApontador p;
	TipoItem item;
	
	TipoPilha pilha;
	
	FLVazia(&lista);
	printf("\nLista Vazia: %d", Vazia(lista));
	item.letra='a'; Insere(item, &lista);
	item.letra='b'; Insere(item, &lista);
	item.letra='c'; Insere(item, &lista);
	item.letra='d'; Insere(item, &lista);
	item.letra='e'; Insere(item, &lista);
	printf("\nExibindo a Lista 1\n");
	Imprime(lista);
	//Retira_p( p, &lista, &item);
	FPVazia(&pilha);
	Vazia(pilha);
	//printf("\nLista Vazia: %c", lista.Primeiro->Prox->Item.letra);
	Inverte_string(&pilha, &lista);
	printf("\n\n");
	
	Imprime(pilha);
	printf("\n\n");
	//Imprime(lista);
    printf("\nLista Vazia: %d", Vazia(lista));
}
	
