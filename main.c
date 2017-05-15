#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


char arquivo[] = "arquivos/arquivo1.txt";

int fitaMemoria[4] = {-1, -1, -1, -1};
int tamanho = sizeof(fitaMemoria) / sizeof(fitaMemoria[0]);
int quantidadeRequisicoes = 0;
int quantidadeTrocas = 0;
int ultimaPosicao = 0;
char ch[10];
int valorAtual = 0;
bool flag = false;
int i = 0;

void manipulandoArquivo();
void printaFita();

void main(){
	
	manipulandoArquivo();
	
	//return 0;
}

void manipulandoArquivo(){
	FILE *arq;
	
	arq = fopen(arquivo, "r");
	
	while(!feof(arq) )
	{
		fgets(ch,9,arq);
		valorAtual = atoi(ch);
		
		if(fitaMemoria[ultimaPosicao] == -1){
			fitaMemoria[ultimaPosicao] = valorAtual;
			if(ultimaPosicao == 3){
				ultimaPosicao = 0;
			}	
			else{
				ultimaPosicao++;
			}
				
		}
		else{
			for(i = 0; i < tamanho; i++){
				if(fitaMemoria[i] == valorAtual){
					flag = true;
					break;
				}
			}
			if(flag == false){
				fitaMemoria[ultimaPosicao] = valorAtual;
				quantidadeTrocas++;
				if(ultimaPosicao == 3)
					ultimaPosicao = 0;
				else
					ultimaPosicao++;
			}
			quantidadeRequisicoes++;
			flag = false;			
		}
		
		printf("--------------------------------------\n");
		printf("Página pedida: %d\n", valorAtual);
		printaFita();
		printf("\nQuantidade de requisicoes: %d \n", quantidadeRequisicoes);
		printf("Quantidade de trocas: %d\n\n", quantidadeTrocas);	
	}
	
	fclose(arq);
}

void printaFita(){
	printf("Fita: ");
	for(i = 0; i < tamanho; i++){
		printf("%d ", fitaMemoria[i]);
	}
}
