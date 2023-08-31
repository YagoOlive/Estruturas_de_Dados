#define INICIOARRANJO 1
#define MAXTAM 10

#include<stdio.h>
#include<string.h>

typedef int TipoApontador;

struct TipoItem{
	char descricao[100];
	char cidade[30];
	float valor;
};

struct TipoLista{
	TipoItem itens[MAXTAM];
	TipoApontador primeiro, ultimo;
};

void Cria_Lista_Vazia(TipoLista *lista){
	lista->primeiro= INICIOARRANJO;
	lista->ultimo= lista->primeiro;
}

int Verifica_l_Vazia(TipoLista lista){
	return(lista.primeiro==lista.ultimo);
}

void Insere(TipoItem x, TipoLista *lista){
	if(lista->ultimo>MAXTAM){
	    printf("***LISTA CHEIA!***");
	}
	else{
		lista->itens[lista->ultimo-1]=x;
		lista->ultimo++;
	}
}

void Retira(TipoApontador p, TipoLista *lista, TipoItem *item){
	int i;
	if(Verifica_l_Vazia(*lista) || p>=lista->ultimo){
		printf("***POSICAO INEXISTENTE!***");
	}
	else{
		*item = lista->itens[p-1];
		lista->ultimo--;
		for(i=p;i<lista->ultimo;i++){
			lista->itens[i-1]=lista->itens[i];
		}
		
	}
}

void Imprime(TipoLista lista){
	int i;
	for(i=lista.primeiro-1;i<=lista.ultimo-2;i++){
			printf("\n\nCidade: %s", lista.itens[i].cidade);
			printf("\nDescricao: %s", lista.itens[i].descricao);
			printf("\nValor: R$ %f", lista.itens[i].valor);
		}
}

float Soma_valor(TipoLista lista){
	float soma = 0;
	int i;
	for(i=lista.primeiro-1;i<=lista.ultimo-2;i++){
		soma = soma + lista.itens[i].valor;
	}
	return soma;
}
float Imovel_mais_caro (TipoLista lista){
	int i;
	float mais_caro = lista.itens[0].valor;
	for(i=lista.primeiro;i<=lista.ultimo-2;i++){
	    if(mais_caro<lista.itens[i].valor){
	    	mais_caro = lista.itens[i].valor;
		}
	}
	return mais_caro;
}

int Busca_cidade(TipoLista lista, char busca_cidade[30]){
	int i, cont=0;
	for(i=lista.primeiro-1;i<=lista.ultimo-2; i++){
	    if(strcmp(busca_cidade, lista.itens[i].cidade)==0){
	    	cont++;
		}
	}
	    return cont;
}

int Busca_cidade_RI(TipoLista lista, char busca_cidade[30]){
	int i, cont=0, indice_posicao;
	for(i=lista.primeiro-1;i<=lista.ultimo-2; i++){
	    if(strcmp(busca_cidade, lista.itens[i].cidade)==0){
	    	cont=1;
	    	indice_posicao=i;
	    	break;
		}
		
	}
	if(cont==0)
	    return -1;
	else
	    return indice_posicao;
}

int Busca_descricao(TipoLista lista, char busca_descricao[100]){
	int i, aux=0;
	for(i=lista.primeiro-1;i<=lista.ultimo-2; i++){
	    if(strcmp(busca_descricao, lista.itens[i].descricao)==0){
	    	aux=1;
		}
	}

	if(aux>0)
	    return 1;
	else 
	    return -1;
}

void Retira_cidade(TipoLista *lista, char cidade_retira[]){
	int i;
	TipoItem imoveis;
	for(i=lista->primeiro-1;i<=lista->ultimo-2; i++){
	    if(strcmp(cidade_retira, lista->itens[i].cidade)==0){
	    	Retira(i+1,lista,&imoveis);
		}
	}
}

int Compara_listas(TipoLista lista, TipoLista lista2){
	int cont_igualdade=0, cont_casas=0;
	for(i=lista->primeiro-1;i<=lista->ultimo-2; i++){
		cont_igualdade=0;
	    if(strcmp(lista.itens[i].cidade, lista2.itens[i].cidade)==0){
	    	cont_igualdade++;
		}
		if(strcmp(lista.itens[i].descricao, lista2.itens[i].descricao)==0){
	    	cont_igualdade++;
		}
		if(lista.itens[i].valor==lista2.itens[i].valor){
			cont_igualdade++;
		}
		if(cont_igualdade==3){
			cont_casas++;
		}
	}
	if(cont_casas==lista.ultimo-2)
	    return 1;
	else
	    return 0;
}

int Compara_tamanho_lista(TipoLista lista, TipoLista lista2){
	if(lista.ultimo-2>lista2.ultimo-2)
	    return 1;
	else if(lista.ultimo<lista2.ultimo)
	    return 2;
	else
	    return 0;
}

