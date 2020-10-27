/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:58:32 by yejeon            #+#    #+#             */
/*   Updated: 2020/10/21 21:58:32 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*result;

	p = (char*)s;
	result = 0;
	while (*p)
	{
		if (*p == c)
			result = p;
		p++;
	}
	return (result);
}
