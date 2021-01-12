/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:23:12 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/24 02:26:24 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PARSER_H
# define FT_PRINTF_PARSER_H

int		read_specifier(const char *specifier, t_format_spec *spec,
		va_list list, bool load);
bool	update_flags(t_format_spec *f, const char c, va_list list, bool load);

#endif
