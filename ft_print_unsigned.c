/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:49:10 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/17 17:28:29 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_num_len(unsigned int num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	ft_print_unsigned(unsigned int num)
{
	int 	i;
	char	*str;

	str = ft_calloc(get_num_len(num), sizeof(char));
	if (str == NULL || get_num_len(num) == 0)
		return (0);
	i = get_num_len(num);
	while (i-- > 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
	}
	i = ft_print_string(str);
	free(str);
	return (i);
}
