/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:09:02 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/24 00:21:18 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_utils.h"

int		print_string(t_format_spec *spec, va_list list)
{
	int		len;
	char	*s;

	s = va_arg(list, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (spec->precision != -1 && len > spec->precision)
		len = spec->precision;
	if (!spec->flags.justify_left)
		print_padding(len, true, spec);
	write(1, s, len);
	if (spec->flags.justify_left)
		print_padding(len, false, spec);
	return (pad(len, spec));
}
