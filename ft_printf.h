/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:52:09 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/24 02:26:37 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdbool.h>

typedef struct	s_flags
{
	bool		justify_left;
	bool		force_sign;
	bool		force_space;
	bool		sharp;
	bool		zero_pad;
}				t_flags;

typedef struct	s_format_spec
{
	int			(*proc)(struct s_format_spec *, va_list);
	t_flags		flags;
	int			width;
	int			precision;
	char		sps[3];
}				t_format_spec;

int				ft_printf(const char *params, ...);

#endif
