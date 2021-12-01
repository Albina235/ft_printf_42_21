/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:34:05 by evalorie          #+#    #+#             */
/*   Updated: 2021/12/01 11:38:09 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_s(t_struct *a, char *s)
{
	if (s == NULL)
		a->count += write (1, "(null)", 6);
	else
		a->count += write (1, s, ft_strlen(s));
}

static void	ft_check_type(t_struct *a, char *str)
{
	if (str[++a->i] == '%')
		a->count += write(1, "%", 1);
	else if (str[a->i] == 's')
		ft_check_s(a, va_arg(a->pa, char *));
	else if (str[a->i] == 'c')
		a->count += ft_putchar(va_arg(a->pa, char *));
	else if (str[a->i] == 'd' || str[a->i] == 'i')
		ft_putnbr(va_arg(a->pa, int), a);
	else if (str[a->i] == 'u')
		ft_putnbr((unsigned int)va_arg(a->pa, int), a);
	else if (str[a->i] == 'p')
	{
		a->count += write(1, "0x", 2);
		a->count += ft_putnbr_xx(va_arg(a->pa, long int), HEX_L);
	}
	else if (str[a->i] == 'x')
		a->count += ft_putnbr_xx((unsigned int)va_arg(a->pa, int), HEX_L);
	else if (str[a->i] == 'X')
		a->count += ft_putnbr_xx((unsigned int)va_arg(a->pa, int), HEX_U);
}

int	ft_printf(const char *str, ...)
{
	t_struct	a;

	va_start (a.pa, str);
	a.count = 0;
	a.i = -1;
	while (str[++a.i])
	{
		if (str[a.i] == '%' && str[a.i + 1] != '\0')
			ft_check_type(&a, (char *)str);
		else
			a.count += write (1, &str[a.i], 1);
	}
	va_end(a.pa);
	return (a.count);
}

/*int main (void)
{
	int	n = 516;
	int i;
	char c = 'f';

	i = ft_printf("%d\n %s", n, "sdf");
	printf("%d", i);
	return (0);
}*/
