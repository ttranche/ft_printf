/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:17:25 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/24 12:21:05 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_parser.h"

int		perc(va_list list, int *total, const char **params)
{
	t_format_spec	*spec;
	int				len;

	spec = ft_calloc(1, sizeof(t_format_spec));
	if (!spec)
		return (0);
	spec->precision = -1;
	len = read_specifier(*params, spec, list, false);
	if (spec->proc)
	{
		*params += len;
		*total += spec->proc(spec, list) - 1;
	}
	else
		write(1, *params, 1);
	free(spec);
	return (1);
}

int		ft_printf(const char *params, ...)
{
	va_list		list;
	int			total;

	va_start(list, params);
	total = 0;
	while (*params)
	{
		if (*params == '%')
		{
			if (!params[1])
				--total;
			else if (!perc(list, &total, &params))
				return (-1);
		}
		else
			write(1, params, 1);
		++total;
		++params;
	}
	va_end(list);
	return (total);
}
