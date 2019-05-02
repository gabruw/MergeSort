#include <stdio.h>

void MergeSort(int vet[], int aux[], int esq, int dir);
void Intercalar(int vet[], int aux[], int ini1, int ini2, int fim2);

int main(){
	int vet[10] = {12, 33, 24, 99, 36, 8, 114, 77, 53, 43};
	int aux[10];
	int i;
	
 	MergeSort(vet, aux, 0, 9);
 	
 	for(i = 0; i < 10; i++){
  		printf("%d\n", vet[i]);
 	}
}

void Intercalar(int vet[], int aux[], int ini1, int ini2, int fim2){
	int in1 = ini1; 
	int in2 = ini2; 
	int fim1 = in2 - 1;
	int au = 0;
	int i;
 	
	while(in1 <= fim1 && in2 <= fim2){
		if (vet[in1] < vet[in2]){
	   		aux[au++] = vet[in1++];
		}else{
	   		aux[au++] = vet[in2++];
	  	}
	}
	
	while(in1 <= fim1){
		aux[au++] = vet[in1++];
	}
	
 	while(in2 <= fim2){
  		aux[au++] = vet[in2++];
 	}
 
	for(i = 0; i < au; i++){
		vet[i + ini1] = aux[i];
	}
}
	
void MergeSort(int vet[], int aux[], int esq, int dir){
	int meio;
	int i;
		
 	if(esq < dir){
  		meio = (esq + dir)/2;
  		
  		MergeSort(vet, aux, esq, meio);
  		MergeSort(vet, aux, meio+1, dir);
  		Intercalar(vet, aux, esq, meio+1, dir);  
 	}
}