int Compara_valor_total(TipoLista lista, TipoLista lista2){
	float soma_l=0, soma_l2=0;
	soma_l=Soma_valor(lista);
	soma_l2=Soma_valor(lista2);
	if(soma_l>soma_l2)
	    return 1;
	else if(soma_l<soma_l2)
	    return 2;
	else
	    return 0;
}
	  
int Cidades_iguais(TipoLista lista, TipoLista lista2){
	int i, j;
	for(i=lista->primeiro-1;i<=lista->ultimo-2; i++){
		for(j=lista2->primeiro-1;j<=lista2->ultimo-2; j++){
	        if(strcmp(lista.itens[i].cidade, lista2.itens[j].cidade)==0){
	            printf("%s\n",lista.itens[i].cidade);
	        }
        }
    }
}	   

int Cidades_diferentes(TipoLista lista, TipoLista lista2){
	int i, j;
	for(i=lista->primeiro-1;i<=lista->ultimo-2; i++){
		for(j=lista2->primeiro-1;j<=lista2->ultimo-2; j++){
	        if(strcmp(lista.itens[i].cidade, lista2.itens[j].cidade)=!0){
	            printf("%s\n",lista2.itens[j].cidade);
	        }
        }
    }
}

void Junta_listas(TipoLista lista, TipoLista lista2){
	TipoLista lista_junta;
	for(i=lista->primeiro-1;i<=lista->ultimo-2; i++){
		
		strcpy(lista_junta.itens[i].cidade, lista.itens[i].cidade); 
		strcpy(lista_junta.itens[i].descricao, lista.itens[i].descricao); 
		lista_junta.itens[i].valor = lista.itens[i].valor;
    }
    for(i=lista.ultimo-1;i<=lista2.ultimo-2; i++){
		
		strcpy(lista_junta.itens[i].cidade, lista2.itens[i].cidade); 
		strcpy(lista_junta.itens[i].descricao, lista2.itens[i].descricao); 
		lista_junta.itens[i].valor = lista2.itens[i].valor;
    }
}

void Intercala_listas(TipoLista lista, TipoLista lista2){
	TipoLista lista_intercalada;
	for(i=lista->primeiro-1;i<=lista->ultimo-2; i++){
		if(i%2=!0){
			strcpy(lista_junta.itens[i].cidade, lista.itens[i].cidade); 
		    strcpy(lista_junta.itens[i].descricao, lista.itens[i].descricao); 
		    lista_junta.itens[i].valor = lista.itens[i].valor;
		}
		else if(i%2==0){
			strcpy(lista_junta.itens[i].cidade, lista2.itens[i].cidade); 
		    strcpy(lista_junta.itens[i].descricao, lista2.itens[i].descricao); 
		    lista_junta.itens[i].valor = lista2.itens[i].valor;
		}
		
    }
    for(i=lista.ultimo-1;i<=lista2.ultimo-2; i++){
		
		
    }
}

main(){
	TipoItem imoveis;
	TipoLista lista;
	
	char busca_cidade[30], busca_descricao[100], cidade_retira[100];
	
	Cria_Lista_Vazia(&lista);
	printf("%d", Verifica_l_Vazia(lista));
	strcpy(imoveis.cidade, "passos"); strcpy(imoveis.descricao, "vermelho"); imoveis.valor = 100.000;
	Insere(imoveis, &lista);
	strcpy(imoveis.cidade, "passos"); strcpy(imoveis.descricao, "rosa"); imoveis.valor = 120.000;
	Insere(imoveis, &lista);
	strcpy(imoveis.cidade, "ventania"); strcpy(imoveis.descricao, "cinza"); imoveis.valor = 110.000;
	Insere(imoveis, &lista);
	strcpy(imoveis.cidade, "ventania"); strcpy(imoveis.descricao, "verde"); imoveis.valor = 150.000;
	Insere(imoveis, &lista);
	Imprime(lista);
	 
	printf("\n\nO valor de todos os imoveis eh: R$ %f", Soma_valor(lista));
	
	printf("\n\nO imovel mais caro tem o valor de: R$ %f", Imovel_mais_caro (lista));
	
	printf("\n\nInforme a cidade onde procura um imovel: ");
	gets(busca_cidade);
	printf("\nAh cerca de %d imoveis na cidade %s", Busca_cidade(lista,busca_cidade), busca_cidade);
	
	printf("\n\nInforme a cidade onde procura um imovel: ");
	gets(busca_cidade);
	printf("\nEm %s indice: %d ",busca_cidade,  Busca_cidade_RI(lista,busca_cidade));
	
	printf("\n\nInforme a descricao a buscar: ");
	gets(busca_descricao);
	printf("\n%d imoveis com a descricao %s!", Busca_descricao(lista,busca_descricao), busca_descricao);
	
	printf("\n\nInforme a cidade a excluir: ");
	gets(cidade_retira);
	Retira_cidade(&lista, cidade_retira);
	printf("***Imprime apos excluir!***");
	Imprime(lista);
	
}

  



