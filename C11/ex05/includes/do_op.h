/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:45:42 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/07 18:48:41 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

int		check_op(char c);
int		ft_atoi(char *str);
int		add(int a, int b);
int		soustraction(int a, int b);
int		multiple(int a, int b);
int		divide(int a, int b);
int		modulo(int a, int b);
int		ft_strlen(char *str);
void	ft_putnbr(int nb);
void	calculate(int a, char c, int b);

#endif
