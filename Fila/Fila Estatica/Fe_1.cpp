#include<stdio.h>
#define MAXTAM 5

typedef int TipoApontador;
typedef struct {
	char letra;
} TipoItem ;

typedef struct {
	TipoItem item [ MAXTAM ] ;
	TipoApontador frente, tras ;
} TipoFila;

void FFVazia( TipoFila *fila ){
	fila->frente = 1;
	fila->tras = fila->frente ;
}

int Vazia(TipoFila fila){
	return (fila.frente == fila.tras);
}

void Enfileira (TipoItem x, TipoFila * fila){
	if(fila->tras % MAXTAM + 1 == fila->frente)
			printf("Erro fila esta cheia \n" ) ;
	else {
             fila->item[fila->tras-1]=x;
             fila->tras=fila->tras%MAXTAM+1;
     }
}

void Desenfileira ( TipoFila * fila , TipoItem * item){
	if(Vazia(*fila))
		    printf("Erro fila esta vazia \n" ) ;
	else {
			 *item=fila->item [fila->frente - 1];
			 fila->frente = fila->frente % MAXTAM+1;
	}
}

void exibe (TipoFila fila){
	int i;	
	for(i=fila.frente;i != fila.tras; i=i% MAXTAM+1){
		printf("i==%d | Item==%c\n",i, fila.item[i-1].letra);
	}
}

int VerificaItem(TipoFila fila, TipoItem item){
	
	int i;
	
	for(i=fila.frente;i != fila.tras; i=i% MAXTAM+1){
		if(fila.item[i-1].letra==item.letra){
			return 1;
			break;
		}
	}
	return 0;
}

main(){
	TipoFila fila;
	FFVazia(&fila);
	TipoItem item;
	item.letra='A'; Enfileira(item, &fila);
	item.letra='B'; Enfileira(item, &fila);
	item.letra='C'; Enfileira(item, &fila);
	item.letra='D'; Enfileira(item, &fila);
	item.letra='E'; Enfileira(item, &fila); // Fila cheia. N?o ser? enfileirado. Cabe MAXTAM-1 itens
	printf("\nExibindo a fila\n");
	exibe(fila);
	
	item.letra='A';
	printf("%d", VerificaItem( fila, item));
	

	
	

}
