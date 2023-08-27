#include <stdlib.h>

char *int_get(int num);
unsigned int v_abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int size_buff);

/**
 * int_get - gets a character pointer to new string containing int
 * @num: number to convert to string
 *
 * Return: character pointer to created string.
 */
char *int_get(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = v_abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++; 
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * v_abs - gets the absolute value of an integer
 * @i: integer to get absolute value 
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int v_abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - gets length of buffer needed for an unsigned int
 * @num: number to get length 
 * @base: base of number representation used by buffer
 *
 * Return: integer containing length of buffer needed
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; 

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - fills buffer with correct numbers 
 * @num: number to convert to string 
 * @base: base of number used in conversion
 * @buff: buffer to fill with result 
 * @size_buff: size of buffer in bytes
 *
 * Return: always 0.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int size_buff)
{
	int rem, i = size_buff - 1;

	buff[size_buff] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) 
			buff[i] = rem + 87; 
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}

