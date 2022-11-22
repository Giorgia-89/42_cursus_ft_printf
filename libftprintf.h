/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:52:27 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/22 15:18:09 by giorgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>

//should putchar return 1?
void	ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_printf(const char *str, ...)
//these do not work! they print in reverse. Is the error in the main?
//or do i need to use lstaddback?
//char	*ft_putlowerhex(int n); 
//char	*ft_putupperhex(int n);



#endif