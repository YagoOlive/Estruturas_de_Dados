#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Estrutura de Dados Lista Dinâmica*/
struct TipoItem{
	int isbn;
	char titulo[100];
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
		printf("%d\t" , Aux->Item.isbn);
		printf("%s\n" , Aux->Item.titulo);
		Aux = Aux->Prox ;
	}
}

/* Retorna o endereço de memória de uma célula que possui 
   um item com o isbn passado como parâmetro*/
TipoApontador Busca(int isbn, TipoLista Lista){
	TipoApontador Aux, p=NULL;
	Aux = Lista.Primeiro->Prox;
	while (Aux != NULL){
		if(Aux->Item.isbn==isbn)
			p=Aux;
		Aux = Aux->Prox ;
	}
	return p;
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

main(){
	TipoLista lista;
	TipoApontador p;
	FLVazia(&lista);
	printf("\nLista Vazia %d", Vazia(lista));
	TipoItem item;
	item.isbn=1;strcpy(item.titulo, "Estrutura de Dados");
	Insere(item, &lista);
	item.isbn=2;strcpy(item.titulo, "Inteligencia Artificial");
	Insere(item, &lista);
	item.isbn=3;strcpy(item.titulo, "Banco de Dados");
	Insere(item, &lista);
	
	printf("\n\nExibindo a Lista\n");
	Imprime(lista);			
	
	// Busca o endereço da memória da célula que contém um Item com isbn 1
	p=Busca(1, lista);
	printf("\nResultado da busca %p", p);//Exibe o endereço de memória da célula com o isbn passado por parâmetro
	printf("\nLivro %s", p->Item.titulo);
	
	// Retira a próxima célula (retira a célula com isbn 2)
	Retira(p, &lista, &item);
	printf("\nItem retirado %s", item.titulo);
	
	printf("\n\nExibindo a Lista Apos a funcao Retira\n");
	Imprime(lista);	
}
