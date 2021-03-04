/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnews.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:02:14 by amazzei           #+#    #+#             */
/*   Updated: 2020/02/03 15:02:15 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnew(size_t size)
{
    char    *str;

    if (!(str = (char *)malloc(sizeof(char) * size + 1)))
        return (0x0);
    str[size] = '\0';
    while (size--)
        str[size] = '\0';
    return (str);
}