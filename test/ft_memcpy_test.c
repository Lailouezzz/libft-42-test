/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 08:21:16 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/14 08:29:25 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_memcpy_test(void)
{
	char	buf[500];
	size_t	k;

	buf[499] = 0;
	memset(buf, 'z', 250);
	FT_ASSERT(ft_memcpy(buf + 250, buf, 249) == buf + 250, "memcpy ret dst");
	k = 0;
	while (k < sizeof(buf) - 1)
	{
		if (buf[k] != 'z')
			break ;
		++k;
	}
	FT_ASSERT(buf[499] == 0 && k == sizeof(buf) - 1, "memcpy");
}

int	main(void)
{
	EXEC_TEST(ft_memcpy_test, "memcpy");
	return (0);
}
