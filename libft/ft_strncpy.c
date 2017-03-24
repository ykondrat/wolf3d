/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:55:59 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/10 15:04:50 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *str, size_t n)
{
	size_t i;

	i = 0;
	if (n != 0)
	{
		while (n != 0)
		{
			dest[i] = str[i];
			if (dest[i] == 0)
			{
				while (n != 0)
				{
					dest[i++] = 0;
					n--;
				}
				break ;
			}
			n--;
			i++;
		}
	}
	return (dest);
}
