/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:14:31 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/12 15:26:06 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	length_left;
	int	length_right;

	if (!root)
		return (0);
	length_left = btree_level_count(root->left);
	length_right = btree_level_count(root->right);
	if (length_left > length_right)
		return (length_left + 1);
	else
		return (length_right + 1);
}
