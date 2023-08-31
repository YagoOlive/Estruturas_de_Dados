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

int Compara_pilha(TipoPilha pilha, TipoPilha pilha2){
	
	
	if(pilha.topo!=pilha2.topo){
		return 0;
	}
	else{
	
	    TipoItem item, item2;
		while(!Vazia(pilha)){
			
		    Desempilha(&pilha, &item);
		    Desempilha(&pilha2, &item2);
		    
		    if(item.letra != item2.letra) 
		        return 0;
	        
	                  
	    } 
		return 1; 
	}				
}
	


main(){
	TipoPilha pilha, pilha2;
	TipoItem item;
	
	
	FPVazia(&pilha);
	FPVazia(&pilha2);
	//printf("\nvazia: p %d\n", Vazia(pilha));
	//printf("\nvazia: p2 %d\n", Vazia(pilha2));
	
	item.letra='a';Empilha(item, &pilha);
	item.letra='z';Empilha(item, &pilha);
	item.letra='c';Empilha(item, &pilha);
	item.letra='d';Empilha(item, &pilha);
	
	
	item.letra='a';Empilha(item, &pilha2);
	item.letra='b';Empilha(item, &pilha2);
	item.letra='c';Empilha(item, &pilha2);
	item.letra='d';Empilha(item, &pilha2);
	
	printf("%d", Compara_pilha(pilha, pilha2));
	 
	
}
