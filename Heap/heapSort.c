#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//-------------------------------Função aloca Vetor-----------------------------
int *Aloca(int *vet, int tam){
  int *aux=malloc(tam*sizeof(int));
  return aux;
}//aloca

//-----------------------------Função preenche Vetor----------------------------
void PreencheVetor(int *vet, int tam){
  srand(time(NULL));
  for(int i=0; i<tam ;i++){
    vet[i]=rand()%1000;
  }//for
}//PreencheVetor

//-------------------------------Função Exibe Vetor-----------------------------
void Exibe(int *vet, int tam){
  printf("\n{");
    for(int i=0; i<tam; i++){
      printf("%d ",vet[i]);
    }
  printf("}\n");
}

//---------------------------------Função Cria Heap-----------------------------
void criaHeap(int *vet,int pai, int fim){
  int aux=vet[pai];
  int filho=pai*2+1;

    while(filho<=fim){
        if(filho<fim){
          if((vet[filho]) < (vet[filho+1])){
            filho++;
          }//if interno
        }//if externo

        if(aux<vet[filho]){
          vet[pai]=vet[filho];
          pai=filho;
          filho=pai*2+1;
        }else{
          filho=fim+1;
        }//else
    }//while
    vet[pai]=aux;
}//criaHeap

//---------------------------------Função Heap Sort-----------------------------
void heapSort(int *vet, int tam){
  int aux;

    for(int i=(tam-1)/2; i>=0; i--){
      criaHeap(vet,i,tam-1);
    }//for

    //balanceando o heap para remover a raiz e organizar o vetor
    for(int i=tam-1; i>=1; i--){
      aux=vet[0];
      vet[0]=vet[i];
      vet[i]=aux;
      criaHeap(vet,0,i-1);
    }//for
}//heapSort

//-------------------------------Função Principal Main--------------------------
int main(int argc, const char *argv[]){
  //váriaveis
  int *vetor,tam;

    printf("Tamanho: ");
    scanf("%d",&tam);

    //aloca dinamicamente a memória
    vetor=Aloca(vetor,tam);

    //Preenchendo vetor randomico
    PreencheVetor(vetor,tam);

    Exibe(vetor,tam);

    heapSort(vetor,tam);

    Exibe(vetor,tam);

    free(vetor);
  return 0;
}//main
