#ifndef LISTA_LS_H
#define LISTA_LS_H
#include <cs50.h>

#define MAX_USUARIO 100
#define FALSE 0
#define TRUE 1

typedef struct t_lista_ls Lista_ls;
typedef char boolean;

typedef struct t_usuario
{
    string nome, email;
    int idade;
}
Usuario;

Lista_ls *criar_lista_ls();
void apagar_lista_ls(Lista_ls *li);
boolean inserir_no_inicio_da_lista(Lista_ls *li, Usuario us);
boolean inserir_no_fim_da_lista(Lista_ls *li, Usuario us);
boolean inserir_na_posicao(Lista_ls *li, Usuario us, int pos);

#endif
