/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccribe <luccribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:18:18 by luccribe          #+#    #+#             */
/*   Updated: 2025/11/19 21:18:20 by luccribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(va_list *ptr);
int	ft_print_string(va_list *ptr);
int	ft_print_pointer(va_list *ptr);
int	ft_print_int(va_list *ptr);
int	ft_print_unsigned(va_list *ptr);
int	ft_print_hex(va_list *ptr, char upper_or_lower);

#endif
