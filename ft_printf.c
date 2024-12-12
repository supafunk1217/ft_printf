/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcossett <rcossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:42:30 by rcossett          #+#    #+#             */
/*   Updated: 2024/12/09 14:05:31 by rcossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	ft_write(c, len);
}

void	ft_check_format(va_list args, const char format, int *len)
{
	const char	*hex_base_low;
	const char	*hex_base_up;

	hex_base_low = "0123456789abcdef";
	hex_base_up = "0123456789ABCDEF";
	if (format == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (format == 'i' || format == 'd')
		ft_putnbr(va_arg(args, int), len);
	else if (format == 'u')
		ft_base(va_arg(args, unsigned int), "0123456789", 10, len);
	else if (format == 'x')
		ft_base(va_arg(args, unsigned int), hex_base_low, 16, len);
	else if (format == 'X')
		ft_base(va_arg(args, unsigned int), hex_base_up, 16, len);
	else if (format == 'p')
		ft_print_pointer(va_arg(args, void *), len);
	else if (format == '%')
		ft_write('%', len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_check_format(args, str[i], &len);
		}
		else
			ft_write(str[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
