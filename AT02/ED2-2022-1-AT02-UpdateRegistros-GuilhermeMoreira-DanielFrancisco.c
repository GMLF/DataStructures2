//Guilherme Moreira Lima Furlaneto  2207192
//Daniel Francisco da Silva    2207141

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----------------------Struct Professor----------------------

typedef struct {
    int id;
    char nome[31];
    char sexo;
    int idade;
    char especialidade[31];
    char telefone[15];
} Professor;

// ----------------------Funções Tamanho Fixo----------------------

void EscreveRegistroFixado(FILE *temporario, Professor professor) {
    // Para escrever código com 3 digitos
    if(professor.id < 10)
        fprintf(temporario, "00");
    else if(professor.id < 100)
        fprintf(temporario, "0");

    fprintf(temporario, "%d|%s", professor.id, professor.nome);

    // Calcula a quantidade de espaços depois do nome (comprimento fixo)
    int espacos = 30 - strlen(professor.nome);
    // Letra com acento ocupa 2 valores, faz isso pra arrumar a quantidade
    //    de espaços necessárias
    // Se tiver 2 ocorrencias de códigos negativos tira um espaço (uma letra)
    //    sendo gerada por 2 codigos
    int contador = 0;
    for(int j = 0 ; professor.nome[j] != '\0'; j++) {
        if(professor.nome[j] < 0)
            contador++;
        if(contador == 2){
            espacos++;
            contador = 0;
        }
    }
    for(int j = 0; j < espacos; j++)
        fputc(' ', temporario);

    fprintf(temporario, "|%c|", professor.sexo);

    // Para escrever a idade 2 digitos
    if(professor.idade < 10)
        fprintf(temporario, "0");

    fprintf(temporario, "%d|%s", professor.idade, professor.especialidade);

    // Calcula a quantidade de espaços depois da especialidade
    espacos = 30 - strlen(professor.especialidade);
    // Mesma coisa de tirar os espaços a mais com a especialidade...
    contador = 0;
    for(int j = 0 ; professor.especialidade[j] != '\0'; j++) {
        if(professor.especialidade[j] < 0)
            contador++;
        if(contador == 2){
            espacos++;
            contador = 0;
        }
    }
    for(int j = 0; j < espacos; j++)
        fputc(' ', temporario);

    fprintf(temporario, "|%s|\n", professor.telefone);
}

// ----------------------Função escrever saída----------------------

void EscreveSaida(FILE *saida, FILE *temporario, int deslocamento) {
    fprintf(saida, "size=%d top=-1\n", deslocamento);

    char buffer[deslocamento+2];
    // Pula a primeira linha
    fgets(buffer, deslocamento+1, temporario);
    char c = fgetc(temporario);
    while(c != EOF) {
        if(c == '*')
            fgets(buffer, deslocamento+1, temporario);    // Ignora a linha
        else
            fputc(c, saida);

        c = fgetc(temporario);
    }
}

// --------------Função Verifica Parametro Entrada----------------------
void VerificaParametro(int argc){
  if(argc != 5) {
      printf("Quantidade inválida de parâmetros! [nome_programa] [arquivo"\
          "_entrada.txt] [arquivo_operacoes.txt] [arquivo_saida"\
          "_temporario.txt] [arquivo_saida]\n");
      exit(1);
  }//if
}

// ---------------Função Verifica Abertura Arquivo----------------------

void VerificaAberturaArquivo(FILE *entrada, FILE *operacao, FILE *temporario, FILE*saida){
  if (entrada == NULL || operacao == NULL || temporario == NULL || saida == NULL) {
      printf("Erro ao abrir um dos arquivos\n");
      exit(1);
  }//if
}

// ----------------------Main----------------------

