/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:35:59 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/10 15:06:26 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*arr;

	arr = (char*)malloc(sizeof(*arr) * (len + 1));
	if (!s || !arr)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		arr[i] = s[i + start];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
