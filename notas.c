#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>

// struct do aluno
typedef struct aluno
{
    int id;
    char nome[50];
    int excluido;
} tabela_aluno;

// struct das notas
typedef struct notas
{
    int id_aluno;
    int id_nota;
    float valor_nota;
} tabela_notas;

//--------------------------------------------------------------

// definicao das variaveis globais

tabela_aluno tabelas_alunos[10];
tabela_notas tabelas_notas[30];
int qtd_alunos = 0;
int escolha;

//--------------------------------------------------------------

//[3]
float relatorio()
{
    do
    {
        printf("Escolha uma opcao abaixo:\n");
        printf("[1] - Relatorio de notas\n[2] - Relatorio de medias\n[3] - Voltar\n");
        scanf("%i", &escolha);
        switch (escolha)
        {
        case 1:
            // relatorioNotas();
            break;

        case 2:
            // relatorioMedias();
            break;
        }
    } while (escolha != 3);
}

//--------------------------------------------------------------

//[2]
int notas()
{
    do
    {
        printf("Escolha a opcao abaixo:");
        printf("[1] - Incluir nota do aluno\n[2] - Alterar nota do aluno\n[3] - Excluir nota do aluno\n[4] - Consultar notas do aluno\n[5] - Voltar\n");
        scanf("%i", &escolha);
        switch (escolha)
        {
        case 1:
            // incluirNota();
            break;
        case 2:
            // alterarNota();
            break;
        case 3:
            // excluirNota();
            break;
        case 4:
            // consultarNota();
            break;
        }
    } while (escolha != 5);
}

//--------------------------------------------------------------

//[1][5]
int relatorioAluno()
{
}

//--------------------------------------------------------------

//[1][4]
void alterar()
{
    int i, idDigitado;
    char opcao[2];
    char nomeAlterado[50];

    printf("\n-----ALTERAÇÃO DE ALUNO-----\n");
    printf("Digite o código do aluno: ");
    scanf("%i", &idDigitado);
    getchar();
    for (i = 1; i <= qtd_alunos; i++)
    {
        if ((idDigitado == tabelas_alunos[i].id) && (tabelas_alunos[i].excluido == 0))
        {
            printf("Aluno: %s\nNovo nome: ", tabelas_alunos[i].nome);
            fgets(nomeAlterado, 50, stdin);
            printf("Tem certeza que deseja alterar? [S]im ou [N]ão\n");
            
            fgets(opcao, 2, stdin);
            getchar();
            opcao[0] = toupper(opcao[0]);
            if (strcmp(opcao, "S") == 0)
            {
                strcpy(tabelas_alunos[i].nome, nomeAlterado);
                printf("\n---Nome alterado com sucesso!---\n");
            }
            else if (strcmp(opcao, "N") == 0)
            {
                printf("Operação cancelada! Retornando ao menu aluno.\n");
            }
            else if ((tabelas_alunos[i].excluido == 1) && (idDigitado == tabelas_alunos[i].id))
            {
                printf("Aluno não existe na base! Retornando ao menu do aluno.\n");
            }
        }
    }
    if ((qtd_alunos == 0) || (idDigitado > qtd_alunos))
    {
        printf("Aluno não cadastrado! Retornando ao menu do aluno.\n");
    }
    printf("---------------------------\n");
}

//--------------------------------------------------------------

