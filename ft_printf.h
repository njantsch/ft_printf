/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:28:53 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/18 19:12:56 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_print_string(char *str);
int		ft_print_number(int num);
int		ft_print_unsigned(unsigned int num);
int		print_loop(const char *format, va_list args);
int		ft_num_in_hex(unsigned int num, char c);
int		ft_check_sign(char c, va_list args);
int		ft_void_pointer(size_t ptr);
char	*ft_itoa(int n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
