#include<stdio.h>
#include<stdlib.h>
#define MAXTAM 5
// Estrutura Pilha est?tica
typedef struct { 
    int chave; 
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
		printf("\n%d", aux->Item.chave);
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

int Item_Pilhas(TipoPilha P1, TipoPilha P2, TipoItem item){
	
	TipoItem item1;
	TipoItem item2;
	int cont=0;
	
	while(!Vazia(P1)){
		
		Desempilha(&P1, &item1);
		if(item.chave==item1.chave){
						
	    	cont++;
	    	break;
		}
	}
	while(!Vazia(P2)){
		
		Desempilha(&P2, &item2);
		if(item.chave==item2.chave){
						
	    	cont++;
	    	break;
		}
	}
	if(cont==2)
		return 1;
	else
		return 0;
}



main(){
	TipoItem item;
	TipoPilha pilha;
	FPVazia(&pilha);

	TipoPilha pilha2;
	FPVazia(&pilha2);
	
	item.chave=1; Empilha(item, &pilha);		
	item.chave=2; Empilha(item, &pilha);		
	item.chave=3; Empilha(item, &pilha);	
	item.chave=4; Empilha(item, &pilha);		
	item.chave=5; Empilha(item, &pilha);		
	item.chave=6; Empilha(item, &pilha);		
	
    item.chave=1; Empilha(item, &pilha2);		
	item.chave=2; Empilha(item, &pilha2);		
	item.chave=3; Empilha(item, &pilha2);	
	item.chave=4; Empilha(item, &pilha2);		
	item.chave=5; Empilha(item, &pilha2);		
	item.chave=6; Empilha(item, &pilha2);	

	item.chave=1;

	printf("\n");
	printf("\n%d\n", Item_Pilhas(pilha, pilha2, item));

		
	printf("\n");

}