//[1][3]
int excluir()
{
    int i, idDigitado, valida;
    char opcao[2];

    printf("\n-----EXCLUSÃO DE ALUNO-----\n");
    printf("Digite o código do aluno: ");
    scanf("%i", &idDigitado);
    for (i = 1; i <= qtd_alunos; i++)
    {
        if ((idDigitado == tabelas_alunos[i].id) && (tabelas_alunos[i].excluido == 0))
        {
            printf("Tem certeza que deseja excluir? [S]im ou [N]ão\n");
            getchar();
            fgets(opcao, 2, stdin);
            opcao[0] = toupper(opcao[0]);
            if (strcmp(opcao, "S") == 0)
            {
                tabelas_alunos[i].excluido = 1;
                printf("---Aluno deletado com sucesso!---\n");
            }
            else
            {
                printf("Operação cancelada! Retornando ao menu aluno.\n");
            }
        }
    }
    if ((qtd_alunos == 0) || (idDigitado > qtd_alunos) || (tabelas_alunos[i].id == 1))
    {
        printf("Aluno não cadastrado! Retornando ao menu do aluno.\n");
    }
    printf("---------------------------\n");
}

//--------------------------------------------------------------

//[1][2]
void busca()
{
    int i, idDigitado;

    printf("\n------BUSCA DE ALUNOS------\n");
    printf("Digite o id do aluno: ");
    scanf("%i", &idDigitado);
    getchar();
    for (i = 1; i <= qtd_alunos; i++)
    {
        if ((idDigitado == tabelas_alunos[i].id) && (tabelas_alunos[i].excluido == 0))
        {
            printf("Aluno: %s", tabelas_alunos[i].nome);
        }
        else if ((tabelas_alunos[i].excluido == 1) && (idDigitado == tabelas_alunos[i].id))
        {
            printf("Aluno não existe na base! Retornando ao menu do aluno.\n");
        }
    }
    if ((qtd_alunos == 0) || (idDigitado > qtd_alunos))
    {
        printf("Aluno não cadastrado! Retornando ao menu do aluno.\n");
    }
    printf("---------------------------\n");
}

//--------------------------------------------------------------

//[1][1]
void cadastro()
{
    qtd_alunos++;
    tabelas_alunos[qtd_alunos].id = qtd_alunos;

    printf("\n------CADASTRO DE ALUNOS------\n");
    printf("Código do aluno: %i\n", qtd_alunos);
    do
    {
        printf("Digite o nome do aluno: ");
        fgets(tabelas_alunos[qtd_alunos].nome, 50, stdin);
        if (strlen(tabelas_alunos[qtd_alunos].nome) <= 4)
        {
            printf("O nome digitado é inválido. Tente novamente.\n");
        }
    } while (strlen(tabelas_alunos[qtd_alunos].nome) <= 4);
    tabelas_alunos[qtd_alunos].excluido = 0; // ativação do cadastro
    printf("\n-Aluno cadastrado com sucesso!-\n");
    printf("---------------------------\n");
}

//--------------------------------------------------------------

//[1]
int aluno()
{
    do
    {
        printf("\n");
        printf("---Menu do Aluno---\n");
        printf("-------------------\n");
        printf("| [1] - Cadastrar |\n| [2] - Consultar |\n| [3] - Excluir   |\n| [4] - Alterar   |\n| [5] - Relatório |\n| [6] - Voltar    |\n");
        printf("-------------------\n");
        printf("Escolha a opção acima: ");
        scanf("%i", &escolha);
        getchar();

        switch (escolha)
        {
        case 1:
            cadastro();
            break;
        case 2:
            busca();
            break;
        case 3:
            excluir();
            break;
        case 4:
            alterar();
            break;
        case 5:
            relatorioAluno();
            break;
        }
    } while (escolha != 6);
}

//--------------------------------------------------------------

// Codigo principal que chama as funcoes
int main()
{
    setlocale(LC_ALL, ""); // acentuacao

    do
    {
        printf("--Menu Principal--\n");
        printf("------------------\n");
        printf("| [1] - Aluno     |\n| [2] - Notas     |\n| [3] - Relatório |\n| [4] - Sair      |\n");
        printf("------------------\n");
        printf("Escolha a opção acima: ");
        scanf("%i", &escolha);

        switch (escolha)
        {
        case 1:
            aluno();
            break;
        case 2:
            notas();
            break;
        case 3:
            relatorio();
            break;
        }
    } while (escolha != 4);
    return 0;
}
