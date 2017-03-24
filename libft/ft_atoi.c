/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:46:18 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/10 14:52:05 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		i;
	int		symbol;
	int		result;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
		symbol = str[i++];
	while (str[i] >= 48 && str[i] <= 57 && str[i])
		result = result * 10 + (str[i++] - '0');
	if (symbol == 45)
		return (-result);
	return (result);
}
