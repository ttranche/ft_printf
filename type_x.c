/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:37:33 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/23 23:51:40 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_utils.h"

void	print_sharp(bool sharp, t_format_spec *spec)
{
	if (sharp)
	{
		write(1, "0", 1);
		write(1, &spec->sps[0], 1);
	}
}

int		print_hex(t_format_spec *spec, va_list list)
{
	int				len;
	int				sharp;
	char			*charset;
	unsigned int	hex;

	charset = spec->sps[0] == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	hex = va_arg(list, unsigned int);
	if (spec->sps[1] == 'h')
		hex = (unsigned char)hex;
	sharp = spec->flags.sharp && hex != 0 ? 2 : 0;
	len = get_len(hex, 16);
	if (len < spec->precision || (spec->precision == 0 && hex == 0))
		len = spec->precision;
	if (spec->flags.zero_pad && !spec->flags.justify_left
		&& spec->precision < 0 && spec->width > len + sharp)
		len = spec->width - sharp;
	if (!spec->flags.justify_left)
		print_padding(len + sharp, false, spec);
	print_sharp(sharp, spec);
	ft_print_nbr(hex, len, charset);
	if (spec->flags.justify_left)
		print_padding(len + sharp, false, spec);
	return (pad(len + sharp, spec));
}
