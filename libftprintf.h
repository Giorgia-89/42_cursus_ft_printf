/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:52:27 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/24 10:47:04 by giorgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_base(unsigned int n, char *base);
int		ft_pointer(unsigned long ptr);
int		ft_printf(const char *str, ...);
int		ft_strcmp(char *s1, char *s2);

#endif