// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	long ret = syscall(__NR_fstat, (long)fd, (long)st);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
