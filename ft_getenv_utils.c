/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 23:31:32 by florent           #+#    #+#             */
/*   Updated: 2025/08/02 23:31:35 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **fill_tab(char **tab, char *string)
{
    tab[0] = string;
    tab[1] = "/";
    tab[2] = NULL;
    return (tab);
}

char **create_tab(char **tab_env, char **tab, char *res)
{
    tab = malloc(3 * sizeof(char *));
    if (tab == NULL)
    {
        manage_free(tab_env, tab, res);
        return (NULL);
    }
    return (tab);
}