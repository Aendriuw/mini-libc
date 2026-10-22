// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <internal/syscall.h>
#include <string.h>

int puts(const char *s)
{
	long ret = syscall(__NR_write, 1, s, strlen(s));

	syscall(__NR_write, 1, "\n", 1);

	return (int)ret + 1;
}
