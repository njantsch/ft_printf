/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:21:57 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/16 18:24:50 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_sign(char c, va_list *args, int *len)
{
	if (c == 'c')


}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (0);
}

int	print_loop(const char *format, va_list *args, int num_args)
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
			ft_check_sign(format[i], &args, &i, &len);
			i++;
		}
		else
		{
			ft_putchar_len(format[i], &len);
			i++;
		}
	}
	return (len);
}

int	get_arg_count(const char *format)
{
	int		i;
	int		count;
	char	*c;

	i = 0;
	count = 0;
	c = "cspdiuxX";
	while (format[i])
	{
		if (format[i] == 37)
		{
			if (ft_strchr(c, format[i + 1]) != NULL)
				count++;
			else if (format[i + 1] == 37)
				count++;
		}
		i++;
	}
	if (count == 0)
		return (0);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		num_args;
	int		numb_of_ch;

	num_args = get_arg_count(format);
	va_start(args, num_args);
	numb_of_ch = print_loop(format, args, num_args);
	va_end(args);
	return (len);
}

// #include <stdio.h>
// int main(void)
// {
// 	int	num;

// 	num = get_arg_count("Hallo mein name ist %s und %d ist mein %c aber %% st falsch");
// 	printf("arg count is: %d\n", num);
// 	return (0);
// }
