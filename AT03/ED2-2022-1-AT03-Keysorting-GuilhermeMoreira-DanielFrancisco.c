#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define BUFFER 136
//----------------------------
//----------------------------

typedef struct {
  int indice;
  char dados[BUFFER];
} Heroi;

//-------------------------------Função Swap------------------------------------
  void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
  }

//-----------------------------Função Quick-------------------------------------
int Quick(int *v, int inicio, int fim,char op) {
    int troca;
    int cont = inicio;

    for (int i = inicio+1; i <= fim ; i++) {
      if(op=='D'){
        if (v[i]> v[inicio]){
            cont++;
            troca= v[i];
            v[i]= v[cont];
            v[cont]= troca;
        }//if
      }
       if(op == 'C'){
        if (v[i]< v[inicio]){
            cont++;
            troca= v[i];
            v[i]= v[cont];
            v[cont]= troca;
      }
    }
  }//for
    troca = v[inicio];
    v[inicio]= v[cont];
    v[cont]= troca;

    return cont;

}//Quick

//---------------------------Função QuickSort-----------------------------------
void QuickSort(int *v, int inicio, int fim,char op){
  int pivo;
  if (inicio < fim){
      pivo = Quick(v, inicio,fim,op);
      QuickSort(v, inicio,pivo-1,op);
      QuickSort(v, pivo+1, fim,op);
  }

}//QuickSort

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
    vet=malloc(tamanho*sizeof(int));

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
          }

          else{
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

//--------------------------------Função InsertionSort--------------------------
void InsertionSort(int vetor[], int tam,char op){
  int aux,j;

    for(int i=1; i<tam; i++){
      aux=vetor[i];
      j=i-1;
    if(op=='C'){
      while(j>=0 && (aux < vetor[j])){
          vetor[j+1]=vetor[j];
          j=j-1;
      }//while
    }else if(op=='D'){
      while(j>=0 && (aux > vetor[j])){
          vetor[j+1]=vetor[j];
          j=j-1;
      }//while
    }//else if
     vetor[j+1]=aux;
    }//for externo
}//InsertionSort

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

//--------------------- Função LeituraCabecalho_E_ContaQtde---------------------
int LeituraCabecalho_E_ContaQtde(FILE *entrada, FILE *saida, char *sorte,char *op){
  char *string;
  // fgets(string, 100, idx->arqDados);
  int size, top, qtde;


  fscanf(entrada, "SIZE=%d TOP=%d QTDE=%d SORT=%c ORDER=%c\n", &size, &top,
    &qtde, sorte, op);

  if((*sorte)!='Q' && (*sorte)!='H'&& (*sorte)!='I' && (*sorte)!='M'){
    printf("Arquivo Invalido\n");
    fprintf(saida,"Arquivo Inválido\n");
    exit(1);
  }

  fprintf(saida,"SIZE=%d TOP=%d QTDE=%d SORT=%c ORDER=%c\n", size, top, qtde, *sorte, *op);
  return(qtde);
}//LeituraCabecalho_E_ContaQtde

//------------------------------Função VerificaParametros-----------------------
void VerificaParametros(int argc){
  if(argc!=3){
    printf("Quantidade de parametros invalidos\n");
    exit(1);
  }//if
}

//----------------------Verificando Abertura Arquivos---------------------------
void VerificaAberturaArquivos(FILE *arqentrada, FILE *arqsaida){
  if(arqentrada==NULL||arqsaida==NULL){
    printf("Erro ao abrir um dos arquivos\n");
    exit(1);
  }//if
}//VerificaAberturaArquivos

//--------------------------Função Aloca Memória Struct-------------------------
Heroi * AlocaStructHeroi(int qtd){
  Heroi *auxiliar=malloc(qtd*sizeof(Heroi));
  return auxiliar;
}//Heroi

//-----------------------------Função Le e Grava--------------------------------
void Le_E_Grava(FILE *entrada, Heroi *herois, int vetor[]){
int linha=0;
  while(!feof(entrada)){
  fscanf(entrada,"%d",&herois[linha].indice);

    if(fgets(herois[linha].dados,136,entrada)!=NULL){
      vetor[linha]=herois[linha].indice;
      linha++;
    }//

  }//while

}//Le_E_Grava

//-----------------------------Função OrdenaVetor-------------------------------
void OrdenaVetores(char sorte,int vetor[], int qtd_registros,char op){
  sorte=toupper(sorte);

  if(sorte=='Q'){
      printf("\nMetodo Quick\n");
      QuickSort(vetor,0,qtd_registros-1,op);
  }else if(sorte == 'M'){
      printf("\nMetodo Merge\n");
      MergeSort(vetor,0,qtd_registros);
  }else if(sorte == 'I'){
      printf("\nMetodo InsertionSort\n");
      InsertionSort(vetor,qtd_registros,op);
  }else if(sorte == 'H'){
      printf("\nMetodo Heap\n");
        heapSort(vetor,qtd_registros);
  }//else if
}

//-----------------------------Função Principal---------------------------------
int main(int argc, const char *argv[]){
//váriaveis
int qtd_registros;
Heroi *herois;
char sorte,op;

    VerificaParametros(argc);

    FILE *entrada = fopen(argv[1] ,"r");
    FILE *saida =fopen(argv[2],"w");

    VerificaAberturaArquivos(entrada,saida);

    qtd_registros=LeituraCabecalho_E_ContaQtde(entrada,saida,&sorte,&op);

    herois=AlocaStructHeroi(qtd_registros);

    int *vetor=malloc(qtd_registros*sizeof(int));

    Le_E_Grava(entrada,herois,vetor);

    OrdenaVetores(sorte,vetor,qtd_registros,op);

    for(int i=0; i<22; i++){
      for (int j=0; j<22; j++){
        if(vetor[i]==herois[j].indice){
          fprintf(saida,"%d%s",vetor[i],herois[j].dados);
        }
      }
    }

    printf("Arquivo Gerado\n");

    free(vetor);
    free(herois);
    fclose(entrada);
    fclose(saida);
return 0;
}
