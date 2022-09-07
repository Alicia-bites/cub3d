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
NORMINETTE_BIN 	:= 	norminette
NM_BIN			:=	nm
CC				:=	cc
CFLAGS			:=	-MMD -Wall -Wextra -Werror
CFLAGS_MLX 		:=	-lXext -lX11
#CFLAGS			:=	-MMD
#CFLAGSADD		:=	-g3 -fsanitize=address
CFLAGSADD		:=	-g3

# VALGRIND	:=	valgrind -s --suppressions=ignoreliberror --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes
VALGRIND		:=	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes

IPATH			:=	includes
OPATH			:=	obj

SRCS_PATH		:=	sources
GRAPH_PATH		:=	graphics
CB_MLX_PATH		:=	cb_mlx
PARSE_PATH		:=	parsing
RAY_PATH		:=	ray_casting

RM				:=	rm -rf

GRAPH_SRCS		:=	destroy_sprites.c\
					draw_background.c\
					draw_no_player.c\
					draw_player.c\
					free_mlx.c\
					ft_key_hook.c\
					ft_red_cross.c\
					init_game.c\
					my_pixel_put.c\

CB_MLX_SRCS		:=	cb_mlx_init.c\
				cb_mlx_init_settings.c\
				cb_mlx_show.c\
				cb_mlx_show_settings.c\
				cb_mlx_show_string.c

PARSE_SRCS		:=	create_list.c\
					ft_parse.c\
					read_map.c\
					print_map.c\

RAY_SRCS		:=	calculate_ray_position_and_direction.c\
					calculate_step.c\
					perform_dda.c\
					set_vectors.c\
					start_ray_casting_loop.c\

SRCS			:=	main.c\
					$(GRAPH_SRCS)\
					$(CB_MLX_SRCS)\
					$(RAY_SRCS)\
					$(PARSE_SRCS)\
					
OBJS			:=	$(addprefix $(OPATH)/, $(SRCS:.c=.o))
DEPS			:=	$(OBJS:.o=.d)

vpath %.h $(IPATH)
vpath %.c $(SRCS_PATH)\
		$(SRCS_PATH)/$(GRAPH_PATH)\
		$(SRCS_PATH)/$(CB_MLX_PATH)\
		$(SRCS_PATH)/$(RAY_PATH)\
		$(SRCS_PATH)/$(PARSE_PATH)\

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
			$(RM) $(NAME) $(FT_NAME)
  
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

-include $(DEPS)

.PHONY: all clean fclean re norme sym comp comp_vgdb comp_envi
