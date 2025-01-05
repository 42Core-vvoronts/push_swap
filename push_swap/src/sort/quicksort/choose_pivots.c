/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_pivots.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:43:49 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:43:51 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * choose_pivots - chooses the pivots for the quicksort patririon
 * 
 * @tmp: the temporary array to store the values
 * @len: the len of the chunk
 * @pivmin: pointer to store the first pivot
 * @pivmax: pointer to store the second pivot
 * 
 */
void	choose_pivots(t_data *data, t_chunk *src, int *pivmin, int *pivmax)
{
	int	*tmp;
	int	len;
	int	i;

	i = 0;
	len = src->len;
	if (len <= 1)
		return ;
	tmp = malloc(sizeof(int) * len);
	if (!tmp)
		exit(FAIL);
	ft_memset(tmp, 0, sizeof(int) * len);
	while (i < len)
	{
		tmp[i] = get_value(data, src, i);
		i++;
	}
	tmp_insertion_sort(tmp, 0, len - 1);
	*pivmin = tmp[len / 3];
	*pivmax = tmp[2 * len / 3];
	free(tmp);
}

void	tmp_insertion_sort(int *arr, int left, int right)
{
	int	i;
	int	j;
	int	key;

	i = left + 1;
	while (i <= right)
	{
		key = arr[i];
		j = i - 1;
		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}
