/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:08:20 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/03/17 20:07:19 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>

// # define EATING "🍝Comiendo🍝"
// # define FORKING "🍴Cogiendo tenedor🍴"
// # define SLEEPING "😴Durmiendo😴"
// # define THINKING "🤔Pensando🤔"
// # define DIEING "💀Muriendo💀"

# define EATING "is eating"
# define FORKING "has taken a fork"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIEING "died"

struct	s_rules;

typedef struct s_philosopher
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	struct s_rules		*rules;
	pthread_mutex_t		m_t_last_meal;
	pthread_mutex_t		m_x_ate;
	pthread_t			thread_id;
}						t_philosopher;

typedef struct s_rules
{
	int					nb_philos;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	int					dieded;
	int					all_ate;
	long long			first_timestamp;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		forks[200];
	pthread_mutex_t		writing;
	pthread_mutex_t		m_dieded;
	pthread_mutex_t		m_all_ate;
	t_philosopher		philosophers[200];
	pthread_t			seeker;
}						t_rules;

/*File: main.c*/
int			check_life(t_rules *rules);
int			philosophers(t_rules *rules, int i, t_philosopher *philo);
void		one_philo(t_philosopher *philo);
void		time_to_eat(t_philosopher *philo);
void		doing(t_philosopher *philo);

/*File: checkers_helpers.c*/
int			ft_atoi(const char *str);
void		check_all_eats(t_rules *rules);
int			check_life(t_rules *rules);
int			destroy_forks(t_rules *rules);

/*File: time-print.c*/
long long	ft_get_time(void);
long long	time_diff(long long past, long long pres);
void		waiting(long long time);
void		ft_print(t_philosopher *philo, char *action);
void		whatcher(t_rules *rules);

/*File: init-check_input.c*/

int			good_input(int c, char *argv[], int i);
int			init_forks(t_rules *rules);
void		init_philos(t_rules *rules);
int			init_rules(t_rules *rules, char *argv[]);
int			check_max_int(const char *s1, const char *s2, size_t n);

/*File: getters.c*/
int			get_dieded(t_rules *rules);
int			get_all_ate(t_rules *rules);
int			get_x_ate(t_philosopher *philo);
int			get_t_last_meal(t_philosopher *philo);

/*File: setters.c*/
void		set_dieded(t_rules *rules, int val);
void		set_all_ate(t_rules *rules, int val);
void		set_x_ate(t_philosopher *philo, int val);
void		set_t_last_meal(t_philosopher *philo, int val);

#endif