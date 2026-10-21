/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef	__TIME_H__
#define	__TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>

struct timespec {
    long tv_sec, tv_nsec;
};

long nanosleep(const struct timespec *req, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
