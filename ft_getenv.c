/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 23:31:24 by florent           #+#    #+#             */
/*   Updated: 2025/08/04 17:43:44 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char *get_environnement(char **envp, char *var);
static int fill_tab_env(t_stack_string **stack, char **tab_env);
static  void manage_free(char **tab_env, char *res);

int ft_getenv(t_stack_string **stack, char **envp, char *var)
{   
    char    *env_path;
    char    **tab_env;
    int     error;

    env_path = get_environnement(envp, var);
    if (env_path == NULL)
        return (-2);
    env_path += ft_strlen(var);
    tab_env = ft_split(env_path, ':');
    if (tab_env == NULL)
        return (1);
    error = fill_tab_env(stack, tab_env);
    return (error);
}

static void manage_free(char **tab_env, char *res)
{
    int i;

    i = -1;
    if (tab_env != NULL)
    {
        while(tab_env[++i] != NULL)
        {
            free(tab_env[i]);
            tab_env[i] = NULL;
        }
        free(tab_env);
        tab_env = NULL;
    }
    if (res != NULL)
    {
        free(res);
        res = NULL;
    }
}

static char *get_environnement(char **envp, char *var)
{
    int i;
    
    i = 0;
    while(ft_strncmp(var, envp[i], ft_strlen(var)))
        i++;
    return (envp[i]);
}

static int fill_tab_env(t_stack_string **stack, char **tab_env)
{
    char    *res;
    int i;

    i = -1;
    res = NULL;
    while (tab_env[++i])
    {
        res = ft_strjoin(tab_env[i], "/");
        if (res == NULL)
        {
            manage_free(tab_env, res);
            return (1);
        }
        *stack = push_stack(*stack, res);
        if (*stack == NULL)
        {
            manage_free(tab_env, res);
            return (1);
        }
        manage_free(NULL, res);
    }   
    manage_free(tab_env, NULL);
    return (0);
}
