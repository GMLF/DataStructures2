#include <stdlib.h>
#include <stdio.h>
#include <time.h>


//---------------------------Função Aloca Vetor---------------------------------
int *Aloca(int vetor[],int tam){
  int *auxiliar=(int*)malloc(tam*sizeof(int));
  return auxiliar;
}//Aloca

//--------------------------Função Preenche Vetor-------------------------------
void PreencheVetor(int vetor[],int tam){
  srand(time(NULL));

    for(int i=0; i<tam; i++){
      vetor[i]=rand()%100;
    }
}//PreencheVetor

//---------------------------Função Exibe Vetor---------------------------------
void ExibeVetor(int vetor[],int tam){
  printf("{");
  for(int i=0; i<tam; i++){
    printf("%d ",vetor[i]);
  }//for
  printf("}\n");
}//ExibeVetor

//-----------------------------Função Quick-------------------------------------
int Quick(int *v, int inicio, int fim){
  int Esq = inicio;
  int Dir = fim;
  int Pivo =v[inicio];
  int aux;

    while(Esq<Dir){

      while(v[Esq]<=Pivo && Esq<=fim){
        Esq++;
      }//while interno

      while(v[Dir]>Pivo && Dir>=inicio){
        Dir--;
      }//while interno

        if(Esq<Dir){
          aux=v[Esq];
          v[Esq]=v[Dir];
          v[Dir]=aux;
        }//if
    }//while externo

    aux=v[Dir];
    v[Dir]=v[inicio];
    v[inicio]=v[Dir];

 return Dir;
}//Quick

//---------------------------Função QuickSort-----------------------------------
void QuickSort(int *v, int inicio, int fim){
  int pivo;

    if(inicio<fim){
      pivo=Quick(v,inicio,fim);
    //  ExibeVetor(v,fim);
      QuickSort(v,inicio,pivo-1);
      QuickSort(v,pivo+1,fim);
    }//if

}//QuickSort

//----------------------------Função Principal----------------------------------
int main(int argc, const char * argv[]){
  //variaveis
  int *vetor,tamanho,inicio=0;

  printf("Digite o tamanho do vetor: ");
  scanf("%d",&tamanho);

  //alocando memória
  vetor=Aloca(vetor,tamanho);

  //Preenche Vetor de forma aleatória
  PreencheVetor(vetor,tamanho);

  printf("\nvetor Preenchido de forma aleatória\n");
  ExibeVetor(vetor,tamanho);

  QuickSort(vetor,inicio,tamanho-1);

  ExibeVetor(vetor,tamanho);
  return 0;
}
