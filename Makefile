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
NAME 			:=	cub3D
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
GRAPH_PATH		:=	graphics
CAM_PATH		:=	camera_movements
TEX_PATH		:=	texturing
MAP_PATH		:=	map
PARSE_PATH		:=	parsing
RAY_PATH		:=	ray_casting
SETTINGS_PATH		:=	settings
UTILS_PATH		:=	utils
COLOR_PATH		:=	print_colors

AR				:=	ar rcs
RM				:=	rm -rf

GRAPH_SRCS		:=	choose_wall_color.c\
					draw_vertical_line.c\
					key_hook.c\
					ft_red_cross.c\
					init_game.c\
					my_mlx_pixel_put.c\

CAM_SRCS		:=	move_down.c\
					move_left.c\
					move_right.c\
					move_up.c\
					rotate_left.c\
					rotate_right.c\

TEX_SRCS		:=	init_buf.c\
					init_texture.c\
					generate_textures.c\
					choose_wall_texture.c\
					init_re_buf.c\
					load_texture.c\

MAP_SRCS		:=	map.c\
					map_check.c\
					map_check_line.c\
					map_check_line_char.c\
					map_check_line_player_sp.c\
					map_check_width.c\
					map_get_start_obj.c\
					map_rm_nl.c\
					map_rm_nl_line.c\
					map_tab.c\
					map_tab_adjust.c\
					map_tab_adjust_line.c\
					map_tab_check.c\
					map_tab_check_line.c\
					map_tab_check_line_horizontal.c\
					map_tab_check_line_vertical.c\
					map_tab_create.c\
					map_tab_create_line.c\
					map_tab_free.c\
					map_tab_init_bzero.c\
					map_tab_init.c\
					map_tab_init_line.c\
					map_tab_show.c

PARSE_SRCS		:=	parse_argc.c\
					parse.c\
					parse_map_fd.c\
					parse_map_fd_free.c\
					parse_map_fd_init.c\
					parse_map_fd_show.c\
					parse_map_lst.c\
					parse_map_lst_check.c\
					parse_map_lst_fullspace.c\
					parse_map_lst_get_value.c\
					parse_map_lst_line.c\
					parse_map_lst_line_txt_type.c\
					parse_read_file.c

RAY_SRCS		:=	calculate_ray_position_and_direction.c\
					calculate_step.c\
					calculate_start_and_end_of_line.c\
					perform_dda.c\
					init_struct.c\
					start_ray_casting_loop.c\
					init_starting_direction.c\

SETTINGS_SRCS		:=	settings_check.c\
						settings_check_map_order.c\
						settings_check_map_start_line.c\
						settings_check_map_size_min.c\
						settings_check_txt_type.c\
						settings_free.c\
						settings_free_close_fd.c\
						settings_init.c\
						settings_init_map.c\
						settings_init_rgb.c\
						settings_rgb.c\
						settings_rgb_check.c\
						settings_rgb_check_char.c\
						settings_rgb_check_dup.c\
						settings_rgb_check_space.c\
						settings_rgb_check_value.c\
						settings_rgb_convert.c\
						settings_rgb_rm_space_end.c\
						settings_rgb_set_line_no.c\
						settings_rgb_set_value.c\
						settings_rgb_set_value_type.c\
						settings_rm_space_end.c\
						settings_show.c\
						settings_show_string.c\
						settings_texture_fd_check_dup.c\
						settings_texture_fd_open.c\
						settings_texture_fd_save_fd.c\
						settings_texture_fd_save_filename.c\
						settings_texture_fd_set_line_no.c

UTILS_SRCS		:=	get_character_in_map.c\
					print_map.c\
					print_tab.c\
					errors_handler.c\
					clean_up.c\

COLOR_SRCS		:=	print_blue.c\
					print_cyan.c\
					print_green.c\
					print_purple.c\
					print_sea_green_four.c\
					reset_print_color.c\

SRCS			:=	main.c\
				main_init_conf_game.c\
				main_init_map.c\
					$(GRAPH_SRCS)\
					$(CAM_SRCS)\
					$(TEX_SRCS)\
					$(RAY_SRCS)\
					$(MAP_SRCS)\
					$(PARSE_SRCS)\
					$(SETTINGS_SRCS)\
					$(UTILS_SRCS)\
					$(COLOR_SRCS)\
					
OBJS			:=	$(addprefix $(OPATH)/, $(SRCS:.c=.o))
DEPS			:=	$(OBJS:.o=.d)

vpath %.h $(IPATH)
vpath %.c $(SRCS_PATH)\
		$(SRCS_PATH)/$(GRAPH_PATH)\
		$(SRCS_PATH)/$(GRAPH_PATH)/$(CAM_PATH)\
		$(SRCS_PATH)/$(GRAPH_PATH)/$(TEX_PATH)\
		$(SRCS_PATH)/$(RAY_PATH)\
		$(SRCS_PATH)/$(MAP_PATH)\
		$(SRCS_PATH)/$(PARSE_PATH)\
		$(SRCS_PATH)/$(SETTINGS_PATH)\
		$(SRCS_PATH)/$(UTILS_PATH)\
		$(SRCS_PATH)/$(UTILS_PATH)/$(COLOR_PATH)\

vpath %.o $(OPATH)

all:	$(NAME)

$(OPATH)/%.o:	%.c
			$(CC) $(CFLAGS) $(CFLAGSADD) -I $(IPATH) -I $(FTPATH)/$(IFT) -I $(MLX_PATH) -c $< -o $@

$(NAME):	$(OBJS)
			make -C $(MLX_PATH)
			make -C $(FTPATH)
			$(CC) $(CFLAGS) $(CFLAGSADD) $(OBJS) -I $(IPATH) -I $(FTPATH)/$(IFT) -I $(MLX_PATH) -L$(FTPATH) -l$(FT) -L$(MLX_PATH) -l$(MLX) -o $(NAME) $(CFLAGS_MLX)

$(OBJS):	| $(OPATH)

$(OPATH):
			mkdir -p $(OPATH)

clean:
			make clean -C $(MLX_PATH)
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

test_ok:
			make
			@echo "TEST - OK"
			$(VALGRIND) ./$(NAME) maps/ok_all_subject.cub
			@echo $(SEP_P)
			$(VALGRIND) ./$(NAME) maps/ok_map_space_end_line_1.cub
			@echo $(SEP_P)
			$(VALGRIND) ./$(NAME) maps/ok_map_space_end_line_2.cub
			@echo $(SEP_P)
			

test_ko:
			make
			@echo "TEST - KO MISSING FILE"
			$(VALGRIND) ./$(NAME) maps/ok_subject.cub.cub
			@echo $(SEP_S)
			$(VALGRIND) ./$(NAME) maps/ko_SO_no_space_sep.cub
			@echo $(SEP_P)
			@echo "TEST - KO DUPLICATE TEXTURE DATA"
			$(VALGRIND) ./$(NAME) maps/ko_SO_dup.cub
			@echo $(SEP_P)

-include $(DEPS)

.PHONY: all clean fclean re norme sym comp comp_vgdb comp_envi archive test_ok test_ko
