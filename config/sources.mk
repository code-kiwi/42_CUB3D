# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 10:31:28 by mhotting          #+#    #+#              #
#    Updated: 2024/06/13 15:38:08 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################
#              Variable definitions             #
#################################################

# GENERAL
NAME					=	cub3D
EXECUTABLE_DIR			=	./
NAME_EXECUTABLE			=	$(addprefix $(EXECUTABLE_DIR), $(NAME))

CC						=	cc
ifndef NOFLAGS
	CFLAGS				=	-Wall -Werror -Wextra -g
endif
HFLAGS					=	-I$(HEADERS_DIR) -I$(LIBFT_HEADERS_DIR) -I$(MLX_DIR)
FSFLAGS					=	-fsanitize=address
EXT_LIB_FLAGS			=	-lm

# HEADERS
HEADERS_DIR				=	includes/
HEADERS_FILES			=	cub3d.h mlx_api.h event_handlers.h
HEADERS					=	$(addprefix $(HEADERS_DIR), $(HEADERS_FILES))

# LIBFT
LIBFT_DIR				=	libft/
LIBFT_FILE				=	libft.a
LIBFT					=	$(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
LIBFT_HEADERS_SUBDIR	=	includes/
LIBFT_HEADERS_DIR		=	$(addprefix $(LIBFT_DIR), $(LIBFT_HEADERS_SUBDIR))
LIBFT_HEADERS_FILE		=	libft.h
LIBFT_HEADERS			=	$(addprefix $(LIBFT_HEADERS_DIR), $(LIBFT_HEADERS_FILE))
LIBFT_FLAGS				=	-L$(LIBFT_DIR) -lft 

# MLX
MLX_DIR					=	mlx/
MLX_FILE				=	libmlx_Linux.a
MLX						=	$(addprefix $(MLX_DIR), $(MLX_FILE))
MLX_HEADERS_FILE		=	mlx.h
MLX_HEADERS				=	$(addprefix $(MLX_DIR), $(MLX_HEADER_FILE))
MLX_FLAGS				=	-L$(MLX_DIR) -lmlx_Linux -lXext -lX11

# MAIN
MAIN_DIR				=	main/
MAIN_FILE				=	cub3d.c
MAIN					=	$(addprefix $(MAIN_DIR), $(MAIN_FILE))

# CUB_DATA
CUB_DATA_DIR			=	cub_data/
CUB_DATA_FILE			=	t_cub_data_destroy.c	\
								t_cub_data_init.c
CUB_DATA				=	$(addprefix $(CUB_DATA_DIR), $(CUB_DATA_FILE))

# MLX_API
MLX_API_DIR				=	mlx_api/
MLX_API_FILES			=	t_image_utils.c			\
							t_mlx_init.c			\
							t_mlx_destroy.c			\
							t_mlx_hook.c			\
							t_mlx_render.c			\
							t_mlx_draw_pixel.c		\
							t_mlx_draw_line.c		\
							t_mlx_draw_rectangle.c
MLX_API					=	$(addprefix $(MLX_API_DIR), $(MLX_API_FILES))

# GAME_LOOP
GAME_LOOP_DIR			=	game_loop/
GAME_LOOP_FILES			=	game_loop.c
GAME_LOOP				=	$(addprefix $(GAME_LOOP_DIR), $(GAME_LOOP_FILES))

# EVENT_HANDLERS
EVENT_HANDLERS_DIR		=	event_handlers/
EVENT_HANDLERS_FILES	=	add_event_handler.c		\
							destroy_handler.c		\
							keyboard_handler.c
EVENT_HANDLERS			=	$(addprefix $(EVENT_HANDLERS_DIR), $(EVENT_HANDLERS_FILES))

# UTILS
UTILS_DIR				=	utils/
UTILS_FILE				=	handle_error.c
UTILS					=	$(addprefix $(UTILS_DIR), $(UTILS_FILE))

# SOURCES GENERAL
SRCS_MAIN_DIR			=	srcs/
SRCS_FILES				=	$(MAIN) $(MLX_API) $(GAME_LOOP) $(UTILS)	\
							$(CUB_DATA) $(EVENT_HANDLERS)
SRCS					=	$(addprefix $(SRCS_MAIN_DIR), $(SRCS_FILES))

# OBJECTS GENERAL
OBJS_MAIN_DIR			=	objs/
OBJS_FILES				=	$(SRCS_FILES:.c=.o)
OBJS					=	$(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES))

# DEPENDENCIES
DEPS_MAIN_DIR			=	deps/
DEPS_FILES				=	$(OBJS_FILES:.o=.d)
DEPS					=	$(addprefix $(DEPS_MAIN_DIR), $(DEPS_FILES))