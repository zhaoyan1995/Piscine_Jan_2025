/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_btree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:13:49 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/17 17:45:09 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	free_btree(t_btree *root)
{
	if (root == NULL)
		return ;
	if (root->left)
		free_btree(root->left);
	if (root->right)
		free_btree(root->right);
	free(root);
}
