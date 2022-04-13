/*
@Guilherme Moreira Lima Furlaneto  15/03/22
Aula 01 Ed2
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//--------------------Função Gera Vetor Aleatório---------------------
void Aleatorio(int vetor[],int tamanho){
  srand(time(NULL));

    for(int i=0; i<tamanho; i++){
      vetor[i]=rand()%100;
    }//for
}//Aleatorio

//-----------------Função Aloca Dinamicamente Vetor--------------------
int *Aloca(int aux){
  //váriaveis
  int *vet;
    //aloca dinamicamente o vetor
    vet=malloc(aux*sizeof(int));
    //retornando a região alocada
    return vet;
}//Aloca

//-----------------Função Buca Linear----------------------------------
int BuscaLinear(int vetor[],int tamanho, int busca){
  int posicao=-1;

    for(int i=0; i<tamanho; i++){
      if(busca==vetor[i]){
        return i;
      }//if
    }//for
  return posicao;
}//BuscaLinear

//----------------Função Retorna se está ordenado----------------------

void OrganizaVetor(int vetor[],int tamanho){
  int menor,aux;

  for(int i=0; i<tamanho; i++){
    for(int j=0; j<tamanho; j++){
        if(vetor[i]<vetor[j]){
          aux=vetor[i];
          vetor[i]=vetor[j];
          vetor[j]=aux;
        }//if
      }//for interno
    }//for
}//OrganizaVetor

int BuscaOrdenada(int vetor[],int tamanho, int busca){
  int posicao=-1,contador=0;
  
    for(int i=0; i<tamanho; i++){
    if(vetor[i]>busca){
      return posicao;
    }else  if(busca==vetor[i]){
        return i;
      }//if
    }//for
  return posicao;
}//busca
//--------------------Função Principal--------------------------------
int main(int argc, const char * argv[]){

  //váriaveis
  int elemento,tamanho,*vet,posi;

    printf("Tamanho do vetor: ");
    scanf("%d",&tamanho);

    vet=Aloca(tamanho);

    Aleatorio(vet,tamanho);
    /*
    for(int i=0; i<tamanho; i++){
      printf("\n%d\n ",vet[i]);
    }
   */

   OrganizaVetor(vet,tamanho);

    for(int i=0; i<tamanho; i++){
      printf("\n%d\n ",vet[i]);
    }


    printf("\nElemento que deseja procurar: ");
    scanf("%d",&elemento);

   //posi=BuscaLinear(vet,tamanho, elemento);
   posi=BuscaOrdenada(vet,tamanho,elemento);


    printf("\nO elemento procurado está na posicao [%d]\n",posi);


  return 0;
}
