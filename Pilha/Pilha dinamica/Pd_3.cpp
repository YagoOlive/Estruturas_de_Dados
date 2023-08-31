#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

int Palindromo(TipoPilha *pilha){

	TipoItem item;
	TipoItem item2;
    TipoPilha pilha2;
	FPVazia(&pilha2);

	TipoApontador aux=pilha->Topo->Prox; 
	
	while(aux!=NULL){
		item.chave=aux->Item.chave;
		Empilha(item, &pilha2);
		aux=aux->Prox;		
	}

	
	aux=pilha->Topo->Prox;
	while(aux!=NULL){
		Desempilha(pilha, &item);
		Desempilha(&pilha2, &item2);
		aux=aux->Prox;
		if(item.chave!=item2.chave){
			return 0;
			break;
		}
		aux=aux->Prox;		
	}
	return 1;
	
}

main(){
	TipoItem item;
	TipoPilha pilha;
	FPVazia(&pilha);
	int i;
	char x[100] = "subi no onibus";
	
	
	for(i=0; i<strlen(x); i++){
		if(x[i] !=' '){
			
			item.chave= x[i];
			Empilha(item, &pilha);
		}
		
		    
		    
	}
	
	 		
			
	
	// Exibindo a pilha na dire??o topo->fundo
	exibePilha(pilha);
	//Desempilha(&pilha, &item);
	
	//exibePilha(pilha);
	
	// Testando a fun??o de busca
	
	//printf("\n\n\nTeste = %c\n", p->Item.chave);
	printf("\n\n");
	printf("\n%d", Palindromo(&pilha));
}
