/*Estrutura de uma lista dinâmica que armazena dados de um aparelho telefone,
funções para interagir com os objetos armazenados na lista
*/
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
};

struct TipoLista{
	TipoApontador Primeiro , Ultimo ;
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
		printf("\n%d\t" , Aux->Item.cod);
		printf("\n%s\n" , Aux->Item.descricao);
		printf("%d\n" , Aux->Item.ram);
		printf("%f\n" , Aux->Item.valor);
		Aux = Aux->Prox ;
	}
}

/* Retorna o endereço de memória de uma célula que possui 
   um item com o isbn passado como parâmetro*/
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

TipoApontador Busca_descricao(char desc[], TipoLista Lista){
	TipoApontador Aux, p=NULL;
	Aux = Lista.Primeiro->Prox;
	while (Aux != NULL){
		if(strcmp(Aux->Item.descricao, desc)==0)
			p=Aux;
		Aux = Aux->Prox ;
	}
	return p;
}

TipoApontador Busca_Maior_Ram( TipoLista Lista){
	TipoApontador Aux, p_ram;
	Aux = Lista.Primeiro->Prox;
	p_ram=Aux;
	while (Aux != NULL){
		if(Aux->Item.ram>p_ram->Item.ram){
			p_ram=Aux;
		}
		Aux = Aux->Prox ;
	}
	return p_ram;
}

float Soma_valor(TipoLista Lista){
	TipoApontador Aux;
	float soma=0;
	Aux = Lista.Primeiro->Prox;
	while (Aux != NULL){
		soma+=Aux->Item.valor;
		Aux = Aux->Prox ;
	}
	return soma;
}

int Ordem_crescente( TipoLista Lista){
	TipoApontador Aux, p, p2;
	int cont=0, cont2=0;
	Aux = Lista.Primeiro->Prox;
	p=Aux;
	while (Aux != NULL){
		cont2++;
		if(Aux->Item.cod>p->Item.cod){
			cont++;
		}
		Aux = Aux->Prox ;
	}
	if(cont==cont2-1)
	    return 1;
	else
	    return 0;
}

int Busca_Maior_Ram_2listas( TipoLista Lista, TipoLista Lista2){
	TipoApontador Aux, Maior_ram1, Maior_ram2;
	Aux = Lista.Primeiro->Prox;
	Maior_ram1=Busca_Maior_Ram(Lista);
    Maior_ram2=Busca_Maior_Ram(Lista2);
    if((Maior_ram1->Item.ram) > (Maior_ram2->Item.ram))
        return 1;
    else if((Maior_ram1->Item.ram)<(Maior_ram2->Item.ram))
        return 2;
    else
        return 0;
    
}

int Insere_meio( TipoLista Lista, TipoApontador q, TipoItem x){
	TipoApontador Aux, p1_aux, p2_aux;
	Aux = Lista.Primeiro->Prox;
    if(q==Lista.Ultimo){
	    Insere(x, &Lista);
	}
	else{
		Aux= (TipoApontador)malloc(sizeof(TipoCelula));
		Aux->Item=x;
		p1_aux=q->Prox;
		q->Prox=Aux;
		Aux->Prox= p1_aux;	
	}
}

int Troca_posicao( TipoLista Lista, TipoApontador q, TipoApontador p){
	TipoApontador Aux, p_aux1, p_aux2, p_troca;
	Aux = Lista.Primeiro->Prox;
    while (Aux != NULL){
		if(Aux->Prox==p){
			p_aux1 = Aux;
		}
		if(Aux->Prox==q){
			p_aux2 = Aux;
		}
	    Aux = Aux->Prox ;
	}
		p_aux1->Prox=q;
		p_aux2->Prox=p;
		
		p_troca=p->Prox;
		p->Prox=q->Prox;
		q->Prox=p_troca;	
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
	TipoLista lista2;
	TipoApontador p, q;
	FLVazia(&lista);
	printf("\nLista Vazia: %d", Vazia(lista));
	TipoItem item;
	item.cod=1; strcpy(item.descricao, "Nokia"); item.ram=16; item.valor= 1000;
	Insere(item, &lista);
	
	item.cod=2; strcpy(item.descricao, "Motorola"); item.ram=32; item.valor= 1500;
	Insere(item, &lista);
	
	item.cod=3; strcpy(item.descricao, "Samsung"); item.ram=64; item.valor= 2500;
	Insere(item, &lista);
	
	printf("\nExibindo a Lista 1\n");
	Imprime(lista);

		FLVazia(&lista2);
	printf("\nLista 2 Vazia: %d", Vazia(lista2));
	item.cod=1; strcpy(item.descricao, "Iphone"); item.ram=128; item.valor= 10000;
	Insere(item, &lista2);
	
	item.cod=2; strcpy(item.descricao, "Xiaome"); item.ram=32; item.valor= 1000;
	Insere(item, &lista2);
	
	item.cod=3; strcpy(item.descricao, "Nokia"); item.ram=64; item.valor= 2500;
	Insere(item, &lista2);
	
	
	printf("\nExibindo a Lista 2\n");
	Imprime(lista2);		
	
	/*printf("\n\nFuncao busca Codigo");
	p=Busca_codigo(1, lista);
	printf("\nResultado da busca: %p", p);//Exibe o endereço de memória da célula com o cod passado por parâmetro
	printf("\nDescricao: %s", p->Item.descricao);
	
	printf("\n\nFuncao busca Descricao");
	p=Busca_descricao("Nokia", lista);
	printf("\nResultado da busca: %p", p);//Exibe o endereço de memória da célula com o cod passado por parâmetro
	printf("\nCodigo: %d", p->Item.cod);

    printf("\n\nFuncao busca Maior RAM");
	p=Busca_Maior_Ram(lista);
	printf("\nResultado da busca: %p", p);//Exibe o endereço de memória da célula com o maior RAM
	printf("\nDescricao: %s", p->Item.descricao);
	
	printf("\n\nFuncao Exibe Soma valores");
	printf("\nSoma de todos valores: %f", Soma_valor(lista));
	
	printf("\n\nFuncao Ordem crescente");
	printf("\n%d",Ordem_crescente(lista));
	
	// Retira a próxima célula (retira a célula com isbn 2)
	Retira(p, &lista, &item);
	printf("\nItem retirado %s", item.);
	
	printf("\n\nFuncao Maior Ram entre 2 Listas");
	printf("\nmaior Ram na lista %d", Busca_Maior_Ram_2listas( lista, lista2));
	Busca_Maior_Ram_2listas( lista, lista2);
	
	p=Busca_codigo(1, lista);
	item.cod=4; strcpy(item.descricao, "Nokia"); item.ram=256; item.valor= 15000;
	Insere_meio(lista, p, item);
	Imprime(lista);	*/
	
	p=Busca_codigo(1, lista);
	q=Busca_codigo(3, lista);
	Troca_posicao(lista, q, p);
	Imprime(lista);
	
	printf("\n\nExibindo a Lista Apos a funcao Retira\n");
	
}
