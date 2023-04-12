/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 07:06:42 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/12 08:50:53 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <bsd/string.h>
#include "libft.h"

#define FT_TEST(f, ...) ft_##f(__VA_ARGS__) == f(__VA_ARGS__)
#define ASSERT(b) if (!(b)) { failure(); }
#define EXEC_TEST(f, id) printf("[test]\t" id "... ");f();printf("Ok\n");

void	failure(void)
{
	fprintf(stderr, "error");
	exit(EXIT_FAILURE);
}

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

int	main(void)
{
	EXEC_TEST(ft_to_test, "toupper/tolower");
	return (0);
}
