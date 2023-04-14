/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_memset_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:45:27 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/14 08:39:52 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_memset_test(void)
{
	char	buf[500];
	size_t	k;

	FT_ASSERT(ft_memset(buf, 'a', sizeof(buf)) == buf, "memset ret dest");
	k = 0;
	while (k < sizeof(buf))
	{
		if (buf[k] != 'a')
			break ;
		++k;
	}
	FT_ASSERT(k == sizeof(buf), "memset");
}

int	main(void)
{
	EXEC_TEST(ft_memset_test, "memset");
	return (0);
}
