NAME	=	fdf
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
CC  = cc
CFLAGS    =   -Wall -Werror -Wextra -g -fsanitize=address -fsanitize=integer -fsanitize=undefined
INCLUDES   = ./includes
SRC_DIR    = ./srcs
AR = ar
ARFLAFS = -rcs
RM = rm -f
SOURCES	=	main.c

OBJDIR    = ./obj
OBJECTS   = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.c=.o)))
DEPENDS   = $(OBJECTS:.o=.d)

${NAME}: ${INCLUDES} ${OBJECTS}
		make -C $(LIBFTDIR)
		$(CC) ${CFLAGS} ${LIBFT} ${OBJECTS} -o $@

$(OBJDIR)/%.o: $(SRC_DIR)/%.c
	-mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

all: $(NAME)

clean:
	make clean -C $(LIBFTDIR)
	$(RM) $(OBJECTS)
	rm -rf $(OBJDIR)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all bonus fclean clean re 
