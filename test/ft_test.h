/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:12:43 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/13 21:49:45 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_TEST_H
# define FT_TEST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <bsd/string.h>
#include "libft.h"

#define FT_TEST(f, ...) ft_##f(__VA_ARGS__) == f(__VA_ARGS__)
#define FT_TEST_CMP(f, ...) ft_##f(__VA_ARGS__) == f(__VA_ARGS__) \
						|| (ft_##f(__VA_ARGS__) > 0 && f(__VA_ARGS__) > 0) \
						|| (ft_##f(__VA_ARGS__) < 0 && f(__VA_ARGS__) < 0)
#define ASSERT(b, s) if (!(b)) { failure((s)); } else { ok(s); }
#define ASSERT_F_B(b, s) if (!(b)) { failure((s));break ; }
#define EXEC_TEST(f, id) {printf("[test]\t" id "... ");f();printf("\n");}

static void	failure(const char *s)
{
	printf("FAIL (%s) ", s);
}

static void ok(const char *s)
{
	printf("OK (%s) ", s);
}

#endif
