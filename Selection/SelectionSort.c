#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>


//-----------------------------Preenche Vetor-----------------------------------
void PreencheVetor(int vetor[], int tam){
  srand(time(NULL));

  for(int i=0; i<tam; i++){
    vetor[i]=rand()%100;
  }//for
}//PreencheVetor


//-------------------------Alocando Memória Vetor-------------------------------
int *Aloca(int vetor[],int tam){
  int *vet=(int*) malloc(tam*sizeof(int));
  return vet;
}//Aloca

//----------------------------Exibe o Vetor-------------------------------------
void Exibe(int vetor[],int tam){
  for(int i=0; i<tam; i++){
    printf("%d ",vetor[i]);
  }//for
  printf("\n");
}//Exibe

//----------------------------Selection Sort------------------------------------
void SelectionSort(int vetor[],int tam,char op){
  int aux,menor;

    for(int i=0; i<tam-1; i++){
      menor=i;
      for(int j=i+1; j<tam ;j++){
        if(op=='c'){
        if(vetor[j]<vetor[menor]){
          menor=j;
        }//if
      }else if(op=='d'){
        if(vetor[j]>vetor[menor]){
          menor=j;
        }//if
      }//else
    }//for interno
    if(i!=menor){
      aux=vetor[i];
      vetor[i]=vetor[menor];
      vetor[menor]=aux;
    }//if
  }//for externo
}//SelectionSort


//------------------------------------------------------------------------------
int main(int argc, const char * arv[]){
  //váiaveis
  int *v,tam;
  char op;


    printf("|C| Crescente ou |D| Decrescente: ");
    scanf("%c",&op);

    printf("Digite o tamanho do vetor: ");
    scanf("%d",&tam);

    //ALOCANDO VETOR
    v=Aloca(v,tam);

    PreencheVetor(v,tam);

    printf("\nVetor Antes da Opcao escolhida\n");
    Exibe(v,tam);

    SelectionSort(v,tam,op);

    printf("\nVetor Depois da Opcao escolhida\n");
    Exibe(v,tam);

 return 0;
}//main
