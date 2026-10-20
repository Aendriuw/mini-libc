// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	int mode = 0;
	if (flags & O_CREAT) {
		va_list valist;

		va_start(valist, flags);
		mode = va_arg(valist, int);
		va_end(valist);
	}

	long ret = syscall(__NR_open, (long)filename, (long)flags, (long)mode);

	if (ret < -1) {
		errno = -ret;
		return -1;
	}

	return ret;
}
