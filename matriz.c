#include <mpi.h>
#include <stdio.h>
#define GERENTE 0


int main(int argc , char **argv){

  int l, id , size , tag = 666;
  char *enviado,recebido[50];
  MPI_Status stats; // Status da mensagem recebida
  int matriz[3][3];
  int matriz2[3][3];
  int matrizr[3][3];
  int result;

    FILE *arquivo = fopen("matriz.txt","r");
    FILE *arquivo2 = fopen("matriz2.txt","r");

  while(!feof(arquivo)){
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        fscanf(arquivo,"%d\n",&matriz[i][j]);
      }
    }
  }

  while(!feof(arquivo2)){
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        fscanf(arquivo2,"%d\n",&matriz2[i][j]);
      }
    }
  }

    MPI_Init (&argc , &argv);
    MPI_Comm_rank(MPI_COMM_WORLD , &id);
    MPI_Comm_size(MPI_COMM_WORLD , &size); //size == número de processos


  for(int i = id; i < 3; i = i+size){
    for(int j = 0; j < 3; j++){
    result=0;

      for(int k = 0; k < 3; k++){
      result = result + matriz[i][k] * matriz2[k][j];
      }
  matrizr[i][j] = result;
  }
}

  if(id != 0){
    for(int i = id; i < 3; i = i+size)
    MPI_Send(&matrizr[i][0], 3, MPI_INT, 0, 10+i, MPI_COMM_WORLD);
    }else if (id == GERENTE) {
        for(int j = 1; j < size; j++){
          for(int i = j; i < 3; i = i+size){
            MPI_Recv(&matrizr[i][0], 3, MPI_INT, j, 10+i, MPI_COMM_WORLD, &stats);

          }
        }
      }

  MPI_Barrier(MPI_COMM_WORLD);
  if(id == 0){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        printf("%d\t",matrizr[i][j]);
      }
      printf("\n");
    }
  }

MPI_Finalize();
return 0;
}
