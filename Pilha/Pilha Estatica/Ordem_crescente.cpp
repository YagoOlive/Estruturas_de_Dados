#include<stdio.h>
#include<string.h>
#define MAXTAM 1000

typedef int TipoApontador;


typedef struct {
	
    int numero;

}TipoItem; 

typedef struct{
    TipoItem itens[MAXTAM ];
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
    	    printf("\n%d.ind - %d",i , pilha.itens[i].numero);	
		}	
	}
}// Exibi a pilha

int Tamanho(TipoPilha pilha){
    return (pilha.topo) ;
}

int Ordem_crescente(TipoPilha pilha){
	
	TipoItem item, x=pilha.itens[pilha.topo-1];
	Desempilha(&pilha , &x);
	
	while(!Vazia(pilha)){
		Desempilha(&pilha, &item);
		if(x.numero > item.numero){
	
		    x = item;
	    }
	    else
	        return 0;  	
	}
	return 1;
}	

	
main(){
	TipoPilha pilha;
	TipoItem item;
	
	
	FPVazia(&pilha);
	//printf("%d\n", Vazia(pilha));
	
	item.numero=1;Empilha(item, &pilha);
	item.numero=2;Empilha(item, &pilha);
	item.numero=3;Empilha(item, &pilha);
	item.numero=4;Empilha(item, &pilha);
	Imprime(pilha);
	
	printf("\n\n%d", Ordem_crescente(pilha));

}
