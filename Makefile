# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 20:24:47 by asanotomoki       #+#    #+#              #
#    Updated: 2022/10/30 18:10:10 by asanotomoki      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fdf
LIBFTDIR := ./lib/libft
OBJDIR   := ./obj
SRC_DIR := ./srcs
CC  := cc
CFLAGS := -Wall -Werror -Wextra -g -fsanitize=address -fsanitize=integer -fsanitize=undefined

ifeq ($(shell uname), Darwin)
	MLX_DIR		:=	./lib/minilibx_macos/
	LIBMLX		:=	$(MLX_DIR)libmlx.a
	LXFLAGS		:=	-framework OpenGL -framework AppKit
else
	MLX_DIR		:=	./lib/minilibx-linux/
	LIBMLX		:=	$(MLX_DIR)libmlx_Linux.a
	LXFLAGS		:=	-lXext -lX11 -lm
endif

HEADERS :=  ./includes $(LIBFTDIR)/includes/ $(MLX_DIR)/
INCLUDES :=	$(addprefix -I, $(HEADERS))

SRC_FILES = main.c fdf.c error.c draw_tool.c init.c hooks.c create_map.c draw.c color_tool.c
SOURCES	:=  $(addprefix $(SRC_DIR), $(SRC_FILES))
LIBFT := $(LIBFTDIR)/libft.a
OBJECTS  := $(addprefix $(OBJDIR)/, $(SRC_FILES:.c=.o))
RM := rm -f

$(NAME): $(LIBFT) $(LIBMLX) $(OBJECTS) 
	@$(CC) $(CFLAGS) -o $(NAME)  $(LIBFT) $(OBJECTS) $(LIBMLX) $(LXFLAGS)
	@echo fdf compile OK 

$(OBJDIR)/%.o: $(SRC_DIR)/%.c
	@-mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(LIBFT) : 
	@make -C $(LIBFTDIR)
	@echo libft compile  OK
	
$(LIBMLX) : 
	@make -C $(MLX_DIR)
	@echo libMLC compile  OK

all: $(NAME)

clean:
	@make clean -C $(LIBFTDIR)
	@$(RM) $(OBJECTS)
	@rm -rf $(OBJDIR)
	@echo make clean

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re: fclean all

test : all
		./fdf test_maps/42.fdf
retest : re
		./fdf test_maps/42.fdf

.PHONY: all bonus fclean clean re test retest
