#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

//@Guilherme Moreira Lima Furlaneto Ra 2207192

//------------------------------Função Swap-------------------------------------
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

//---------------------------Função Particiona----------------------------------
int criaParticoes(int *vetor,int inicio, int fim){
  int esquerda=inicio;
  int direita = fim;
  int pivo    = vetor[inicio];
  int aux;

    while(esquerda<direita){
      while(vetor[esquerda]<=pivo && esquerda<=fim){
        esquerda++;
      }//while

      while(vetor[direita]>pivo && direita>=inicio){
        direita--;
      }

    if(esquerda<direita){
      swap(&vetor[esquerda],&vetor[direita]);
    }//if
  }//while externo

  aux=vetor[inicio];
  vetor[inicio]  =vetor[direita];
  vetor[direita]   =aux;

  return direita;
}

//----------------------------Função QuickSort----------------------------------
void quicksort(int *vetor, int inicio,int fim){
  if(inicio < fim){
  int  pivo = criaParticoes(vetor,inicio,fim);

    quicksort(vetor,inicio,pivo-1);
    quicksort(vetor,pivo+1,fim);
  }
}

//-------------------------Função Preenche Vetor--------------------------------
void PreencheVetor(int vetor[],int tamanho){
  srand(time(NULL));

  for(int i=0; i<tamanho; i++){
    vetor[i]=rand()%100;
  }//for
}

//---------------------------Função Exibe Vetor---------------------------------
void ExibeVetor(int *vetor, int tamanho){
  printf("{");
  for(int i=0; i<tamanho; i++){
    printf("%d ",vetor[i]);
  }//for
  printf("}\n");
}

//----------------------------Função Principal----------------------------------
int main(){
  int tamanho,*vetor;

      printf("Tamanho do vetor: ");
      scanf("%d",&tamanho);

      vetor=malloc(tamanho*sizeof(int));

      PreencheVetor(vetor,tamanho);

      printf("\nVetor Desorganizado\n");
      ExibeVetor(vetor,tamanho);

      quicksort(vetor,0,tamanho-1);

      printf("\nVetor Organizado\n");
      ExibeVetor(vetor,tamanho);

    free(vetor);
  return 0;
}
