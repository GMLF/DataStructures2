#include <stdlib.h>
#include <stdio.h>

float Media(int vetor[],int tamanho){
  int contador=0;
  float med,multiplos;

//pegando todos os elementos que são multiplos de 3 existentes dentro do vetor;
  for(int i=0; i<tamanho; i++){
    if(vetor[i]%3 == 0){
      multiplos+=vetor[i];
      contador++;
    }//if
  }//for para percorrer o vetor

  return(med=multiplos/contador);
}

int ProcuraVetor(int vetor[], int tamanho){
  //váriaveis
  int elemento,contador=0;

    printf("Digite o elemento que deseja buscar: ");
    scanf("%d",&elemento);

    for(int i=0; i<tamanho; i++){
      if(elemento == vetor[i]){
        contador++;
      }//if
    }
    return(contador);
}

int main(){
  //váriaveis
  int vetor[5]={1,2,3,4,6},codigo,quantidade=0;
  float media_aritimetica;

    //laço de repetição, faça enquanto o código for diferente de -1
      do{
          //recebendo o código do usuário
          printf("Digite o codigo: ");
          scanf("%d",&codigo);

          //Exibindo conforme o codigo digitado for 1
          if(codigo == 1){
            printf("Partiu feriado\n");
          }
          //Exibindo o vetor na ordem conforme o código digitado
          else if(codigo == 2){
            printf("Vetor de tras para frente\n");
            //percorrendo o vetor da ultima posição para a primeira e exibindo os elementos
            for(int i=4; i>=0; i--){
              printf("%d ",vetor[i]);
            }//for
            printf("\n");
          }
          //Calculando a média conforme o código digitado
          else if(codigo == 3){
            //Recebendo o retorno da função que cálcula a média, conforme o vetor passado por referência e o tamaho por cópia
            media_aritimetica = Media(vetor,5);
            //Exibindo a média
            printf("Media Aritimetica %.2f\n",media_aritimetica);
          }
        //Calculando a quantidade de vezes que o elemento aparece no vetor
          else if(codigo == 4){
            //Recebendo o retorno da função que verifica quantas vezes o elemento procurado aparece no vetor, conforme o vetor passado por referência e o tamaho por cópia
            quantidade=ProcuraVetor(vetor,5);
            //Exibindo a quantidade de vezes que o elemento aparece
            printf("O elemento aparece [%d] vezes no vetor\n",quantidade);
          }else{
            printf("Opcao invalida, digite uma nova opcao ou -1 para encerar\n");
          }
      }while(codigo!=-1);//condição de parada do laço de repetição

      //Exibindo a mensagem conforme o código digitado não atender nenhuma das opções
      printf("Quartou!!!\n");
  return 0;
}
