#include<stdio.h>
#include<string.h>
#define MAXTAM 5

typedef int TipoApontador;

struct TipoItem{
int cod;
float valor;
char operacao[20]; // saque / deposito / pagamento
};

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
		printf("codigo= %d\n", fila.item[i-1].cod);
		printf("operacao= %s\n", fila.item[i-1].operacao);
		printf("valor= %2.f\n\n", fila.item[i-1].valor);
	}
}

//Receba uma fila est�tica e retorne o valor do maior dep�sito realizado.
float ItemMaiorValor(TipoFila fila){
	
	int i;
	float maior;

	for(i=fila.frente;i != fila.tras; i=i% MAXTAM+1){
		
		if(strcmp(fila.item[i-1].operacao, "deposito")==0){
			
			maior= fila.item[i-1].valor;
			if(fila.item[i-1].valor>maior){
				
				maior= fila.item[i-1].valor;
		
			}
		}
		
	}
	return maior;
}

main(){
	TipoFila fila;
	FFVazia(&fila);
	TipoItem item;
	item.cod=1; strcpy(item.operacao, "saque"); item.valor= 600.00; Enfileira(item, &fila);
	item.cod=2; strcpy(item.operacao, "deposito"); item.valor= 100.00; Enfileira(item, &fila);
	item.cod=3; strcpy(item.operacao, "saque"); item.valor= 500.00; Enfileira(item, &fila);
	item.cod=4; strcpy(item.operacao, "deposito"); item.valor= 400.00; Enfileira(item, &fila);
	item.cod=5; strcpy(item.operacao, "deposito"); item.valor= 500.00; Enfileira(item, &fila);
	
	printf("\nExibindo a fila\n");
	exibe(fila);
	
	
	printf("Item com maior valor: %f", ItemMaiorValor(fila));	

}
