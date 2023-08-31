#include<stdio.h>
#define MAXTAM 1000

typedef int TipoApontador;


typedef struct {
	
    char letra;

}TipoItem; 

typedef struct{
    TipoItem itens[MAXTAM ] ;
    TipoApontador topo;
}TipoPilha;

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
        pilha ->itens[pilha ->topo - 1] = x ;
    }
}//Insere elemento na pilha

void Desempilha(TipoPilha *pilha , TipoItem *Item){
    if (Vazia(*pilha))
        printf ( "Erro : pilha esta vazia\n" );
    else {
        *Item = pilha ->itens[pilha->topo - 1];
        pilha ->topo--;
    }
} //Retira elemento da pilha

void Imprime(TipoPilha pilha){
	int i;
	if (Vazia(pilha))
        printf ( "Erro : pilha esta vazia\n" );
    else{
    	for(i=pilha.topo-1;i>=0;i--){
    	    printf("\n%d - %c",i , pilha.itens[i].letra);	
		}	
	}
}// Exibi a pilha

int Tamanho(TipoPilha pilha){
    return (pilha.topo) ;
}

main(){
	TipoPilha pilha;
	TipoItem item;
	FPVazia(&pilha);
	Vazia(pilha);
	item.letra='a';Empilha(item, &pilha);
	item.letra='b';Empilha(item, &pilha);
	item.letra='c';Empilha(item, &pilha);
	item.letra='d';Empilha(item, &pilha);
	Imprime(pilha);
	printf("\n\n%d", Tamanho(pilha));
}

