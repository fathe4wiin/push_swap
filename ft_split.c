#include "push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:21:19 by bfathi            #+#    #+#             */
/*   Updated: 2026/01/03 12:00:00 by copilot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_issep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && ft_issep(str[i], sep))
			i++;
		if (str[i] && !ft_issep(str[i], sep))
		{
			words++;
			while (str[i] && !ft_issep(str[i], sep))
				i++;
		}
	}
	return (words);
}

void	skip_sep(char *str, char *charset, int *i, int *wordlen)
{
	*wordlen = 0;
	while (str[*i] && ft_issep(str[*i], charset))
		(*i)++;
	while (str[*i] && !ft_issep(str[*i], charset))
	{
		(*wordlen)++;
		(*i)++;
	}
	*i -= *wordlen;
}

char	*extract_words(char *str, int *i, char *charset, int wordlen)
{
	char	*res;
	int		k;

	k = 0;
	res = malloc(wordlen + 1);
	if (!res)
		return (NULL);
	while (str[*i] && !ft_issep(str[*i], charset))
	{
		res[k] = str[*i];
		k++;
		(*i)++;
	}
	res[k] = '\0';
	return (res);
}

/* 
** Helper function to free the array if allocation fails mid-way
*/
static char	**free_all(char **res, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		wordlen;
	int		j;

	res = malloc((word_count(str, charset) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		skip_sep(str, charset, &i, &wordlen);
		if (wordlen > 0)
		{
			res[j] = extract_words(str, &i, charset, wordlen);
			if (!res[j])
				return (free_all(res, j)); // If malloc fails, clean up
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}