# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marondon <marondon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 21:00:25 by marondon          #+#    #+#              #
#    Updated: 2024/05/06 23:50:34 by marondon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------- EXECUTABLE ---------------------------------#
NAME = cub3D

#--------------------------------- COMPILER -----------------------------------#
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = $(LIBS) $(LIBFT)
# CC = clang-12
# CFLAGS = -Wall -Wextra -Werror -gdwarf-4 -g3
# COMPILER_FLAGS = -Wall -Wextra -Werror -g -fsanitize=address,leak,undefined
# LIBS = -lasan -lubsan -lreadline

#------------------------------- ABBREVIATIONS --------------------------------#
RM = rm -rf
MKDIR = mkdir -p
ARCHIVE = ar rcs

#-------------------------------- ANSI COLORS ---------------------------------#
BLACK := \033[0;30m
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
PURPLE := \033[0;35m
CYAN := \033[0;36m
WHITE := \033[0;37m
NC := \033[0m # No color

#--------------------------------- LIBRARIES ----------------------------------#
LIBFT_DIR := lib/libft
LIBFT := $(LIBFT_DIR)/libft.a
LIB_HEADERS = $(LIBFT_DIR)/inc
LIBFT_MAKE := $(MAKE) -C $(LIBFT_DIR) --no-print-directory
LIBS =  -lmlx -lXext -lX11 -lm

#--------------------------------- FILE TREE ----------------------------------#
RAW_INPUT_SRC =	\
				input_events \
				movement

RAW_PARSING_SRC =	\
				elements \
				file \
				ft_myatoi \
				linklist \
				map_val \
				map \
				parse \
				search

RAW_RAYCASTING_SRC =	\
				raycast \
				rays

RAW_RENDERING_SRC =	\
				3d_view \
				drawing \
				minimap \
				render \

RAW_SRC =	\
				$(RAW_INPUT_SRC:%=input/%) \
				$(RAW_PARSING_SRC:%=parsing/%) \
				$(RAW_RAYCASTING_SRC:%=raycasting/%) \
				$(RAW_RENDERING_SRC:%=rendering/%) \
				error \
				free \
				init \
				utils \
				main

#---------------------------------- HEADERS -----------------------------------#
INC = inc
# HEADERS = \
# 			$(INC)/ast.h \
# 			$(INC)/builtins.h \
# 			$(INC)/environment.h \
# 			$(INC)/executor.h \
# 			$(INC)/expander.h \
# 			$(INC)/files.h \
# 			$(INC)/minishell.h \
# 			$(INC)/structs_n_stdhead.h \
# 			$(INC)/token.h

HEADERS = \
			$(INC)/cub3d.h

#------------------------ SOURCES & OBJECTS & FOLDERS -------------------------#
SRC_DIR = src
OBJ_DIR = obj

OBJ = $(RAW_SRC:%=$(OBJ_DIR)/%.o)

OBJ_DIRS := $(sort $(dir $(OBJ)))

#------------------------------------ CODE ------------------------------------#
.PHONY: all clean fclean re bonus generate_test test

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(LIBFT_MAKE)

$(NAME): $(LIBFT) $(OBJ) $(HEADERS)
	@printf "\r\033[K"
	@printf "$(YELLOW)$(NAME)!\n"
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
	@printf "$(GREEN)$(NAME) created.$(NC)\n"
	@printf "$(GREEN)$(NAME) done$(NC)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIRS)
	@printf "\r\033[K"
	$(LOADING_BAR)
	@$(CC) $(CFLAGS) -I$(INC) -I$(LIB_HEADERS) -c $< -o $@

$(OBJ_DIRS):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)Deleted objects$(NC)\n"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS_NAME)
	@$(LIBFT_MAKE) fclean
	@printf "$(RED)Deleted $(NAME)$(NC)\n"

re:
	@printf "$(YELLOW)Rebuilding...$(NC)\n"
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all

bonus: all

#-------------------------------- LOADING BAR ---------------------------------#
COUNT = 1
TOTAL_FILES := $(words $(RAW_SRC))

define LOADING_BAR
	@PERCENT=$$(( $$(($(COUNT) * 100 / $(TOTAL_FILES))) )); \
	if [ $$PERCENT -le 25 ]; then \
		COLOR="$(YELLOW)"; \
	elif [ $$PERCENT -le 50 ]; then \
		COLOR="$(GREEN)"; \
	elif [ $$PERCENT -le 75 ]; then \
		COLOR="$(CYAN)"; \
	else \
		COLOR="$(PURPLE)"; \
	fi; \
	FILLED=$$(( $$PERCENT / 5 )); \
	UNFILLED=$$(( 20 - $$FILLED )); \
	BAR=""; \
	for i in $$(seq 1 $$FILLED); do BAR="$$BAR#"; done; \
	for i in $$(seq 1 $$UNFILLED); do BAR="$$BAR-"; done; \
	printf "[$$COLOR$$BAR$(WHITE)] $(CYAN)Compiling $$PERCENT%%$(NC) - $<\r"; \
	$(eval COUNT=$(shell expr $$(($(COUNT) + 1))))
endef
