/*
Menu Principal e Submenus:
    1 - Consulta de livros
        Consultar livro por Título
        Consultar livro por Autor
        Consultar livro por Código ISBN
        Retorna ao Menu principal

    2 - Cadastro de livros
        1- Aparece uma mensagem de aviso dos dados que serão necessários para a realização do cadastro do livro, os dados são os mesmos apresentados na opção 1.
        2- Ao final do cadastro o sistema mostrará uma mensagem perguntando se o usuário quer cadastrar um novo livro ou retornar ao menu principal.

    3 - Empréstimo de livros
        1- aparecerá no sistema uma mensagem pedindo que o usuário digite o email, digitar o código ISBN do livro a ser emprestado
            1- Se o livro estiver disponível registrar o empréstimo 
               i. e perguntar se o usuário deseja pegar outro livro
               ii. ou retornar ao menu principal.
            2 - Caso o livro não esteja disponível, o sistema informa que o livro não está disponível e volta para o menu principal.

    4 Relatórios de livros
        1 - Relatório de livros disponíveis
        2 - Relatório de livros emprestados
        3 - Relatório de livros atrasados
        4 - Voltar ao menu principal.

    5 - Sair = programa se encerra

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Definição da estrutura para os livros
typedef struct listaLivros
{
    char titulo[100];
    char autor[100];
    char ISBN[100];
    int codigo;
} Livro;

// Vetor de livros com capacidade para 150 livros
struct listaLivros livros[150];

// Função para o Menu Principal
void MenuPrincipal()
{
    printf("|-----------------------------------------------|\n");
    printf("|          Bem-vindo ao Projeto Biblion.        |\n");
    printf("| Aqui você pode pesquisar livros na biblioteca |\n");
    printf("| e consultar se o livro está disponível ou não.|\n");
    printf("|-----------------------------------------------|\n");
    printf("|        Escolha uma das opções abaixo:         |\n");
    printf("|-----------------------------------------------|\n");
    printf("|           1 - Consulta de livros              |\n");
    printf("|           2 - Cadastro de livros              |\n");
    printf("|           3 - Empréstimo de livros            |\n");
    printf("|           4 - Relatórios de livros            |\n");
    printf("|           5 - Sair                            |\n");
    printf("|-----------------------------------------------|\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese"); // acentos funcionando

    int opcaoMenuPrincipal;

    do
    {
        MenuPrincipal();
        scanf("%d", &opcaoMenuPrincipal);
    } while (opcaoMenuPrincipal < 1 || opcaoMenuPrincipal > 5);
    // Cadastro de livros
    int numLivrosCadastrados = 0;
    int opcaoCadastrar;

    // Relatórios de livros
    int opcaoRelatorios;

    if (opcaoMenuPrincipal == 1) // Consulta de livros
    {
        int opcaoConsultar;
        printf("|-----------------------------------------------|\n");
        printf("|       Você escolheu: 1 - Consultar livros.    |\n");
        printf("|-----------------------------------------------|\n");
        printf("|        Digite o número da opção desejada:     |\n");
        printf("|-----------------------------------------------|\n");
        printf("|         1 - Consultar livro por Título        |\n");
        printf("|         2 - Consultar livro por Autor         |\n");
        printf("|         3 - Consultar livro por Código ISBN   |\n");
        printf("|         4 - Voltar ao menu principal          |\n");
        printf("|-----------------------------------------------|\n");
        scanf("%d", &opcaoConsultar);

        for (int i = 0; i < opcaoConsultar; i++)
        {
            scanf("%s", livros[numLivrosCadastrados].titulo);
            printf("|-----------------------------------------------|\n");
            printf("|   O livro está disponível para empréstimo.    |\n");
            printf("|         Deseja consultar outro livro?         |\n");
            printf("|-----------------------------------------------|\n");
            printf("|     1 - Sim, quero consultar outro livro.     |\n");
            printf("|     2 - Não. Voltar ao menu principal         |\n");
            printf("|-----------------------------------------------|\n");
            scanf("%d", &opcaoConsultar);
            while (opcaoConsultar == 1)
            {
                // return opcaoConsultar;
            }
            while (opcaoConsultar == 2)
            {
                MenuPrincipal();
            }
        }
        for (int i = 1; i < opcaoConsultar; i++)
        {
            printf("Digite o nome do autor do livro que deseja consultar: \n");
            scanf("%s", livros[numLivrosCadastrados].autor);
            // logica para ser implementada
            //  if(livros nao existe?)
            //  {
            //      printf("Livro não encontrado. \n");
            //  }
            //  else if(livro existe && livro está disponível)
            //  {
            //      printf("O livro está disponível para empréstimo. \n");
            //  }
            //  else if(livro existe && livro não está disponível)
            //  {
            //      printf("O livro não está disponível para empréstimo. \n");
            //  }
            printf("O livro está disponível para empréstimo. \n");
            printf("Deseja consultar outro livro? \n");
            printf("1 - Sim \n");
            printf("2 - Não. Voltar ao menu principal \n");
            scanf("%d", &opcaoConsultar);
            while (opcaoConsultar == 1)
            {
                // return opcaoConsultar;
            }
            while (opcaoConsultar == 2)
            {
                MenuPrincipal();
            }
        }
        for (int i = 2; i < opcaoConsultar; i++)
        {

            printf("O livro está disponível para empréstimo. \n");
            printf("Deseja consultar outro livro? \n");
            printf("1 - Sim \n");
            printf("2 - Não. Voltar ao menu principal \n");
            scanf("%d", &opcaoConsultar);
            while (opcaoConsultar == 1)
            {
                // return opcaoConsultar;
            }
            while (opcaoConsultar == 2)
            {
                MenuPrincipal();
            }
        }
        for (int i = 3; i < opcaoConsultar; i++)
        {
            printf("Digite o código ISBN do livro que deseja consultar: \n");
            scanf("%s", livros[numLivrosCadastrados].ISBN);
            printf("O livro está disponível para empréstimo. \n");
            printf("Deseja consultar outro livro? \n");
            printf("1 - Sim \n");
            printf("2 - Não. Voltar ao menu principal \n");
            scanf("%d", &opcaoConsultar);
            while (opcaoConsultar == 1)
            {
                // return opcaoConsultar;
            }
            while (opcaoConsultar == 2)
            {
                MenuPrincipal();
            }
        }
        for (int i = 4; i < opcaoConsultar; i++)
        {
            MenuPrincipal();
        }
    }
    else if (opcaoMenuPrincipal == 2) // Cadastro de livros
    {
        int opcaoCadastrar;

        printf("Você escolheu: 2 - Cadastrar livros. \n");
        printf("Para cadastro de livros precisaremos de algumas informações, como titulo, autor e ISBN. \n");
        printf("Digite o nome do livro que deseja cadastrar: \n");
        scanf("%s", livros[numLivrosCadastrados].titulo);
        printf("Digite o nome do autor do livro que deseja cadastrar: \n");
        scanf("%s", livros[numLivrosCadastrados].autor);
        printf("Digite o ISBN do livro que deseja cadastrar: \n");
        scanf("%s", livros[numLivrosCadastrados].ISBN);
        numLivrosCadastrados++;
        printf("Livro cadastrado com sucesso! \n");
        printf("Deseja cadastrar outro livro? \n");
        printf("1 - Sim \n");
        printf("2 - Não. Voltar ao menu principal \n");
        scanf("%d", &opcaoCadastrar);
        while (opcaoCadastrar == 1)
        {
            return opcaoCadastrar;
        }
        while (opcaoCadastrar == 2)
        {
            return MenuPrincipal;
        }
    }
    else if (opcaoMenuPrincipal == 3) // Empréstimo de livros
    {
        // fluxo de empréstimo de livros para ser implementado
        printf("Você escolheu: 3 - Empréstimo de livros. \n");
    }
    else if (opcaoMenuPrincipal == 4) // Relatórios de livros
    {
        // fluxo de relatórios de livros para ser implementado
        printf("Você escolheu: 4 - Relatórios de livros \n");
        printf("Digite o número da opção desejada: \n");
        printf("1 - Relatório de livros disponíveis \n");
        printf("2 - Relatório de livros emprestados \n");
        printf("3 - Relatório de livros atrasados \n");
        scanf("%d", &opcaoRelatorios);
    }
    else if (opcaoMenuPrincipal == 5) // Sair do programa
    {
        printf("Você escolheu: 5 - Sair. \n");
    }
    else
    {
        printf("Opção inválida. \n");
    }
    
    return 0;
}