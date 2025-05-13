/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:12:36 by obajja            #+#    #+#             */
/*   Updated: 2025/05/12 15:18:42 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void *philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->thread_id % 2 == 0)
		{
			lock left fork;
			lock right fork;
		}
		if (philo->thread_id % 2 != 0)
			wait (100ms)
			lock left fork
			lock right fork
	}

}
