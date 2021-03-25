/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 00:11:28 by yejeon            #+#    #+#             */
/*   Updated: 2021/03/25 08:27:11 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H	
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdio.h>

# define TYPE "csdiupxX%"
# define FLAG "-0"

typedef struct	s_info
{
	char		flag;
	int			width;
	char		dot;
	int			length;
	char		type;
}				t_info;


int		ft_printf(const char *format, ...);

char	is_type(char ch);
int		is_flag(char ch);
int		print_char_while(char ch, int i);
char	*get_str_by_info(t_info *info, size_t n);
void	print_info(t_info *info);


int		print_char(t_info *info, int ch);
int		print_int(t_info *info, int n);
int		print_str(t_info *info, char *s);
int		print_pointer(t_info *info, char *p);
int		print_uint(t_info *info, unsigned int p);

#endif
