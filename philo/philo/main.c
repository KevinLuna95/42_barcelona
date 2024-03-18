/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:56:30 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/03/17 20:23:24 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	time_to_eat(t_philosopher *philo)
{
	if (philo->id % 2)
		usleep(150);
	pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
	ft_print(philo, FORKING);
	pthread_mutex_lock(&philo->rules->forks[philo->right_fork_id]);
	ft_print(philo, FORKING);
	set_t_last_meal(philo, ft_get_time() - philo->rules->first_timestamp);
	ft_print(philo, EATING);
	set_x_ate(philo, 1);
	waiting(philo->rules->time_eat);
	pthread_mutex_unlock(&philo->rules->forks[philo->left_fork_id]);
	pthread_mutex_unlock(&philo->rules->forks[philo->right_fork_id]);
}

void	doing(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->rules->m_dieded);
	pthread_mutex_unlock(&philo->rules->m_dieded);
	if (philo->id % 2)
		usleep(15000);
	while (!get_dieded(philo->rules))
	{
		time_to_eat(philo);
		ft_print(philo, SLEEPING);
		waiting(philo->rules->time_sleep);
		ft_print(philo, THINKING);
	}
}

void	one_philo(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
	ft_print(philo, FORKING);
	pthread_mutex_unlock(&philo->rules->forks[philo->left_fork_id]);
}

int	philosophers(t_rules *rules, int i, t_philosopher *philo)
{
	if (rules->nb_philos == 1)
	{
		philo->rules->first_timestamp = ft_get_time();
		pthread_create(&(philo[0].thread_id), NULL, \
						(void *)one_philo, &philo[0]);
		pthread_create(&(rules->seeker), NULL, (void *)whatcher, rules);
		pthread_join(rules->seeker, NULL);
		pthread_join(philo[0].thread_id, NULL);
	}
	else
	{
		pthread_mutex_lock(&rules->m_dieded);
		while (++i < rules->nb_philos)
			pthread_create(&(philo[i].thread_id), \
							NULL, (void *)doing, &philo[i]);
		rules->first_timestamp = ft_get_time();
		pthread_mutex_unlock(&rules->m_dieded);
		pthread_create(&(rules->seeker), \
							NULL, (void *)whatcher, rules);
		while (--i >= 0)
			pthread_join(philo[i].thread_id, NULL);
		pthread_join(rules->seeker, NULL);
	}
	if (destroy_forks(rules))
		return (0);
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
		if (ft_atoi(argv[1]) < 250 && ft_atoi(argv[1]) >= 1)
		{
			if (!init_rules(&rules, argv))
				return (write(2, "Error\n", 6), 1);
		}
		else
			return (write(2, "Error: + 250 o menos de 1 philo NEIN\n", 38), 1);
		if (!philosophers(&rules, -1, (&rules)->philosophers))
			return (1);
	}
	return (0);
}
