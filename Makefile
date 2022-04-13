##
## EPITECH PROJECT, 2022
## B-ASM-400-PAR-4-1-asmminilibc-laetitia.bousch
## File description:
## Makefile
##

TARGET 	= libasm.so

SRC 	= src/strlen.asm	\
		  src/strchr.asm	\
		  src/strrchr.asm	\
		  src/memset.asm	\
		  src/memcpy.asm	\
		  src/strcmp.asm	\
		  src/memmove.asm	\
		  src/strncmp.asm	\
		  src/strpbrk.asm   \
		  src/strcasecmp.asm	\
		  src/strcspn.asm	\
		  src/strstr.asm

OBJS 	= $(SRC:.asm=.o)

NASM 	= nasm

ASM_FLAGS = -f elf64 -g -F dwarf

LD = ld

TEST_SRC	=	tests/strlen.c	\
				tests/memcpy.c  \
				tests/memmove.c	\
				tests/memset.c  \
				tests/strcasecmp.c \
				tests/strchr.c	\
				tests/strcmp.c  \
				tests/strncmp.c	\
				tests/strpbrk.c \
				tests/strstr.c	\
				tests/strcspn.c

TEST_OBJ	=	$(TEST_SRC:.c=.o)

TEST_LDFLAGS	=	-lcriterion --coverage -ldl

CPPFLAGS += --coverage

CC	=	gcc


RM	=	rm -f



all : $(TARGET)

$(TARGET): $(OBJS)
	$(LD) -shared -o $(TARGET) $(OBJS)

%.o : %.asm
	$(NASM) $(ASM_FLAGS) -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re : fclean all

tests: $(TEST_OBJ)
	$(CC) -o unit_tests $(TEST_OBJ) $(TEST_LDFLAGS)

unit_tests: all tests

tests_run:	unit_tests
	./unit_tests

clean_test:
	$(RM) $(TEST_OBJ)
	$(RM) tests/*.gc*

fclean_test: clean_test
	$(RM) unit_tests

ffclean: fclean fclean_test