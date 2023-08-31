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

void InvertePalavra( char palavra[50], TipoPilha *pilha){
	int i;
	TipoItem item;
	
	for(i=0;i<strlen(palavra); i++){
		
		item.chave=palavra[i];
		Empilha(item, pilha);
	}
	for(i=0;i<strlen(palavra); i++){
		
		Desempilha(pilha, &item);
		palavra[i]=item.chave;
		
	}
}

void InverteTexto( char texto[2000]){
	int marcador=0, inicio=0, i, j, cont;
	char palavra[50];
	TipoItem item;
	TipoPilha pilha;
	FPVazia(&pilha);
	
	for(i=0;i<strlen(texto); i++){
		
		if(texto[i]== ' '){	
		
			for(j=marcador;j<i;j++){
				item.chave = texto[j];
				Empilha(item, &pilha);
			}
			for(j=marcador;j<i;j++){
				Desempilha(&pilha, &item);
				texto[j]= item.chave;
			}
			marcador=i;	
		}	
		
    }
}

main(){
	TipoItem item;
	TipoPilha pilha;
	FPVazia(&pilha);
	
	char texto[2000] = "ESTE EXERCICIO MUITO FACIL ";
	
	puts(texto);
			
	InverteTexto(texto);
	
	puts(texto);

	
	

}
