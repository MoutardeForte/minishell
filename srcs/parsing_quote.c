/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing-quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:20:14 by user42            #+#    #+#             */
/*   Updated: 2020/09/25 14:31:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_single_quote(char *input)
{
	char	*ret;
	int		len;

	len = single_quote_len(input, EXP);
	ret = ft_substr(input, 1, len);
	return (ret);
}

char	*get_double_quote(char *input, char *env[])
{
	char	*ret;
	char	*str;
	int		len;
	int		i;
	int		j;

	len = double_quote_len(input, env, EXP);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	ret[len] = '\0';
	i = 1;
	j = 0;
	while (input[i] && i < double_quote_len(input, env, NOT_EXP) && j < len)
	{
		if ((str = expanded_str(&input[i], env, DOUBLE_QUOTE)))
		{
			ft_strcpy(&ret[j], str);
			free(str);
		}
		str = NULL;
		j += len_after_char(&input[i], env, DOUBLE_QUOTE, EXP);
		i += len_after_char(&input[i], env, DOUBLE_QUOTE, NOT_EXP);
	}
	return (ret);
}

char	*get_quote(char *input, char *env[])
{
	if (input[0] == SINGLE_QUOTE)
		return (get_single_quote(input));
	else
		return (get_double_quote(input, env));
}