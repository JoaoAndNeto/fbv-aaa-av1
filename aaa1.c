#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//####================= SISTEMA DE GESTAO DE DISCIPLINA =================####

//================================Estrutura==================================

typedef struct
{
    char nome[60];
    float nota1;
    float nota2;
} Aluno;

Aluno *fichaAluno;

int quant = 0;
int tam = 10;

//===========================Prototipo das funcoes==========================
void meuMenu(int *esc);
void incluir();
Aluno excluir();
Aluno pesquisar();
void relatorio();

//==================================MAIN=====================================
int main(void)
{
    fichaAluno = (Aluno *)malloc(tam * sizeof(Aluno));
    if(fichaAluno == NULL) return -1;
    
    int escolha;
    printf("\n ======== ATIVIDADE ACADEMICA AVALIATIVA ========\n");
    printf(" ================================================\n");

    while (escolha != 5)
    {
        meuMenu(&escolha);
        switch(escolha)
        {

        case 1:
            printf("\n ======== Incluir aluno ========\n");
            printf(" ===============================\n");
            incluir();
            break;

        case 2:
            printf("\n ======== Excluir aluno ========\n");
            printf(" ===============================\n");
            Aluno alu2 = excluir();
            break;

        case 3:
            printf("\n ======== Pesquisar aluno ========\n");
            printf(" =================================\n");
            Aluno alu = pesquisar();

            if (quant > 0)
            {
                printf("\n Nome: %s", alu.nome);
                printf("\n Nota 1: %.2f", alu.nota1);
                printf("\n Nota 2: %.2f\n", alu.nota2);
                printf("\n ===============================\n");
            }
            else
                printf("\n NÃƒÂ£o existe aluno na lista!\n");
            break;

        case 4:
            printf("\n\n ======== Relatorio de notas ========\n");
            printf(" ======================================\n");
            relatorio();
            break;

        case 5:
            printf("\n\n ======== Sair ========\n");
            printf(" ======================\n");
            printf(" \n x x x Encerrando o programa...x x x \n");
            break;

        default:
            printf("\n\n ======== OPCAO INVALIDA!! ========\n");
            printf("\n Por favor, informe uma opcao valida!\n");
            printf("\n =======================================\n");
        }
    }
    if (quant = tam){
		fichaAluno = (Aluno *) realloc(fichaAluno,(tam*2) * sizeof(Aluno));
    	if(fichaAluno == NULL) return -1;
	}
    
    free(fichaAluno);
    return 0;
}

void meuMenu(int *esc)
{
    printf("\n 1- Incluir Aluno"
           "\n 2- Excluir Aluno"
           "\n 3- Pesquisar Aluno"
           "\n 4- Relatorio de Notas"
           "\n 5- Sair \n");
    printf("\n Escolha uma opcao: ");
    scanf("%d", esc);
    fflush(stdin);
}

void incluir()
{
    Aluno alu;
    printf(" Incluir novo aluno \n");

    printf("\n | Nome: ");
    gets(alu.nome);
    fflush(stdin);

    printf(" | Nota 1: ");
    scanf("%f", &alu.nota1);
    fflush(stdin);

    printf(" | Nota 2: ");
    scanf("%f", &alu.nota2);
    fflush(stdin);

    fichaAluno[quant] = alu;
    quant++;

    printf("\n Aluno: %s  | Nota 1: %.2f | Nota 2: %.2f \n\n", alu.nome, alu.nota1, alu.nota2);
    printf(" ====================================\n");
}

Aluno excluir()
{
    Aluno alu2;
    int i, j;

    printf("\n Insira o nome do aluno que deseja excluir: ");
    gets(alu2.nome);

    for(i = 0; i < quant; i++)
    {

        if (strcmp(fichaAluno[i].nome, alu2.nome) == 0)
        {

            for( j = i; j < quant - 1; j++ )
            {
                fichaAluno[j] = fichaAluno[j + 1];

            }
            printf("\n Aluno excluido com sucesso!\n");
            quant --;
        }
    }
}

Aluno pesquisar()
{
    Aluno alunoVazio;
    int i, pesq;
    for (i = 0; i < quant; i++)
    {
        printf("\n Numero: %d -> Nome: %s\n\n", i, fichaAluno[i].nome);
        
    }
    if (quant > 0)
    {
        printf("\n Digite o numero do aluno que voce esta procurando => Numero: ");
        scanf("%d", &pesq);
        printf("\n ===============================\n");
        return fichaAluno[pesq];
        
        
    }
    return alunoVazio;
}

void relatorio()
{
    int i;
    for (i = 0; i < quant; i++)
    {
        float media;
        float n1 = fichaAluno[i].nota1;
        float n2 = fichaAluno[i].nota2;
        media = (n1 + n2)/2;

        if (media >= 6)
        {
            printf("\n| Nome: %s", fichaAluno[i].nome);
            printf("\t| Nota 1: %.2f", fichaAluno[i].nota1);
            printf("\t| Nota 2: %.2f", fichaAluno[i].nota2);
            printf("\t| Media: %.2f", media);
            printf("\t| Situacao: Aprovado! o/\n");
        }
        else if (media >= 4)
        {
            printf("\n| Nome: %s", fichaAluno[i].nome);
            printf("\t| Nota 1: %.2f", fichaAluno[i].nota1);
            printf("\t| Nota 2: %.2f", fichaAluno[i].nota2);
            printf("\t| Media: %.2f", media);
            printf("\t| Situacao: Recuperacao!\n");
        }
        else
        {
            printf("\n| Nome: %s", fichaAluno[i].nome);
            printf("\t| Nota 1: %.2f", fichaAluno[i].nota1);
            printf("\t| Nota 2: %.2f", fichaAluno[i].nota2);
            printf("\t| Media: %.2f", media);
            printf("\t| Situacao: Reprovado!\n");
        }
    } printf("\n ===============================\n");
}