/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:06:08 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/17 15:59:27 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_str_base(char *str, int str_base)
{
	int		i;
	int		num;
	int		res;

	i = 0;
	num = 0;
	res = 0;
	while ((str[i] >= 48 && str[i] <= 57)
		|| (str[i] >= 65 && str[i] <= (65 + (str_base - 10))))
	{
		num = (str[i] >= 48 && str[i] <= 57) ? str[i] - '0' : str[i] - 55;
		res = res * str_base + num;
		i++;
	}
	return (res);
}

int			ft_atoi_base(char *str, int str_base)
{
	int		sym;
	int		res;
	int		i;

	i = 0;
	res = 0;
	ft_strcapitalizer(str);
	if (str_base < 2 || str_base > 16)
		return (0);
	while (str[i] < 33)
		i++;
	if (str[i] == 43 || str[i] == 45)
		sym = str[i++];
	if (str_base <= 10)
		while (str[i] >= 48 && str[i] <= (47 + str_base))
			res = res * str_base + str[i++] - '0';
	else
		res = ft_atoi_str_base(str + i, str_base);
	if (sym == 45 && str_base == 10)
		return (-res);
	return (res);
}
