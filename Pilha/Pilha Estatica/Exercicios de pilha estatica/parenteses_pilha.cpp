#include<stdio.h>
#include<string.h>
#define MAXTAM 1000

typedef int TipoApontador;


typedef struct {
	
    char parenteses;

}TipoItem; 

typedef struct{
    TipoItem itens[MAXTAM ];
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
    	    printf("\n%d - %c",i , pilha.itens[i].parenteses);	
		}	
	}
}// Exibi a pilha

int Tamanho(TipoPilha pilha){
    return (pilha.topo) ;
}

void Paridade_parenteses(char str[], TipoPilha pilha){
	TipoItem item;
	int i, tamanho, paridade=0;
	tamanho = strlen(str);
	for(i=0;i<=tamanho;i++){
		
		if(str[i]=='('){
			item.parenteses=str[i];
			Empilha(item, &pilha);	
		}
		if(str[i]==')'){
			item.parenteses=str[i];
			if(Vazia(pilha)==1){
			    printf("Erro de paridade!");
			    paridade=1;
			    break;
			}
			else{
			    Desempilha(&pilha , &item);	
			}	
		}
	}
	if(paridade==0){
		if(Vazia(pilha)==0)
	        printf("\nErro de paridade!\n");
	    if(Vazia(pilha)==1)
	        printf("\nParidade correta\n");
	}	
}

main(){
	TipoPilha pilha;
	TipoItem item;
	char texto[] = "a(())))";
	
	FPVazia(&pilha);
	//printf("%d\n", Vazia(pilha));
	
	Paridade_parenteses(texto, pilha);
	
	//Imprime(pilha);
	//printf("\n\n%d", Tamanho(pilha));
}

