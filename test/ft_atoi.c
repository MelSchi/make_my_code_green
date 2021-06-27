/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_atoi.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mwen <mwen@student.42wolfsburg.de>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/05/14 23:40:08 by mwen			  #+#	#+#			 */
/*   Updated: 2021/06/27 01:04:16 by mwen			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int	ft_checksign(char c)
{
	int	sign;

	sign = 0;
	if (c == '-')
		sign = -1;
	else if (c == '+')
		sign = 1;
	return (sign);
}

int	ft_atoi (const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >=9 && nptr[i] <= 13))
		i++;
	if (ft_checksign(nptr[i]) != 0)
	{
		sign = ft_checksign(nptr[i]);
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * res);
}