/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:10:09 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/23 17:54:23 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_handler.h"

int		get_type(t_format_spec *spec, char c)
{
	if (c == 'c')
		spec->proc = &print_char;
	else if (c == 's')
		spec->proc = &print_string;
	else if (c == 'p')
		spec->proc = &print_pointer;
	else if (c == 'd' || c == 'i' || c == 'u')
		spec->proc = &print_int;
	else if (c == 'x' || c == 'X')
		spec->proc = &print_hex;
	else if (c == '%')
		spec->proc = &print_percent;
	else if (c == 'f')
		spec->proc = &print_float;
	return (spec->proc != NULL);
}
