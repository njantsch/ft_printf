/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:21:57 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/17 19:50:50 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_sign(char c, va_list args, int len)
{
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_print_string(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		len += ft_print_integer(va_arg(args, int));
	else if (c == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == '%')
		len += ft_putchar(va_arg(args, int));
	else if (c == 'p')
		len += ft_void_pointer(va_arg(args, void *));
	else if (c == 'x' || c == 'X')
		len += ft_num_in_hex(va_arg(args, int), c);
	return (len);
}

int	print_loop(const char *format, va_list args)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == 37)
		{
			i++;
			len += ft_check_sign(format[i], args, len);
			i++;
		}
		else
		{
			len += ft_putchar_len(format[i]);
			i++;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		numb_of_ch;

	va_start(args, format);
	numb_of_ch = print_loop(format, args);
	va_end(args);
	return (numb_of_ch);
}

// #include <stdio.h>
// int main(void)
// {
// 	int	num;

// 	num = get_arg_count("Hallo mein name ist %s und %d ist mein %c aber %% st falsch");
// 	printf("arg count is: %d\n", num);
// 	return (0);
// }
