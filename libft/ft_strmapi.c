/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:07:10 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/10 15:04:28 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				arr[i] = f(i, s[i]);
				i++;
			}
			arr[i] = '\0';
			return (arr);
		}
	}
	return (NULL);
}