int main(int argc, char *argv[]) {

    FILE *entrada = fopen(argv[1], "r");
    FILE *operacao = fopen(argv[2], "r");
    FILE *temporario = fopen(argv[3], "w+");
    FILE *saida = fopen(argv[4], "w");


      VerificaParametro(argc);

      VerificaAberturaArquivo(entrada,operacao,temporario,saida);

    // Copia arquivo de entrada pro arquivo de saída temporário e fecha
    // arquivo de entrada
    char c = fgetc(entrada);
    while(c != EOF) {
        fputc(c, temporario);
        c = fgetc(entrada);
    }
    fclose(entrada);

    // Struct para adicionar professores no arquivo
    Professor professor;

    char op;
    int deslocamento;
    int top;

    while(!feof(operacao)) {
        op = fgetc(operacao);
        // Inserir professor
        if(op == 'i') {
            fscanf(operacao, " %d,%[^,],%c,%d,%[^,],%s\n",
                &professor.id, professor.nome, &professor.sexo,
                &professor.idade, professor.especialidade, professor.telefone);

            // Vai para o começo do arquivo pra pegar o top
            fseek(temporario, 0, SEEK_SET);
            fscanf(temporario, "size=%d top=%d\n", &deslocamento, &top);

            if(top == -1) {
                // Escreve no fim do arquivo
                fseek(temporario, 0, SEEK_END);
                EscreveRegistroFixado(temporario, professor);
            } else {
                // Vai até a posição livre
                fseek(temporario, (deslocamento*top)+top, SEEK_CUR);

                // Atualiza a posicao livre
                int top_aux;
                fscanf(temporario, "*%d", &top_aux);
                fseek(temporario, 0, SEEK_SET);
                if(top_aux == -1 || top_aux >= 10)
                    fprintf(temporario, "size=%d top=%d\n", deslocamento, top_aux);
                else
                    fprintf(temporario, "size=%d top=0%d\n", deslocamento, top_aux);

                // Escreve o novo registro
                fseek(temporario, (deslocamento*top)+top, SEEK_CUR);
                EscreveRegistroFixado(temporario, professor);
            }

        // Deletar professor
        } else if(op == 'd') {
            int id;
            fscanf(operacao, " %d\n", &id);

            // Vai para o começo do arquivo pra pegar o top
            fseek(temporario, 0, SEEK_SET);
            fscanf(temporario, "size=%d top=%d\n", &deslocamento, &top);

            // Procura o professor a deletar
            int linha = 0;
            while(!feof(temporario)) {
                // Se linha começar com * ignora a linha pois está deletada
                if(fgetc(temporario) == '*') {
                    char buffer[deslocamento+2];
                    fgets(buffer, deslocamento+1, temporario);
                } else {
                    // Volta um catactere para ler do início da linha
                    fseek(temporario, -1, SEEK_CUR);

                    fscanf(temporario, "%d|%[^|]|%c|%d|%[^|]|%[^|]|\n",
                        &professor.id, professor.nome, &professor.sexo,
                        &professor.idade, professor.especialidade, professor.telefone);
                }

                // Se encontrou faz o que precisa
                if(professor.id == id) {
                    // Coloca do top no começo do registro
                    fseek(temporario, -1*(deslocamento+1), SEEK_CUR);
                    fprintf(temporario, "*%d|", top);

                    // Atualiza o top
                    fseek(temporario, 0, SEEK_SET);
                    if(linha == -1 || linha >= 10)
                        fprintf(temporario, "size=%d top=%d\n", deslocamento, linha);
                    else
                        fprintf(temporario, "size=%d top=0%d\n", deslocamento, linha);

                    break;
                }

                // Atualiza o registro que está lendo (top) (nro_linha - 1)
                linha++;
            }
        } else {
            fprintf(temporario, "Arquivo invalido");
            fprintf(saida, "Arquivo invalido");

            return 0;
        }
    }

    fclose(operacao);

    // Volta para o início do arquivo
    fseek(temporario, 0, SEEK_SET);
    // Salva os dados no arquivo de saída
    EscreveSaida(saida, temporario, deslocamento);

    fclose(temporario);
    fclose(saida);

    return 0;
}
