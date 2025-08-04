/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:44:29 by pbongiov          #+#    #+#             */
/*   Updated: 2025/07/19 19:35:51 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	new_word;

	count = 0;
	new_word = 0;
	while (*s)
	{
		if (*s != c && new_word == 0)
		{
			new_word = 1;
			count++;
		}
		else if (*s == c)
			new_word = 0;
		s++;
	}
	return (count);
}

static char	*sep_word(const char *s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	i = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**ft_lesslines(char **str, char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			str[i] = sep_word(s, c);
			if (!str[i])
			{
				ft_free_str(str);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	return (ft_lesslines(str, s, c));
}
