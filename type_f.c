/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:15:37 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/24 12:46:59 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_utils.h"

int			ft_putnbr_l(long n, bool print)
{
	unsigned long	nbr;
	int				len;

	nbr = n < 0 ? -n : n;
	len = 1;
	if (nbr > 9)
		len += ft_putnbr_l(nbr / 10, print);
	if (print)
		ft_putchar_fd(nbr % 10 + '0', 1);
	return (len);
}

long double	round_exp(long double d, int times, int i)
{
	int sign;

	sign = 0;
	if (d < 0)
	{
		d *= -1;
		sign = 1;
	}
	if (!times && (((d - (long)d) >= .5 && (long)d % 2) || (d - (long)d) > .5))
		d++;
	if (!times)
		d -= (d - (long)d);
	while (i++ < times)
		d *= 10;
	if ((d - ((long)d)) >= 0.5)
		d += 0.501;
	i = 0;
	while (i++ < times)
		d /= 10;
	return (sign ? -d : d);
}

int			print_exp(long double f, int max, bool print, t_format_spec *spec)
{
	int		i;
	int		len;

	f = round_exp(f, max, 0);
	len = 1 + ft_putnbr_l((long)f, print);
	if (max == 0 && !spec->flags.sharp)
		return (len - 1);
	if (print)
		write(1, ".", 1);
	i = 0;
	if (f < 0)
		f *= -1;
	while (i++ < max)
	{
		f -= (long)f;
		f *= 10;
		if (++len && print && (long)f % 10 >= 0)
			ft_putchar_fd((char)((long)f % 10 + '0'), 1);
		else if (print)
			ft_putchar_fd('0', 1);
	}
	return (len);
}

int			print_float(t_format_spec *spec, va_list list)
{
	double	fl;
	int		len;
	char	*pre;

	len = 0;
	fl = va_arg(list, double);
	pre = get_pre(fl < 0.0 || (1.0 / fl) < 0, spec);
	if (spec->precision == -1)
		spec->precision = 6;
	len += print_exp(fl, spec->precision, false, spec);
	if (pre)
		len++;
	if (pre && spec->flags.zero_pad)
		write(1, pre, 1);
	if (!spec->flags.justify_left)
		print_padding(len, true, spec);
	if (pre && !spec->flags.zero_pad)
		write(1, pre, 1);
	print_exp(fl, spec->precision, true, spec);
	if (spec->flags.justify_left)
		print_padding(len, false, spec);
	return (pad(len, spec));
}
