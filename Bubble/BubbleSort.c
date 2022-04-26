#include <stdlib.h>
#include <stdio.h>

int bubblesort(int *v, int tam){

  for (size_t l=0; l<tam+1; l++){
    for (size_t j = 0; j < tam-1; j++) {
      if (v[j] > v[j+1]){
        int aux = v[j+1];
        v[j+1]= v[j];
        v[j]= aux;
      }
    }
    printf("passou\n");
    tam--;
  }
}

int main(){

  int vetor[10]={7,4,1,8,5,2,0,9,6,3};

  bubblesort(vetor,10);
  for (size_t i = 0; i < 10; i++){
    printf("%d\n",vetor[i]);
  }

  return 0;
}
