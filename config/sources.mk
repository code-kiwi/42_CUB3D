# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 10:31:28 by mhotting          #+#    #+#              #
#    Updated: 2024/06/14 15:00:43 by mhotting         ###   ########.fr        #
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
HEADERS_FILES			=	cub3d.h mlx_api.h event_handlers.h map.h vector.h
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
MAIN_FILES				=	cub3d.c
MAIN					=	$(addprefix $(MAIN_DIR), $(MAIN_FILES))

# GAME
GAME_DIR				=	game/
GAME_FILES				=	t_game_destroy.c		\
							t_game_init.c			\
							game_loop.c
GAME					=	$(addprefix $(GAME_DIR), $(GAME_FILES))

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

# EVENT_HANDLERS
EVENT_HANDLERS_DIR		=	event_handlers/
EVENT_HANDLERS_FILES	=	add_event_handler.c		\
							destroy_handler.c		\
							key_up_handler.c		\
							key_down_handler.c

EVENT_HANDLERS			=	$(addprefix $(EVENT_HANDLERS_DIR), $(EVENT_HANDLERS_FILES))

# BASIC_RENDER
BASIC_RENDER_DIR		=	basic_render/
BASIC_RENDER_FILES		=		
BASIC_RENDER			=	$(addprefix $(BASIC_RENDER_DIR), $(BASIC_RENDER_FILES))

# MAP
MAP_DIR					=	map/
MAP_FILES				=	read_map.c				\
							is_in_bounds.c			\
							read_elements.c			\
							is_valid.c
MAP						=	$(addprefix $(MAP_DIR), $(MAP_FILES))

# PLAYER
PLAYER_DIR				=	player/
PLAYER_FILES			=	t_player_init.c
PLAYER					=	$(addprefix $(PLAYER_DIR), $(PLAYER_FILES))

# RAY
RAY_DIR					=	ray/
RAY_FILES				=	raycasting.c			\
							draw_walls.c
RAY						=	$(addprefix $(RAY_DIR), $(RAY_FILES))

# VECTOR
VECTOR_DIR				=	vector/
VECTOR_FILE				=	vector.c
VECTOR					=	$(addprefix $(VECTOR_DIR), $(VECTOR_FILE))

# UTILS
UTILS_DIR				=	utils/
UTILS_FILE				=	math.c					\
							array.c					\
							handle_error.c
UTILS					=	$(addprefix $(UTILS_DIR), $(UTILS_FILE))

# SOURCES GENERAL
SRCS_MAIN_DIR			=	srcs/
SRCS_FILES				=	$(MAIN) $(MLX_API) $(UTILS) $(GAME) $(VECTOR)	\
							$(EVENT_HANDLERS) $(MAP) $(BASIC_RENDER)		\
							$(PLAYER) $(RAY)
SRCS					=	$(addprefix $(SRCS_MAIN_DIR), $(SRCS_FILES))

# OBJECTS GENERAL
OBJS_MAIN_DIR			=	objs/
OBJS_FILES				=	$(SRCS_FILES:.c=.o)
OBJS					=	$(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES))

# DEPENDENCIES
DEPS_MAIN_DIR			=	deps/
DEPS_FILES				=	$(OBJS_FILES:.o=.d)
DEPS					=	$(addprefix $(DEPS_MAIN_DIR), $(DEPS_FILES))