/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antsitsk <antsitsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:05:38 by antsitsk          #+#    #+#             */
/*   Updated: 2025/04/23 11:48:28 by antsitsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//for strmapi
char ft_toupper_wrapper(unsigned int index, char c)
{
	(void)index;
    if (c >= 'a' && c <= 'z')
        return (c - 32); // Convert lowercase to uppercase
    return c; // Return unchanged character if it's not a lowercase letter
}

//for striteri
void	iter_func(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}


int	main(void)
{
	//test isalpha
	printf("ft_isalpha('A'): %d\n", ft_isalpha('A'));
	printf("ft_isalpha('1'): %d\n", ft_isalpha('1'));

	//test isdigit
	printf("ft_isdigit('8'): %d\n", ft_isdigit('8'));
	printf("ft_isdigit('a'): %d\n", ft_isdigit('a'));

	//test isalnum
	printf("ft_isalnum('A'): %d\n", ft_isalnum('A'));
	printf("ft_isalnum('!'): %d\n", ft_isalnum('!'));

	//test isascii
	printf("ft_isascii('A'): %d\n", ft_isascii('A'));
	printf("ft_isascii(128): %d\n", ft_isascii(128));

	//test isprint
	printf("ft_isprint('!'): %d\n", ft_isprint('!'));
	printf("ft_isprint(127): %d\n", ft_isprint(127));

	//test strlen
	printf("ft_strlen: %zu\n", ft_strlen("Hello World"));

	//test memset
	char str3[] = "Hello";
	ft_memset(str3, 'a', 3);
	printf("ft_memset: %s\n", str3); //should print "aaalo"

	//test bzero
	char str2[] = "Hello, World!";
	ft_bzero(str2, 5);
	printf("ft_bzero(ascii values): ");
	for (int i = 0; i < 5; i++)
		printf("%d ", (unsigned char)str2[i]);
	printf("\n");//should print "     World!"

	//test memcpy
	char str6[10];
	ft_memcpy(str6, "Hello", 5);
	printf("ft_memcpy: %s\n", str6); //should print "Hello"

	//test memmove
	char str7[] = "Hello, World!";
	ft_memmove(str7 + 7, str7, 6);
	printf("ft_memmove: %s\n", str7); //should print "Hello, Hello"

	//test strlcpy
	char str10[20];
	printf("ft_strlcpy: %zu\n", ft_strlcpy(str10, "Hello", 20)); //should print 5
	printf("Resulting string: %s\n", str10); //should print "Hello"

	//test strlcat
	char str9[20] = "Hello";
	printf("ft_strlcat: %zu\n", ft_strlcat(str9, " World", 20));
	printf("Resulting string: %s\n", str9);

	//test toupper
	printf("ft_toupper: %d\n", ft_toupper('a'));

	//test tolower
	printf("ft_tolower: %d\n", ft_tolower('A'));

	//test strchr
	printf("ft_strchr: %s\n", ft_strchr("Hello World", 'o'));

	//test strrchr
	printf("ft_strrchr: %s\n", ft_strrchr("Hello World", 'o'));

	//test strncmp
	printf("ft_strncmp: %d\n", ft_strncmp("abc", "abc", 3));
	printf("ft_strncmp: %d\n", ft_strncmp("abc", "abd", 3));

	//test memchr
	char str11[] = "Find the letter!";
	char *memchr_result = (char *)ft_memchr(str11, 'l', ft_strlen(str11));
	if (memchr_result)
		printf("ft_memchr: Found '%c' at position: %ld\n", *memchr_result, memchr_result - str11);
	else
		printf("ft_memchr: Character not found\n");

	//test memcmp
	char str4[] = "abc";
	char str5[] = "abc";
	printf("ft_memcmp: %d\n", ft_memcmp(str4, str5, 3));

	//test strnstr
	printf("ft_strnstr: %s\n", ft_strnstr("Hello World", "World", 12));

	//test atoi
	char str1[] = "42";
	printf("ft_atoi: %d\n", ft_atoi(str1));

	//test calloc
	char *calloc_result = ft_calloc(10, sizeof(char));
	printf("ft_calloc: %s\n", calloc_result);
	free(calloc_result);

	//test strdup
	char *str8 = ft_strdup("Hello");
	printf("ft_strdup: %s\n", str8);
	free(str8);

	//test substr
	char *s = "Hello, World!";
	char *substring = ft_substr(s, 7, 5);
	printf("Substring: %s\n", substring); //output: "World"
	free(substring);

	//test strjoin
	char	*result = ft_strjoin("Hello, ", "World!");
	printf("%s\n", result);
	free(result);

	//test strtrim
	printf("%s\n", ft_strtrim("--hello--", "-"));

	//test split
	char **res = ft_split("hi there", ' ');
	printf("%s\n%s\n", res[0], res[1]);

	//test itoa
	printf("%s\n", ft_itoa(42));
	printf("%s\n", ft_itoa(-42));
	printf("%s\n", ft_itoa(0));
	
	//test strmapi
	// Test ft_strmapi with the string "hello" and the ft_toupper_wrapper function
    char *result1 = ft_strmapi("hello", ft_toupper_wrapper);
    
    if (result1)
    {
        // Should print "HELLO"
        printf("Result: %s\n", result1);
        free(result1); // Don't forget to free the memory allocated by ft_strmapi
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

	//test striteri
	char str[] = "hello42";
	ft_striteri(str, iter_func);
	printf("After ft_striteri: %s\n", str);

	//test ft_putchar_fd
	ft_putchar_fd('A', 1);
    ft_putchar_fd('\n', 1);

	//test ft_putstr_fd
	ft_putstr_fd("Hello, 42!\n", 1);

	//test ft_putendl_fd
	ft_putendl_fd("This is a line with a newline at the end.", 1);
    ft_putendl_fd("Another line, same deal!", 1);
    ft_putendl_fd(NULL, 1); // Should do nothing (graceful null check)

	//test ft_putnbr_fd
	ft_putnbr_fd(42, 1);         // prints: 42
    ft_putchar_fd('\n', 1);

    ft_putnbr_fd(-12345, 1);     // prints: -12345
    ft_putchar_fd('\n', 1);

    ft_putnbr_fd(0, 1);          // prints: 0
    ft_putchar_fd('\n', 1);

    ft_putnbr_fd(2147483647, 1); // prints: 2147483647 (INT_MAX)
    ft_putchar_fd('\n', 1);

    ft_putnbr_fd(-2147483648, 1); // prints: -2147483648 (INT_MIN)
    ft_putchar_fd('\n', 1);

	return (0);
}
