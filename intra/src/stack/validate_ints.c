/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:46:03 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/09 11:21:19 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/**
 * Checks for duplicates in an array.
 * @param arr The array to check.
 * @param len The length of the array.
 * @return true if duplicates are found, false otherwise.
 */
bool	is_duplicate_in_array(int *arr, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 1)
		return (false);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j++])
			{
				write(STDERR_FILENO, "Error\n", 6);
				return (true);
			}
		}
		i++;
	}
	return (false);
}

/**
 * Converts string stack to integer stack and validates.
 * @param str_stack The string stack.
 * @param len The length of the stack.
 * @return The integer stack or NULL on error.
 */
int	*get_valid_ints(char **str_stack, size_t len)
{
	int		*int_stack;
	int		error;
	size_t	i;

	int_stack = malloc(sizeof(int) * len);
	if (!int_stack)
		return (NULL);
	i = 0;
	while (i < len)
	{
		int_stack[i] = ft_atoier(str_stack[i], &error);
		if (error != 0)
		{
			write(STDERR_FILENO, "Error\n", 6);
			free(int_stack);
			return (NULL);
		}
		i++;
	}
	if (is_duplicate_in_array(int_stack, len))
	{
		free(int_stack);
		return (NULL);
	}
	return (int_stack);
}
