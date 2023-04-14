/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:09:28 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/14 08:50:58 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_strlen_test(void)
{
	FT_ASSERT(FT_TEST(strlen, ""), "strlen1");
	FT_ASSERT(FT_TEST(strlen, "42"), "strlen2");
	FT_ASSERT(FT_TEST(strlen, "1111111111111"), "strlen3");
}

int	main(void)
{
	EXEC_TEST(ft_strlen_test, "strlen");
	return (0);
}
