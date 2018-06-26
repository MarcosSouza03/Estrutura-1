//Marcos Martins De Souza, iserindo os valores e mostrando.


#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

typedef int titem;
typedef struct no{
	titem dado;
	struct no *esq, *dir;
} tno;
typedef struct sarvore{
	tno *raiz;
}tarvore;

void inicializa(tarvore *a){
	a->raiz=NULL;
}

tno *criaNo(titem valor){
	tno *novo;
	novo=(tno*)malloc(sizeof(tno));
	novo->dado=valor;
	novo->esq=NULL;
	novo->dir=NULL;
	return novo;
}

tno *insereNo (tno *raiz,tno *novo){
	if (raiz==NULL)
	raiz=novo;
	else{
		if(novo->dado > raiz->dado)
		raiz->dir = insereNo(raiz->dir,novo);
		else if (novo->dado <= raiz->dado)
		raiz->esq=insereNo(raiz->esq,novo);
	}
	
	return raiz;
}

void inOrder(tno *raiz){
	if (raiz !=NULL){
		inOrder(raiz->esq);
		printf(" %d ",raiz->dado);
		inOrder(raiz->dir);
		
	}
}

void preOrder(tno *raiz){
	if (raiz !=NULL){
		printf(" %d " ,raiz->dado);
		preOrder(raiz->esq);
		preOrder(raiz->dir);
	}
	
}
void posOrder(tno*raiz){
	if(raiz!=NULL){
		posOrder(raiz->esq);
		posOrder(raiz->dir);	
		printf(" %d " ,raiz->dado);
	}
}

void insereVetor(tarvore *a, titem *v1, titem n){
	tno *no;
	for(n=0;n<10;n++){
		no=criaNo(v1[n]);
		a->raiz=insereNo(a->raiz,no);
	}
}

int menu()
{
	int op;
	printf("\t\t***ARVORE DE BUSCA BINARIA - COM 10 VETORES\n\n");
	printf("Escolha uma das opcoes abaixo:\n");
	printf("1 - Iserir\n");
	printf("2 - Mostrar vetor\n");
	printf("3 - Apresentar percusos\n");
	scanf ("%d", &op);
	return op;
}
 int main(){
 	int i,j,v1[10];
 
 tarvore tree;
 tno *no;
 int op;
 inicializa(&tree);
 do{
 	op=menu();
 	switch (op){
 		case 1:
 			for (j=0;j<10;j++){
 				printf("Inserir o numeros [%d]",j);
 				scanf ("%d", &v1[j]);
			 }
			 insereVetor (&tree,v1,j);
			 break;
			 
			 case 2: 
			 for(j=0;j<10;j++){
			 	printf(" %d ", v1[j]);
			 }
			 break;
			 case 3:
			 	if (tree.raiz==NULL){
			 		printf("Primeiro deve Inserir o Vetor");
				 }else 
				 printf ("Raiz: %d ", tree.raiz->dado);
				 break;
				 case 4:
				 	if(tree.raiz==NULL){
				 		printf("Primeiro deve Inserir o Vetor");
					 }else{
					 	printf("\nPercuso Em Ordem: \n");
					 	inOrder(tree.raiz);
					 	printf("\nPercuso Pre Ordem: \n");
					 	preOrder(tree.raiz);
					 	printf("\nPercuso Pos Ordem: \n");
					 	posOrder(tree.raiz);
					 }
					
	 }
getch();
system("cls");
}while(op!=6);
}

	

