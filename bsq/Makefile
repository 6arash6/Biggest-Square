# ************************************************************************** */
#                                                                            */
#                                                        :::      ::::::::   */
#   Makefile                                            :+:      :+:    :+:   */
#                                                    +:+ +:+         +:+     */
#   By: student <student@student.42.fr>            +#+  +:+       +#+        */
#                                                +#+#+#+#+#+   +#+           */
#   Created: 2024/01/01 00:00:00 by student          #+#    #+#             */
#   Updated: 2024/01/01 00:00:00 by student         ###   ########.fr       */
#                                                                            */
# ************************************************************************** */

NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
INCDIR = include
OBJDIR = obj

SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/ft_create_map.c \
       $(SRCDIR)/ft_get_matrix.c \
       $(SRCDIR)/ft_get_line.c \
       $(SRCDIR)/ft_process_map.c \
       $(SRCDIR)/ft_util.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
