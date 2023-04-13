/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_memset_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:45:27 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/13 21:52:12 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_bzero_memset_test(void)
{
	char	buf[500];
	size_t	k;

	ASSERT(ft_memset(buf, 'a', sizeof(buf)) == buf, "memset ret dest");
	k = 0;
	while (k < sizeof(buf))
	{
		if (buf[k] != 'a')
			break ;
		++k;
	}
	ASSERT(k == sizeof(buf), "memset");
	ft_bzero(buf, sizeof(buf));
	k = 0;
	while (k < sizeof(buf))
	{
		if (buf[k] != '\0')
			break ;
		++k;
	}
	ASSERT(k == sizeof(buf), "bzero");
}

int	main(void)
{
	EXEC_TEST(ft_bzero_memset_test, "bzero/memset");
	return (0);
}
