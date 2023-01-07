/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:35:39 by jlaisne           #+#    #+#             */
/*   Updated: 2022/12/31 15:01:37 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c || (s[i] >= 9 && s[i] <= 13))
			i++;
		if (s[i] != c && (s[i] < 9 || s[i] > 13) && s[i])
		{
			count++;
			while (s[i] != c && (s[i] < 9 || s[i] > 13) && s[i])
				i++;
		}
	}
	return (count + 1);
}

static char	**fill_tab(char **tab, const char *s, char c, int i)
{
	int	count;
	int	len;
	int	j;

	count = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c || (s[i] >= 9 && s[i] <= 13))
			i++;
		if (s[i] != c && (s[i] < 9 || s[i] > 13) && s[i])
		{
			j = i;
			while (s[i] != c && (s[i] < 9 || s[i] > 13) && s[i])
			{
				i++;
				len++;
			}
			tab[count++] = ft_substr(s, j, len);
			if (tab[count - 1] == NULL)
				return (free_tab(tab));
		}
	}
	return (tab[count] = NULL, tab);
}

static char	**create_tab(char const *s, char c)
{
	char			**tab;
	unsigned int	i;

	i = 0;
	tab = (char **)malloc((ft_count(s, c)) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = fill_tab(tab, s, c, i);
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	else
	{
		tab = create_tab(s, c);
		if (!tab)
			return (NULL);
		return (tab);
	}
}
