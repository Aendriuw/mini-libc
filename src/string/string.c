// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	size_t i = 0;
	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	size_t i = 0;
	while (i < len) {
		destination[i] = source[i];
		i++;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	size_t i = strlen(destination);
	strcpy(destination + i, source);

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	size_t dest_len = strlen(destination);	
	strncpy(destination + dest_len, source, len);
	destination[dest_len + len] = '\0'; 

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	size_t i = 0;
	while (str1[i] != '\0' && str2[i] != '\0') {
		if (str1[i] != str2[i]) {
			return (int)(str1[i] - str2[i]);
		}
		i++;
	}

	return (int)(str1[i] - str2[i]);
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && i < len) {
		if (str1[i] != str2[i]) {
			return (int)(str1[i] - str2[i]);
		}
		i++;
	}

	if (i == len) {
		return 0;
	}
	return (int)(str1[i] - str2[i]);
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	size_t i = 0;

	while (str[i]) {
		if (str[i] == c) {
			return (char *)(str + i);
		}
		i++;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	size_t i = 0;
	char *last_occurence = NULL;

	while (str[i]) {
		if (str[i] == c) {
			last_occurence = (char *)(str + i);
		}
		i++;
	}

	return last_occurence;
}

char *strstr(const char *haystack, const char *needle)
{
	size_t i = 0, needle_len = strlen(needle);

	while (haystack[i]) {
		if (!strncmp(haystack + i, needle, needle_len)) {
			return (char *)haystack + i;
		}
		i++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	size_t i = 0, needle_len = strlen(needle);
	char *last_occurence = NULL;

	while (haystack[i]) {
		if (!strncmp(haystack + i, needle, needle_len)) {
			last_occurence = (char *)(haystack + i);
		}
		i++;
	}

	return last_occurence;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	const unsigned char *s = source;
	unsigned char *d = destination;
	for (size_t i = 0; i < num; i++) {
		d[i] = s[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	if (source == destination) {
		return destination;
	}

	long long ptr_distance = (long long)source - (long long)destination;

	if (ptr_distance < 0) {
		ptr_distance = -ptr_distance;
	}

	if ((size_t)ptr_distance < num || source > destination) {
		return memcpy(destination, source, num);
	}

	const unsigned char *s = source;
	unsigned char *d = destination;
	for (size_t i = num; i != 0; i--) {
		d[i - 1] = s[i - 1];	
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char *p1 = ptr1;
	const unsigned char *p2 = ptr2;
	
	for (size_t i = 0; i < num; i++) {
		if (p1[i] != p2[i]) {
			return (int)(p2[i] - p1[i]);
		}
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	unsigned char *s = source;

	while (num--) {
		*s = (unsigned char)value;
		s++;
	}

	return source;
}
