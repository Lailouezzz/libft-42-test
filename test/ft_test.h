/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:12:43 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/14 08:37:16 by ale-boud         ###   ########.fr       */
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
#define FT_ASSERT(b, s) if (!(b)) { failure((s)); } else { ok(s); }
#define EXEC_TEST(f, id) {printf("[\033[1;30mtest\e[0m]\t\033[4;33m" id "\e[0m: ");f();printf("\n");}

static void	failure(const char *s)
{
	printf("\033[1;31mFAIL(%s)\e[0m ", s);
}

static void ok(const char *s)
{
	printf("\033[1;32mOK(%s)\e[0m ", s);
}

void	memrand(void *p, size_t n)
{
	while (n != 0)
	{
		--n;
		((char *)p)[n] = rand() % 0xFF;
	}
}

void	strrand(char *p, size_t n)
{
	if (n == 0)
		return ;
	n = rand() % n;
	p[n] = '\0';
	while (n != 0)
	{
		--n;
		((char *)p)[n] = (rand() % ('z' - 'A')) + 'A';
	}
}


#endif
