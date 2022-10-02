#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
/*
@Guilherme Moreira Lima Furlaneto     Ra 2207192
@Daniel Francisco                     Ra 2207141
*/

unsigned long bubble_sort(int array[], int n) {
  unsigned long comparacoes = 0;

    bool changed = true;
    while(changed) {
        changed = false;
        for(int i = 0; i < n-1; i++) {
            // Cada vez que entra no segundo for acontece uma comparação entre os elementos do vetor
            comparacoes++;
            if(array[i] > array[i+1]) {
                int aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                changed = true;
            }
        }
    }
    return comparacoes;
}//bubbleSort

//----------------------------Selection Sort------------------------------------
unsigned long SelectionSort(int vetor[],int tam,char op){
  int aux,menor;
  unsigned long comparacoes = 0;

    for(int i=0; i<tam-1; i++){
      menor=i;
      for(int j=i+1; j<tam ;j++){
        if(op=='c'|| op=='r'){
          comparacoes++;
        if(vetor[j]<vetor[menor]){
          menor=j;
        }//if
      }else if(op=='d'){
        if(vetor[j]>vetor[menor]){
          menor=j;
        }//if
      }//else
    }//for interno
    comparacoes++;
    if(i!=menor){
      aux=vetor[i];
      vetor[i]=vetor[menor];
      vetor[menor]=aux;
    }//if
  }//for externo

  return comparacoes;
}//SelectionSort

//----------------------------Insertion Sort------------------------------------
unsigned long InsertionSort(int vetor[], int tam){
  int aux,j;
  unsigned long comparacoes = 0;

    for(int i=1; i<tam; i++){
      aux=vetor[i];
      j=i-1;
      while(j>=0 && (aux < vetor[j])){
          comparacoes++;
          vetor[j+1]=vetor[j];
          j=j-1;
      }//while
     vetor[j+1]=aux;
    }//for externo
    return comparacoes;
}//InsertionSort

