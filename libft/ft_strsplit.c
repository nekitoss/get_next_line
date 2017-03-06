/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:21:34 by nekitoss          #+#    #+#             */
/*   Updated: 2016/12/03 20:21:34 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *str, char c)
{
	int		i;
	int		is_word;
	int		is_space;
	int		word_counter;

	i = 0;
	is_word = 0;
	is_space = 1;
	word_counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && !is_word)
		{
			is_space = 0;
			is_word = 1;
			word_counter++;
		}
		if (str[i] == c && !is_space)
		{
			is_space = 1;
			is_word = 0;
		}
		i++;
	}
	return (word_counter);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		start;
	int		end;
	int		num_words;
	char	**res_arr;

	i = 0;
	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	res_arr = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (res_arr)
	{
		res_arr[num_words] = NULL;
		end = 0;
		start = 0;
		while (i < num_words)
		{
			start = ft_str_un_i_chr(&s[end], c) + start;
			end = ft_str_i_chr(&s[start], c) + start;
			res_arr[i++] = ft_strsub(s, start, end - start);
			start = end;
		}
	}
	return (res_arr);
}
