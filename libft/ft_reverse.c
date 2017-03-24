/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:18:51 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/10 15:00:45 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse(char *str)
{
	size_t	i;
	size_t	j;
	char	buff;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		buff = str[i];
		str[i] = str[j];
		str[j] = buff;
		i++;
		j--;
	}
	return (str);
}
