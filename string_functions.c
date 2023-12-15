#include "simple_shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: comparison of both strings
 */

int _strcmp(char *s1, char *s2)
{
	return (strcmp(s1, s2));
}

/**
 * *_strcat - concatenates two strings
 * @src: one to be appended
 * @dest: one to be appended to
 * Return: pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	return (strcat(dest, src));
}

/**
 * *_strcpy - copies the string pointed to by src
 * to the buffer pointed by dest
 * @src: to be copied
 * @dest: to be copied to
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	return (strcpy(dest, src));
}
