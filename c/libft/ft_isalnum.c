/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:22:03 by yejeon            #+#    #+#             */
/*   Updated: 2020/10/29 11:08:57 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	return (('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || \
			('a' <= c && c <= 'z'));
}
