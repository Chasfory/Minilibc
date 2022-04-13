/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-laetitia.bousch
** File description:
** strstr
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

Test(strstr, empty_string)
{
    void *library_so = load_assembly_library();
    char *(*my_strstr)(char *, char *) = dlsym(library_so, "strstr");
    char test[] = "issou";
    char *res = my_strstr(test, "sou");
    char *res_same = strstr(test, "sou");

    cr_assert_eq(res, res_same);
}

Test(strstr, simple_string)
{
    void *library_so = load_assembly_library();
    char *(*my_strstr)(char *, char *) = dlsym(library_so, "strstr");
    char test[] = "issou";
    char *res = my_strstr(test, "sou");
    char *res_same = strstr(test, "sou");

    cr_assert_eq(res, res_same);
}

Test(strstr, empty_needle)
{
    void *library_so = load_assembly_library();
    char *(*my_strstr)(char *, char *) = dlsym(library_so, "strstr");
    char test[] = "issou";
    char *res = my_strstr(test, "");
    char *res_same = strstr(test, "");

    cr_assert_eq(res, res_same);
}

Test(strstr, not_found)
{
    void *library_so = load_assembly_library();
    char *(*my_strstr)(char *, char *) = dlsym(library_so, "strstr");
    char test[] = "issou";
    char *res = my_strstr(test, "a");
    char *res_same = strstr(test, "a");

    cr_assert_eq(res, res_same);
}