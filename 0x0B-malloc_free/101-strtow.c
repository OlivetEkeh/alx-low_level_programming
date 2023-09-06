#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * count_words - Helper function to count the number of words in a string.
 * @str: The input string.
 *
 * Return: Number of words.
 */

int count_words(char *str)
{
	int count = 0;
	int in_word = 0;
	int i;


	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		else
		{
			in_word = 0;
		}
	}

	return (count);
}

/**
 * strtow - Splits a string into an array of words.
 * @str: The input string.
 *
 * Return: An array of strings (words).
 */
char **strtow(char *str)
{
	int word_count;
	int i, j, k;
	int word_length = 0;
	char **word_array;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);


	if (word_count == 0)
		return (NULL);

	word_array = malloc((word_count + 1) * sizeof(char *));
	if (word_array == NULL)
		return (NULL);

	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			word_length++;
		}
		else if (word_length > 0)
		{
			word_array[j] = malloc((word_length + 1) * sizeof(char));
			if (word_array[j] == NULL)
			{
				for (k = 0; k < j; k++)
					free(word_array[k]);
				free(word_array);
				return (NULL);
			}

			for (k = 0; k < word_length; k++)
				word_array[j][k] = str[i - word_length + k];
			word_array[j][word_length] = '\0';

			j++;
			word_length = 0;
		}
	}

	if (word_length > 0)
	{
		word_array[j] = malloc((word_length + 1) * sizeof(char));
		if (word_array[j] == NULL)
		{
			for (k = 0; k < j; k++)
				free(word_array[k]);
			free(word_array);
			return (NULL);
		}

		for (k = 0; k < word_length; k++)
			word_array[j][k] = str[i - word_length + k];
		word_array[j][word_length] = '\0';
	}

	word_array[word_count] = NULL;

	return (word_array);
}
