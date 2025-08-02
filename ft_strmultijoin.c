
#include "pipex.h"

char	*ft_strmultijoin(char **s2)
{
    int     i;
    char    *res;
    char    *copy;

    i = 0;
    res = ft_strdup("");
    if (res == NULL)
        return (NULL);
    while(s2[i] != NULL)
    {
        copy = ft_strjoin(res, s2[i]);
        free(res);
        if (copy == NULL)
            return (NULL);
        res = ft_strdup(copy);
        free(copy);
        if (res == NULL)
            return (NULL);
        i++;
    }
    return (res);
}