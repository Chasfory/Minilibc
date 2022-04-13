/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-laetitia.bousch
** File description:
** strcmp
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

Test(strcmp, same_strings)
{
    void *library_so = load_assembly_library();
    int (*my_strcmp)(char *, char *) = dlsym(library_so, "strcmp");
    char s1[] = "issou";
    char s2[] = "issou";
    int res = my_strcmp(s1, s2);
    int res_same = strcmp(s1, s2);

    cr_assert_eq(res, res_same);
}

Test(strcmp, s1_less)
{
    void *library_so = load_assembly_library();
    int (*my_strcmp)(char *, char *) = dlsym(library_so, "strcmp");
    char s1[] = "iasou";
    char s2[] = "issou";
    int res = my_strcmp(s1, s2);
    int res_same = strcmp(s1, s2);

    cr_assert_eq(res, res_same);
}

Test(strcmp, s2_less)
{
    void *library_so = load_assembly_library();
    int (*my_strcmp)(char *, char *) = dlsym(library_so, "strcmp");
    char s1[] = "issou";
    char s2[] = "iasou";
    int res = my_strcmp(s1, s2);
    int res_same = strcmp(s1, s2);

    cr_assert_eq(res, res_same);
}

Test(strcmp, spe_string)
{
    void *library_so = load_assembly_library();
    int (*my_strcmp)(char *, char *) = dlsym(library_so, "strcmp");
    char s1[] = "iasou";
    char s2[] = "issou";
    int res = my_strcmp(s1, s2);
    int res_same = strcmp(s1, s2);

    cr_assert_eq(res, res_same);
}

Test(strcmp, s1_shorter)
{
    void *library_so = load_assembly_library();
    int (*my_strcmp)(char *, char *) = dlsym(library_so, "strcmp");
    char s1[] = "iss";
    char s2[] = "issou";
    int res = my_strcmp(s1, s2);
    int res_same = strcmp(s1, s2);

    cr_assert_eq(res, res_same);
}

Test(strcmp, s2_shorter)
{
    void *library_so = load_assembly_library();
    int (*my_strcmp)(char *, char *) = dlsym(library_so, "strcmp");
    char s1[] = "issou";
    char s2[] = "is";
    int res = my_strcmp(s1, s2);
    int res_same = strcmp(s1, s2);

    cr_assert_eq(res, res_same);
}