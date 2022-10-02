#include <stdio.h>
#include <stdlib.h>


int main(){

  int vetor[5],opcao,soma=0;

    for(int i=0; i<5; i++){
      scanf("%d",&vetor[i]);
      soma+=vetor[i];
    }


    scanf("%d",&opcao);

    if(opcao==1){
      printf("%d",soma);
    }else if(opcao==2){
      for(int i=4; i>=0; i--){
      printf("%d ",vetor[i]);
      }

    }else if(opcao==3){
        int maior=vetor[0];
          for(int i=0; i<5; i++){
            if(vetor[i]>maior){
              maior=vetor[i];
            }//if
          }//for
          printf("%d ",maior);
    }



  return 0;
}
