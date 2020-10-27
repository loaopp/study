/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:43:41 by yejeon            #+#    #+#             */
/*   Updated: 2020/10/18 13:43:41 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (dest[i])
		i++;
	if (i < size)
	{
		while (src[j] && (i + j < size))
		{
			dest[i + j] = src[j];
			j++;
		}
		if (i + j == size)
			dest[size - 1] = 0;
		else
			dest[i + j] = 0;
	}
	while (src[j])
		j++;
	if (i < size)
		return (i + j);
	else
		return (size + j);
}
