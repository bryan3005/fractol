/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:17:31 by mbryan            #+#    #+#             */
/*   Updated: 2015/02/02 10:57:04 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strcdup(const char *s, char c)
{
	char	*cpy;

	if (s == NULL)
		return (NULL);
	cpy = ft_strndup(s, ft_strclen(s, c));
	return (cpy);
}
