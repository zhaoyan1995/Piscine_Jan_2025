/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:53:02 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/16 23:51:06 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}	t_btree;

typedef struct s_queue
{
	int		front;
	int		rear;
	int		max_size;
	int		nbr_current_level;
	int		nbr_next_level;
	t_btree	**node;
}	t_queue;

t_btree	*btree_create_node(void *item);

#endif
