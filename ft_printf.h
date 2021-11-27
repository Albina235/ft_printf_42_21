/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:08:52 by evalorie          #+#    #+#             */
/*   Updated: 2021/11/27 14:15:34 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_struct
{
	int	count;
	va_list	pa;
	//char	tmp_str;
	int	i;
}			t_struct;

# define HEX_L	"0123456789abcdef"
# define HEX_U	"0123456789ABCDEF"

int	ft_printf(const char *str, ...);

#endif
