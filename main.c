/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 07:06:42 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/12 09:49:40 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#define ASSERT(b) if (!(b)) { failure(); }
#define EXEC_TEST(f, id) printf("[test]\t" id "... ");f();printf("Ok\n");

/* Utils */

void	failure(void)
{
	printf("error\n");
	exit(EXIT_FAILURE);
}

void	memrand(void *p, size_t n)
{
	while (n != 0)
	{
		--n;
		((char *)p)[n] = rand() % 0xFF;
	}
}

/* Test */

void	ft_to_test(void)
{
	/* toupper */
	ASSERT(FT_TEST(toupper, 'a'));
	ASSERT(FT_TEST(toupper, 'z'));
	ASSERT(FT_TEST(toupper, 'A'));
	ASSERT(FT_TEST(toupper, 'Z'));
	ASSERT(FT_TEST(toupper, 'f'));
	ASSERT(FT_TEST(toupper, 'R'));
	ASSERT(FT_TEST(toupper, ';'));
	/* tolower */
	ASSERT(FT_TEST(tolower, 'a'));
	ASSERT(FT_TEST(tolower, 'z'));
	ASSERT(FT_TEST(tolower, 'A'));
	ASSERT(FT_TEST(tolower, 'Z'));
	ASSERT(FT_TEST(tolower, 'f'));
	ASSERT(FT_TEST(tolower, 'R'));
	ASSERT(FT_TEST(tolower, ';'));
}

void	ft_bzero_memset_test(void)
{
	char	buf[500];
	size_t	k;

	ft_memset(buf, 'a', sizeof(buf));
	k = 0;
	while (k < sizeof(buf))
	{
		ASSERT(buf[k] == 'a');
		++k;
	}
	ft_bzero(buf, sizeof(buf));
	k = 0;
	while (k < sizeof(buf))
	{
		ASSERT(buf[k] == '\0');
		++k;
	}
}

void	ft_memcpy_test(void)
{
	char	buf[500];
	size_t	k;

	memset(buf, 'z', 250);
	ft_memcpy(buf + 250, buf, 250);
	k = 0;
	while (k < sizeof(buf))
	{
		ASSERT(buf[k] == 'z');
		++k;
	}
}

void	ft_memmove_test(void)
{
	char	buf[500];
	char	buf2[500];
	size_t	k;

	memrand(buf, 250);
	memcpy(buf2, buf, 250);
	ASSERT(ft_memmove(buf + 50, buf, 250) == buf + 50);
	k = 0;
	while (k < 250)
	{
		ASSERT(buf[k + 50] == buf2[k]);
		++k;
	}
	memrand(buf + 200, 250);
	memcpy(buf2, buf + 200, 250);
	ASSERT(ft_memmove(buf, buf + 200, 250) == buf);
	k = 0;
	while (k < 250)
	{
		ASSERT(buf[k] == buf2[k]);
		++k;
	}
}

void	ft_memcmp_test(void)
{
	char	buf[500];
	char	buf2[500];

	memrand(buf, 500);
	memcpy(buf2, buf, 500);
	ASSERT(FT_TEST_CMP(memcmp, buf, buf2, 500));
	memset(buf, 'a', 500);
	memset(buf2, 'a', 500);
	ASSERT(FT_TEST_CMP(memcmp, buf, buf2, 500));
}

void	ft_memchr_test(void)
{
	char	buf[256];

	memrand(buf, 256);
	ASSERT(FT_TEST(memchr, buf, 'a', 256));
}

int	main(void)
{
	srand(time(NULL));
	EXEC_TEST(ft_to_test, "toupper/tolower");
	EXEC_TEST(ft_bzero_memset_test, "bzero/memset");
	EXEC_TEST(ft_memcpy_test, "memcpy");
	EXEC_TEST(ft_memmove_test, "memmove");
	EXEC_TEST(ft_memcmp_test, "memcmp");
	EXEC_TEST(ft_memchr_test, "memchr");
	return (EXIT_SUCCESS);
}
