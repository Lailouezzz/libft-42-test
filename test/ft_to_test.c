/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:09:28 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/13 21:39:39 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_to_test(void)
{
	/* toupper */
	ASSERT(FT_TEST(toupper, 'a')
		&& FT_TEST(toupper, 'z')
		&& FT_TEST(toupper, 'Z')
		&& FT_TEST(toupper, 'f')
		&& FT_TEST(toupper, 'T')
		&& FT_TEST(toupper, '4')
		&& FT_TEST(toupper, '\t')
		&& FT_TEST(toupper, '\0')
		&& FT_TEST(toupper, 'A'), "toupper");
	/* tolower */
	ASSERT(FT_TEST(tolower, 'a')
		&& FT_TEST(tolower, 'z')
		&& FT_TEST(tolower, 'Z')
		&& FT_TEST(tolower, 'f')
		&& FT_TEST(tolower, 'T')
		&& FT_TEST(tolower, '4')
		&& FT_TEST(tolower, '\t')
		&& FT_TEST(tolower, '\0')
		&& FT_TEST(tolower, 'A'), "toupper");
}

int	main(void)
{
	EXEC_TEST(ft_to_test, "toupper/tolower");
	return (0);
}
