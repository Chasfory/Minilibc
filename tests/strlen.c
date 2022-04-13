/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-laetitia.bousch
** File description:
** strlen
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

Test(strlen, empty_string)
{
    void *library_so = load_assembly_library();
    size_t(*my_strlen)(const char *) = dlsym(library_so, "strlen");
    const char *test = "";

    cr_assert_eq(my_strlen(test), strlen(test));
}

Test(strlen, spe_string)
{
    void *library_so = load_assembly_library();
    size_t(*my_strlen)(const char *) = dlsym(library_so, "strlen");
    const char *test = "éiopç";

    cr_assert_eq(my_strlen(test), strlen(test));
}

Test(strlen, long_string)
{
    void *library_so = load_assembly_library();
    size_t(*my_strlen)(const char *) = dlsym(library_so, "strlen");
    const char *test = "azertyuiopqsdfghjklmwxcvbnazertyuiopqsdfghjklmwxcvbnazertyuiop";

    cr_assert_eq(my_strlen(test), strlen(test));
}

Test(strlen, normal_string)
{
    void *library_so = load_assembly_library();
    size_t(*my_strlen)(const char *) = dlsym(library_so, "strlen");
    const char *test = "toto";

    cr_assert_eq(my_strlen(test), strlen(test));
}