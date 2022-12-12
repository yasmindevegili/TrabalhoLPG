#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno
{
    int id;
    char nome[100];
} tabela_aluno;

// variaveis globais
tabela_aluno tabelas_alunos[24];
int qtd_alunos=24;
int i;

//função de Relatório
void relatorioAluno()
{
    //acesso ao horário e data
	struct tm *data_hora_atual;
	time_t segundos;
	time(&segundos);
	data_hora_atual = localtime(&segundos);

    printf("_____________________________\n");
    printf("\n");
    printf("-----RELATÓRIO DE ALUNOS-----\n");
    printf("_____________________________\n");
    printf("-----------------------------\n");
    printf("|   ID  |       NOME        |\n");
	for(i=1; i <= qtd_alunos; i++){
		printf("|   %d\t|", tabelas_alunos[i].id);
		printf("      %s\t    |", tabelas_alunos[i].nome);
	}
    printf("\n---------------------------\n");
    printf("______________________________ Gerado em %d/%d/%d %i:%i:%i\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900, data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec);
}

//função de busca por id
void busca()
{
    //variaveis
    int idDigitado;

    printf("\n------BUSCA DE ALUNOS------\n");
    printf("Digite o id do aluno: ");
    scanf("%d", &idDigitado);
    getchar();
    for (i = 1; i <= qtd_alunos; i++)
    {
        if (idDigitado == tabelas_alunos[i].id)
        {
            printf("Aluno: %s\n", tabelas_alunos[i].nome);
        }
        else{
            printf("Aluno não encontrado!\n");
        }
    }
    printf("---------------------------\n");
}

void menu(){

    //variaveis
    int escolha;

    //menu de escolhas
    do
    {
        //acesso ao horário e data
    	struct tm *data_hora_atual;
		time_t segundos;
		time(&segundos);
		data_hora_atual = localtime(&segundos);

    	printf("Acesso ao sistema em %d/%d/%d %i:%i:%i\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900, data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec);
        printf("--Menu Principal--\n");
        printf("--------------------------\n");
        printf("| [1] - Consultar por id |\n| [2] - Relatório        |\n| [3] - Sair             |\n");
        printf("--------------------------\n");
        printf("Escolha a opção acima: ");
        scanf("%i", &escolha);

        switch (escolha)
        {
        case 1:
            busca();
            break;
        case 2:
            relatorioAluno();
            break;
        }
    } while (escolha != 3);
}

// função principal
int main()
{
    // adicionando acentuação
    setlocale(LC_ALL, "");
    
    FILE *entrada;
    char imput[100];
    const char s[2] = ";";
    const char *token;
    
    //abertura da file
    entrada = fopen("registros.txt", "r");

    //lendo linha por linha
    while (fgets(imput, 200, entrada))
    {   
        token = strtok(imput, s);
        printf("%s\n", token);
        tabelas_alunos[i].id = atoi(token);
        token = strtok(NULL, "\n");
        strcpy(tabelas_alunos[i].nome, token);
        i++;
        

    }
   
    menu();
    
    //fechando o arquivo
    fclose(entrada);
}
