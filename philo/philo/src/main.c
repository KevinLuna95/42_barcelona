/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:56:30 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/03/03 20:12:41 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time()
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	waiting(long long time, t_rules *rules)
{
	long long	i;

	i = ft_get_time();
	while (!(rules->dieded))
	{
		if (time_diff(i, ft_get_time()) >= time)
			break ;
		usleep(50);
	}
}

static int	good_input(int c, char *argv[], int i)
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
				if (argv[c][0] > '2' || argv[c][1] > '1' || argv[c][2] > '4' \
				|| argv[c][3] > '7' || argv[c][4] > '4' || argv[c][5] > '8' \
				|| argv[c][6] > '3' || argv[c][7] > '6' || argv[c][8] > '4' \
				|| argv[c][9] > '7')
					return (0);
			}
			i++;
		}
		i = 0;
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
	}
	if (pthread_mutex_init(&rules->writing, NULL))
		return (0);
	if (pthread_mutex_init(&rules->meal_check, NULL))
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

void	ft_print(t_philosopher *philo, char *action)
{
	pthread_mutex_lock(&philo->rules->writing);
	printf("Tiempo: %lldms, Philosofo: %d -> %s\n", \
		ft_get_time() - philo->rules->first_timestamp, philo->id, action);
	pthread_mutex_unlock(&philo->rules->writing);
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

void	time_to_eat(t_philosopher *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	// if (philo->x_ate <= philo->rules->nb_eat)
	// {
	pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
	ft_print(philo, FORKING" left");
	pthread_mutex_lock(&philo->rules->forks[philo->right_fork_id]);
	ft_print(philo, FORKING" right");
	philo->t_last_meal = ft_get_time() - philo->rules->first_timestamp;
	ft_print(philo, EATING);
	waiting(philo->rules->time_eat, philo->rules);
	pthread_mutex_unlock(&philo->rules->forks[philo->left_fork_id]);
		ft_print(philo, "SOLTANDO TENEDOR");
	pthread_mutex_unlock(&philo->rules->forks[philo->right_fork_id]);
		ft_print(philo, "SOLTANDO TENEDOR");
	// }
}

void	doing(t_philosopher *philo)
{
	if (philo->id % 2)
		usleep(100);
	while(!philo->rules->dieded)
	{
	time_to_eat(philo);
	}
	// ft_print(philo, DIEING);
}


int	philosophers(t_rules *rules, int i, t_philosopher *philo)
{
	rules->first_timestamp = ft_get_time();
	while (++i < rules->nb_philos)
	{
		pthread_create(&(philo[i].thread_id), NULL, (void *)doing, &philo[i]);
	}
	while (--i >= 0)
	{
		pthread_join(philo[i].thread_id, NULL);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_rules	rules;

	if (argc < 5 || argc > 6)
		write(2, "Error: Bad arguments\n", 21);
	else if (!good_input(argc, argv, 0))
		write(2, "Error: wrong input\n", 19);
	else
	{
		if (ft_atoi(argv[1]) > 2 && ft_atoi(argv[1]) < 250)
		{
			if (!init_rules(&rules, argv))
				return (write(2, "Error\n", 6), 1);
		}
		else
			return (write(2, "Error: - 2 o + 250 philos NEIN\n", 31), 1);
		if (!philosophers(&rules, -1, (&rules)->philosophers))
			return (1);
	}
	return (0);
}
