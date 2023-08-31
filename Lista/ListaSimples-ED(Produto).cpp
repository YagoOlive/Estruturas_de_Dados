#include<stdio.h>
#include<string.h>


// Estrutura de Dados - Lista Simples
struct Produto{ //Item que será manipulado
	char descricao[100];
	int codigo;
	int quantidade;
	float preco;
};
struct Lista{ //Lista
	Produto lista[50];
	int tamanho;
};

// **** Operações ****

// Inicializa as variáveis de controle da estrutura
// No caso, a variável tamanho
void fazListaVazia(Lista *l){
	l->tamanho=0;
}

void insere(Produto p, Lista *l){
	if(l->tamanho>=50){
		printf("\n Lista cheia!");
		return;
	}
	l->lista[l->tamanho]=p;
	l->tamanho++;
}

void imprime(Lista l){
	int i;
	for(i=0;i<l.tamanho;i++){
		printf("\n\n %s", l.lista[i].descricao);
		printf("\n %d", l.lista[i].codigo);
		printf("\n %f", l.lista[i].preco);
		printf("\n %d", l.lista[i].quantidade);
	}
}

void retira(int posicao, Lista *l){
	int i;
	if(posicao >= l->tamanho){ 
		printf("Erro : Posicao nao existe \n") ;
		return ;
	}
	
	l->tamanho--;
	for(i=posicao; i < l->tamanho; i++){
		l->lista[i] = l->lista[i+1];
	}
}

float Soma_preco(Lista *l){
	float soma = 0;
	int i;
	for(i=0;i<l->tamanho;i++){
		soma = soma + l->lista[i].preco;
	}
	return soma;
}

int Media_quantidade(Lista *l){
	int i, cont=0, soma_quantidade=0, media;
	for(i=0;i<l->tamanho; i++){
	    soma_quantidade = soma_quantidade + l->lista[i].quantidade;
	    cont++;	
	}
	media = soma_quantidade/cont;
	return media;
}

int Produto_caro(Lista *l){
	int i, codigo_mc;
	float mais_caro = l->lista[0].preco;
	for(i=0;i<l->tamanho; i++){
	    if(mais_caro<l->lista[i].preco){
	    	mais_caro = l->lista[i].preco;
	    	codigo_mc = l->lista[i].codigo;
		}
	}
	return codigo_mc;
}

int Quantidade_barato(Lista *l){
	int i, quantidade_barato=l->lista[0].quantidade;
	float mais_barato = l->lista[0].preco;
	for(i=0;i<l->tamanho; i++){
	    if(mais_barato>l->lista[i].preco){
	    	mais_barato = l->lista[i].preco;
	    	quantidade_barato = l->lista[i].quantidade;
		}
	}
	return quantidade_barato;
}

int Busca_descricao(Lista *l, char busca_descricao[100]){
	int i, posicao=-1;
	for(i=0;i<l->tamanho; i++){
	    if(strcmp(busca_descricao, l->lista[i].descricao)==0){
	    	posicao = i;
		}
	}

	if(posicao>=0)
	    return posicao;
	else 
	    return -1;
}

int Busca_codigo(Lista *l, int busca_codigo){
	int i, posicao=-1;
	for(i=0;i<l->tamanho; i++){
	    if(busca_codigo==l->lista[i].codigo){
	    	posicao = i;
	    	break;
		}
	}
	if(posicao>=0)
        retira(posicao, l);
}

int Verifica_letra(Lista *l){
	int i, aux=0, tam_descricao;
	for(i=0;i<l->tamanho; i++){
	    tam_descricao= strlen(l->lista[i].descricao);
	    if((l->lista[i].descricao[tam_descricao-1]== 'a')||(l->lista[i].descricao[tam_descricao-1]== 'e')||(l->lista[i].descricao[tam_descricao-1]== 'i')||(l->lista[i].descricao[tam_descricao-1]== 'o')||(l->lista[i].descricao[tam_descricao-1]== 'u')){
	    	aux=1;
		}
	}
	if(aux>0)
		return 1;
	else
	    return 0;
}

int Compara_lista(Lista *l, Lista *l2){
	int  cont1=0, cont2=0;
	if(l->tamanho>l2->tamanho)
	    return 1;
	else if(l->tamanho<l2->tamanho)
	    return 2;
	else
	    return 0;
}

main(){
	Produto produto;
	Lista lista;
	Lista lista2;
	char descricao_buscar[100];
	int codigo_buscar;
	fazListaVazia(&lista); 
	strcpy(produto.descricao, "azul"); produto.codigo = 7070;  produto.quantidade = 70; produto.preco = 70.50;
	insere(produto, &lista);
	strcpy(produto.descricao, "amarelo"); produto.codigo = 6060;  produto.quantidade = 60; produto.preco = 60.50;
	insere(produto, &lista);
    strcpy(produto.descricao, "vermelho"); produto.codigo = 8080;  produto.quantidade = 80; produto.preco = 80.50;
	insere(produto, &lista);
	strcpy(produto.descricao, "cinza"); produto.codigo = 5050;  produto.quantidade = 50; produto.preco = 50.50;
	insere(produto, &lista);
	imprime(lista);
	
	retira(0, &lista);
	
	printf("\n Exibindo apos a funcao retira \n");
	imprime(lista);
	
	printf("\n\n Valor total em produtos: %f", Soma_preco(&lista));
	
	printf("\n\n Media de produtos: %d", Media_quantidade(&lista));
	
	printf("\n\n Produto mais caro: %d", Produto_caro(&lista));
	
	printf("\n\n Quantidade do produto mais barato: %d", Quantidade_barato(&lista));
	
	printf("\n\nInforme a descricao que deseja buscar: ");
	gets(descricao_buscar);
	printf("\n\nPosicao relativa a descricao: %d", Busca_descricao(&lista, descricao_buscar));
	
	printf("\n\nInforme o codigo do produto que deseja retirar: ");
	scanf("%d", &codigo_buscar);
	printf("\n\nPosicao relativa a descricao: %d", Busca_codigo(&lista, codigo_buscar));
	
	printf("\nExibindo apos a funcao busca codigo \n");
	imprime(lista);
	
	printf("\n\nOcorrencia de vogal na ultima letra da descricao: %d", Verifica_letra(&lista));
	
	fazListaVazia(&lista2);
	strcpy(produto.descricao, "verde"); produto.codigo = 7070;  produto.quantidade = 70; produto.preco = 70.50;
	insere(produto, &lista2);
	strcpy(produto.descricao, "roxo"); produto.codigo = 3030;  produto.quantidade = 30; produto.preco = 30.50;
	insere(produto, &lista2);
    strcpy(produto.descricao, "preto"); produto.codigo = 9090;  produto.quantidade = 90; produto.preco = 90.50;
	insere(produto, &lista2);
	strcpy(produto.descricao, "branco"); produto.codigo = 5050;  produto.quantidade = 50; produto.preco = 50.50;
	insere(produto, &lista2);
	
	printf("\n Compara listas: %d\n", Compara_lista(&lista, &lista2));
	
}

