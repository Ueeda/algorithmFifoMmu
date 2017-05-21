#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Var globais
int *fitaMemoria;
int tamanhoFita;

// Métodos
void iniciaFita(int *fita, int tamanhoVetor);
void printaFita();

void main(){
	iniciaFita(fitaMemoria, 5);
	printaFita(fitaMemoria);
}

void iniciaFita(int *fita, int tamanhoVetor){
	tamanhoFita = tamanhoVetor;
	int i;
	fita = (int *)malloc(tamanhoFita * sizeof(int));
	for(i = 0; i < tamanhoVetor; i++){
		fita[i] = -1;
	}
	
}

void printaFita(){
	int i;
	printf("Fita: ");
	for(i = 0; i < tamanhoFita; i++){
		printf("%d ", fitaMemoria[i]);
	}
}


