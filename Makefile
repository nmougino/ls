# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/07 23:21:20 by nmougino          #+#    #+#              #
#    Updated: 2016/09/13 02:47:33 by nmougino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Compilator - clang est plus sur que gcc
CC =		clang
CFLAGS =	-Wall -Wextra -Werror# -fsanitize=address -g3 -Weverything -Wno-padded
#ADDFLAGS =	-fsanitize=address
ADDFLAGS =

#	Binary
NAME =		ft_ls

#	Default rule
DEFRULE =	all

#	Dossiers utiles
SRCDIR =	srcs
INCDIR =	includes
OBJDIR =	objs

#	Liste des sources
SRC =		check_perm.c \
			compute.c \
			compute_mm.c \
			disp_attr.c \
			disp_details.c \
			disp_long.c \
			disp_mode.c \
			display.c \
			error.c \
			free_dep.c \
			list_dir.c \
			ls_rec.c \
			ls_std.c \
			main.c \
			parser.c \
			path_dep.c \
			sort_fun_rev.c \
			sort_fun2.c \
			sort_fun.c
LIB =		ft
OBJ =		$(SRC:.c=.o)

#	Prefixes
LLIBP =		$(addprefix -l, $(LIB))
LIBP =		$(addprefix lib, $(LIB))
OBJP =		$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

#	Couleurs
DEF =		\033[0m
GRA =		\033[1m
SOU =		\033[4m
BLI =		\033[5m
BLA =		\033[30m
RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
PUR =		\033[35m
CYA =		\033[36m
WHI =		\033[37m

define \n


endef

# #
#	RULES
#

.PHONY = default glu all re $(OBJDIR) $(NAME) deplib clean fclean

#	Main rules
default:
	@echo "$(GRA)  DEFAULT RULE EXECUTION  :::  rule $(DEFRULE)$(DEF)"
	@$(addprefix make ,$(DEFRULE))
	@echo "$(GRE)$(GRA)Programme termine :)$(DEF)"

glu: re
	make clean

all: libcomp $(OBJDIR) $(NAME)

re: fclean all

#	Compilation rules
libcomp:
	make all -C lib$(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS)	$(ADDFLAGS) -c -o $@ $^ -I $(INCDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "$(GRA)$(CYA)@ ++ Objects compilation$(DEF)"

$(NAME): $(OBJP)
	@echo "$(GRA)$(CYA)@ ++ $@ compilation$(DEF)"
	@$(CC) $(CFLAGS) $(ADDFLAGS)	-o $@ $^ -I $(INCDIR) -L lib$(LIB) -l$(LIB)

#	MrProper's legacy
clean:
	@echo "$(RED)@ Objects deletion$(DEF)"
	@rm -rf $(OBJDIR)
	@echo "$(RED)@ Library deletion$(DEF)"
	@make fclean -C libft/

fclean: clean
	@echo "$(RED)@ Binary deletion$(DEF)"
	@rm -f $(NAME)
