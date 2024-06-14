# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 10:31:28 by mhotting          #+#    #+#              #
#    Updated: 2024/06/14 01:08:57 by codekiwi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################
#              Variable definitions             #
#################################################

# GENERAL
NAME					=	cub3D
CC						=	cc
ifndef NOFLAGS
	CFLAGS				=	-Wall -Werror -Wextra -g
endif
HFLAGS					=	-I$(HEADERS_DIR) -I$(LIBFT_HEADERS_DIR)
FSFLAGS					=	-fsanitize=address
EXT_LIB_FLAGS			=	-lm

# HEADERS
HEADERS_DIR				=	includes/
HEADERS_FILES			=	cub3d.h map.h vector.h
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

# BASIC_RENDER
BASIC_RENDER_DIR		=	basic_render/
BASIC_RENDER_FILE		=	raycasting.c		\
							draw_walls.c
BASIC_RENDER			=	$(addprefix $(BASIC_RENDER_DIR), $(BASIC_RENDER_FILE))

# MAP
MAP_DIR					=	map/
MAP_FILE				=	read_map.c			\
							is_in_bounds.c		\
							read_elements.c		\
							is_valid.c
MAP						=	$(addprefix $(MAP_DIR), $(MAP_FILE))

# VECTOR
VECTOR_DIR				=	vector/
VECTOR_FILE				=	vector.c
VECTOR					=	$(addprefix $(VECTOR_DIR), $(VECTOR_FILE))

# UTILS
UTILS_DIR				=	utils/
UTILS_FILE				=	math.c				\
							array.c
UTILS					=	$(addprefix $(UTILS_DIR), $(UTILS_FILE))

# SOURCES GENERAL
SRCS_MAIN_DIR			=	srcs/
SRCS_FILES				=	$(MAIN) $(MAP) $(BASIC_RENDER) $(VECTOR) $(UTILS)
SRCS					=	$(addprefix $(SRCS_MAIN_DIR), $(SRCS_FILES))

# OBJECTS GENERAL
OBJS_MAIN_DIR			=	objs/
OBJS_FILES				=	$(SRCS_FILES:.c=.o)
OBJS					=	$(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES))

# DEPENDENCIES
DEPS_MAIN_DIR			=	deps/
DEPS_FILES				=	$(OBJS_FILES:.o=.d)
DEPS					=	$(addprefix $(DEPS_MAIN_DIR), $(DEPS_FILES))