//DO NOT UPLOAD!!! ONLY FOR TESTING!!!
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret1, ret2;

    // Test: Simple string
    ret1 = ft_printf("Hello, world!\n");
    ft_printf("Printed %d characters above.\n\n", ret1);

    // Test: Integer
    ret1 = ft_printf("Integer: %d\n", 42);
    ret2 = printf("Integer: %d\n", 42);
    ft_printf("ft_printf: %d chars, printf: %d chars\n\n", ret1, ret2);

    // Test: String
    ret1 = ft_printf("String: %s\n", "42 Network");
    ret2 = printf("String: %s\n", "42 Network");
    ft_printf("ft_printf: %d chars, printf: %d chars\n\n", ret1, ret2);

    // Test: Char
    ret1 = ft_printf("Char: %c\n", 'A');
    ret2 = printf("Char: %c\n", 'A');
    ft_printf("ft_printf: %d chars, printf: %d chars\n\n", ret1, ret2);

    // Test: Hexadecimal (lowercase and uppercase)
    ret1 = ft_printf("Hex (lower): %x\n", 255);
    ret2 = printf("Hex (lower): %x\n", 255);
    ft_printf("ft_printf: %d chars, printf: %d chars\n", ret1, ret2);

    ret1 = ft_printf("Hex (upper): %X\n", 255);
    ret2 = printf("Hex (upper): %X\n", 255);
    ft_printf("ft_printf: %d chars, printf: %d chars\n\n", ret1, ret2);

    // Test: Unsigned
    ret1 = ft_printf("Unsigned: %u\n", 4294967295u);
    ret2 = printf("Unsigned: %u\n", 4294967295u);
    ft_printf("ft_printf: %d chars, printf: %d chars\n\n", ret1, ret2);

    // Test: Pointer (address)
    int x = 42;
    ret1 = ft_printf("Pointer: %p\n", &x);
    ret2 = printf("Pointer: %p\n", &x);
    ft_printf("ft_printf: %d chars, printf: %d chars\n\n", ret1, ret2);

    // Test: Null string
    ret1 = ft_printf("Null string: %s\n", (char *)0);
    ret2 = printf("Null string: %s\n", (char *)0);
    ft_printf("ft_printf: %d chars, printf: %d chars\n\n", ret1, ret2);

    // Test: Percent sign
    ret1 = ft_printf("Percent: %%\n");
    ret2 = printf("Percent: %%\n");
    ft_printf("ft_printf: %d chars, printf: %d chars\n\n", ret1, ret2);

    return 0;
}
