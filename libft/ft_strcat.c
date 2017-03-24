/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:59:39 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/10 15:01:42 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *str)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	while (str[j])
		dest[i++] = str[j++];
	dest[i] = '\0';
	return (dest);
}
