#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct lista_livros
{
    char titulo[100];
    char autor[100];
    char ISBN[100];
    int disponivel;
    int emprestado;
} livro;

livro livros[150];

void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

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
    setlocale(LC_ALL, "Portuguese"); 

    int opcaoMenuPrincipal;
    int opcaoCadastrar;
    int opcaoRelatorios;
    int opcaoConsultar;
    int opcaoEmprestimo;
    int encontrado = 0;
    char isbnfornecido[150];
    int numLivrosCadastrados = 0;

    do
    {
        MenuPrincipal();
        scanf("%d", &opcaoMenuPrincipal);
        switch (opcaoMenuPrincipal)
        {
        case 1:
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
            int encontrado = 0;

            switch (opcaoConsultar)
            {
            case 1:
                printf("Digite o título do livro que deseja consultar: \n");
                limparBufferEntrada();
                char tituloConsulta[100];
                fgets(tituloConsulta, sizeof(tituloConsulta), stdin);
                tituloConsulta[strcspn(tituloConsulta, "\n")] = 0; 

                for (int i = 0; i < numLivrosCadastrados; i++)
                {
                    if (strcmp(livros[i].titulo, tituloConsulta) == 0)
                    {
                        printf("Livro encontrado - Título: %s, Autor: %s, ISBN: %s\n", livros[i].titulo, livros[i].autor, livros[i].ISBN);
                        encontrado = 1;
                    }
                }

                if (!encontrado)
                {
                    printf("Livro não encontrado.\n");
                }
                break;

            case 2:
                printf("Digite o nome do autor do livro que deseja consultar: \n");
                limparBufferEntrada();
                char autorConsulta[100];
                fgets(autorConsulta, sizeof(autorConsulta), stdin);
                autorConsulta[strcspn(autorConsulta, "\n")] = 0; 

                int encontradoAutor = 0;
                for (int i = 0; i < numLivrosCadastrados; i++)
                {
                    if (strcmp(livros[i].autor, autorConsulta) == 0)
                    {
                        printf("Livro encontrado - Título: %s, Autor: %s, ISBN: %s\n", livros[i].titulo, livros[i].autor, livros[i].ISBN);
                        encontradoAutor = 1;
                    }
                }

                if (!encontradoAutor)
                {
                    printf("Livro não encontrado.\n");
                }
                break;

            case 3:
                printf("Digite o código ISBN do livro que deseja consultar: \n");
                limparBufferEntrada();
                char isbnConsulta[100];
                fgets(isbnConsulta, sizeof(isbnConsulta), stdin);
                isbnConsulta[strcspn(isbnConsulta, "\n")] = 0; 

                int encontradoISBN = 0;
                for (int i = 0; i < numLivrosCadastrados; i++)
                {
                    if (strcmp(livros[i].ISBN, isbnConsulta) == 0)
                    {
                        printf("Livro encontrado - Título: %s, Autor: %s e ISBN: %s\n", livros[i].titulo, livros[i].autor, livros[i].ISBN);
                        encontradoISBN = 1;
                    }
                }

                if (!encontradoISBN)
                {
                    printf("Livro não encontrado.\n");
                }
                break;
            }
            break;

        case 2:
            printf("|-----------------------------------------------|\n");
            printf("|     Você escolheu: 2 - Cadastrar livros.      |\n");
            printf("|-----------------------------------------------|\n");
            do
            {
                printf("|-----------------------------------------------|\n");
                printf("|Para cadastro de livros precisaremos de algumas|\n");
                printf("|   informações, como: titulo, autor e ISBN.    |\n");
                printf("|-----------------------------------------------|\n");

                printf("Digite o nome do livro que deseja cadastrar: \n");
                limparBufferEntrada(); // Limpar o buffer de entrada
                fgets(livros[numLivrosCadastrados].titulo, sizeof(livros[numLivrosCadastrados].titulo), stdin);
                livros[numLivrosCadastrados].titulo[strcspn(livros[numLivrosCadastrados].titulo, "\n")] = 0; // Remover a quebra de linha

                printf("Digite o nome do autor do livro que deseja cadastrar: \n");
                fflush(stdin);
                fgets(livros[numLivrosCadastrados].autor, sizeof(livros[numLivrosCadastrados].autor), stdin);
                livros[numLivrosCadastrados].autor[strcspn(livros[numLivrosCadastrados].autor, "\n")] = 0;

                printf("Digite o ISBN do livro que deseja cadastrar: \n");
                fflush(stdin);
                fgets(livros[numLivrosCadastrados].ISBN, sizeof(livros[numLivrosCadastrados].ISBN), stdin);
                livros[numLivrosCadastrados].ISBN[strcspn(livros[numLivrosCadastrados].ISBN, "\n")] = 0;

                // Inicializando o campo disponível
                livros[numLivrosCadastrados].disponivel = 1; // não deveria começar com 0?
                livros[numLivrosCadastrados].emprestado = 0; // Perguntar para o Bruno se é necessário inicializar o campo emprestado.

                numLivrosCadastrados++;

                if (numLivrosCadastrados >= 150)
                {
                    printf("Limite maximo de cadastros atingido. Nao e possivel cadastrar mais livros.\n");
                }

                printf("Livro cadastrado com sucesso! \n");
                printf("Deseja cadastrar outro livro? \n");
                printf("1 - Sim \n");
                printf("2 - Não. Voltar ao menu principal \n");
                scanf("%d", &opcaoMenuPrincipal);

                while (opcaoMenuPrincipal != 1 && opcaoMenuPrincipal != 2)
                {
                    printf("Opção inválida. Digite 1 para cadastrar outro livro ou 2 para voltar ao menu principal.\n");
                    scanf("%d", &opcaoMenuPrincipal);
                }

            } while (opcaoMenuPrincipal == 1);

            break;

        case 3: // Empréstimo de livros

            opcaoEmprestimo = 1;
            while (opcaoEmprestimo == 1)
            {
                char email[100];

                printf("Digite o código ISBN do livro que deseja emprestar: ");
                scanf(" %s", &isbnfornecido);
                strcpy(livros[9].ISBN, "teste");
                encontrado = 0;

                for (int i = 0; i < 150; i++)
                { // esse 'for' vai checar o ISBN fornecido com os ISBNs registrados.
                    if (strcmp(livros[i].ISBN, isbnfornecido) == 0)
                    {
                        encontrado = 1;

                        if (livros[i].emprestado == 0)
                        { // as variaveis começam com o valor 0, então vai entrar nesse if se o livro não tiver sido emprestado antes
                            printf("O livro está disponível para empréstimo!\nPor favor digite seu email para completar o empréstimo: ");
                            scanf(" %s", email);
                            livros[i].emprestado = 1; // o livro foi marcado como emprestado
                            printf("O livro foi emprestado com sucesso.\n");
                        }
                        else
                        {
                            printf("O livro não está disponível para empréstimo.\n");
                        }
                        break; // isso quebra o for.
                    }
                }

                if (encontrado == 0)
                {
                    printf("Livro não encontrado.\n");
                }

                printf("Deseja emprestar outro livro?\n");
                printf("1 - Sim\n");
                printf("2 - Não. Voltar ao menu principal\n");
                scanf(" %d", &opcaoEmprestimo);
                while (opcaoEmprestimo != 1 && opcaoEmprestimo != 2)
                {
                    printf("Valor inválido\n");
                    printf("Deseja emprestar outro livro?\n");
                    printf("1 - Sim\n");
                    printf("2 - Não. Voltar ao menu principal\n");
                    scanf(" %d", &opcaoEmprestimo);
                }
            }
            break;
        case 4: // Relatórios de livros
            printf("Você escolheu: 4 - Relatórios de livros \n");
            printf("Digite o número da opção desejada: \n");
            printf("1 - Relatório de livros disponíveis \n");
            printf("2 - Relatório de livros emprestados \n");
            printf("3 - Relatório de livros atrasados \n");
            scanf("%d", &opcaoRelatorios);
            break;

        case 5:
            printf("Você escolheu: 5 - Sair. \n");
            opcaoMenuPrincipal = 1;
        }
    } while (opcaoMenuPrincipal != 5);

    return 0;
}
