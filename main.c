#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //Menu principal
    printf("|-----------------------------------------------|\n");
    printf("|          Bem-vindo ao Projeto Biblion.        |\n");
    printf("| Aqui você pode pesquisar livros na biblioteca |\n"); 
    printf("| e consultar se o livro está disponível ou não.|\n");
    printf("|-----------------------------------------------|\n");
    printf("|        Escolha uma das opções abaixo:         |\n");
    printf("|-----------------------------------------------|\n");
    printf("| 1 - Consulta de livros                        |\n");
    printf("| 2 - Cadastro de livros                        |\n");
    printf("| 3 - Empréstimo de livros                      |\n");
    printf("| 4 - Sair                                      |\n");
    printf("|-----------------------------------------------|\n");

    int MenuPrincipal;
    scanf("%d", &MenuPrincipal);

    //Menu de opções do Menu Principal
    if (MenuPrincipal == 1) //Consulta de livros
    {
        printf("Você escolheu: 1 - Consultar livros. \n");
    }
    else if (MenuPrincipal == 2) //Cadastro de livros
    {
      printf("Você escolheu: 2 - Cadastrar livros. \n");
            
    }
    else if (MenuPrincipal == 3)//Empréstimo de livros
    {
        printf("Você escolheu: 3 - Empréstimo de livros. \n");
   }
    else if (MenuPrincipal == 4)//Sair do programa
    {
        printf("Você escolheu: 4 - Sair. \n");

    }
    else
    {
        printf("Opção inválida. \n");
    }
       
}
