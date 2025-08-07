/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:16:47 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/07 19:25:56 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_quote(char **tab)
{
    char    *tmp;
    char    *occ;
    int nb_quote;
    int i;
    
    nb_quote = 0;
    i = 0;
    while (tab[i] != NULL)
    {
        tmp = tab[i];
        if (occ = ft_strchr(tmp, '\''))
        {
            occ++;
            tmp = occ;
            nb_quote++;
        }
    }
    
}