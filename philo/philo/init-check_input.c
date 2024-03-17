/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-check_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:17:40 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/03/17 18:26:05 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	good_input(int c, char *argv[], int i)
{
	while (argv[--c] && c > 0)
	{
		if (argv[c][0] == '\0')
			return (0);
		while (argv[c][i])
		{
			if ((argv[c][i] < '0' || argv[c][i] > '9'))
				return (0);
			if (i == 9)
			{
				if (check_max_int("2147483647", argv[c], 10) < 0)
					return (0);
			}
			i++;
		}
		i = 0;
		if (ft_atoi(argv[c]) < 60 && c != 1 && c != 5)
			return (0);
	}
	return (1);
}

int	init_forks(t_rules *rules)
{
	int	i;

	i = rules->nb_philos;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL))
			return (0);
		if (pthread_mutex_init(&rules->philosophers[i].m_x_ate, NULL))
			return (0);
		if (pthread_mutex_init(&rules->philosophers[i].m_t_last_meal, NULL))
			return (0);
	}
	if (pthread_mutex_init(&rules->writing, NULL))
		return (0);
	if (pthread_mutex_init(&rules->m_dieded, NULL))
		return (0);
	if (pthread_mutex_init(&rules->meal_check, NULL))
		return (0);
	if (pthread_mutex_init(&rules->m_all_ate, NULL))
		return (0);
	return (1);
}

void	init_philos(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philos)
	{
		rules->philosophers[i].id = i;
		rules->philosophers[i].left_fork_id = i;
		rules->philosophers[i].right_fork_id = (i + 1) % rules->nb_philos;
		rules->philosophers[i].rules = rules;
		rules->philosophers[i].x_ate = 0;
		rules->philosophers[i].t_last_meal = 0;
	}
}

int	init_rules(t_rules *rules, char *argv[])
{
	rules->nb_philos = ft_atoi(argv[1]);
	rules->time_death = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	rules->dieded = 0;
	rules->all_ate = 0;
	if (rules->time_death < 0 || rules->time_eat < 0
		|| rules->time_sleep < 0)
		return (0);
	if (argv[5])
	{
		rules->nb_eat = ft_atoi(argv[5]);
		if (rules->nb_eat <= 0)
			return (0);
	}
	else
		rules->nb_eat = -1;
	if (!init_forks(rules))
		return (0);
	init_philos(rules);
	return (1);
}

int	check_max_int(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (n && s1[count] && s2[count] && (s1[count] <= s2[count]))
	{
		n--;
		count++;
	}
	if (!n && (s1[count] - s2[count]) > 0)
		return (0);
	return (1);
}
