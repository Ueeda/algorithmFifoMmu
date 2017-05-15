#include <stdio.h>
#include <stdlib.h>

char arquivo[] = "arquivos/arquivo1.txt";

int fitaMemoria[4] = {-1, -1, -1, -1};
int quantidadeTrocaFrames = 0;
int ultimaPosicao = 0;
char ch[10];
int valorAtual = 0;

void manipulandoArquivo();

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
		
		int tamanho = sizeof(fitaMemoria) / sizeof(fitaMemoria[0]);
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
			int i;
			for(i = 0; i < sizeof(fitaMemoria); i++){
				if(fitaMemoria[i] == valorAtual)
					continue;
				else{
					fitaMemoria[ultimaPosicao] = valorAtual;
					quantidadeTrocaFrames++;
					if(ultimaPosicao == 3)
						ultimaPosicao = 0;
					else
						ultimaPosicao++;
					break;
				}
			}
			
		}
		
	}
	
	printf("Quantidade de trocas: %d", quantidadeTrocaFrames);
	
	fclose(arq);
}
