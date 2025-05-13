/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:07:48 by obajja            #+#    #+#             */
/*   Updated: 2025/05/10 16:12:00 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int main(int argc, char **argv)
{
    t_env *env;
	
	env = ft_calloc(1, sizeof(t_env));
	if (!env)
		return (EXIT_FAILURE);
	if (data_init(env, argv, argc))
        return (EXIT_FAILURE);
	data_print(env);
    //philo_init(atoi(argv[1]), env);
    return (0);
}
