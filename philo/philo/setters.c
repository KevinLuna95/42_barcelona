/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:22:28 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/03/17 15:37:40 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_dieded(t_rules *rules, int val)
{
	pthread_mutex_lock(&rules->m_dieded);
	rules->dieded = val;
	pthread_mutex_unlock(&rules->m_dieded);
}

/*incrementa all_ate en val*/
void	set_all_ate(t_rules *rules, int val)
{
	pthread_mutex_lock(&rules->m_all_ate);
	rules->all_ate += val;
	pthread_mutex_unlock(&rules->m_all_ate);
}

/*incrementa x_ate en val*/
void	set_x_ate(t_philosopher *philo, int val)
{
	pthread_mutex_lock(&philo->m_x_ate);
	philo->x_ate += val;
	pthread_mutex_unlock(&philo->m_x_ate);
}

void	set_t_last_meal(t_philosopher *philo, int val)
{
	pthread_mutex_lock(&philo->m_t_last_meal);
	philo->t_last_meal = val;
	pthread_mutex_unlock(&philo->m_t_last_meal);
}
