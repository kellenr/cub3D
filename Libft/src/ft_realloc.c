/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:16:00 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/28 12:21:53 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Reallocates a memory block with a new size.
  * @param ptr: the pointer to the memory block to reallocate
  * @param old_size: the size of the old memory block
  * @param new_size: the size of the new memory block
  * @return the pointer to the new memory block
 */
void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, new_size);
		free(ptr);
	}
	return (new_ptr);
}
