/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:39:43 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/10 15:04:05 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *str, size_t n)
{
	size_t i;

	i = 0;
	if (!str)
		return ((unsigned long)i);
	while (str[i] && i < n - 1)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	while (str[i])
		i++;
	return ((unsigned long)i);
}
