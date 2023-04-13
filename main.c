/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 07:06:42 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/13 21:10:08 by ale-boud         ###   ########.fr       */
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
	ASSERT(FT_TEST(strncmp, "test\200", "test\0", 6))
}

void	ft_strjoin_test(void)
{
	char	buf1[500];
	char	buf2[500];
	char	*buf3;

	strrand(buf1, 50);
	strrand(buf2, 50);
	buf3 = ft_strjoin(buf1, buf2);
	ASSERT(strncmp(buf1, buf3, strlen(buf1)) == 0);
	ASSERT(strncmp(buf2, buf3 + strlen(buf1), strlen(buf2)) == 0);
	ASSERT(strlen(buf1) + strlen(buf2) == strlen(buf3));
	free(buf3);
}

void	ft_substr_test(void)
{
	char	buf1[50];
	char	*buf2;

	strrand(buf1, 50);
	if (strlen(buf1) == 0)
		return (ft_substr_test());
	int pos = rand() % strlen(buf1);
	buf2 = ft_substr(buf1, pos, 50);
	ASSERT(strstr(buf1, buf2) != NULL);
	ASSERT(strcmp(buf1 + pos, buf2) == 0);
	free(buf2);
}

void	ft_calloc_test(void)
{
	char	*ptr;
	size_t	k;

	ptr = ft_calloc(10, 2);
	k = 0;
	while (k < 20)
	{
		ASSERT(ptr[k] == 0);
		++k;
	}
	free(ptr);
}

void	ft_atoi_test(void)
{
	ASSERT(FT_TEST(atoi, "+42"));
	ASSERT(FT_TEST(atoi, "+0"));
	ASSERT(FT_TEST(atoi, "-0"));
	ASSERT(FT_TEST(atoi, "--+-42"));
	ASSERT(FT_TEST(atoi, "    -525"));
	ASSERT(FT_TEST(atoi, "gsfdjbgnsdf gfdjgdsf498 gjudfhng856"));
	ASSERT(FT_TEST(atoi, "\t+42 8"));
	ASSERT(FT_TEST(atoi, " \n  \t+42   "));
	ASSERT(FT_TEST(atoi, "2147483647"));
	ASSERT(FT_TEST(atoi, "-2147483648"));
}

void	ft_strdup_test(void)
{
	char	buf[15];
	char	*p;

	strrand(buf, 15);
	p = ft_strdup(buf);
	ASSERT(strlen(buf) == strlen(p));
	ASSERT(strcmp(buf, p) == 0);
	free(p);
}

void	ft_strtrim_test(void)
{
	char	*buf1 = "   test       ";
	char	*set1 = " ";
	char	*buf2 = "adcbdaddcdcd";
	char	*set23 = "abcd";
	char	*buf3 = "abdcccdcbagerta6";
	char	*buf4 = "";
	char	*buf5 = "abcd";
	char	*p;

	p = ft_strtrim(buf1, set1);
	ASSERT(strlen(p) == 4);
	ASSERT(strcmp(p, "test") == 0);
	free(p);
	p = ft_strtrim(buf2, set23);
	ASSERT(strlen(p) == 0);
	free(p);
	p = ft_strtrim(buf3, set23);
	ASSERT(strlen(p) == 6);
	ASSERT(strcmp(p, "gerta6") == 0);
	free(p);
	p = ft_strtrim(buf4, "");
	ASSERT(strlen(p) == 0);
	free(p);
	p = ft_strtrim(buf5, "");
	ASSERT(strlen(p) == 4);
	free(p);
	p = ft_strtrim("asde", "");
	ASSERT(strcmp(p, "asde") == 0);
	ASSERT(strlen(p) == 4);
	free(p);
}

void	ft_split_test(void)
{
	char	**p;

	p = ft_split("je suis a 42     a test aaaaaaabaaaa", 'a');
	ASSERT(p[4] == NULL);
	ASSERT(strcmp(p[0], "je suis ") == 0);
	ASSERT(strcmp(p[1], " 42     ") == 0);
	ASSERT(strcmp(p[2], " test ") == 0);
	ASSERT(strcmp(p[3], "b") == 0);
	free(p[0]);
	free(p[1]);
	free(p[2]);
	free(p[3]);
	free(p);
	p = ft_split("aaaje suis 42      test baaaa", 'a');
	ASSERT(strcmp(p[0], "je suis 42      test b") == 0);
	ASSERT(p[1] == NULL);
	free(p[0]);
	free(p);
	p = ft_split("", ' ');
	ASSERT(p[0] == NULL);
	free(p);
}

void	ft_itoa_test(void)
{
	char	*p;

	p = ft_itoa(42);
	ASSERT(strcmp(p, "42") == 0);
	free(p);
	p = ft_itoa(0);
	ASSERT(strcmp(p, "0") == 0);
	free(p);
	p = ft_itoa(-1);
	ASSERT(strcmp(p, "-1") == 0);
	free(p);
	p = ft_itoa(1);
	ASSERT(strcmp(p, "1") == 0);
	free(p);
	p = ft_itoa(-2147483648);
	ASSERT(strcmp(p, "-2147483648") == 0);
	free(p);
	p = ft_itoa(2147483647);
	ASSERT(strcmp(p, "2147483647") == 0);
	free(p);
}

int	main(int argc, char **argv)
{
	int n = 1000;
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
	EXEC_TEST(ft_strnstr_test, "strnstr(ft_strncmp)", n);
	EXEC_TEST(ft_strjoin_test, "strjoin", n);
	EXEC_TEST(ft_substr_test, "substr", n);
	EXEC_TEST(ft_calloc_test, "calloc", n);
	EXEC_TEST(ft_atoi_test, "atoi", 1);
	EXEC_TEST(ft_strdup_test, "strdup", n);
	EXEC_TEST(ft_strtrim_test, "strtrim", 1);
	EXEC_TEST(ft_split_test, "split", 1);
	EXEC_TEST(ft_itoa_test, "itoa", 1);
	return (EXIT_SUCCESS);
}
