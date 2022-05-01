#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int *Aloca(int vetor[],int tam){
  int *aux=(int*)malloc(tam*sizeof(int));

    return aux;
}//aloca

void Preenche(int vetor[],int tam){
  srand(time(NULL));

  for(int i=0; i<tam ;i++){
    vetor[i]=rand()%100;
  }//for
}//Preenche

void Exibe(int vetor[],int tam){
  for(int i=0; i<tam; i++){
    printf("\t%d ",vetor[i]);
  }//for
  printf("\n");
}//Exibe

void InsertionSort(int vetor[], int tam,char op){
  int aux,j;

    for(int i=1; i<tam; i++){
      aux=vetor[i];
      j=i-1;
    if(op=='c'){
      while(j>=0 && (aux < vetor[j])){
          vetor[j+1]=vetor[j];
          j=j-1;
      }//while
    }else if(op=='d'){
      while(j>=0 && (aux > vetor[j])){
          vetor[j+1]=vetor[j];
          j=j-1;
      }//while
    }//else if
     vetor[j+1]=aux;
    }//for externo
  }//InsertionSort

int main(int argc, const char * argv[]){
  //váriaveis
  int *v,tam;
  char op;

    printf("Digite a opcao: ");
    scanf("%c",&op);

    printf("Tamamho do vetor: ");
    scanf("%d",&tam);

    v=Aloca(v,tam);

    Preenche(v,tam);

    Exibe(v,tam);

    InsertionSort(v,tam,op);

    Exibe(v,tam);


 return 0;
}//main
