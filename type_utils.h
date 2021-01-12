/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:31:19 by ttranche          #+#    #+#             */
/*   Updated: 2020/11/24 01:26:28 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_UTILS_H
# define TYPE_UTILS_H

# include "ft_printf.h"

void	print_padding(int len, bool pre, t_format_spec *spec);
int		pad(int len, t_format_spec *spec);
int		ft_print_nbr(unsigned long long offset, int len, char *hex);
int		get_len(unsigned long long offset, int size);
char	*get_pre(long neg, t_format_spec *spec);

#endif
