/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_transform.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:35:48 by evalorie          #+#    #+#             */
/*   Updated: 2021/12/01 11:38:39 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_xx(size_t nb, char *alf)
{
	int	index[100];
	int	i;
	int	tmp;

	index[0] = 0;
	i = nb == 0;
	while (nb)
	{
		index[i] = nb % 16;
		nb = nb / 16;
		i++;
	}
	tmp = i;
	while (i)
		write (1, &alf[index[--i]], 1);
	return (tmp);
}

void	ft_itoa(t_struct *a, ssize_t nb)
{
	char			c;
	long long int	mod;

	mod = nb % 10;
	nb = nb / 10;
	if (nb != 0)
		ft_itoa(a, nb);
	c = mod + '0';
	a->count += write (1, &c, 1);
}

void	ft_putnbr(ssize_t n, t_struct *a)
{
	if (n < 0)
	{
		a->count += write (1, "-", 1);
		n *= -1;
	}
	ft_itoa(a, n);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(char *c)
{
	write (1, &c, 1);
	return (1);
}
