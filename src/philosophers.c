/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:07:48 by obajja            #+#    #+#             */
/*   Updated: 2025/03/13 14:21:02 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int main(int argc, char **argv)
{
    if (argc < 5 || argc > 6)
        return (1);
    num_philo = ft_atoi(argv[1]);
    time_to_die = ft_atoi(argv[2]);
    time_to_eat = ft_atoi(argv[3]);
    time_to_sleep = ft_atoi(argv[4]);
    if (argc == 5)
        must_eat = ft_atoi(argv[5]);


    return (0);
}
