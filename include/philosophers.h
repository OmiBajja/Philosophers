/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:07:59 by obajja            #+#    #+#             */
/*   Updated: 2025/05/12 15:19:36 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct	s_data
{
	int					nb_philo;
	long				tt_die;
	long				tt_eat;
	long				tt_sleep;
	int					must_eat;
}				t_data;

typedef struct	s_philo
{
	int					thread_id;
	int					last_meal;
	int					meal_count;
	pthread_mutex_t		meal_data;	
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}				t_philo;

typedef struct s_env
{
	t_philo		*philo;
	t_data		*data;

}	t_env;

void	*ft_calloc(size_t elementCount, size_t elementSize);
int		ft_atoi(const char *str);
void 	data_print(t_env *env);
int		data_init(t_env *env, char **argv, int argc);
int 	philo_init(t_env *env);
void 	*philo_routine(void *arg);
void	meal_prep(t_philo *philo);

#endif