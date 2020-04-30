#include <stdio.h>
#include <cs50.h>

#include "lista_ls.h"

Usuario novo_usuario(string nome, string email, int idade);

int main(void)
{
    Lista_ls *usuarios = criar_lista_ls();

    inserir_no_fim_da_lista(usuarios, novo_usuario("1- Maria", "maria@yahoo.com", 58));
    inserir_no_fim_da_lista(usuarios, novo_usuario("2- Manoel", "ma@yahoo.com", 25));
    inserir_no_fim_da_lista(usuarios, novo_usuario("3- Felipe", "Fely@gmail.com", 98));

    // inserir_no_inicio_da_lista(usuarios, novo_usuario("Maria José", "mary@bool.com", 15));
    // inserir_na_posicao(usuarios, novo_usuario("Antônio martins", "atm@yahoo.com", 55), 2);
    // remover_primeiro_item(usuarios);
    // remover_ultimo_item(usuarios);
    // remover_item_na_posicao(usuarios, 2 );

    show_usuario(usuarios);
    
    apagar_lista_ls(usuarios);
    return 0;
}

Usuario novo_usuario(string nome, string email, int idade)
{
    Usuario tmp = {nome, email, idade};
    return tmp;
}
