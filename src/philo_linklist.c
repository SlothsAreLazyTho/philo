/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_linklist.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 17:12:46 by cbijman       #+#    #+#                 */
/*   Updated: 2023/09/19 16:34:08 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*ps_newlst(t_philosopher *philo)
{
	t_table	*table;

	table = ft_calloc(1, sizeof(t_table));
	if (!table)
		return (NULL);
	table->philo = philo;
	table->next = NULL;
	return (table);
}

void	ps_lstadd_back(t_table **lst, t_table *nlst)
{
	t_table	*node;

	if (!*lst)
	{
		*lst = nlst;
		return ;
	}
	node = (*lst);
	while (node->next)
		node = node->next;
	node->next = nlst;
}

int	ps_lstsize(t_table **lst)
{
	t_table	*node;
	size_t	i;

	node = *lst;
	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
