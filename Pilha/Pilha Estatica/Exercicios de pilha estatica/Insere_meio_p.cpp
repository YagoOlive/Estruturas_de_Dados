#include<stdio.h>
#include<string.h>
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

void Insere_antes_p(TipoPilha *pilha, TipoApontador p, TipoItem item){
	
	int i=0;
/*	char str[50]="";
	TipoItem aux;
	while(!pilha->topo>=p){
		Desempilha(pilha, &aux);
		str[i]=aux.letra;
		i++;
	}
	printf("\n\n");
	Imprime(*pilha);
	Empilha(item, pilha);		
	for(i;i>=0;i--){
		aux.letra=str[i];
		Empilha(aux, pilha);			
	}*/
	for(i=pilha->topo-1;i>=p;i--){
		pilha->itens[i+1]=pilha->itens[i];	
	}
	pilha->itens[p]=item;
	pilha->topo++;
}

main(){
	TipoPilha pilha;
	TipoItem item;
	TipoApontador p;
		
	FPVazia(&pilha);
	printf("\nvazia: %d\n", Vazia(pilha));
	
	item.letra='a';Empilha(item, &pilha);
	item.letra='b';Empilha(item, &pilha);
	item.letra='d';Empilha(item, &pilha);
	item.letra='e';Empilha(item, &pilha);
	
	item.letra='c';
	p=2;
	Insere_antes_p(&pilha, p, item);
	
	Imprime(pilha);
	
	
}
