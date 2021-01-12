/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:11:05 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/23 18:36:33 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_HANDLER_H
# define TYPE_HANDLER_H

# include "ft_printf.h"

int		get_type(t_format_spec *spec, char c);

int		print_char(t_format_spec *spec, va_list list);
int		print_float(t_format_spec *spec, va_list list);
int		print_int(t_format_spec *spec, va_list list);
int		print_string(t_format_spec *spec, va_list list);
int		print_pointer(t_format_spec *spec, va_list list);
int		print_hex(t_format_spec *spec, va_list list);
int		print_percent(t_format_spec *spec, va_list list);

#endif
