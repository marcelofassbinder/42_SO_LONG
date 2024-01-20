/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:44:25 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/20 14:29:29 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(int fd, char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(fd, va_arg(args, int));
	if (c == 's')
		count += ft_putstr(fd, va_arg(args, char *));
	if (c == 'd' || c == 'i')
		count += ft_putnbr_int(fd, va_arg(args, int), "0123456789");
	if (c == 'x')
		count += ft_putnbr_base(fd, va_arg(args, unsigned int), "0123456789abcdef");
	if (c == 'X')
		count += ft_putnbr_base(fd, va_arg(args, unsigned int), "0123456789ABCDEF");
	if (c == 'p')
		count += ft_putmem(fd, va_arg(args, void *));
	if (c == 'u')
		count += ft_putnbr_base(fd, va_arg(args, unsigned int), "0123456789");
	if (c == '%')
		count += ft_putchar(fd, '%');
	return (count);
}
