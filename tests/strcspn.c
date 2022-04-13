/*
** EPITECH PROJECT, 2022
** test_strcspn.c
** File description:
** test_strcspn.c
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

Test(strcspn, all_chars)
{
    void *library_so = load_assembly_library();
    unsigned int(*my_strcspn)(char *, char *) = dlsym(library_so, "strcspn");
    char test[] = "test";

    cr_expect_eq(my_strcspn(test, "test"), strcspn(test, "test"));
}

Test(strcspn, nothing_comparation)
{
    void *library_so = load_assembly_library();
    unsigned int(*my_strcspn)(char *, char *) = dlsym(library_so, "strcspn");
    char test[] = "test";

    cr_expect_eq(my_strcspn(test, "lilo"), strcspn(test, "lilo"));
}

Test(strcspn, one_char)
{
    void *library_so = load_assembly_library();
    unsigned int(*my_strcspn)(char *, char *) = dlsym(library_so, "strcspn");
    char test[] = "test";
    unsigned int found = my_strcspn(test, "e");
    unsigned int real_found = strcspn(test, "e");

    cr_expect_eq(my_strcspn(test, "e"), strcspn(test, "e"));
}

Test(strcspn, some_chars)
{
    void *library_so = load_assembly_library();
    unsigned int(*my_strcspn)(char *, char *) = dlsym(library_so, "strcspn");
    char test[] = "test";
    unsigned int found = my_strcspn(test, "st");
    unsigned int real_found = strcspn(test, "st");

    cr_expect_eq(found, real_found);
}

Test(strcspn, empty_string)
{
    void *library_so = load_assembly_library();
    unsigned int(*my_strcspn)(char *, char *) = dlsym(library_so, "strcspn");
    char test[] = "";

    cr_expect_eq(my_strcspn(test, "test"), strcspn(test, "test"));
}

Test(strcspn, empty_needle)
{
    void *library_so = load_assembly_library();
    unsigned int(*my_strcspn)(char *, char *) = dlsym(library_so, "strcspn");
    char test[] = "test";
    unsigned int found = my_strcspn(test, "");
    unsigned int real_found = strcspn(test, "");

    cr_expect_eq(found, real_found);
}
