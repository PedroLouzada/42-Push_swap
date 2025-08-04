# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 20:52:10 by pbongiov          #+#    #+#              #
#    Updated: 2025/07/19 21:04:41 by pbongiov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS_FILES = push_swap.c lists_config.c ft_split.c swap.c push.c rotate.c reverse.c parsing.c radix_sort.c utils.c

SRCS_DIR = srcs

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS_DIR = objs

OBJS	=$(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.c=.o))

CFLAGS = -g -Wall -Wextra -Werror
CC = cc

all:	$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:		fclean 	all

.PHONY : all clean fclean re