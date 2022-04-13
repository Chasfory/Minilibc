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

Test(strcasecmp, same)
{
    void *library_so = load_assembly_library();
    int (*my_strcasecmp)(char *, char *) = dlsym(library_so, "strcasecmp");
    char s1[] = "issou";
    char s2[] = "issou";
    int res = my_strcasecmp(s1, s2);
    int res_same = strcasecmp(s1, s2);

    cr_assert_eq(res, res_same);
}

Test(strcasecmp, different_case)
{
    void *library_so = load_assembly_library();
    int (*my_strcasecmp)(char *, char *) = dlsym(library_so, "strcasecmp");
    char s1[] = "issou";
    char s2[] = "isSou";
    int res = my_strcasecmp(s1, s2);
    int res_same = strcasecmp(s1, s2);

    cr_assert_eq(res, res_same);
}

Test(strcasecmp, same_without_char)
{
    void *library_so = load_assembly_library();
    int (*my_strcasecmp)(char *, char *) = dlsym(library_so, "strcasecmp");
    char s1[] = "<;:!/.?,>";
    char s2[] = "<;:!/.?,>";
    int res = my_strcasecmp(s1, s2);
    int res_same = strcasecmp(s1, s2);

    cr_assert_eq(res, res_same);
}

Test(strcasecmp, s2_all_different_case)
{
    void *library_so = load_assembly_library();
    int (*my_strcasecmp)(char *, char *) = dlsym(library_so, "strcasecmp");
    char s1[] = "ISSOU";
    char s2[] = "issou";
    int res = my_strcasecmp(s1, s2);
    int res_same = strcasecmp(s1, s2);

    cr_assert_eq(res, res_same);
}

Test(strcasecmp, diff_without_char)
{
    void *library_so = load_assembly_library();
    int (*my_strcasecmp)(char *, char *) = dlsym(library_so, "strcasecmp");
    char s1[] = "<;:!/.?,>";
    char s2[] = "<;:$/.?,>";
    int res = my_strcasecmp(s1, s2);
    int res_same = strcasecmp(s1, s2);

    cr_assert_eq(res, res_same);
}

Test(strcasecmp, s1_all_different_case)
{
    void *library_so = load_assembly_library();
    int (*my_strcasecmp)(char *, char *) = dlsym(library_so, "strcasecmp");
    char s1[] = "ISSOU";
    char s2[] = "issou";
    int res = my_strcasecmp(s1, s2);
    int res_same = strcasecmp(s1, s2);

    cr_assert_eq(res, res_same);
}

Test(strcasecmp, s1_shorter)
{
    void *library_so = load_assembly_library();
    int (*my_strcasecmp)(char *, char *) = dlsym(library_so, "strcasecmp");
    char s1[] = "iss";
    char s2[] = "issou";
    int res = my_strcasecmp(s1, s2);
    int res_same = strcasecmp(s1, s2);

    cr_assert_eq(res, res_same);
}