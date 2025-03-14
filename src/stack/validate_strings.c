/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:46:09 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/09 11:21:19 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/**
 * Checks if a string contains only spaces.
 * @param str The string to check.
 * @return true if the string contains only spaces, false otherwise.
 */
bool	is_only_spaces_str(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (false);
		str++;
	}
	write(STDERR_FILENO, "Error\n", 6);
	return (true);
}

/**
 * Checks if a string is empty.
 * @param str The string to check.
 * @return true if the string is empty, false otherwise.
 */
bool	is_empty_str(char *str)
{
	if (*str)
		return (false);
	else
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (true);
	}
}

/**
 * Validates a string.
 * @param str The string to validate.
 * @return true if the string is valid, false otherwise.
 */
bool	is_valid_str(char *str)
{
	if (is_empty_str(str))
		return (false);
	else if (is_only_spaces_str(str))
		return (false);
	else
		return (true);
}

/**
 * Converts argv to a valid string stack.
 * @param argv The argument vector.
 * @return The valid string stack or NULL on error.
 */
// char	**get_valid_strings(char **argv)
// {
// 	char	**str_stack;
// 	char	**tmp_split;
// 	char	**tmp_join;

// 	str_stack = NULL;
// 	while (*argv)
// 	{
// 		if (!is_valid_str(*argv))
// 			return ((void *)free2(0, str_stack, NULL));
// 		tmp_split = ft_split(*argv, ' ');
// 		if (!tmp_split)
// 			return ((void *)free2(0, str_stack, NULL));
// 		tmp_join = ft_parrjoin(str_stack, tmp_split);
// 		free(tmp_split);
// 		if (!tmp_join)
// 			return ((void *)free2(0, str_stack, NULL));
// 		str_stack = tmp_join;
// 		argv++;
// 	}
// 	return (str_stack);
// }
char	**get_valid_strings(char **argv)
{
	char	**str_stack;
	char	**tmp_split;
	char	**tmp_join;

	str_stack = NULL;
	while (*argv)
	{
		if (!is_valid_str(*argv))
			return ((void *)ft_parrclean(0, free, str_stack, NULL));
		tmp_split = ft_split(*argv, ' ');
		if (!tmp_split)
			return ((void *)ft_parrclean(0, free, str_stack, NULL));
		tmp_join = ft_parrjoin(str_stack, tmp_split);
		if (!tmp_join)
			return ((void *)ft_parrclean(0, free, str_stack, tmp_split));
		free(str_stack);
		free(tmp_split);
		str_stack = tmp_join;
		argv++;
	}
	return (str_stack);
}
