/*
** EPITECH PROJECT, 2022
** test_strlen.c
** File description:
** test_strlen.c
*/

#include <stdio.h>
#include <dlfcn.h>
#include <criterion/criterion.h>
#include <fcntl.h>

static void *load_assembly_library(void)
{
    void *library_so = dlopen("./libasm.so", RTLD_LAZY);

    if (!library_so) {
        dprintf(2, "cannot open shared lib : %s\n", dlerror());
        exit(84);
    }
    return library_so;
}

Test(memmove, normal)
{
    void *library_so = load_assembly_library();
    void *(*my_memset)(void *, int, size_t) = dlsym(library_so, "memset");
    char test[] = "issou";
    char *ret = my_memset(test, 0, 5);
    char *ret_same = memset(test, 0, 5);

    cr_assert_eq(ret, ret_same);
}

Test(memmove, no_size)
{
    void *library_so = load_assembly_library();
    void *(*my_memset)(void *, int, size_t) = dlsym(library_so, "memset");
    char test[] = "issou";
    char *ret = my_memset(test, 0, 0);
    char *ret_same = memset(test, 0, 0);

    cr_assert_eq(ret, ret_same);
}