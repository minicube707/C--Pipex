/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 02:24:33 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/05 02:56:32 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **copy_tab(char **tab)
{
    char **new_tab;
    int     nb_elem;
    int     i;
    
    nb_elem = 0;
    while(tab[nb_elem] != NULL)
        nb_elem++;
    nb_elem++;  
    new_tab = malloc(nb_elem * sizeof(char **));
    if (new_tab == NULL)
        return (NULL);
    i = 0;
    while(i < nb_elem - 1)
    {
        new_tab[i] = ft_strdup(tab[i]);
        if (new_tab[i] == NULL)
        {
            clear_tab(tab);
            clear_tab(new_tab);
            return (NULL);
        }
        new_tab[i+1] = NULL;
        i++;
    }
    new_tab[i] = NULL;
    return (new_tab);
}

void    clear_tab(char **tab)
{
    int i;

    i = 0;
    while(tab[i] != NULL)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void    print_tab(char **tab)
{
    int i;
    
    i = 0;
    while(tab[i] != NULL)
    {
        ft_putstr_fd(tab[i], 1);
        ft_putstr_fd("\n", 1);
        i++;
    }
    ft_putstr_fd("\n", 1);
}
