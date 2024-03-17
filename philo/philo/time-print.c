/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time-print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:17:35 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/03/17 20:18:35 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	waiting(long long time, t_philosopher *philo)
{
	long long	i;

	i = ft_get_time();
	while (1)
	{
		if (time_diff(i, ft_get_time()) >= time)
			break ;
		usleep(50);
	}
	if (philo)
		i = 0;
}

void	ft_print(t_philosopher *philo, char *action)
{
	pthread_mutex_lock(&philo->rules->writing);
	if (!get_dieded(philo->rules))
		printf("%lld %d %s\n", \
		ft_get_time() - philo->rules->first_timestamp, philo->id, action);
	pthread_mutex_unlock(&philo->rules->writing);
}

void	whatcher(t_rules *rules)
{
	while (1)
	{
		if (!check_life(rules))
		{
			break ;
		}
		usleep(500);
	}
}