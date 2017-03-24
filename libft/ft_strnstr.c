/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:11:49 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/10 15:05:20 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = ft_strlen(to_find);
	if (k == 0)
		return ((char*)str);
	while (str[i] && i < n)
	{
		while (str[i + j] == to_find[j] && (i + j) < n)
		{
			if (j == k - 1)
				return ((char*)str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
