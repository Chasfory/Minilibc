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

Test(strpbrk, simple_string)
{
    void *library_so = load_assembly_library();
    char *(*my_strpbrk)(char *, char *) = dlsym(library_so, "strpbrk");
    char test[] = "issou";
    char *res = my_strpbrk(test, "so");
    char *res_same = strpbrk(test, "so");

    cr_assert_eq(res, res_same);
}

Test(strpbrk, empty_string)
{
    void *library_so = load_assembly_library();
    char *(*my_strpbrk)(char *, char *) = dlsym(library_so, "strpbrk");
    char test[] = "";
    char *res = my_strpbrk(test, "s");
    char *res_same = strpbrk(test, "s");

    cr_assert_eq(res, res_same);
}

Test(strpbrk, invalid_needle)
{
    void *library_so = load_assembly_library();
    char *(*my_strpbrk)(char *, char *) = dlsym(library_so, "strpbrk");
    char test[] = "issou";
    char *res = my_strpbrk(test, "kappa");
    char *res_same = strpbrk(test, "kappa");

    cr_assert_eq(res, res_same);
}

Test(strpbrk, empty_needle)
{
    void *library_so = load_assembly_library();
    char *(*my_strpbrk)(char *, char *) = dlsym(library_so, "strpbrk");
    char test[] = "issou";
    char *res = my_strpbrk(test, "");
    char *res_same = strpbrk(test, "");

    cr_assert_eq(res, res_same);
}