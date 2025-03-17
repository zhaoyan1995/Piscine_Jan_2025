/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:20:44 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/07 19:35:03 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*result;

	result = malloc(sizeof(t_btree));
	if (result == NULL)
		return (NULL);
	result->item = item;
	result->left = NULL;
	result->right = NULL;
	return (result);
}
