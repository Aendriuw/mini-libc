// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	long ret = syscall(__NR_truncate, (long)path, (long)length);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return (off_t)ret;
}
