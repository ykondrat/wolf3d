/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:58:09 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/10 15:06:03 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_word_counter(char const *s, char c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

static int		ft_letter_counter(char const *s, char c)
{
	int counter;

	counter = 0;
	while (s[counter])
	{
		if (s[counter] == c)
			break ;
		counter++;
	}
	return (counter);
}

static char		*ft_array_ij(char const *s, char c, char *array, int index)
{
	int j;

	j = 0;
	while (s[index] && s[index] != c)
	{
		array[j] = s[index];
		index++;
		j++;
	}
	array[j] = '\0';
	return (array);
}

static char		**ft_array_i(char const *s, char c, char **array)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c && s[j])
			j++;
		if (s[j] && s[j] != c)
		{
			array[i] = (char*)malloc(sizeof(char) *
					(ft_letter_counter(&s[j], c) + 1));
			if (!array[i])
				return (NULL);
			array[i] = ft_array_ij(s, c, array[i], j);
			while (s[j] && s[j] != c)
				j++;
			i++;
		}
	}
	array[i] = 0;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;

	if (!s || !c)
		return (NULL);
	array = (char**)malloc(sizeof(char*) * (ft_word_counter(s, c) + 1));
	if (!array)
		return (NULL);
	array = ft_array_i(s, c, array);
	return (array);
}
