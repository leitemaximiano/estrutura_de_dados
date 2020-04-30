#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

#include "lista_ls.h"


struct t_lista_ls
{
    int qtd;
    Usuario dados[MAX_USUARIO];
};

boolean esta_vasia(Lista_ls *li)
{
    if (li->qtd == 0)
        return TRUE;

    return FALSE;
}


boolean lista_cheia(Lista_ls *li)
{
    if(li->qtd == MAX_USUARIO)
        return TRUE;

    return FALSE;
}

boolean ponteiro_esta_nulo(Lista_ls *li)
{
    if (li == NULL)
        return TRUE;

    return FALSE;
}

Lista_ls *criar_lista_ls(void)
{
    Lista_ls *li = (Lista_ls *)malloc(sizeof(Lista_ls));

    if (!ponteiro_esta_nulo(li))
        li->qtd = 0;

    return li;
}

void apagar_lista_ls(Lista_ls *li)
{
    if(ponteiro_esta_nulo(li))
        free(li);
}

boolean inserir_no_inicio_da_lista(Lista_ls *li, Usuario us)
{
    if(ponteiro_esta_nulo(li) || lista_cheia(li))
        return FALSE;
    int i;

    for(i = li->qtd - 1; i >= 0; i--)
    {
        li->dados[i + 1] = li->dados[i];
    }

    li->dados[0] = us;
    li->qtd++;


    return TRUE;
}

boolean inserir_no_fim_da_lista(Lista_ls *li, Usuario us)
{
    if(ponteiro_esta_nulo(li) || lista_cheia(li))
        return FALSE;

    li->dados[li->qtd] = us;
    li->qtd++;

    return TRUE;
}

boolean inserir_na_posicao(Lista_ls *li, Usuario us, int pos)
{
    if(ponteiro_esta_nulo(li) || lista_cheia(li) || pos <= 0)
        return FALSE;
    if(pos > li->qtd)
        return FALSE;
    int i;
    for (i = li->qtd - 1; i>= pos; i--)
        li->dados[i+1] = li->dados[i];

    li->dados[i] = us;
    li->qtd++;
    return TRUE;
}


void show_usuario(Lista_ls *li)
{
    if(ponteiro_esta_nulo(li))
        return;
    
    printf("Nome dos usuários:\n");
    for(int i = 0, qtd = li->qtd; i < qtd; i++)
        printf("%s\n", li->dados[i].nome);
    printf("\n");
}

boolean remover_ultimo_item(Lista_ls *li)
{
    if(ponteiro_esta_nulo(li) || esta_vasia(li))
        return FALSE;
    
    li->qtd--;
    return TRUE;
}
boolean remover_primeiro_item(Lista_ls *li)
{
    if(ponteiro_esta_nulo(li) || esta_vasia(li))
        return FALSE;
    
    for (int i = 0, len = li->qtd-1; i <= len; i++)
        li->dados[i] = li->dados[i+1];
    li->qtd--;

    return TRUE; 
}

boolean remover_item_na_posicao(Lista_ls *li, int pos)
{
    if(ponteiro_esta_nulo(li) || esta_vasia(li) || pos < 0 )
        return FALSE;
    if(pos > li->qtd)
        return FALSE;

    for (int i = pos -1, len = li->qtd-1; i <= len; i++)
        li->dados[i] = li->dados[i+1];
    li->qtd--;

    return TRUE; 
}