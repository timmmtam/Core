/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:44:54 by timtan            #+#    #+#             */
/*   Updated: 2025/06/04 04:20:47 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char **init_array(char const *s, char c)
{
    size_t  no_of_words;
    size_t  i;

    no_of_words = 0;
    i = 0;
    while(s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i] != '\0')
            no_of_words++;
        while (s[i] && s[i] != c)
            i++;
    }
    return (malloc(sizeof(char *) * (no_of_words + 1)));
}

static char **fill_array(char **strings, char const *s, char c)
{
    size_t  i;
    size_t  j;
    size_t  start;

    i = 0;
    j = 0;
    while (s[i] != '\0')
    {
        while (s[i] == c)
            i++;
        if (!s[i])
            break;
        start = i;
        while (s[i] && s[i] != c)
            i++;
        strings[j] = malloc(i - start + 1);
        if (!strings[j])
        {
            while (j > 0)
                free(strings[--j]);
            return (NULL);
        }
        ft_strlcpy(strings[j], s + start, i - start + 1);
        j++;
    }
    strings[j] = NULL;
    return (strings);
}

char    **ft_split(char const *s, char c)
{
    char    **strings;

    if (!s)
        return (NULL);
    strings = init_array(s, c);
    if (!strings)
        return (NULL);
    strings = fill_array(strings, s, c);
    if (!strings)
        free(strings);
    return (strings);
}