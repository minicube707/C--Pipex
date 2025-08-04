/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:14:46 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/04 23:26:27 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list *new_list(void)
{
    return NULL;
}

/*--------------------------------------------------*/
/**
* Vérifie si une List est vide
* @return true si la List est vide, faux sinon
*/
t_bool is_empty_list(t_list * li)
{
    if(li == NULL)
        return true;
    return false;
}

/*--------------------------------------------------*/
/**
* Retourne la hauteur (longueur) de la List
* @return La taille de la List
*/
int lenght_list(t_list *li)
{
    int size = 0;

    if(!is_empty_list(li))
    {
        while (li != NULL)
        {
            ++size;
            li = li -> next;
        }
    }

    return size;
}

/*--------------------------------------------------*/
/**
* Affiche une Queue
* @param li La List
*/
void print_list(t_list *li)
{
    
    if(is_empty_list(li))
    {
        printf("La list est vide, rien a afficher \n");
        return;
    }

    while (li != NULL){
        printf("[%s] \n", li->string);
        li = li -> next;
    }
    printf("\n");
}

/*--------------------------------------------------*/
/**
* Ajoute un entier à la fin de la List
* @param li La List
* @param val Un entier
* @return La nouvelle List
*/
t_list *put_back(t_list *li, char *string)
{

    t_list *element;
    element = malloc(sizeof(*element));
    
    if(element == NULL)
    {
        ft_putstr_fd("Error: the file doesnt exit\n", 1);
        return (NULL);
    }

    element->string = string;
    element->next = NULL;

    if (is_empty_list(li))
        return element;

    t_list  *temp;
    temp = li;

    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = element;
    return li;   
}

/*--------------------------------------------------*/
/**
* Retire le premier élément de la List
* @param li La List
* @return La nouvelle List
*/
t_list *pop_front(t_list *li)
{

    t_list *new_first;
       
    if(is_empty_list(li))
        return li;
        
    new_first = li->next;
    free(li);
    li = NULL;

    return new_first;
}

/*--------------------------------------------------*/
/**
* Vide la List de ses éléments
* @param li La List
* @return La nouvelle List vide
*/
t_list *clear_list(t_list *li)
{

    if(is_empty_list(li))
        return new_list();

    while (li != NULL){
        li = pop_front(li);
    }
}