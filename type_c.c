/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:13:04 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/22 22:01:27 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_utils.h"

int		print_char(t_format_spec *spec, va_list list)
{
	int		len;
	char	c;

	c = (char)va_arg(list, int);
	len = 1;
	if (!spec->flags.justify_left)
		print_padding(len, true, spec);
	write(1, &c, len);
	if (spec->flags.justify_left)
		print_padding(len, false, spec);
	return (pad(len, spec));
}
