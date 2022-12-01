/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_buf_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:24:04 by jduval            #+#    #+#             */
/*   Updated: 2022/11/29 16:33:38 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	cbuf_size(t_cbuf *buffer)
{
	size_t	size = buffer->max;
	
	if (!buffer)
		return (0);
	if (buffer->full == FALSE)
	{
		if (buffer->head >= buffer->tail)
			size = (buffer->head - buffer->tail);
		else 
			size = (buffer->max + buffer->head - buffer->tail);
	}
	return (size);
}

void	reset_cbuf(t_cbuf *buffer)
{
	buffer->head = -1;
	buffer->tail = -1;
	buffer->full = FALSE; 
}

t_bool	cbuf_full(t_cbuf *buffer)
{
	return (buffer->full);
}

t_bool	cbuf_empty(t_cbuf *buffer)
{
	if ((buffer->full == FALSE) && (buffer->head == buffer->tail))
		return (TRUE);
	return (FALSE);
}

t_cbuf	*cbuf_init(int *tab, size_t size)
{
	t_cbuf	*new_cbuf;

	if (!*tab || size <= 0)
		return (NULL);
	new_cbuf = malloc(sizeof(t_cbuf));
	if (new_cbuf == NULL)
		return (NULL);
	new_cbuf->tab = tab;
	new_cbuf->max = size;
	reset_cbuf(new_cbuf);
	if (!cbuf_empty(new_cbuf))
	{
		reset_cbuf(new_cbuf);
		free (new_cbuf);
		return (NULL);
	}
	return (new_cbuf);
}
