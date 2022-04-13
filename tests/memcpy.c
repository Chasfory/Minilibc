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

Test(memcpy, normal_string)
{
    void *library_so = load_assembly_library();
    void *(*my_memcpy)(void *, void *, size_t) = dlsym(library_so, "memcpy");
    char test[6] = {0};
    char src[] = "issou";
    char *ret = my_memcpy(test, src, 5);

    cr_expect_not_null(ret);
    for (int i = 0; i < 5; ++i)
        cr_expect_eq(ret[i], src[i]);
}

Test(memcpy, no_string)
{
    void *library_so = load_assembly_library();
    void *(*my_memcpy)(void *, void *, size_t) = dlsym(library_so, "memcpy");
    char test[6] = {0};
    char src[] = "issou";
    char *ret = my_memcpy(test, src, 0);

    cr_expect_not_null(ret);
    for (int i = 0; i < 5; ++i)
        cr_expect_eq(ret[i], 0);
}

Test(memcpy, long_string)
{
    void *library_so = load_assembly_library();
    void *(*my_memcpy)(void *, void *, size_t) = dlsym(library_so, "memcpy");
    char *src = "azertyuiopqsdfghjklmwxcvbnazertyuiopqsdfghjklmwxcvbnazertyuiop";
    char test[63] = {0};
    char *ret = my_memcpy(test, src, 63);

    cr_expect_not_null(ret);
    for (int i = 0; i < 62; ++i)
        cr_expect_eq(ret[i], src[i]);
}