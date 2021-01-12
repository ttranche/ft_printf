/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:53:44 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/23 13:05:15 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_utils.h"

int		print_percent(t_format_spec *spec, va_list list)
{
	int					len;

	len = 1;
	(void)list;
	if (!spec->flags.justify_left)
		print_padding(len, true, spec);
	write(1, "%", 1);
	if (spec->flags.justify_left)
		print_padding(len, false, spec);
	return (pad(len, spec));
}
