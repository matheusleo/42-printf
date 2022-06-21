/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:28:21 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/20 22:20:49 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"
#include <stdio.h>

// bonus

// flag parser functions
char	*is_format_char(char c)
{
	char	*formats;

	formats = "cspiduxX";
	return (ft_strchr(formats, c));
}

t_flags	ft_flag_parser(char *str_flags)
{
	t_flags	flags;

	flags.alt_form = FALSE;
	flags.spaced_form = FALSE;
	flags.signed_form = FALSE;
	while (!is_format_char(*str_flags))
	{
		if (*str_flags == '#')
			flags.alt_form = TRUE;
		if (*str_flags == ' ')
			flags.spaced_form = TRUE;
		if (*str_flags == '+')
			flags.signed_form = TRUE;
		str_flags++;
	}
	return (flags);
}

// color functions
void	set_color(void)
{
	printf("\e[0;95m");
}

void	reset_color(void)
{
	printf("\033[0m");
}

// test functions
void	test_print_hex(void)
{
	char	*example;
	t_flags	used_flags;
	int		returned;

	example = "# +dcsdpiuxX";
	used_flags = flag_parser(example);
	set_color();
	printf("Test #00 - Test flags\n\n");
	reset_color();
	printf("used_flags.alt_form - %d\n", used_flags.alt_form);
	printf("used_flags.spaced_form - %d\n", used_flags.spaced_form);
	printf("used_flags.signed_form - %d\n-------\n", used_flags.signed_form);

	// Function lower hex with flag
	set_color();
	printf("Test #01 - Function lower hex with flag\n\n");
	reset_color();
	printf("Original printf - ");
	returned = printf("%#x", 420);
	printf("\n");
	printf("Original printf returned - %d\n", returned);

	ft_print_str("My function - ");
	returned = ft_print_hex(420, FALSE, used_flags.alt_form); // used_flags.alt_form == TRUE, now
	printf("\n");
	printf("My function returned - %d\n-------\n", returned);

	// Function upper hex with flag
	set_color();
	printf("Test #02 - Function upper hex with flag\n\n");
	reset_color();
	printf("Original printf - ");
	returned = printf("%#X", 420);
	printf("\n");
	printf("Original printf returned - %d\n", returned);

	ft_print_str("My function - ");
	returned = ft_print_hex(420, TRUE, used_flags.alt_form); // used_flags.alt_form == TRUE, now
	printf("\n");
	printf("My function returned - %d\n-------\n", returned);

	// Function lower hex without flag
	set_color();
	printf("Test #03 - Function lower hex without flag\n\n");
	reset_color();
	printf("Original printf - ");
	returned = printf("%x", 420);
	printf("\n");
	printf("Original printf returned - %d\n", returned);

	ft_print_str("My function - ");
	returned = ft_print_hex(420, FALSE, FALSE);
	printf("\n");
	printf("My function returned - %d\n-------\n", returned);

	// Function upper hex without flag
	set_color();
	printf("Test #04 - Function upper hex without flag\n\n");
	reset_color();
	printf("Original printf - ");
	returned = printf("%x", 420);
	printf("\n");
	printf("Original printf returned - %d\n", returned);

	ft_print_str("My function - ");
	returned = ft_print_hex(420, TRUE, FALSE);
	printf("\n");
	printf("My function returned - %d\n-------\n", returned);
}

void	test_print_int(void)
{
	char	*example;
	t_flags	used_flags;
	int		returned;

	example = "+dcsdpiuxX";
	used_flags = flag_parser(example);
	printf("Original string - %s\n\n", example);
	set_color();
	printf("Test #00 - Test flags\n\n");
	reset_color();
	printf("used_flags.alt_form - %d\n", used_flags.alt_form);
	printf("used_flags.spaced_form - %d\n", used_flags.spaced_form);
	printf("used_flags.signed_form - %d\n-------\n", used_flags.signed_form);

	// Function int with flag +
	set_color();
	printf("Test #01 - Function int with flag +\n\n");
	reset_color();
	printf("Original printf - ");
	returned = printf("%+d", 420);
	printf("\n");
	printf("Original printf returned - %d\n", returned);

	ft_print_str("My function - ");
	returned = ft_print_int(420, TRUE, FALSE);
	printf("\n");
	printf("My function returned - %d\n-------\n", returned);

	// Function int with flag ' '
	set_color();
	printf("Test #02 - Function int with flag ' '\n\n");
	reset_color();
	printf("Original printf - ");
	returned = printf("% d", 420);
	printf("\n");
	printf("Original printf returned - %d\n", returned);

	ft_print_str("My function - ");
	returned = ft_print_int(420, FALSE, TRUE);
	printf("\n");
	printf("My function returned - %d\n-------\n", returned);

	// Function int with flag + and ' '
	set_color();
	printf("Test #03 - Function int with flag + and ' '\n\n");
	reset_color();
	printf("Original printf - ");
	returned = printf("%+ d", 420);
	printf("\n");
	printf("Original printf returned - %d\n", returned);

	ft_print_str("My function - ");
	returned = ft_print_int(420, TRUE, TRUE);
	printf("\n");
	printf("My function returned - %d\n-------\n", returned);

	// Function int with flag ' ' and +
	set_color();
	printf("Test #04 - Function int with flag ' ' and +\n\n");
	reset_color();
	printf("Original printf - ");
	returned = printf("% +d", 420);
	printf("\n");
	printf("Original printf returned - %d\n", returned);

	ft_print_str("My function - ");
	returned = ft_print_int(420, TRUE, TRUE);
	printf("\n");
	printf("My function returned - %d\n-------\n", returned);

	// Function int without flags
	set_color();
	printf("Test #05 - Function int without flags\n\n");
	reset_color();
	printf("Original printf - ");
	returned = printf("%d", 420);
	printf("\n");
	printf("Original printf returned - %d\n", returned);

	ft_print_str("My function - ");
	returned = ft_print_int(420, FALSE, FALSE);
	printf("\n");
	printf("My function returned - %d\n-------\n", returned);
}

int main(void)
{
	test_print_int();
}
