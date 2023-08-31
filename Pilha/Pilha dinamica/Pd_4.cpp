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

void Par_impar(TipoPilha pilha, TipoPilha *Impar, TipoPilha *Par){
	
	TipoItem item;
	FPVazia(Impar);
	FPVazia(Par);
	
	while(!Vazia(pilha)){
		Desempilha(&pilha, &item);
		
		if(item.chave%2==0)
			Empilha(item, Par);	
		
		else
			Empilha(item, Impar);
	}
		
}

main(){
	TipoItem item;
	TipoPilha pilha;
	TipoPilha Impar;
	TipoPilha Par;
	FPVazia(&pilha);

	
	item.chave=1; Empilha(item, &pilha);		
	item.chave=2; Empilha(item, &pilha);		
	item.chave=3; Empilha(item, &pilha);	
	item.chave=4; Empilha(item, &pilha);		
	item.chave=5; Empilha(item, &pilha);		
	item.chave=6; Empilha(item, &pilha);		
	

	
	// Exibindo a pilha na dire??o topo->fundo
	//exibePilha(pilha);
	//Desempilha(&pilha, &item);
	//printf("\n\nItem desempilhado: %c\n", item.chave);
	exibePilha(pilha);
	printf("\n\n");
	Par_impar(pilha, &Par, &Impar);
	
	exibePilha(Par);
	printf("\n\n");
	exibePilha(Impar);
	// Testando a fun??o de busca
	//item.chave='c';
	//TipoApontador p = busca(pilha, item);
	//printf("\n\n\nTeste = %c\n", p->Item.chave);
	 
}
