/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:46:37 by mradwan           #+#    #+#             */
/*   Updated: 2022/08/08 16:34:15 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_undoalloc(char *s, int i)
{
	while (i >= 0)
	{
		free(&s[i]);
		i--;
	}
	free(s);
}

static	int	ft_worddet(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && (s[i] != c))
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_cpystr(char const *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	ft_memcpy(str, s, i);
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**split;

	if (!s)
		return (0);
	count = ft_worddet(s, c);
	split = malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (0);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		split[i] = ft_cpystr(s, c);
		if (!split[i])
			ft_undoalloc(*split, i);
		s += ft_strlen(split[i]);
		i++;
	}
	split[i] = 0;
	return (split);
}
/*
int	main(void)
{
	int i = 0;
	char a[] = "   this";
	char **split = ft_split(a, ' ');
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}
*/