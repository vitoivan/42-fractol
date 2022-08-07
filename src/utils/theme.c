/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:11:47 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 09:25:52 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

static void	clear_theme_var(char **theme_var)
{
	while (*theme_var)
	{
		if (*theme_var)
			free(*theme_var);
		theme_var++;
	}
}

static int	get_theme(char *theme)
{
	if (ft_strcmp(theme, "1") == 0)
		return (1);
	if (ft_strcmp(theme, "2") == 0)
		return (2);
	if (ft_strcmp(theme, "3") == 0)
		return (3);
	if (ft_strcmp(theme, "4") == 0)
		return (4);
	if (ft_strcmp(theme, "5") == 0)
		return (5);
	return (0);
}

int	check_valid_theme(char *str)
{
	int		theme_nbr;
	char	**aux;

	theme_nbr = 0;
	aux = NULL;
	if (ft_strchr(str, '='))
	{
		aux = ft_split(str, '=');
		theme_nbr = get_theme(aux[1]);
		clear_theme_var(aux);
	}
	return (theme_nbr);
}
