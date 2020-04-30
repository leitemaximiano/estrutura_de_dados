#include <cs50.h>
#include <stdlib.h>

#include "lista_ls.h"

struct t_lista_ls
{
    int qtd;
    Usuario dados;
};

Lista_ls *criar_lista_ls(void)
{
    Lista_ls *li = (Lista_ls *)malloc(sizeof(Lista_ls));

    if (li != NULL)
        li->qtd = 0;

    return li;
}

void apagar_lista_ls(Lista_ls *li)
{
    if(li != NULL)
        free(li);
}
