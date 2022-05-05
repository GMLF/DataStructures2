#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
/*
@Guilherme Moreira
data 29/03
*/

//---------------------------Função Aloca Vetor---------------------------------
int *Aloca(int vetor[],int tam){
  int *auxiliar=(int*)malloc(tam*sizeof(int));
  return auxiliar;
}//Aloca

//--------------------------Função Preenche Vetor-------------------------------
void PreencheVetor(int vetor[],int tam){
  vetor[0]=45;
  vetor[1]=36;
  vetor[2]=2;
  vetor[3]=8;
  vetor[4]=0;
  vetor[5]=1;
  vetor[6]=23;
  vetor[7]=7;
  vetor[8]=5;
  vetor[9]=10;
}//PreencheVetor

//---------------------------Função Exibe Vetor---------------------------------
void ExibeVetor(int vetor[],int tam){
  printf("{");
  for(int i=0; i<tam; i++){
    printf("%d ",vetor[i]);
  }//for
  printf("}\n");
}//ExibeVetor


//-----------------------------Função Merge-------------------------------------
void Merge( int vetor[], int inicio, int meio, int fim){
  //vetor auxiliar que irá ter a região alocada igual a do vetor principal
  int *vet;
  //tamanhodo vetor             //váriavel auxiliar que recebe a posição de inicio do vetor, para criar subvetores a esquerda
  int tamanho;                  int p1=inicio;
  //váriavel que recebe a onde o vetor quebra, para criar subvetores a direita
  int p2=meio+1;
  //contador auxiliar
  int k;

    tamanho=(fim-inicio)+1;
    vet=Aloca(vet,tamanho);

//enquanto o vetor auxiliar for diferente de nulo, faça
if(vet!=NULL){
      //for rodando de 0 até o tamanho
      for(int i=0; i<tamanho; i++){

      //enquanto o inicio foi menor ou igual ao meio e o meio foi menor ou igual ao fim, faça
       if((p1<=meio) && (p2<=fim)){
         //se o elemento da esquerda for menor que o elemento da direita
          if(vetor[p1]<vetor[p2]){
            //vetor auxiliar, recebe o elemento na posição da esquerda
            vet[i]=vetor[p1++];
          }else{
            //se não, recebe o elemento da direita
            vet[i]=vetor[p2++];
          }//else
       }else{
          //se o vetor da esquerda for menor ou igual o meio
          if(p1<=meio){
            //vetor auxiliar, recebe a próxima posição do vetor da esquerda
            vet[i]=vetor[p1++];
          }else{
            //se não, recebe o próximo da posição da direita
            vet[i]=vetor[p2++];
          }//else interno
        }//else externo
      }//for

    //trocando os indices dos vetores
    for(int j=0, k=inicio; j<tamanho; j++, k++){
      //vetor original na posição do inicio, recebe o elemento da posição j do vetor auxiliar
      vetor[k]= vet[j];
    }//for
  }//if
  //desalocando memória
  free(vet);
}//Merge

//---------------------------Função MergeSort-----------------------------------
void MergeSort(int vetor[],int inicio ,int fim){
  int meio;

    if(inicio<fim){
      //encontrando sempre o meio do vetor e dos subvetores
      meio=((inicio+fim)/2);
      //passando o inicio e meio para realizar a quebra do lado esquerdo
      MergeSort(vetor,inicio,meio);
      //passando o meio+1 e fim para realizar a quebra do vetor do lado direito
      MergeSort(vetor,meio+1,fim);
      //chamando a merge para re-organizar os subvetores em um vetor unitario
      Merge(vetor,inicio,meio,fim);
    }//if
}//MergeSort

//----------------------------Função Principal----------------------------------
int main(int argc, const char * argv[]){
  //variaveis
  int *vetor,fim,inicio=0;

  printf("Digite o tamanho do vetor: ");
  scanf("%d",&fim);

  //alocando memória
  vetor=Aloca(vetor,fim);

  //Preenche Vetor de forma aleatória
  PreencheVetor(vetor,fim);

  printf("\nvetor Preenchido de forma aleatória\n");
  ExibeVetor(vetor,fim);


  MergeSort(vetor,inicio,fim);

  printf("\nVetor Organizado\n");
  ExibeVetor(vetor,fim);
  //desalocando memória
  free(vetor);
 return 0;
}//main
