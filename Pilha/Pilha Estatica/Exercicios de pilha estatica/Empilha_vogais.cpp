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

void Empilha_vogais(char str[50], TipoPilha *pilha){
	TipoItem item;
	int i, tamanho;
	tamanho = strlen(str);
	
	for(i=0;i<=tamanho;i++){
		
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
			item.letra=str[i];
			Empilha(item, pilha);
		}		
	}
	
}

main(){
	TipoPilha pilha;
	TipoItem item;
	char palavra[50]="salve";
	FPVazia(&pilha);
	printf("\nvazia: %d", Vazia(pilha));
	Empilha_vogais(palavra, &pilha);
	printf("\nvazia: %d", Vazia(pilha));
	Imprime(pilha);
	//printf("\n\n%d", Tamanho(pilha));
}
