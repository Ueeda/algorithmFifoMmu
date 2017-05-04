#include <stdio.h>

char arquivo[] = "arquivos/arquivo.txt";

void manipulandoArquivo();

int main(){
	
	
	manipulandoArquivo();
	
	return 0;
}

void manipulandoArquivo(){
	FILE *arq;
	
	arq = fopen(arquivo, "r");
	
	if(arq == NULL){
		printf("Erro na abertura do arquivo");
	}
	else{
		
	}
	
	fclose(arq);
}
