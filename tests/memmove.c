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

Test(memmove, same_string)
{
    void *library_so = load_assembly_library();
    void *(*my_memmove)(void *, void *, size_t) = dlsym(library_so, "memmove");
    char dest[6] = {0};
    char src[] = "issou";
    char *ret = my_memmove(src, src, 5);
    char *ret_same = memmove(src, src, 5);

    cr_assert_eq(ret, ret_same);
}

Test(memmove, forward)
{
    void *library_so = load_assembly_library();
    void *(*my_memmove)(void *, void *, size_t) = dlsym(library_so, "memmove");
    char *test = malloc(10 * sizeof(char));
    memcpy(test + 5, "issou", 5);
    char *ret = my_memmove(test, test + 5, 5);
    char *ret_same = memmove(test, test + 5, 5);

    cr_assert_eq(ret, ret_same);
}

Test(memmove, backward)
{
    void *library_so = load_assembly_library();
    void *(*my_memmove)(void *, void *, size_t) = dlsym(library_so, "memmove");
    char *test = malloc(10 * sizeof(char));
    memcpy(test, "issou", 5);
    char *ret = my_memmove(test + 5, test, 5);
    char *ret_same = memmove(test + 5, test, 5);

    cr_assert_eq(ret, ret_same);
}