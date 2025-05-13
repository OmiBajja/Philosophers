/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:11:43 by obajja            #+#    #+#             */
/*   Updated: 2025/05/11 12:45:48 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void data_print(t_env *env)
{
	printf("Nb_Philo: %d\n",env->data->nb_philo);
	printf("Tt_die: %ld\n",env->data->tt_die);
	printf("Tt_eat: %ld\n",env->data->tt_eat);
	printf("Tt_sleep: %ld\n",env->data->tt_sleep);
}

int philo_create(t_env *env, pthread_mutex_t *forks, pthread_t 	*threads)
{
	int	i;

	i = 0;
	while (i < env->data->nb_philo)
	{
		env->philo[i].thread_id = i + 1;
		env->philo[i].last_meal = 0;
		env->philo[i].meal_count = 0;
		pthread_mutex_init(&env->philo[i].meal_data, NULL);
		env->philo[i].left_fork = &forks[i];
		env->philo[i].right_fork = &forks[(i + 1) % env->data->nb_philo];
		if (pthread_create(&threads[i], NULL, philo_routine, &env->philo[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int philo_init(t_env *env)
{
	int				i;
	pthread_t 		*threads;
	pthread_mutex_t *forks;
	
	i = 0;
	env->philo = ft_calloc(env->data->nb_philo, sizeof(t_philo));
	if (!env->philo)
		return (EXIT_FAILURE);
	threads = ft_calloc(env->data->nb_philo, sizeof(pthread_t));
	if (!threads)
		return (EXIT_FAILURE);
	forks = ft_calloc(env->data->nb_philo, sizeof(pthread_mutex_t));
	if (!forks)
		return (EXIT_FAILURE);
	while (i < env->data->nb_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL))
			return (EXIT_FAILURE);
		i++;
	}
	return (philo_create(env, forks, threads));
}

int	data_init(t_env *env, char **argv, int argc)
{
	env->data = ft_calloc(1, sizeof(t_data));
	if (!env->data)
		return (EXIT_FAILURE);
	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	env->data->nb_philo = ft_atoi(argv[1]);
	env->data->tt_die = ft_atoi(argv[2]);
	env->data->tt_eat = ft_atoi(argv[3]);
	env->data->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		env->data->must_eat = ft_atoi(argv[5]);
	return (EXIT_SUCCESS);
}