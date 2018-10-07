//MATERIA: PROJETO DE ALGORITMO
//UNIVERSIDADE FEDERAL DE VIÇOSA CAMPUS DE RIO PARANAÍBA 
//ALUNOS : Rodrigo de Oliveira Costa , Kleiber de Carvalho Ferreira.
/*"trabalho contem osseguintes algortimos de ordenação implementados  
2 - selec_sort  3 - insertion_sort 
4 - bubble_sort 5 - shell_sort 6 - merge_sort:  
7 - quick_sort (ELEMENTO DO MEIO) 8 - quick_sort (por mediana)  
9 - heap_Sort" */

#include <dir.h>
#include <time.h>
#include <string.h>
#include "algoritmos.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void escolhaAlgoritmo(int *op)
{
	do{
		printf("Digite a opcao de Algoritmo:\n1 - min_max1 \n2 - selec_sort  \n3 - insertion_sort \n4 - bubble_sort \n5 - shell_sort \n6 - merge_sort: \n7 - quick_sort \n8 - quick_sort (por media) \n9 - heap_Sort\n0 - Sair:\n");
		// coloquem os outros 2 algoritmos
		scanf("%d", &*op);
		fflush(stdin);
		system("cls");
	}while (*op < 1 || *op > 10);
	
}
void escolhaEntrada(int * tamanho){
	do{
		printf("Digite o tamanho da entrada para o Algoritmo:\n10 - 1000 - 10000 - 100000 - 1000000 - 10000000\n");
		scanf("%d", &*tamanho);
		system("cls");
				
	}while(*tamanho!=10 && *tamanho!=1000 && *tamanho!=10000 && *tamanho!=100000 && *tamanho!=1000000 && *tamanho!=10000000);	
}
void gravaresultado(float resultado, int tamanho, char *nome,  char *modeloEntra){

	int i, numero;	
	FILE * file;
	file = fopen("RESULTADOS_TEMPOS_EXCUÇÂO.txt", "a+");
	
	if (file == NULL){
			printf("Socorro! O arquivo não pôde ser aberto!\n");
	}

	fprintf(file,"\n algoritmo %s \n entrada %s %d\n Tempo(s):%f \n**",nome,modeloEntra,tamanho,resultado);


		fclose(file);
}
void preencheVetor(int vetor[], int tamanho, char *modeloEntra){
	int i, numero,aux;
	char urlEntrada[60];
	do{
	
		printf("Digite qual modelo de entrada voce quer :\n1-crescente,\n2-decrescente,\n3-aleatoria\n");
		scanf("%d",&aux);
	}while(aux != 1 && aux !=2 && aux != 3);
	if(aux==1)
	strcpy (modeloEntra,"crescente");
	if(aux==2)
	strcpy (modeloEntra,"decrescente");
	if(aux==3)
	strcpy (modeloEntra,"aleatoria");
	
	sprintf(urlEntrada, "entradas/entrada_%s_%d.txt",modeloEntra, tamanho);	
	
	FILE * file;
	file = fopen(urlEntrada, "rt");
	
			while (file == NULL){
			printf("Erro.\n");
			free(vetor);// se caso der errado, pelo menos libera a memoria alocada
			system("PAUSE");
			exit(1);
		}
				
		for (i = 0; i < tamanho; i++){
			fscanf(file,"%d\n", &numero);
			//printf("\n %d - %d",i+1,numero);//sabia que o print demora, entao deixe comentado
			vetor[i]=numero;
		}
		
		fclose(file);
		
		
}
void imprimeVetor(int vetor[], int tamanho) {
	int i;
	printf("\n");
	for (i =0; i < tamanho; i++) {
		printf("%d\n", vetor[i]);
	}
}
int main(){
	int op, tamanho, *vetor, min, max, i;
	float tempoGasto, start, end;
	char nome[100],modeloEntra[100];
	
	escolhaAlgoritmo(&op);
	escolhaEntrada(&tamanho);
	//alocaVetor(vetor, tamanho);
	vetor = (int *) malloc(tamanho * sizeof(int));
		if (vetor == NULL){
			printf("Erro.\n");
			system("PAUSE");
			exit(1);
		}
		else{
			printf("Sucesso.\n");
		}	
	
	preencheVetor(vetor, tamanho,modeloEntra);
	
	//imprimeVetor(vetor, tamanho);	


	switch(op) {
			case 1:
				start=clock();
				min_max1(vetor, &min, &max, tamanho);
				end = clock();
				tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
				strcpy (nome,"Max");
				gravaresultado(tempoGasto,tamanho,nome,modeloEntra);
				printf("\nMin:%d \nMax:%d \nTempo(s):%f", min, max,tempoGasto);

				break;
			case 2:
				printf("\n ORDENANDO Selec_sorte......:");			
				start=clock();
				selection_sort(vetor,tamanho);
				end = clock();
				tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
				//imprimeVetor(vetor,tamanho);
				strcpy (nome,"Selec_sorte");
				gravaresultado(tempoGasto,tamanho,nome,modeloEntra);
				printf("\n Tempo  Selec_sorte \nTempo(s):%f",tempoGasto);
				break;
			case 3:
				printf("\n ORDENANDO insertion_sort ......:");			
				start=clock();
				insertion_sort(vetor,tamanho);
				end = clock();
				tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
				//imprimeVetor(vetor,tamanho);
				strcpy (nome,"insertion_sort");
				gravaresultado(tempoGasto,tamanho,nome,modeloEntra);
				printf("\n Tempo  insertion_sort\n Tempo(s):%f",tempoGasto);
				break;
			case 4:
				printf("\n ORDENANDO bubble  ......:");			
				start=clock();
				bubble_sort(vetor,tamanho);
				end = clock();
				tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
				//imprimeVetor(vetor,tamanho);
				strcpy (nome,"bubble_sort");
				gravaresultado(tempoGasto,tamanho,nome,modeloEntra);
				printf("\n Tempo  bubble_sort\n Tempo(s):%f",tempoGasto);
				break;
			case 5:
				printf("\n ORDENANDO shell_sort  ......:");			
				start=clock();
				shell_sort(vetor,tamanho);
				end = clock();
				tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
				//imprimeVetor(vetor,tamanho);
				strcpy (nome,"shell_sort");
				gravaresultado(tempoGasto,tamanho,nome,modeloEntra);
				printf("\n Tempo  shell_sort\n Tempo(s):%f",tempoGasto);
				break;
			case 6:
				printf("\n ORDENANDO merge_sort  ......:");			
				start=clock();
				mergeSort(vetor,0,tamanho);
				end = clock();
				tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
				//imprimeVetor(vetor,tamanho);
				strcpy (nome,"merge_sort");
				gravaresultado(tempoGasto,tamanho,nome,modeloEntra);
				printf("\n Tempo  merge_sort\n Tempo(s):%f",tempoGasto);
				break;
			case 7:
				printf("\n ORDENANDO quick_sort  ......:");			
				start=clock();
				quick_sort(vetor,tamanho);
				end = clock();
				tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
				//imprimeVetor(vetor,tamanho);
				strcpy (nome,"quick_sort");
				gravaresultado(tempoGasto,tamanho,nome,modeloEntra);
				printf("\n Tempo  quick_sort\n Tempo(s):%f",tempoGasto);
				break;
			case 8:
				printf("\n ORDENANDO quick_sort (nedia)  ......:");			
				start=clock();
				quick_sortMEDIA(vetor,tamanho);
				end = clock();
				tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
				//imprimeVetor(vetor,tamanho);
				strcpy (nome,"quick_sort media");
				gravaresultado(tempoGasto,tamanho,nome,modeloEntra);
				printf("\n Tempo  quick_sort\n Tempo(s):%f",tempoGasto);
				break;
			case 9:
				printf("\n ORDENANDO quick_sort (nedia)  ......:");			
				start=clock();
				heapSort(vetor,tamanho);
				end = clock();
				tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
				//imprimeVetor(vetor,tamanho);
				strcpy (nome,"heapSort");
				gravaresultado(tempoGasto,tamanho,nome,modeloEntra);
				printf("\n Tempo  heapSort\n Tempo(s):%f",tempoGasto);
				break;
			default:
				printf("\nInvalido");
		}


	free(vetor);

	return 0;
}

