/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:46:17 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/24 01:42:42 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_utils.h"

int		print_pointer(t_format_spec *spec, va_list list)
{
	unsigned long long	addr;
	int					len;

	addr = va_arg(list, unsigned long long);
	len = get_len(addr, 16);
	if (len < spec->precision || (spec->precision == 0 && addr == 0))
		len = spec->precision;
	if (spec->flags.zero_pad && !spec->flags.justify_left
		&& spec->precision < 0 && spec->width > len + 2)
		len = spec->width - 2;
	if (!spec->flags.justify_left)
		print_padding(len + 2, false, spec);
	write(1, "0x", 2);
	ft_print_nbr(addr, len, "0123456789abcdef");
	if (spec->flags.justify_left)
		print_padding(len + 2, false, spec);
	return (pad(len + 2, spec));
}
