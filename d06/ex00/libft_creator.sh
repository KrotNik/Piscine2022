#!/bin/bash
gcc -c -Wall -Werror -Wextra ft_putchar.c 
gcc -c -Wall -Werror -Wextra ft_swap.c
gcc -c -Wall -Werror -Wextra ft_putstr.c
gcc -c -Wall -Werror -Wextra ft_strlen.c
gcc -c -Wall -Werror -Wextra ft_strcmp.c

ar rcs libft.a *.o

rm *.o
