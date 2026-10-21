#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

long nanosleep(const struct timespec *req, struct timespec *rem)
{
	long ret =  syscall(__NR_nanosleep, (long)req, (long)rem);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return 0;
}

unsigned int sleep(unsigned int seconds)
{
	struct timespec req, rem;
	req.tv_sec = seconds;
	req.tv_nsec = 0;

	rem.tv_sec = 0;
	rem.tv_nsec = 0;

	long ret = nanosleep(&req, &rem);

	if (ret != 0) {
		return rem.tv_sec;
	}

	return 0;
}
