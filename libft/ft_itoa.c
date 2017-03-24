/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:22:59 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/10 14:54:23 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_size(int n)
{
	int		size;

	size = 1;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char		*ft_minus(int n, char *str, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	str[i] = '-';
	str[i + 1] = '\0';
	return (ft_reverse(str));
}

static char		*ft_n(int n, char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	str[i] = '\0';
	return (ft_reverse(str));
}

char			*ft_itoa(int n)
{
	char	*str;
	int		size;

	if (n == -2147483648)
	{
		if ((str = (char*)malloc(sizeof(char) * 12)) == NULL)
			return (NULL);
		str = ft_minus(2147483647, str, 11);
		str[10] = '8';
		str[11] = '\0';
		return (str);
	}
	size = ft_size(n);
	str = (char*)malloc(sizeof(*str) * size + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		return (ft_minus(-n, str, size));
	else
		return (ft_n(n, str, size));
	return (NULL);
}
