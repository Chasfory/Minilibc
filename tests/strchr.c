/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-laetitia.bousch
** File description:
** strchr
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

Test(strchr, simple)
{
    void *library_so = load_assembly_library();
    char *(*my_strchr)(char *, char) = dlsym(library_so, "strchr");
    char test[] = "issou";
    char *ret = my_strchr(test, 's');
    char *ret_same = strchr(test, 's');

    cr_assert_eq(ret, ret_same);
}

Test(strchr, empty_string)
{
    void *library_so = load_assembly_library();
    char *(*my_strchr)(char *, char) = dlsym(library_so, "strchr");
    char test[] = "";
    char *ret = my_strchr(test, 's');
    char *ret_same = strchr(test, 's');

    cr_assert_eq(ret, ret_same);
}

Test(strchr, terminator) {
    void *library_so = load_assembly_library();
    char *(*my_strchr)(char *, char) = dlsym(library_so, "strchr");
    char test[] = "issou";
    char *ret = my_strchr(test, '\0');
    char *ret_same = strchr(test, '\0');

    cr_assert_eq(ret, ret_same);
}