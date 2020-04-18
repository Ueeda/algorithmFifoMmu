/******************************************************************************
* arquivo: BrunoMantovani_RafaelUeda.c (10/05/2017)
* autor: Bruno Mantovani e Rafael Ueda
* curso: Sistemas de Informação
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int *fitaMemoria;

void manipulandoArquivo(char *nomeArq, int tamanhoFita, int nArquivo);
void printaFita();
void iniciaVetor(int numeroPosicoes);
void reiniciaVariaveis();
bool verificaValor(long valor, int tamanho);

void main(){
	clock_t tempoInicial, tempoFinal;

	tempoInicial = clock();
	
	manipulandoArquivo("arquivos/arquivo1.txt", 4,1);
	manipulandoArquivo("arquivos/arquivo2.txt", 4,2);
	manipulandoArquivo("arquivos/arquivo3.txt", 64,3);
	manipulandoArquivo("arquivos/arquivo3.txt", 256,3);
	manipulandoArquivo("arquivos/arquivo3.txt", 1024,3);
	manipulandoArquivo("arquivos/arquivo3.txt", 2048,3);
	manipulandoArquivo("arquivos/arquivo4.txt", 64,4);
	manipulandoArquivo("arquivos/arquivo4.txt", 256,4);
	manipulandoArquivo("arquivos/arquivo4.txt", 1024,4);
	manipulandoArquivo("arquivos/arquivo4.txt", 2048,4);
	
	tempoFinal = clock();
	
	double tempo = (double)(tempoFinal-tempoInicial)/(double)(CLOCKS_PER_SEC);

	printf("\nTempo total em segundos: %.2f", tempo);

}

void manipulandoArquivo(char *nomeArq, int tamanhoFita, int nArquivo){
	int tamanho = tamanhoFita;
	int numeroArquivo = nArquivo;
	char ch[10];
	int valorAtual = 0;
	bool flag = false;
	int i = 0;
	int quantidadeRequisicoes = 0;
	int pageFaults = 0;
	int ultimaPosicao = 0;
	
	iniciaVetor(tamanho);
	
	FILE *arq;
	
	arq = fopen(nomeArq, "r");
	
	while(!feof(arq))
	{
		fgets(ch,9,arq);
		valorAtual = atoi(ch);
		
		
		if(verificaValor(valorAtual, tamanho) == false){
			if(fitaMemoria[ultimaPosicao] == -1){
				//printf("vetor ainda nao esta cheio \n");
				fitaMemoria[ultimaPosicao] = valorAtual;
				//printf("posicao inicio %d \n", valorAtual);
				ultimaPosicao++;
				if(ultimaPosicao > (tamanho - 1))
					ultimaPosicao = 0;		
			}
			else{
				fitaMemoria[ultimaPosicao] = valorAtual;
				pageFaults++;
				//printf("posicao %d \n", valorAtual);
				ultimaPosicao++;
				if(ultimaPosicao > (tamanho - 1))
					ultimaPosicao = 0;					
			}
		}
		quantidadeRequisicoes++;
	//	free (fitaMemoria);
	}
	
	fclose(arq);
	
	printf ("Arquivo %d, %5d paginas, %7d requisicoes: FIFO: %5d Page Faults \n", numeroArquivo, tamanho, quantidadeRequisicoes, pageFaults) ;

}

bool verificaValor(long valor, int tamanho){
	int i;
	for(i = 0; i < tamanho; i++){
		if(fitaMemoria[i] == valor){
			return true;
		}
	}
	return false;
}

void iniciaVetor(int numeroPosicoes){
	int i;
	if(fitaMemoria == NULL)
		fitaMemoria = (int *)malloc(numeroPosicoes * sizeof(int));
	else
		fitaMemoria = (int *)realloc(fitaMemoria, numeroPosicoes * sizeof(int));
	for(i = 0; i < numeroPosicoes; i++){
		fitaMemoria[i] = -1;
	}
}