//-----------------------------Função Merge-------------------------------------
void Merge( int vetor[], int inicio, int meio, int fim,unsigned long *comparacoes){
    //vetor auxiliar que irá ter a região alocada igual a do vetor principal
    int *vet;
    //tamanhodo vetor             //váriavel auxiliar que recebe a posição de inicio do vetor, para criar subvetores a esquerda
    int tamanho;                  int p1=inicio;
    //váriavel que recebe a onde o vetor quebra, para criar subvetores a direita
    int p2=meio+1;
    //contador auxiliar
    int k;

      tamanho=(fim-inicio)+1;
      vet=(int*)malloc(tamanho*sizeof(int));
      //  vet=Aloca(vet,tamanho);

  //enquanto o vetor auxiliar for diferente de nulo, faça
  if(vet!=NULL){
        //for rodando de 0 até o tamanho
        for(int i=0; i<tamanho; i++){

        //enquanto o inicio foi menor ou igual ao meio e o meio foi menor ou igual ao fim, faça
         if((p1<=meio) && (p2<=fim)){
            // Única comparação entre os elementos do vetor
             *comparacoes = *comparacoes + 1;
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

//---------------------------Função MergeSort---------------------------------
void MergeSort(int vetor[],int inicio ,int fim, unsigned long *comparacoes){
    int meio;

      if(inicio<fim){
        //encontrando sempre o meio do vetor e dos subvetores
        meio=((inicio+fim)/2);
        //passando o inicio e meio para realizar a quebra do lado esquerdo
        MergeSort(vetor,inicio,meio,comparacoes);
        //passando o meio+1 e fim para realizar a quebra do vetor do lado direito
        MergeSort(vetor,meio+1,fim,comparacoes);
        //chamando a merge para re-organizar os subvetores em um vetor unitario
        Merge(vetor,inicio,meio,fim,comparacoes);
      }//if
}//MergeSort

//-----------------------------Função Quick-----------------------------------
int Quick(int *v, int inicio, int fim,unsigned long *comparacoes){
    int Esq = inicio;
    int Dir = fim;
    int Pivo =v[inicio];
    int aux;

      while(Esq<Dir){

        while(v[Esq]<=Pivo && Esq<=fim){
          // Comparações para encontrar o elemento maior que o pivo
          *comparacoes = *comparacoes + 1;
          Esq++;
        }//while interno

        while(v[Dir]>Pivo && Dir>=inicio){
          // Comparações para encontrar o elemento menor que o pivo
          *comparacoes = *comparacoes + 1;
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
      v[inicio]=aux;

   return Dir;
 }//Quick

  //---------------------------Função QuickSort---------------------------------
void QuickSort(int *v, int inicio, int fim,unsigned long *comparacoes){
    int pivo;

      if(inicio<fim){
        pivo=Quick(v,inicio,fim,comparacoes);
      //  ExibeVetor(v,fim);
        QuickSort(v,inicio,pivo-1,comparacoes);
        QuickSort(v,pivo+1,fim,comparacoes);
      }//if

}//QuickSort

  //---------------------------------Função Cria Heap---------------------------
void criaHeap(int *vet,int pai, int fim,unsigned long *comparacoes){
    int aux=vet[pai];
    int filho=pai*2+1;

      while(filho<=fim){
          if(filho<fim){
            if((vet[filho]) < (vet[filho+1])){
              *comparacoes=*comparacoes+1;
              filho++;
            }//if interno
          }//if externo

          if(aux<vet[filho]){
            *comparacoes=*comparacoes+1;
            vet[pai]=vet[filho];
            pai=filho;
            filho=pai*2+1;
          }else{
            filho=fim+1;
          }//else
      }//while
      vet[pai]=aux;
}//criaHeap

  //---------------------------------Função Heap Sort---------------------------
void heapSort(int *vet, int tam,unsigned long *comparacoes){
    int aux;

      for(int i=(tam-1)/2; i>=0; i--){
        criaHeap(vet,i,tam-1,comparacoes);
      }//for

      //balanceando o heap para remover a raiz e organizar o vetor
      for(int i=tam-1; i>=1; i--){
        aux=vet[0];
        vet[0]=vet[i];
        vet[i]=aux;
        criaHeap(vet,0,i-1,comparacoes);
      }//for
}//heapSort

  //-------------------------Função Verifica Arquivo----------------------------
void verificaArquivo(FILE *entrada,FILE *saida){
    if(entrada==NULL || saida==NULL){
      printf("Erro na abertura de um dos arquivos\n");
      exit(1);
    }
}//verificaArquivo

//----------------------------Função leArquivo----------------------------------
void leArquivo(FILE *entrada, int *valor, char *op,FILE *saida){
      fscanf(entrada,"%d %c",valor,op);

      (*op)=tolower(*op);

      if((*op)!='c' && (*op)!='d' && (*op)!='r'){
          fprintf(saida,"Arquivo Inválido!\n");
          fclose(saida);
          exit(1);
        }//if
}//leArquivo

//----------------------------Função Preenche Vetor-----------------------------
void preencheVetor(int bubble[],int selection[],int insertion[],int merge[],int quick[],int heap[],int tamanho, char op,  FILE *saida){

  srand(time(NULL));
  int aux;


  if(op=='d'){
    for(int i=0; i<tamanho; i++){
      bubble[i]=i+1;
      selection[i]=i+1;
      insertion[i]=i+1;
      merge[i]=i+1;
      quick[i]=i+1;
      heap[i]=i+1;
    }//for
  }else if(op=='c'){
    for(int i=tamanho; i>=0; i--){
      bubble[i]=i+1;
      selection[i]=i+1;
      insertion[i]=i+1;
      merge[i]=i+1;
      quick[i]=i+1;
      heap[i]=i+1;
    }//for
  }else if(op=='r'){
    for(int i=0; i<tamanho; i++){
      aux=rand()%32000+1;

      bubble[i]=aux;
      selection[i]=aux;
      insertion[i]=aux;
      merge[i]=aux;
      quick[i]=aux;
      heap[i]=aux;
    }//for
  }else{
    fprintf(saida,"Arquivo Inválido!\n");
  }//else
}//preencheVetor

//--------------------------Função Printa Vetor Arquivo-------------------------
void printaVetor(FILE *saida, int *vetor, int valor,char op){
  if(op=='d'|| op=='r'||op=='c'){
    for(int i=0; i<valor; i++){
      fprintf(saida," %d",vetor[i]);
    }
  }/*else if(op=='c'){
    for(int i=valor-1; i>=0; i--){
      fprintf(saida," %d",vetor[i]);
    }//for
  }//else if*/
}//printaVetor

//---------------------------Função Gera Arquivo--------------------------------
void preencheArquivo(int bubble[],int selection[],int insertion[],int merge[],int quick[],int heap[],FILE *saida, int valor,char op){
  unsigned long comparacoes;
  clock_t start_time;
  int time_taken_millis;


  fprintf(saida,"InsertionSort:");
  start_time=clock();
  comparacoes=InsertionSort(insertion,valor);
  time_taken_millis=(int)((clock()-start_time)*1E3/CLOCKS_PER_SEC);
  printaVetor(saida,insertion,valor,op);
  fprintf(saida,", %lu comp",comparacoes);
  fprintf(saida,", %d ms\n",time_taken_millis);


  fprintf(saida,"SelectionSort: ");
  start_time=clock();
  comparacoes=SelectionSort(selection,valor,op);
  time_taken_millis=(int)((clock()-start_time)*1E3/CLOCKS_PER_SEC);
  printaVetor(saida,selection,valor,op);
  fprintf(saida,", %lu comp",comparacoes);
  fprintf(saida,", %d ms\n",time_taken_millis);


  fprintf(saida,"BubbleSort: ");
  start_time = clock();
  comparacoes=bubble_sort(bubble,valor);
  time_taken_millis=(int)((clock()-start_time)*1E3/CLOCKS_PER_SEC);
  printaVetor(saida,bubble,valor,op);
  fprintf(saida,", %lu comp",comparacoes);
  fprintf(saida,", %d ms\n",time_taken_millis);


  fprintf(saida,"MergeSort: ");
  start_time = clock();
  comparacoes=0;
  MergeSort(merge,0,valor-1,&comparacoes);
  printaVetor(saida,merge,valor,op);
  fprintf(saida,", %lu comp",comparacoes);
  fprintf(saida,", %d ms\n",time_taken_millis);

  fprintf(saida,"QuickSort: ");
  start_time = clock();
  comparacoes=0;
  QuickSort(quick,0,valor-1,&comparacoes);
  printaVetor(saida,quick,valor,op);
  fprintf(saida,", %lu comp",comparacoes);
  fprintf(saida,", %d ms\n",time_taken_millis);

  fprintf(saida,"HeapSort: ");
  start_time = clock();
  comparacoes=0;
  heapSort(heap,valor,&comparacoes);
  printaVetor(saida,heap,valor,op);
  fprintf(saida,", %lu comp",comparacoes);
  fprintf(saida,", %d ms\n",time_taken_millis);
}

//--------------------------Função Verifica Parametros--------------------------
void verificaParametro(int argc){
  if(argc!=3){
    printf("Parametros Errados\n");
    exit(1);
  }//if
}//verificaParametro
//----------------------------Função Principal----------------------------------
int main(int argc, const char *argv[]){
  //váriaveis
  int valor;
  char op;
  int *bubble,*selection,*insertion,*merge,*quick,*heap;

      verificaParametro(argc);

      FILE *entrada= fopen(argv[1],"r");
      FILE *saida =fopen(argv[2],"w");


     verificaArquivo(entrada,saida);

      leArquivo(entrada,&valor,&op,saida);


      bubble=   (int*) malloc(valor * sizeof(int));
      selection=(int*) malloc(valor * sizeof(int));
      insertion=(int*) malloc(valor * sizeof(int));
      merge=    (int*) malloc(valor * sizeof(int));
      quick=    (int*) malloc(valor * sizeof(int));
      heap=    (int*) malloc(valor * sizeof(int));



      preencheVetor(bubble,selection,insertion,merge,quick,heap,valor,op,saida);

      preencheArquivo(bubble,selection,insertion,merge,quick,heap,saida,valor,op);


    free(bubble);
    free(selection);
    free(insertion);
    free(merge);
    free(quick);
    free(heap);
    fclose(entrada);
    fclose(saida);
  return 0;
}
