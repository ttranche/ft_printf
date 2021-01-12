/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:12:08 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/24 11:37:30 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_utils.h"

int		ft_print_int(long offset, int len)
{
	char	*hex;

	if (offset < 0)
		offset *= -1;
	hex = "0123456789";
	if (len > 0)
		ft_print_int(offset / 10, len - 1);
	if (len > 0)
		write(1, &hex[offset % 10], 1);
	return (1);
}

int		get_len_int(long offset)
{
	int len;

	len = 0;
	if (offset < 0)
		offset *= -1;
	if (offset < 10)
		return (len + 1);
	while (offset > 0)
	{
		len++;
		offset /= 10;
	}
	return (len);
}

int		do_print(char *pre, long addr, int len, t_format_spec *spec)
{
	if (pre)
		len++;
	if (spec->flags.zero_pad && !spec->flags.justify_left
		&& spec->precision < 0 && spec->width > len)
		len = spec->width;
	if (!spec->flags.justify_left)
		print_padding(len, false, spec);
	if (pre)
	{
		write(1, pre, 1);
		ft_print_int(addr, len - 1);
	}
	else
		ft_print_int(addr, len);
	if (spec->flags.justify_left)
		print_padding(len, false, spec);
	return (len);
}

int		print_int(t_format_spec *spec, va_list list)
{
	long	addr;
	int		len;
	char	*pre;

	if (spec->sps[0] == 'u')
	{
		if (spec->sps[1] == 'h')
			addr = (unsigned char)va_arg(list, unsigned int);
		else
			addr = (unsigned int)va_arg(list, unsigned int);
	}
	else
	{
		if (spec->sps[1] == 'h')
			addr = (char)va_arg(list, int);
		else
			addr = (int)va_arg(list, int);
	}
	len = get_len_int(addr);
	pre = get_pre(addr < 0, spec);
	if (len < spec->precision || (spec->precision == 0 && addr == 0))
		len = spec->precision;
	len = do_print(pre, addr, len, spec);
	return (pad(len, spec));
}
