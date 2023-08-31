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

void Inverte_string(char str[50] ){
	TipoItem item;
	TipoPilha pilha;
	int i, tamanho;
	FPVazia(&pilha);
	tamanho = strlen(str);
	
	for(i=0;i<tamanho;i++){
		item.letra=str[i];
		Empilha(item, &pilha);			
	}
	i=0;
	while(!Vazia(pilha)){
		Desempilha(&pilha, &item);
		str[i]=item.letra;
		i++;
	}			
	
	
}

main(){
	TipoPilha pilha, pilha2;
	TipoItem item;
	char palavra[50]="salve";
	
	FPVazia(&pilha);
	FPVazia(&pilha);
	printf("\nvazia: %d\n", Vazia(pilha));
	Inverte_string(palavra);
	printf("%s", palavra);
	
}
