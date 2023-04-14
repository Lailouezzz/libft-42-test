/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 08:39:28 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/14 08:48:03 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_bzero_test(void)
{
	char	buf[500];
	int		k;

	memset(buf, 'z', 500);
	ft_bzero(buf, 0);
	FT_ASSERT(*buf == 'z', "bzero1");
	ft_bzero(buf, 42);
	k = 0;
	while (k < 100 && buf[k] == 0)
		++k;
	FT_ASSERT(k == 42 && buf[42] == 'z', "bzero2");
	memset(buf, 'z', 500);
	*buf = 0;
	ft_bzero(buf, 42);
	k = 0;
	while (k < 100 && buf[k] == 0)
		++k;
	FT_ASSERT(k == 42 && buf[42] == 'z', "bzero3");
}

int	main(void)
{
	EXEC_TEST(ft_bzero_test, "bzero");
	return (0);
}
