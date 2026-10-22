// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *ret = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (ret == MAP_FAILED) {
		return NULL;
	}

	if (mem_list_add(ret, size) != 0) {
		munmap(ret, size);
		return NULL;
	}

	return (void *)ret;
}

void *calloc(size_t nmemb, size_t size)
{
	void *ret = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (ret == MAP_FAILED) {
		return NULL;
	}

	if (mem_list_add(ret, size) != 0) {
		munmap(ret, size);
		return NULL;
	}

	memset(ret, 0, size * nmemb);

	return (void *)ret;
}

void free(void *ptr)
{
	struct mem_list *curr_ptr_mem = mem_list_find(ptr);

	munmap(curr_ptr_mem->start, curr_ptr_mem->len);
	mem_list_del(curr_ptr_mem->start);
}

void *realloc(void *ptr, size_t size)
{
	if (ptr == NULL) {
		return malloc(size);
	}

	if (size == 0) {
		free(ptr);
		return NULL;
	}

	void *realloc_ptr = malloc(size);
	if (realloc_ptr != NULL) {
		memcpy(realloc_ptr, ptr, size);
		free(ptr);
	}

	return realloc_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t prod = nmemb * size;
	if (prod / nmemb != size) {
		return NULL;
	}
	return realloc(ptr, size * nmemb);
}
