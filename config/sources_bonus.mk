# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_bonus.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 11:26:46 by mhotting          #+#    #+#              #
#    Updated: 2024/06/19 11:44:38 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################
#              Variable definitions             #
#################################################

NAME_BONUS					=	cub3D_bonus
EXECUTABLE_DIR				=	./
NAME_EXECUTABLE_BONUS		=	$(addprefix $(EXECUTABLE_DIR), $(NAME_BONUS))
BONUS_DIR					=	bonus/

CC							=	cc
ifndef NOFLAGS
	CFLAGS					=	-Wall -Werror -Wextra -g
endif
HFLAGS_BONUS				=	-I$(HEADERS_DIR_BONUS) -I$(LIBFT_HEADERS_DIR) -I$(MLX_DIR)
FSFLAGS						=	-fsanitize=address
EXT_LIB_FLAGS				=	-lm

# HEADERS
HEADERS_DIR_BONUS			=	includes_bonus/
HEADERS_FILES_BONUS			=	cub3d_bonus.h 					\
								mlx_api_bonus.h					\
								event_handlers_bonus.h 			\
								map_bonus.h						\
								vector_bonus.h
HEADERS_BONUS				=	$(addprefix $(HEADERS_DIR_BONUS), $(HEADERS_FILES_BONUS))

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
MAIN_DIR_BONUS					=	main_bonus/
MAIN_FILES_BONUS				=	cub3d_bonus.c
MAIN_BONUS						=	$(addprefix $(MAIN_DIR_BONUS), $(MAIN_FILES_BONUS))

# GAME
GAME_DIR_BONUS					=	game_bonus/
GAME_FILES_BONUS				=	t_game_destroy_bonus.c			\
									t_game_init_bonus.c				\
									game_loop_bonus.c
GAME_BONUS						=	$(addprefix $(GAME_DIR_BONUS), $(GAME_FILES_BONUS))

# MLX_API
MLX_API_DIR_BONUS				=	mlx_api_bonus/
MLX_API_FILES_BONUS				=	t_image_utils_bonus.c			\
									t_mlx_init_bonus.c				\
									t_mlx_destroy_bonus.c			\
									t_mlx_hook_bonus.c				\
									t_mlx_render_bonus.c			\
									t_mlx_draw_pixel_bonus.c		\
									t_mlx_get_pixel_bonus.c			\
									t_mlx_draw_line_bonus.c			\
									t_mlx_draw_rectangle_bonus.c	\
									t_argb_color_utils_bonus.c
MLX_API_BONUS					=	$(addprefix $(MLX_API_DIR_BONUS), $(MLX_API_FILES_BONUS))

# EVENT_HANDLERS
EVENT_HANDLERS_DIR_BONUS		=	event_handlers_bonus/
EVENT_HANDLERS_FILES_BONUS		=	add_event_handler_bonus.c		\
									destroy_handler_bonus.c			\
									key_release_handler_bonus.c		\
									key_press_handler_bonus.c
EVENT_HANDLERS_BONUS			=	$(addprefix $(EVENT_HANDLERS_DIR_BONUS), $(EVENT_HANDLERS_FILES_BONUS))

# BASIC_RENDER
BASIC_RENDER_DIR_BONUS			=	basic_render_bonus/
BASIC_RENDER_FILES_BONUS		=	draw_walls_bonus.c				\
									draw_column_bonus.c
BASIC_RENDER_BONUS				=	$(addprefix $(BASIC_RENDER_DIR_BONUS), $(BASIC_RENDER_FILES_BONUS))

# MAP
MAP_DIR_BONUS					=	map_bonus/
MAP_FILES_BONUS					=	read_map_bonus.c				\
									is_in_bounds_bonus.c			\
									read_elements_bonus.c			\
									is_valid_bonus.c				\
									free_map_bonus.c
MAP_BONUS						=	$(addprefix $(MAP_DIR_BONUS), $(MAP_FILES_BONUS))

# PLAYER
PLAYER_DIR_BONUS				=	player_bonus/
PLAYER_FILES_BONUS				=	t_player_init_bonus.c			\
									update_player_bonus.c
PLAYER_BONUS					=	$(addprefix $(PLAYER_DIR_BONUS), $(PLAYER_FILES_BONUS))

# RAY
RAY_DIR_BONUS					=	ray_bonus/
RAY_FILES_BONUS					=	raycasting_bonus.c				\
									cast_rays_bonus.c
RAY_BONUS						=	$(addprefix $(RAY_DIR_BONUS), $(RAY_FILES_BONUS))

# VECTOR
VECTOR_DIR_BONUS				=	vector_bonus/
VECTOR_FILES_BONUS				=	vector_bonus.c
VECTOR_BONUS					=	$(addprefix $(VECTOR_DIR_BONUS), $(VECTORS_FILES_BONUS))

# UTILS
UTILS_DIR_BONUS					=	utils_bonus/
UTILS_FILE_BONUS				=	math_bonus.c					\
									array_bonus.c					\
									handle_error_bonus.c			\
									number_bonus.c					\
									check_extension_bonus.c			\
									string_bonus.c
UTILS_BONUS						=	$(addprefix $(UTILS_DIR_BONUS), $(UTILS_FILES_BONUS))

# SOURCES GENERAL
SRCS_MAIN_SUBDIR_BONUS			=	srcs_bonus/
SRCS_MAIN_DIR_BONUS				=	$(addprefix $(BONUS_DIR), $(SRCS_MAIN_SUBDIR_BONUS))
SRCS_FILES_BONUS				=	$(MAIN_BONUS) $(MLX_API_BONUS) 			\
									$(UTILS_BONUS) $(GAME_BONUS) 			\
									$(VECTOR_BONUS)	$(EVENT_HANDLERS_BONUS) \
									$(MAP_BONUS) $(BASIC_RENDER_BONUS)		\
									$(PLAYER_BONUS) $(RAY_BONUS)
SRCS_BONUS						=	$(addprefix $(SRCS_MAIN_DIR_BONUS), $(SRCS_FILES_BONUS))

# OBJECTS GENERAL
OBJS_MAIN_SUBDIR_BONUS			=	objs_bonus/
OBJS_MAIN_DIR_BONUS				=	$(addprefix $(BONUS_DIR), $(OBJS_MAIN_SUBDIR_BONUS))
OBJS_FILES_BONUS				=	$(SRCS_FILES_BONUS:.c=.o)
OBJS_BONUS						=	$(addprefix $(OBJS_MAIN_DIR_BONUS), $(OBJS_FILES_BONUS))

# DEPENDENCIES
DEPS_MAIN_SUBDIR_BONUS			=	deps_bonus/
DEPS_MAIN_DIR_BONUS				=	$(addprefix $(BONUS_DIR), $(DEPS_MAIN_SUBDIR_BONUS))
DEPS_FILES_BONUS				=	$(OBJS_FILES_BONUS:.o=.d)
DEPS_BONUS						=	$(addprefix $(DEPS_MAIN_DIR_BONUS), $(DEPS_FILES_BONUS))