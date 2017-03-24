/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:17:20 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/10 15:03:54 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *str, size_t n)
{
	size_t	i;
	size_t	d;
	size_t	s;

	i = 0;
	d = ft_strlen(dest);
	s = ft_strlen(str);
	if (n >= d)
	{
		while (str[i] && d < n - 1)
			dest[d++] = str[i++];
		dest[d] = '\0';
		return ((unsigned long)(s - i) + (unsigned long)d);
	}
	return ((unsigned long)s + (unsigned long)n);
}
