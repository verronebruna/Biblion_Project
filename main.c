#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>
typedef struct lista_livros
    {
        char titulo[100];
        char autor[100];
        char genero[100];
        char ISBN[100];
        int anoPublicacao, codigo;


    };
    struct lista_livros livros[150]; // Criando um vetor de livros com capacidade para 150 livros



int main() {
     int opcao=1;
    do{
setlocale(LC_ALL, "Portuguese");//acentos funcionando
    //Menu principal
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

    int MenuPrincipal;
    scanf("%d", &MenuPrincipal);

    //Cadastro de livros
    int numLivrosCadastrados = 0;
    int opcaoCadastrar;

    //Relatórios de livros
    int opcaoRelatorios;

     //Menu de opções do Menu Principal
    if (MenuPrincipal == 1) //Consulta de livros
    {
        int opcaoConsultar;
        printf("Você escolheu: 1 - Consultar livros. \n");
        printf("Digite o número da opção desejada: \n");
        printf("1 - Consultar livro por título \n");
        printf("2 - Consultar livro por autor \n");
        printf("3 - Consultar livro por gênero \n");
        printf("4 - Consultar livro por código ISBN \n");
        printf("5 - Voltar ao menu principal \n");
        scanf("%d", &opcaoConsultar);

        switch(opcaoConsultar)
        {

          case 1:
              do{
            printf("Digite o título do livro que deseja consultar: \n");
            scanf("%s", livros[numLivrosCadastrados].titulo);
            printf("O livro está disponível para empréstimo. \n");
            printf("Deseja consultar outro livro? \n");
            printf("1 - Sim \n");
            printf("2 - Não. Voltar ao menu principal \n");
            scanf("%d", &opcao);}
            while(opcao==1);
            break;


        case 2:
            do{
            printf("Digite o nome do autor do livro que deseja consultar: \n");
            scanf("%s", livros[numLivrosCadastrados].autor);
            //logica para ser implementada
            // if(livros nao existe?)
            // {
            //     printf("Livro não encontrado. \n");
            // }
            // else if(livro existe && livro está disponível)
            // {
            //     printf("O livro está disponível para empréstimo. \n");
            // }
            // else if(livro existe && livro não está disponível)
            // {
            //     printf("O livro não está disponível para empréstimo. \n");
            // }
            printf("O livro está disponível para empréstimo. \n");
            printf("Deseja consultar outro livro? \n");
            printf("1 - Sim \n");
            printf("2 - Não. Voltar ao menu principal \n");
            scanf("%d", &opcao);}
            while(opcao==1);
            break;

        case 3:
do{
            printf("Digite o gênero do livro que deseja consultar: \n");
            scanf("%s", livros[numLivrosCadastrados].genero);
            printf("O livro está disponível para empréstimo. \n");
            printf("Deseja consultar outro livro? \n");
            printf("1 - Sim \n");
            printf("2 - Não. Voltar ao menu principal \n");
            scanf("%d", &opcao);}
            while(opcao==1);
            break;

        case 4:
do{
            printf("Digite o código ISBN do livro que deseja consultar: \n");
            scanf("%s", livros[numLivrosCadastrados].ISBN);
            printf("O livro está disponível para empréstimo. \n");
            printf("Deseja consultar outro livro? \n");
            printf("1 - Sim \n");
            printf("2 - Não. Voltar ao menu principal \n");
            scanf("%d", &opcao);}
            while(opcao==1);
            break;

             case 5:
            opcao=2;

            break;


    }
}    else if (MenuPrincipal == 2) //Cadastro de livros
    {do{
        printf("Você escolheu: 2 - Cadastrar livros. \n");
        printf("Para cadastro de livros precisaremos de algumas informações, como titulo, autor, gênero e ISBN. \n");
            printf("Digite o nome do livro que deseja cadastrar: \n");
            scanf("%s", livros[numLivrosCadastrados].titulo);
            printf("Digite o nome do autor do livro que deseja cadastrar: \n");
            scanf("%s", livros[numLivrosCadastrados].autor);
            printf("Digite o gênero do livro que deseja cadastrar: \n");
            scanf("%s", livros[numLivrosCadastrados].genero);
            printf("Digite o ISBN do livro que deseja cadastrar: \n");
            scanf("%s", livros[numLivrosCadastrados].ISBN);
            numLivrosCadastrados++;
            printf("Livro cadastrado com sucesso! \n");
            printf("Deseja cadastrar outro livro? \n");
            printf("1 - Sim \n");
            printf("2 - Não. Voltar ao menu principal \n");
            scanf("%d", &opcao);}
            while(opcao==1);


    }
    else if (MenuPrincipal == 3)//Empréstimo de livros
    {
        //fluxo de empréstimo de livros para ser implementado
        printf("Você escolheu: 3 - Empréstimo de livros. \n");
   }
   else if (MenuPrincipal == 4)//Relatórios de livros
    {
        //fluxo de relatórios de livros para ser implementado
        printf("Você escolheu: 4 - Relatórios de livros \n");
        printf("Digite o número da opção desejada: \n");
        printf("1 - Relatório de livros disponíveis \n");
        printf("2 - Relatório de livros emprestados \n");
        printf("3 - Relatório de livros atrasados \n");
        scanf("%d", &opcaoRelatorios);

    }
    else if (MenuPrincipal == 5)//Sair do programa
    {
        printf("Você escolheu: 5 - Sair. \n");
        opcao=1;

    }
    else
    {
        printf("Opção inválida. \n");
    }

}while(opcao != 1);}
