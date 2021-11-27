#include "ft_printf.h"

int	ft_putnbr_xX(int nb, char *alf)
{
	int	index[100];
	int	i;
	int tmp;

	/*if (!alf || ft_strlen(alf) < base)
		return (-1);*/
	index[0] = 0;
	i = 1; 
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

void	ft_itoa(t_struct *a, long long int nb)
{
	char	c;
	long long int	mod;

	mod = nb % 10;
	nb = nb / 10;
	if (nb != 0)
		ft_itoa(a, nb);
	c = mod + '0';
	a->count += write (1, &c, 1);
}

void	ft_putnbr(int n, t_struct *a)
{
	long long int	nb;

	nb = (long long int)n;
	if (nb < 0)
	{
		a->count += write (1, "-", 1);
		nb *= -1;
	}
	ft_itoa(a, nb);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_check_s(t_struct *a, char *s)
{
	if (s == NULL)
		a->count += write (1, "(null)", 6);
	else
		a->count += write (1, s, ft_strlen(s));
}

int	ft_putchar(char *c)
{
	write (1, &c, 1);
	return (1);
}

void	ft_check_type(t_struct *a, char *str)
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
		a->count += ft_putnbr_xX(va_arg(a->pa, long int), HEX_L);
	}
	else if (str[a->i] == 'x')
		a->count += ft_putnbr_xX((unsigned int)va_arg(a->pa, int), HEX_L);
	else if (str[a->i] == 'X')
		a->count += ft_putnbr_xX((unsigned int)va_arg(a->pa, int), HEX_U);
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

int main (void)
{
	int	n = 516;
	int i;
	char c = 'f';

	i = ft_printf("%d\n %s", n, "sdf");
	printf("%d", i);
	return (0);
}
