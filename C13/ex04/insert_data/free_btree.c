/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_btree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:53:40 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/13 18:59:09 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	free_btree(t_btree *root)
{
	if (!root)
		return ;
	free_btree(root->left);
	free_btree(root->right);
	free(root);
}
