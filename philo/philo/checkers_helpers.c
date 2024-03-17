/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:31:29 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/03/17 20:16:33 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_all_eats(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philos)
	{
		if (get_x_ate(&rules->philosophers[i]) < get_all_ate(rules))
			break ;
	}
	if (i == rules->nb_philos)
		set_all_ate(rules, 1);
	if (get_all_ate(rules) == rules->nb_eat + 1)
		set_dieded(rules, 1);
}

int	check_life(t_rules *rules)
{
	int	i;

	i = -1;
	if (get_dieded(rules))
		return (0);
	while (++i < rules->nb_philos)
	{
		if (rules->time_death < (ft_get_time() - rules->first_timestamp) \
			- get_t_last_meal(&rules->philosophers[i]))
		{
			set_dieded(rules, 1);
			printf("%lld %d %s\n", ft_get_time() - rules->first_timestamp, \
									rules->philosophers[i].id, DIEING);
			return (0);
		}
	}
	return (1);
}

static void	first(int *c, int *neg, const char *str)
{
	while (((((str[*c]) >= 9 && (str[*c]) <= 13) \
			|| (str[*c]) == ' ') && str[*c]))
		*c += 1;
	if (str[*c] == '-')
	{
		*c += 1;
		*neg = 1;
	}
	else if (str[*c] == '+')
		*c += 1;
}

int	ft_atoi(const char *str)
{
	int		c;
	int		neg;
	int		flag;
	int		res;

	c = 0;
	neg = 0;
	flag = 1;
	res = 0;
	first(&c, &neg, str);
	while (str[c] && flag)
	{
		if (((str[c]) >= '0' && (str[c]) <= '9'))
			res = ((res * 10) + (str[c++] - '0'));
		else
			flag = 0;
	}
	if (neg)
		res *= -1;
	return (res);
}

int	destroy_forks(t_rules *rules)
{
	int	i;
	int	fail;

	i = rules->nb_philos;
	fail = 0;
	while (--i >= 0)
	{
		if (pthread_mutex_destroy(&rules->forks[i]))
			fail = 1;
		if (pthread_mutex_destroy(&rules->philosophers[i].m_x_ate))
			fail = 1;
		if (pthread_mutex_destroy(&rules->philosophers[i].m_t_last_meal))
			fail = 1;
	}
	if (pthread_mutex_destroy(&rules->writing))
		fail = 1;
	if (pthread_mutex_destroy(&rules->m_dieded))
		fail = 1;
	if (pthread_mutex_destroy(&rules->meal_check))
		fail = 1;
	if (pthread_mutex_destroy(&rules->m_all_ate))
		fail = 1;
	return (0);
}
