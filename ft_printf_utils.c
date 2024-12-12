/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcossett <rcossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:56:20 by rcossett          #+#    #+#             */
/*   Updated: 2024/11/17 14:50:56 by rcossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write(char c, int *len)
{
	int	result;

	if (*len != -1)
	{
		result = write(1, &c, 1);
		if (result == -1)
			*len = -1;
		else
			*len += result;
	}
}

void	ft_putstr(char *str, int *len)
{
	char	*msg;

	if (str == NULL)
	{
		msg = "(null)";
		while (*msg)
		{
			ft_write(*msg, len);
			msg++;
		}
		return ;
	}
	while (*str)
		ft_write(*str++, len);
}

void	ft_base(unsigned long int n, const char *str_base, int base, int *len)
{
	if (n >= (unsigned long int)base)
		ft_base(n / base, str_base, base, len);
	ft_write(*(str_base + (n % base)), len);
}

void	ft_putnbr(int n, int *len)
{
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		ft_write('-', len);
		ft_base(-n, "0123456789", 10, len);
	}
	else
		ft_base(n, "0123456789", 10, len);
}

void	ft_print_pointer(void *ptr, int *len)
{
	uintptr_t	adress;

	adress = (uintptr_t)ptr;
	ft_write('0', len);
	ft_write('x', len);
	ft_base(adress, "0123456789abcdef", 16, len);
}
