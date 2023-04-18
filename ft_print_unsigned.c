/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:49:10 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/18 20:26:10 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int num)
{
	unsigned int	i;

	i = 1;
	if (num >= 10)
		i += ft_print_unsigned(num / 10);
	ft_putchar(num % 10 + '0');
	return (i);
}
