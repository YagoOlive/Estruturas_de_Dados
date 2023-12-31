#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTAM 1000

/* Estrutura de Dados Lista Din�mica*/
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


/* Fun��es de manipula��o da Lista Din�mica*/
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

//Fun��es que manipula uma pilha
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


void Separa(TipoLista Lista, TipoPilha *pilha,  TipoPilha *pilha2) {
    TipoItem item;
    TipoApontador aux;

    aux = Lista.Primeiro->Prox;
    while (aux != NULL) {
    	if(aux->Item.letra=='a'||aux->Item.letra=='e'||aux->Item.letra=='i'||aux->Item.letra=='o'||aux->Item.letra=='u'){
    		Empilha(aux->Item, pilha);
		}
		else{
			Empilha(aux->Item, pilha2);
		}
        
        aux = aux->Prox;
    }
}

main(){
	TipoLista lista;
	TipoApontador p;
	TipoItem item;
	
	TipoPilha pilha;
	TipoPilha pilha2;
	
	FLVazia(&lista);
	printf("\nLista Vazia: %d", Vazia(lista));
	item.letra='a'; Insere(item, &lista);
	item.letra='b'; Insere(item, &lista);
	item.letra='c'; Insere(item, &lista);
	item.letra='d'; Insere(item, &lista);
	item.letra='e'; Insere(item, &lista);
	printf("\nExibindo a Lista 1\n");
	Imprime(lista);
	
	FPVazia(&pilha);
	printf("\nLista Vazia: %d", Vazia(pilha));
	
	FPVazia(&pilha2);
	printf("\nPilha2 Vazia: %d", Vazia(pilha2));
	
	//printf("\nLista Vazia: %c", lista.Primeiro->Prox->Item.letra);
	Separa(lista, &pilha, &pilha2);
	printf("\n\n");
	
	Imprime(pilha);
	printf("\n\n");
	Imprime(pilha2);
	//Imprime(lista);
    //printf("\nLista Vazia: %d", Vazia(lista));
}
