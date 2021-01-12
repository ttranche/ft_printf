/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:01:28 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/24 02:25:34 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "type_handler.h"

bool	update_flags(t_format_spec *f, const char c, va_list list, bool load)
{
	if (c == '-')
		return (f->flags.justify_left = true);
	if (c == '+')
		return (f->flags.force_sign = true);
	if (c == ' ')
		return (f->flags.force_space = true);
	if (c == '#')
		return (f->flags.sharp = true);
	if (c == '0')
		return (f->flags.zero_pad = true);
	if (c == '*' || c == '\'')
	{
		if (load && c == '*')
		{
			f->width = va_arg(list, int);
			if (f->width < 0)
			{
				f->width *= -1;
				f->flags.justify_left = true;
			}
		}
		return (true);
	}
	return (0);
}

int		absval(int v)
{
	if (v < 0)
		return (-1);
	return (v);
}

void	read_prefix(const char **specifier, t_format_spec *spec)
{
	if ((*specifier)[0] == 'h' && (*specifier)[1] == 'h')
	{
		spec->sps[0] = 'h';
		spec->sps[1] = 'h';
		*specifier += 2;
	}
}

int		read_specifier(const char *specifier, t_format_spec *spec,
		va_list list, bool load)
{
	const char *orig;

	orig = specifier;
	++specifier;
	while (update_flags(spec, *specifier, list, load))
		++specifier;
	spec->width |= mini_atoi(&specifier);
	if (*specifier == '.' && ++specifier)
	{
		if (*specifier == '*' && ++specifier && load)
			spec->precision = absval(va_arg(list, int));
		else
			spec->precision = mini_atoi(&specifier);
	}
	read_prefix(&specifier, spec);
	get_type(spec, *specifier);
	spec->sps[0] = *specifier;
	if (spec->proc && !load)
		return (read_specifier(orig, spec, list, true));
	return (specifier - orig);
}
