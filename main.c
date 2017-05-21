#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *fitaMemoria;
int tamanho;
int numeroArquivo;
char ch[10];
int valorAtual = 0;
bool flag = false;
int i = 0;
char c[0];
int quantidadeRequisicoes = 0;
int pageFaults = 0;
int ultimaPosicao = 0;



void manipulandoArquivo(int tamanhoFita, int nArquivo);
void printaFita();
void iniciaVetor(int numeroPosicoes);
void reiniciaVariaveis();

void main(){
	
	manipulandoArquivo(4,1);
	manipulandoArquivo(4,2);
	manipulandoArquivo(64,3);
	manipulandoArquivo(256,3);
	manipulandoArquivo(1024,3);
	manipulandoArquivo(2048,3);
	manipulandoArquivo(64,4);
	manipulandoArquivo(256,4);
	manipulandoArquivo(1024,4);
	manipulandoArquivo(2048,4);
	
}

void manipulandoArquivo(int tamanhoFita, int nArquivo){
	numeroArquivo = nArquivo;
	tamanho = tamanhoFita;
	
	char arquivo[] = "arquivos/arquivo";
	
	c[0] = numeroArquivo+48;
	
	strcat(arquivo,c);
	strcat(arquivo,".txt");
	
	
	
	iniciaVetor(tamanho);
	
	FILE *arq;
	
	arq = fopen(arquivo, "r");
	
	while(!feof(arq))
	{
		fgets(ch,9,arq);
		valorAtual = atoi(ch);
		
		if(fitaMemoria[ultimaPosicao] == -1){
			fitaMemoria[ultimaPosicao] = valorAtual;
			if(ultimaPosicao == (tamanho - 1)){
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
				pageFaults++;
				if(ultimaPosicao == (tamanho - 1))
					ultimaPosicao = 0;
				else
					ultimaPosicao++;
			}
			
			flag = false;			
		}
		quantidadeRequisicoes++;
	}
	
	fclose(arq);
	
	printf ("Arquivo %d, %5d paginas, %7d requisicoes: FIFO: %5d Page Faults \n", numeroArquivo, tamanho, quantidadeRequisicoes, pageFaults) ;
	
	reiniciaVariaveis();
	
	//printaFita();
}

void iniciaVetor(int numeroPosicoes){
	fitaMemoria = (int *)malloc(numeroPosicoes * sizeof(int));
	for(i = 0; i < numeroPosicoes; i++){
		fitaMemoria[i] = -1;
	}
}

void printaFita(){
	printf("Fita: ");
	for(i = 0; i < tamanho; i++){
		printf("%d ", fitaMemoria[i]);
	}
}

void reiniciaVariaveis(){
	int *fitaMemoria = NULL;
	int tamanho = NULL;
	int numeroArquivo = NULL;
	int valorAtual = 0;
	bool flag = false;
	int i = 0;
	char c[0];
	int quantidadeRequisicoes = 0;
	int pageFaults = 0;
	int ultimaPosicao = 0;
}


