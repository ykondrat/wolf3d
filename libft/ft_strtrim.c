/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:38:58 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/10 15:06:39 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_check_length(char const *s, int i, int j)
{
	while (s[i])
		i++;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	if (i > j)
		return (i - j);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*arr;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	arr = (char*)malloc(sizeof(*arr) * (ft_check_length(s, 0, 0) + 1));
	if (!arr)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < ft_check_length(s, 0, 0))
	{
		arr[j] = s[i + j];
		j++;
	}
	arr[j] = '\0';
	return (arr);
}
