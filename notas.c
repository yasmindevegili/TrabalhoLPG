#include <stdio.h>
#include <string.h>
#include <locale.h>

// struct do aluno
typedef struct aluno
{
    int id;
    char nome[50];
    int excluido;
} tabela_aluno[10];

// struct das notas
typedef struct notas
{
    int id_aluno;
    int id_nota;
    float valor_nota;
} tabela_notas[30];

//--------------------------------------------------------------

// definicao das variaveis globais
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

//[1][5] A FAZER relatorioAluno();

//[1][4]
void alterar()
{
    struct aluno tabela_aluno[10];
    int idDigitado;
    int i;
    int valida;
    char opcao[2];
    char nomeAlterado[50];

    printf("Digite o código do aluno: ");
    scanf("%i", &idDigitado);
    for (i = 0; i < qtd_alunos; i++)
    {
        if ((tabela_aluno[i].excluido == 1) && (tabela_aluno[i].id == idDigitado))
        {
            printf("Aluno não existe! Já foi excluído.");
        }
        else if ((tabela_aluno[i].excluido == 0) && (tabela_aluno[i].id == idDigitado))
        {
            printf("O nome do aluno é: %s\n", tabela_aluno[i].nome);
            printf("Digite um novo nome para o aluno: ");
            scanf("%s", &nomeAlterado);
            printf("Deseja alterar o nome aluno? [S]im ou [N]ão\n");
            fgets(opcao, 2, stdin);

            valida = strcmp(opcao, 'S');
            if (valida == 0)
            {
                nomeAlterado[50] = tabela_aluno[qtd_alunos].nome;
                printf("O nome foi alterado!");
            }
        }
    }
    if (qtd_alunos < idDigitado)
    {
        printf("Nenhum aluno foi cadastrado!\n");
    }
}

//[1][3]
void excluir()
{
    struct aluno tabela_aluno[10];
    int idDigitado;
    int i;
    char opcao[2];
    int valida;

    printf("\n-----Exclusão de Alunos-----\n");
    printf("Digite o código do aluno:\n");
    scanf("%i", &idDigitado);

    if (tabela_aluno[idDigitado].excluido == 1)
    {
        printf("Aluno não existe na base! Já foi excluído.\n");
    }
    else if (idDigitado > qtd_alunos)
    {
        printf("Aluno não existe!\n");
    }
    else
    {
        printf("Deseja excluir o aluno? [S]im ou [N]ão\n");
        getchar();
        fgets(opcao, 2, stdin);

        valida = strcmp(opcao, "S");
        if (valida == 0)
        {
            for (i = 1; i <= qtd_alunos; i++)
            {
                if (tabela_aluno[i].id = idDigitado)
                {
                    tabela_aluno[i].excluido = 1;
                    printf("O aluno foi excluído!\n");
                    printf("%i\n", tabela_aluno[i].excluido);
                }
            }
        }
        else
        {
            printf("Retornando ao menu aluno...\n");
        }
    }
    printf("----------------------------\n");
}

//--------------------------------------------------------------

//[1][2]
void busca()
{
    struct aluno tabela_aluno[10];
    int idDigitado;
    int i;

    printf("\n------Busca de Alunos------\n");
    printf("Digite o id do aluno: ");
    scanf("%i", &idDigitado);
    getchar();

    // printf("%i", tabela_aluno[idDigitado].excluido);
    for (i = 1; i <= qtd_alunos; i++)
    {
        if (tabela_aluno[idDigitado].id != idDigitado)
        {
            printf("Aluno não existe!\n");
        }
        else if ((tabela_aluno[i].excluido == 1) && (tabela_aluno[i].id == idDigitado))
        {
            printf("Aluno não existe! Já foi excluído\n");
        }
        else if ((tabela_aluno[i].excluido == 0) && (tabela_aluno[i].id == idDigitado))
        {
            printf("O nome do aluno é: %s", tabela_aluno[idDigitado].nome);
        }
    }
    if (qtd_alunos == 0)
    {
        printf("Nenhum aluno foi cadastrado!\n");
    }
    printf("---------------------------\n");
}

//--------------------------------------------------------------

//[1][1]
void cadastro()
{
    struct aluno tabela_aluno[10];
    qtd_alunos++;
    tabela_aluno[qtd_alunos].id = qtd_alunos;
    tabela_aluno[qtd_alunos].excluido = 0;

    printf("\n------Cadastro de Alunos------\n");
    printf("Código do aluno: %i\n", qtd_alunos);

    do
    {
        printf("Digite o nome do aluno: ");
        fgets(tabela_aluno[qtd_alunos].nome, 50, stdin);

        if (strlen(tabela_aluno[qtd_alunos].nome) <= 4) // Vericacao do tamanho do imput
        {
            printf("O nome que você digitou é inválido! Por favor insira um nome válido.\n");
        }

    } while (strlen(tabela_aluno[qtd_alunos].nome) <= 4);

    printf("\n-Aluno cadastrado com sucesso!-\n\n");
}

//--------------------------------------------------------------

//[1]
int aluno()
{
    struct aluno tabela_aluno[10];
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
            // alterar();
            break;
        case 5:
            // relatorioAluno();
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
            // notas();
            break;
        case 3:
            // relatorio();
            break;
        }
    } while (escolha != 4);
    return 0;
}
