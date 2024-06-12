# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 10:35:12 by mhotting          #+#    #+#              #
#    Updated: 2024/06/12 10:59:38 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config/sources.mk

#################################################
#               Rule definitions                #
#################################################

# RULES
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(HFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(EXT_LIB_FLAGS) -o $@

$(OBJS_MAIN_DIR)%.o: $(SRCS_MAIN_DIR)%.c $(HEADERS) $(LIBFT_HEADERS)
	@mkdir -p $(@D)
	@mkdir -p $(DEPS_MAIN_DIR)$(dir $*)
	$(CC) $(CFLAGS) $(HFLAGS) -MP -MMD -MF $(DEPS_MAIN_DIR)$*.d -c $< -o $@ 

$(LIBFT): init_submodule FORCE
	$(MAKE) -sC $(LIBFT_DIR)

$(MLX): init_submodule FORCE
	$(MAKE) -sC $(MLX_DIR) > /dev/null 2>&1

FORCE:

bonus: all

fsanitize: fclean $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(HFLAGS) $(FSFLAGS) $(OBJS) $(LIBFT_FLAGS) $(EXT_LIB_FLAGS) -o $(NAME)

init_submodule:
	@if git submodule status | egrep -q '^[-+]' ; then \
		echo "*Info: Need to initialize git submodules"; \
		git submodule update --init; \
	fi

-include $(DEPS)

clean:
	rm -rf $(OBJS_MAIN_DIR)
	rm -rf $(DEPS_MAIN_DIR)

clean-libft:
	$(MAKE) -C $(LIBFT_DIR) clean

clean-mlx:
	make -sC $(MLX_DIR) clean > /dev/null 2>&1

fclean: clean
	rm -f $(NAME)

fclean-libft:
	$(MAKE) -sC $(LIBFT_DIR) fclean

fclean-mlx: clean-mlx

ffclean: fclean fclean-libft fclean-mlx

re: fclean all

rre: ffclean re

.PHONY: all clean fclean re clean-libft clean-mlx fclean-libft fclean-mlx ffclean rre bonus FORCE fsanitize init_submodule