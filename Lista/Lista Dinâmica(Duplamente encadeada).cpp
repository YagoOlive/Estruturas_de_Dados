#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Estrutura de Dados Lista Dinâmica*/
struct TipoItem{
	int cod;
	char descricao[50];
	float valor;
	int ram;
};

typedef struct TipoCelula *TipoApontador;

struct TipoCelula {
	TipoItem Item ;
	TipoApontador Prox;
	TipoApontador Ant;
};

struct TipoLista{
	TipoApontador Primeiro , Ultimo ;
};


/* Funções de manipulação da Lista Dinâmica DP encadeada*/
void FLVazia(TipoLista *Lista){
	Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula)) ;
	Lista->Ultimo = Lista->Primeiro ; 
	Lista->Primeiro->Ant = NULL;
	Lista->Primeiro->Prox = NULL ;
}

int Vazia(TipoLista Lista){
		return(Lista.Primeiro == Lista.Ultimo);
}

void Insere (TipoItem x , TipoLista* Lista ){
	Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
	Lista->Ultimo->Prox->Ant = Lista->Ultimo;
	Lista->Ultimo = Lista->Ultimo->Prox;
	Lista->Ultimo->Item = x;
	Lista->Ultimo->Prox = NULL;
}

void Insere_apos_p (TipoItem x , TipoLista* Lista, TipoApontador p){
	TipoApontador Aux, q;
	q=(TipoApontador)malloc(sizeof(TipoCelula));
	q->Item=x;
	q->Ant=p;
	q->Prox=p->Prox;
	p->Prox->Ant=q;
	p->Prox=q;
	 
}

void Altera (TipoItem x , TipoLista* Lista, TipoApontador p ){
	TipoApontador Aux;
	if (Vazia(*Lista)||p==NULL)
        printf("\nerro\n");
    else
    {
	    Aux = Lista->Primeiro;
	    while (Aux->Prox != NULL){
	        if(Aux->Prox==p)
		        Aux->Prox->Item = x;
		    Aux = Aux->Prox; 
     	}
    }
}

void Imprime(TipoLista Lista){
	TipoApontador Aux;
	Aux = Lista.Primeiro->Prox;
	while (Aux != NULL){
		printf("\n%d\t" , Aux->Item.cod);
		printf("\n%s\n" , Aux->Item.descricao);
		printf("%d\n" , Aux->Item.ram);
		printf("%f\n" , Aux->Item.valor);
		Aux = Aux->Prox ;
	}
}

void Imprime_indice(TipoLista Lista, int indice){
	TipoApontador Aux;
	if(indice==1){
		Aux = Lista.Primeiro->Prox;
	        while (Aux != NULL){
		        printf("\n%d\t" , Aux->Item.cod);
		        printf("\n%s\n" , Aux->Item.descricao);
		        printf("%d\n" , Aux->Item.ram);
	        	printf("%f\n" , Aux->Item.valor);
		        Aux = Aux->Prox ;
	        }
	}
	else if(indice==0){
		Aux = Lista.Ultimo;
		   while(Aux != Lista.Primeiro){
		   	    printf("\n%d\t" , Aux->Item.cod);
		        printf("\n%s\n" , Aux->Item.descricao);
		        printf("%d\n" , Aux->Item.ram);
	        	printf("%f\n" , Aux->Item.valor);
		        Aux = Aux->Ant;
		   }
	}
	else{
		printf("Indie Invalido!");
		printf("Informe o indice novamente: ");
		scanf("%d", &indice);
		Imprime_indice(Lista, indice);
	} 
	
}

void Retira_p(TipoLista *Lista, TipoApontador p){

    TipoApontador aux, q;
    if (Vazia(*Lista))
        printf("\nerro\n");
    else
    {
        aux = Lista->Primeiro;
        while ( aux->Prox != NULL)
        {
			if(aux->Prox==p){
            	
            	q=p->Prox;
            	q->Ant=aux;
            	aux->Prox=p->Prox;
            	free(p);
			} else{
				aux=aux->Prox;
			}
			
        }
        if (aux->Prox == NULL)
            Lista->Ultimo = aux;

    }
}

TipoApontador Busca_codigo(int cod, TipoLista Lista){
	TipoApontador Aux, p=NULL;
	Aux = Lista.Primeiro->Prox;
	while (Aux != NULL){
		if(Aux->Item.cod==cod)
			p=Aux;
		Aux = Aux->Prox ;
	}
	return p;
}

main(){
	TipoLista lista;
	TipoApontador p, q;
	TipoItem item;
	int i;
	
	FLVazia(&lista);
	printf("\nLista Vazia: %d", Vazia(lista));
	
	item.cod=1; strcpy(item.descricao, "Nokia"); item.ram=16; item.valor= 1000;
	Insere(item, &lista);
	
	item.cod=2; strcpy(item.descricao, "Motorola"); item.ram=32; item.valor= 1500;
	Insere(item, &lista);
	
	item.cod=3; strcpy(item.descricao, "Samsung"); item.ram=64; item.valor= 2500;
	Insere(item, &lista);
	
	item.cod=4; strcpy(item.descricao, "Motorola"); item.ram=64; item.valor= 2500;
	Insere(item, &lista);
	
	item.cod=5; strcpy(item.descricao, "Motorola"); item.ram=64; item.valor= 2500;
	Insere(item, &lista);
	
	printf("\nExibindo a Lista 1\n");
	Imprime(lista);
	
	p=Busca_codigo(5, lista);
	item.cod=6; strcpy(item.descricao, "Acer"); item.ram=4; item.valor= 600;
	Altera (item , &lista, p);
	printf("\n\nExibindo apos a funcao altera\n");
	Imprime(lista);
	
	p=Busca_codigo(4, lista);
	item.cod=5; strcpy(item.descricao, "Positivo"); item.ram=8; item.valor= 800;
	Insere_apos_p(item , &lista, p);
	printf("\n\nExibindo apos a funcao Insere apos P\n");
	Imprime(lista);
	
	p=Busca_codigo(5, lista);
	Retira_p(&lista, p);
	printf("\n\nExibindo apos a funcao Retira\n");
	Imprime(lista);
	
	printf("\n\nExibindo apos a funcao Imprime indice\n");
	i=2; // i define o sentido em que a lista sera impressa 0= de tras para frente/ 1= sentido normal
	Imprime_indice(lista, i);
}
