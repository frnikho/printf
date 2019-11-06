SRCPATH		=	src
TESTPATH	=	tests

SRC 		= 	$(SRCPATH)/my_compute_factorial_it.c		\
				$(SRCPATH)/my_compute_factorial_rec.c 		\
				$(SRCPATH)/my_compute_power_it.c			\
				$(SRCPATH)/my_compute_power_rec.c 			\
				$(SRCPATH)/my_compute_square_root.c 		\
				$(SRCPATH)/my_convert_into_integer.c 		\
				$(SRCPATH)/my_find_prime_sup.c 				\
				$(SRCPATH)/my_getnbr.c 						\
				$(SRCPATH)/my_is_prime.c 					\
				$(SRCPATH)/my_isalpha.c 					\
				$(SRCPATH)/my_islowcase.c 					\
				$(SRCPATH)/my_isnum.c 						\
				$(SRCPATH)/my_isstrempty.c 					\
				$(SRCPATH)/my_isupcase.c 					\
				$(SRCPATH)/my_put_nbr.c 					\
				$(SRCPATH)/my_putchar.c 					\
				$(SRCPATH)/my_putstr.c 						\
				$(SRCPATH)/my_revstr.c 						\
				$(SRCPATH)/my_show_word_array.c 			\
				$(SRCPATH)/my_showmem.c 					\
				$(SRCPATH)/my_showstr.c 					\
				$(SRCPATH)/my_str_isalpha.c 				\
				$(SRCPATH)/my_str_islower.c 				\
				$(SRCPATH)/my_str_isnum.c 					\
				$(SRCPATH)/my_str_isprintable.c 			\
				$(SRCPATH)/my_str_isupper.c 				\
				$(SRCPATH)/my_strcapitalize.c 				\
				$(SRCPATH)/my_strcat.c 						\
				$(SRCPATH)/my_strcmp.c 						\
				$(SRCPATH)/my_strcpy.c 						\
				$(SRCPATH)/my_strlen.c 						\
				$(SRCPATH)/my_strlowcase.c 					\
				$(SRCPATH)/my_strncat.c 					\
				$(SRCPATH)/my_strncmp.c 					\
				$(SRCPATH)/my_strncpy.c 					\
				$(SRCPATH)/my_strstr.c 						\
				$(SRCPATH)/my_strupcase.c					\
				$(SRCPATH)/my_putnbr_base.c					\
				$(SRCPATH)/get_int_length.c					\
				$(SRCPATH)/my_isprintable.c					\
				$(SRCPATH)/my_printf.c

TESTS		=	$(TESTPATH)/test_my_printf.c				\
				$(TESTPATH)/test_my_putnbr_base.c			\
				$(TESTPATH)/test_get_int_length.c

OBJ			=	$(SRC:%.c=%.o)
OBJTESTS	=	$(TESTS:%.c=%.o)

NAME		=	libmy.a
TNAME		=	unit_tests

INCLUDE		=	-I include/
CFLAGS		=	$(INCLUDE)
TFLAGS		=	-lcriterion

all:			$(NAME)
$(NAME):		$(OBJ)
				ar rcs $(NAME) $(OBJ)
clean:
				rm -rf $(OBJ) $(OBJTESTS)
fclean:			clean
				rm -rf $(NAME) $(TNAME)
re:				fclean all
test_run:		$(OBJTESTS) $(OBJ)
				gcc -o $(TNAME) $(OBJ) $(OBJTESTS) $(TFLAGS)
				./unit_tests