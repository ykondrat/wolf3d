/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:57:32 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/10 15:04:21 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*arr;

	if (s && f)
	{
		i = 0;
		while (s[i])
			i++;
		arr = (char*)malloc(sizeof(*arr) * (i + 1));
		if (arr)
		{
			i = 0;
			while (s[i])
			{
				arr[i] = f(s[i]);
				i++;
			}
			arr[i] = '\0';
			return (arr);
		}
	}
	return (NULL);
}
