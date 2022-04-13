/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-laetitia.bousch
** File description:
** strrchr
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

Test(strrchr, simple_string)
{
    void *library_so = load_assembly_library();
    char *(*my_strrchr)(char *, char) = dlsym(library_so, "strrchr");
    char test[] = "issou";
    char *res = my_strrchr(test, 's');
    char *res_same = strrchr(test, 's');

    cr_assert_eq(res, res_same);
}

Test(strrchr, empty_string)
{
    void *library_so = load_assembly_library();
    char *(*my_strrchr)(char *, char) = dlsym(library_so, "strrchr");
    char test[] = "";
    char *res = my_strrchr(test, 's');
    char *res_same = strrchr(test, 's');

    cr_assert_eq(res, res_same);
}

Test(strrchr, empty_string)
{
    void *library_so = load_assembly_library();
    char *(*my_strrchr)(char *, char) = dlsym(library_so, "strrchr");
    char test[] = "issou";
    char *res = my_strrchr(test, '\0');
    char *res_same = strrchr(test, '\0');

    cr_assert_eq(res, res_same);
}