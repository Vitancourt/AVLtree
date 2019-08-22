#include<stdio.h>
#include<stdlib.h>

struct no{
	int vlr;
	struct no *esq;
	struct no *dir;
};

typedef struct no no;

no *liberaArvore(no *arvore);
no *noVazio();
no *criaArvore(no *arvore);
no *insere(no *arvore, int vlr);
no *balance(no *arvore);
int altura(no *a);
int fatBal(no *a);
no *rot_dir(no *p);
no *rot_esq(no *p);
void imprimeEmOrdem(no *arvore);

int main(void){
	no *raiz;
	raiz = insere(raiz, 20);
	raiz = balance(raiz);
	raiz = insere(raiz, 15);
	raiz = balance(raiz);
	raiz = insere(raiz, 25);
	raiz = balance(raiz);
	raiz = insere(raiz, 12);
	raiz = balance(raiz);
	raiz = insere(raiz, 17);
	raiz = balance(raiz);
	raiz = insere(raiz, 30);
	raiz = balance(raiz);
	raiz = insere(raiz, 26);
	raiz = balance(raiz);
	imprimeEmOrdem(raiz);
	printf("-EmOrdem--\n");
	raiz = liberaArvore(raiz);
}

no *liberaArvore(no *arvore){
	if(arvore != NULL){
		liberaArvore(arvore->esq);
		liberaArvore(arvore->dir);
		free(arvore);
	}
	return NULL;
}

no *noVazio(){
	return NULL;
}

no *criaArvore(no *arvore){
	arvore = malloc(sizeof(no));
	arvore->dir = noVazio();
	arvore->esq = noVazio();
	return arvore;
}

no *insere(no *arvore, int vlr){	
	if(arvore == NULL){
		arvore = criaArvore(arvore);	
		arvore->vlr = vlr;		
		
	}else{
		if(vlr < (arvore->vlr)){
			arvore->esq = insere(arvore->esq, vlr);			
		}else{
			arvore->dir = insere(arvore->dir, vlr);
		}
	}
	return arvore;
}

no *balance(no *arvore){
	if(arvore != NULL){
		arvore->dir = balance(arvore->dir);
		arvore->esq = balance(arvore->esq);
		int fat, fat2;
		fat = fatBal(arvore);
		if(arvore->dir != NULL){
			fat2 = fatBal(arvore->dir);
		}
		if((fat == -2) &(fat2 == -1)){
			arvore = rot_esq(arvore);	
		}
		if(arvore->esq != NULL){
			fat2 = fatBal(arvore->esq);
		}
		if((fat == 2) & (fat2 = 1)){
			arvore = rot_dir(arvore);		
		}
		
	}
	return arvore;
}

// altura
int max2 (int a, int b){   
 return   a > b ? a : b; 
}

int altura (no *a){
  if (a == NULL)
	return 0;
  else 
	return max2(1 + altura(a->esq), 1+altura(a->dir));
}

int fatBal(no *a){
	int esq, dir;
	dir = altura(a->dir);
	esq = altura(a->esq);
	return (esq - dir);
}

no *rot_dir(no *p){
	no *raiz, *temp, *temp2;
	raiz = p->esq;
	if(raiz->dir == NULL){
		raiz->dir = p;
		p->esq = NULL;
	}else{
		temp = raiz->dir;
		p->esq = temp;
		raiz->dir = p;	
	}
	return raiz;
}

no *rot_esq(no *p){
	no *raiz, *temp, *temp2;
	raiz = p->dir;
	if(raiz->esq == NULL){
		raiz->esq = p;
		p->dir = NULL;
	}else{
		temp = raiz->esq;
		p->dir = temp;
		raiz->esq = p;
	}
	return raiz;	
}

void imprimeEmOrdem(no *arvore){
	if(arvore != NULL){
		imprimeEmOrdem(arvore->esq);
		printf("%d\n", arvore->vlr);
		imprimeEmOrdem(arvore->dir);		
	}
}


