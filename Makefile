# constant
SEP_P		:=	"----------------------------------------------"
SEP_S		:=	".............................................."

# libft settings
FTPATH			:=	libft
IFT				:=	include
FT_NAME			:=	libft.a
FT				:=	ft

# minilibX settings
MLX_PATH		:=	minilibX
MLX_NAME		:=	libmlx.a
MLX				:=	mlx

# project settings
NAME 			:=	cub3d
NAME_AR			:=	libcub3d.a
NORMINETTE_BIN 	:= 	norminette
NM_BIN			:=	nm
CC				:=	cc
CFLAGS			:=	-MMD -Wall -Wextra -Werror
CFLAGS_MLX 		:=	-lXext -lX11 -lm
#CFLAGS			:=	-MMD
#CFLAGSADD		:=	-g3 -fsanitize=address
CFLAGSADD		:=	-g3

VALGRIND		:=	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes

IPATH			:=	includes
OPATH			:=	obj
UTPATH			:=	unit_test

SRCS_PATH		:=	sources
CB_MLX_PATH		:=	cb_mlx
GRAPH_PATH		:=	graphics
MAP_PATH		:=	map
PARSE_PATH		:=	parsing
RAY_PATH		:=	ray_casting
SETTINGS_PATH		:=	settings
UTILS_PATH		:=	utils

AR				:=	ar rcs
RM				:=	rm -rf

CB_MLX_SRCS		:=	cb_mlx_init.c\
				cb_mlx_show.c\
				cb_mlx_show_string.c

GRAPH_SRCS		:=	choose_wall_color.c\
					destroy_sprites.c\
					draw_vertical_line.c\
					free_mlx.c\
					ft_key_hook.c\
					ft_red_cross.c\
					init_game.c\
					my_mlx_pixel_put.c\

MAP_SRCS		:=	map_lst.c

PARSE_SRCS		:=	parse_argc.c\
				parse.c\
				parse_map_fd.c\
				parse_map_fd_free.c\
				parse_map_fd_init.c\
				parse_map_fd_show.c\
				parse_read_file.c\
				create_list.c\
					ft_parse.c\
					read_map.c\

RAY_SRCS		:=	calculate_ray_position_and_direction.c\
					calculate_step.c\
					draw_wall.c\
					perform_dda.c\
					set_vectors.c\
					start_ray_casting_loop.c\

SETTINGS_SRCS		:=	settings_init.c\
				settings_rgb.c\
				settings_rgb_check.c\
				settings_rgb_check_char.c\
				settings_rgb_check_space.c\
				settings_rgb_check_value.c\
				settings_rgb_set_value.c\
				settings_rgb_set_value_type.c\
				settings_show.c\
				settings_texture_fd_check.c\
				settings_texture_fd_open.c\
				settings_texture_fd_save.c

UTILS_SRCS		:=	get_character_in_map.c\
					print_map.c\

SRCS			:=	main.c\
					$(CB_MLX_SRCS)\
					$(GRAPH_SRCS)\
					$(MAP_SRCS)\
					$(PARSE_SRCS)\
					$(RAY_SRCS)\
					$(SETTINGS_SRCS)\
					$(UTILS_SRCS)
					
OBJS			:=	$(addprefix $(OPATH)/, $(SRCS:.c=.o))
DEPS			:=	$(OBJS:.o=.d)

vpath %.h $(IPATH)
vpath %.c $(SRCS_PATH)\
		$(SRCS_PATH)/$(CB_MLX_PATH)\
		$(SRCS_PATH)/$(GRAPH_PATH)\
		$(SRCS_PATH)/$(MAP_PATH)\
		$(SRCS_PATH)/$(PARSE_PATH)\
		$(SRCS_PATH)/$(RAY_PATH)\
		$(SRCS_PATH)/$(SETTINGS_PATH)\
		$(SRCS_PATH)/$(UTILS_PATH)

vpath %.o $(OPATH)

all:	$(NAME)

$(OPATH)/%.o:	%.c
			$(CC) $(CFLAGS) $(CFLAGSADD) -I $(IPATH) -I $(FTPATH)/$(IFT) -I $(MLX_PATH) -c $< -o $@

$(NAME):	$(OBJS)
			make -C $(FTPATH)
			$(CC) $(CFLAGS) $(CFLAGSADD) $(OBJS) -I $(IPATH) -I $(FTPATH)/$(IFT) -I $(MLX_PATH) -L$(FTPATH) -l$(FT) -L$(MLX_PATH) -l$(MLX) -o $(NAME) $(CFLAGS_MLX)

$(OBJS):	| $(OPATH)

$(OPATH):
			mkdir -p $(OPATH)

clean:
			make clean -C $(FTPATH)
			$(RM) $(OPATH)

fclean:
			make clean
			$(RM) $(NAME) $(FTPATH)/$(FT_NAME)
  
re:
			make fclean
			make all

norme:
			$(NORMINETTE_BIN) $(SRCS) $(FTPATH)

sym:
			$(NM_BIN) -Dgu $(NAME) $(FTPATH)

comp:
			make
			$(VALGRIND) ./$(NAME)

comp_vgdb:
			make
			$(VALGRIND) --vgdb-error=0 ./$(NAME)

compi_envi:
			make
			$(VALGRIND) env -i ./$(NAME)

archive:		$(filter-out $(OBJ)/main.o, $(OBJS))
			$(AR) $(UTPATH)/$(NAME_AR) $^
			@ranlib $(UTPATH)/$(NAME_AR)

test:
			make
			$(VALGRIND) ./$(NAME) maps/map_subject.cub
			@echo $(SEP_P)
			$(VALGRIND) ./$(NAME) maps/map_subject.cub.cub
			@echo $(SEP_P)

-include $(DEPS)

.PHONY: all clean fclean re norme sym comp comp_vgdb comp_envi archive test
