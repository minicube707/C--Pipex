/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:39:39 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/04 23:47:56 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_super_list *new_super_list(void)
{
    return NULL;
}

/*--------------------------------------------------*/
/**
* Vérifie si une List est vide
* @return true si la List est vide, faux sinon
*/
t_bool is_empty_super_list(t_super_list * li)
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
int lenght_super_list(t_super_list *li)
{
    int size = 0;

    if(!is_empty_super_list(li))
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
void print_super_list(t_super_list *li)
{
    
    if(is_empty_super_list(li))
    {
        printf("La Super list est vide, rien a afficher \n");
        return;
    }

    while (li != NULL){
        print_list(li->head_list);
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
t_super_list *put_super_back(t_super_list *su, t_list *li)
{

    t_super_list *element;
    element = malloc(sizeof(*element));
    
    if(element == NULL)
    {
        ft_putstr_fd("Error: the file doesnt exit\n", 1);
        return (NULL);
    }

    element->head_list = li;
    element->next = NULL;

    if (is_empty_super_list(li))
        return element;

    t_super_list  *temp;
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
t_super_list *pop_super_front(t_super_list *li)
{

    t_super_list *new_first;
       
    if(is_empty_super_list(li))
        return li;
        
    new_first = li->next;
    clear_list(li->head_list);
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
t_super_list *clear_super_list(t_super_list *li)
{

    if(is_empty_super_list(li))
        return new_super_list();

    while (li != NULL){
        li = pop_super_front(li);
    }
}
