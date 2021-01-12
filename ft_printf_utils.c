/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:02:54 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/24 01:31:39 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		mini_atoi(const char **s)
{
	int ret;

	ret = 0;
	while (ft_isdigit(**s))
	{
		ret = ret * 10 + (**s - '0');
		(*s)++;
	}
	return (ret);
}
