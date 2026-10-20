// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	long ret = syscall(__NR_ftruncate, (long)fd, (long)length);
	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return (off_t)ret;
}
