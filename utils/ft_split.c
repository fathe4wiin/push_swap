/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:18:41 by bfathi            #+#    #+#             */
/*   Updated: 2026/01/12 00:54:00 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
				return (free_all(res, j));
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}
