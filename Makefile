# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 20:24:47 by asanotomoki       #+#    #+#              #
#    Updated: 2022/10/31 21:03:01 by asanotomoki      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fdf
LIBFTDIR := ./lib/libft
OBJDIR   := ./obj
SRC_DIR := ./srcs
CC  := cc
CFLAGS := -Wall -Werror -Wextra

ifeq ($(shell uname), Darwin)
	MLX_DIR		:=	./lib/minilibx_macos
	LIBMLX		:=	$(MLX_DIR)/libmlx.a
	LXFLAGS		:=	-framework OpenGL -framework AppKit
else
	MLX_DIR		:=	./lib/minilibx-linux
	LIBMLX		:=	$(MLX_DIR)/libmlx_Linux.a
	LXFLAGS		:=	-lXext -lX11 -lm
endif

HEADERS :=  ./includes $(LIBFTDIR)/includes/ $(MLX_DIR)/
INCLUDES :=	$(addprefix -I, $(HEADERS))

SRC_FILES = main.c fdf.c \
			draw.c draw_tool.c \
			create_map.c map_tool.c map_tool2.c \
			error.c init.c \
			hooks.c operation.c \
			color_tool.c
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
	@echo LIBMLX compile  OK

all: $(NAME)

clean:
	@make clean -C $(LIBFTDIR)
	@make clean -C $(MLX_DIR)
	@rm -rf $(OBJDIR)
	@echo make clean

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(LIBMLX)

re: fclean all

.PHONY: all bonus fclean clean re
