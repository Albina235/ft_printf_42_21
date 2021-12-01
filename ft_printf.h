/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:08:52 by evalorie          #+#    #+#             */
/*   Updated: 2021/12/01 11:37:40 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_struct
{
	int		count;
	va_list	pa;
	int		i;
}			t_struct;

# define HEX_L	"0123456789abcdef"
# define HEX_U	"0123456789ABCDEF"

int		ft_printf(const char *str, ...);
int		ft_putnbr_xx(size_t nb, char *alf);
void	ft_itoa(t_struct *a, ssize_t nb);
void	ft_putnbr(ssize_t n, t_struct *a);
int		ft_strlen(char *str);
int		ft_putchar(char *c);

#endif
