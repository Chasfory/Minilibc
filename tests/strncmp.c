/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-laetitia.bousch
** File description:
** strncmp
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

Test(strncmp, same_string)
{
    void *library_so = load_assembly_library();
    int (*my_strncmp)(char *, char *, size_t) = dlsym(library_so, "strncmp");
    char s1[] = "issou";
    char s2[] = "issou";
    int res = my_strncmp(s1, s2, strlen(s1));
    int res_same = strncmp(s1, s2, strlen(s1));

    cr_assert_eq(res, res_same);
}

Test(strncmp, shorter_string)
{
    void *library_so = load_assembly_library();
    int (*my_strncmp)(char *, char *, size_t) = dlsym(library_so, "strncmp");
    char s1[] = "issiu";
    char s2[] = "issou";
    int res = my_strncmp(s1, s2, 3);
    int res_same = strncmp(s1, s2, 3);

    cr_assert_eq(res, res_same);
}

Test(strncmp, s1_less)
{
    void *library_so = load_assembly_library();
    int (*my_strncmp)(char *, char *, size_t) = dlsym(library_so, "strncmp");
    char s1[] = "iasou";
    char s2[] = "issou";
    int res = my_strncmp(s1, s2, 100);
    int res_same = strncmp(s1, s2, 100);

    cr_assert_eq(res, res_same);
}

Test(strncmp, s2_less)
{
    void *library_so = load_assembly_library();
    int (*my_strncmp)(char *, char *, size_t) = dlsym(library_so, "strncmp");
    char s1[] = "issou";
    char s2[] = "iasou";
    int res = my_strncmp(s1, s2, 100);
    int res_same = strncmp(s1, s2, 100);

    cr_assert_eq(res, res_same);
}

Test(strncmp, s1_shorter)
{
    void *library_so = load_assembly_library();
    int (*my_strncmp)(char *, char *, size_t) = dlsym(library_so, "strncmp");
    char s1[] = "iss";
    char s2[] = "issou";
    int res = my_strncmp(s1, s2, 100);
    int res_same = strncmp(s1, s2, 100);

    cr_assert_eq(res, res_same);
}

Test(strncmp, s2_shorter)
{
    void *library_so = load_assembly_library();
    int (*my_strncmp)(char *, char *, size_t) = dlsym(library_so, "strncmp");
    char s1[] = "issou";
    char s2[] = "is";
    int res = my_strncmp(s1, s2, 100);
    int res_same = strncmp(s1, s2, 100);

    cr_assert_eq(res, res_same);
}