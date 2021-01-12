/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:29:51 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/24 12:12:27 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_utils.h"

void	print_padding(int len, bool pre, t_format_spec *spec)
{
	int pad;

	pad = spec->width - len;
	if (pad < 0)
		return ;
	while (pad--)
		write(1, spec->flags.zero_pad && pre ? "0" : " ", 1);
}

int		pad(int len, t_format_spec *spec)
{
	int pad;

	pad = spec->width - len;
	if (pad < 0)
		return (len);
	return (pad + len);
}

int		ft_print_nbr(unsigned long long offset, int len, char *hex)
{
	char	size;

	size = ft_strlen(hex);
	if (len > 0)
		ft_print_nbr(offset / size, len - 1, hex);
	if (len > 0)
		write(1, &hex[offset % size], 1);
	return (1);
}

int		get_len(unsigned long long offset, int size)
{
	int len;

	len = 0;
	if (offset < (unsigned long long)size)
		return (len + 1);
	while (offset > 0)
	{
		len++;
		offset /= size;
	}
	return (len);
}

char	*get_pre(long neg, t_format_spec *spec)
{
	if (spec->sps[0] == 'u')
		return (NULL);
	if (neg)
		return ("-");
	else if (spec->flags.force_sign)
		return ("+");
	else if (spec->flags.force_space)
		return (" ");
	return (NULL);
}
