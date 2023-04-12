/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 07:06:42 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/12 10:46:24 by ale-boud         ###   ########.fr       */
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
#define EXEC_TEST(f, id, time) {printf("[test]\t" id "... ");int k = time;while(k--!=0){f();}printf("Ok\n");}

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

	ASSERT(ft_memset(buf, 'a', sizeof(buf)) == buf);
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
	ASSERT(ft_memcpy(buf + 250, buf, 250) == buf + 250);
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

void	ft_strlen_test(void)
{
	char	buf[50];

	strrand(buf, 50);
	ASSERT(FT_TEST(strlen, buf));
}

void	ft_strlcpy_strlcat_test(void)
{
	char	buf[30];
	char	buf2[30];
	char	buf3[30];
	char	buf4[30];

	strrand(buf, 15);
	ASSERT(ft_strlcpy(buf2, buf, 10) == strlcpy(buf3, buf, 10));
	ASSERT(strcmp(buf2, buf3) == 0);
	strrand(buf4, 10);
	strcpy(buf, buf4);
	ASSERT(strlcat(buf, buf2, 20) == ft_strlcat(buf4, buf2, 20));
	ASSERT(strcmp(buf, buf4) == 0);
}

void	ft_strchr_strrchr_test(void)
{
	char	buf[256];

	strrand(buf, 256);
	ASSERT(FT_TEST(strchr, buf, 'a'));
	ASSERT(FT_TEST(strrchr, buf, 'a'));
}

void	ft_strnstr_test(void)
{
	char	big[100];
	char	little[100];

	strrand(big, 20);
	strrand(little, 3);
	ASSERT(FT_TEST(strnstr, big, little, 5));
	ASSERT(FT_TEST(strnstr, big, little, 15));
	ASSERT(FT_TEST(strnstr, big, little, 15));
	ASSERT(FT_TEST(strnstr, little, little, 15));
	ASSERT(FT_TEST(strnstr, little, big, 25));
}

int	main(int argc, char **argv)
{
	int n = 1;
	if (argc >= 2)
		n = atoi(argv[1]);
	if (argc >= 3)
		srand(atoi(argv[2]));
	else
	{
		unsigned int	t = time(NULL);
		printf("SEED : %u\n", t);
		srand(t);
	}
	EXEC_TEST(ft_to_test, "toupper/tolower", 1);
	EXEC_TEST(ft_bzero_memset_test, "bzero/memset", 1);
	EXEC_TEST(ft_memcpy_test, "memcpy", 1);
	EXEC_TEST(ft_memmove_test, "memmove", n);
	EXEC_TEST(ft_memcmp_test, "memcmp", n);
	EXEC_TEST(ft_memchr_test, "memchr", n);
	EXEC_TEST(ft_strlen_test, "strlen", n);
	EXEC_TEST(ft_strlcpy_strlcat_test, "strlcpy/strlcat", n);
	EXEC_TEST(ft_strchr_strrchr_test, "strchr/strrchr", n);
	EXEC_TEST(ft_strnstr_test, "strnstr", n);
	return (EXIT_SUCCESS);
}
