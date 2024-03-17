/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:22:28 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/03/17 15:28:43 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_dieded(t_rules *rules)
{
	int	res;

	pthread_mutex_lock(&rules->m_dieded);
	res = rules->dieded;
	pthread_mutex_unlock(&rules->m_dieded);
	return (res);
}

int	get_all_ate(t_rules *rules)
{
	int	res;

	pthread_mutex_lock(&rules->m_all_ate);
	res = rules->all_ate;
	pthread_mutex_unlock(&rules->m_all_ate);
	return (res);
}

int	get_t_last_meal(t_philosopher *philo)
{
	int	res;

	pthread_mutex_lock(&philo->m_t_last_meal);
	res = philo->t_last_meal;
	pthread_mutex_unlock(&philo->m_t_last_meal);
	return (res);
}

int	get_x_ate(t_philosopher *philo)
{
	int	res;

	pthread_mutex_lock(&philo->m_x_ate);
	res = philo->x_ate;
	pthread_mutex_unlock(&philo->m_x_ate);
	return (res);
}
