# project settings
PRJ_PATH		:=	..
IPATH			:=	includes
PRJ_NAME		:=	libcub3d.a
PRJ			:=	cub3d

# libft settings
FTPATH			:=	libft
IFT				:=	include
FT_NAME			:=	libft.a
FT				:=	ft

# minilibX settings
MLX_PATH		:=	minilibX
MLX_NAME		:=	libmlx.a
MLX				:=	mlx

# unit test settings
NAME 			:=	ut_cub3d
CC			:=	cc
CFLAGS			:=	-MMD -Wall -Wextra -Werror
CFLAGSADD		:=	-g3
CFLAGS_MLX 		:=	-lXext -lX11 -lm

OPATH			:=	obj

RM				:=	rm -rf

SRCS			:=	main.c\
				ut_rgb.c\
				ut_txt_file.c

OBJS			:=	$(addprefix $(OPATH)/, $(SRCS:.c=.o))
DEPS			:=	$(OBJS:.o=.d)

vpath %.h $(IPATH)\
	$(PRJ_PATH)\
       	$(PRJ_PATH)/$(IPATH)\
	$(PRJ_PATH)/$(FTPATH)/$(IFT)\
	$(PRJ_PATH)/$(MLX_PATH)

all:	$(NAME)

$(OPATH)/%.o:	%.c
			$(CC) $(CFLAGS) $(CFLAGSADD) -I $(PRJ_PATH)/$(IPATH) -I $(PRJ_PATH)/$(FTPATH)/$(IFT) -I $(PRJ_PATH)/$(MLX_PATH) -I . -c $< -o $@

$(NAME):	$(OBJS) $(PRJ_NAME)
			$(CC) $(CFLAGS) $(CFLAGSADD) $(OBJS) -I . -o $(NAME) -L. -l$(PRJ) -L$(PRJ_PATH)/$(FTPATH) -l$(FT) -L$(PRJ_PATH)/$(MLX_PATH) -l$(MLX) $(CFLAGS_MLX)

$(OBJS):	| $(OPATH)

$(OPATH):
			mkdir -p $(OPATH)

clean:
			$(RM) $(OPATH)

fclean:
			make clean
			$(RM) $(NAME) $(PRJ_NAME)
re:
			make fclean
			make all

$(PRJ_NAME):
			make archive -C $(PRJ_PATH)

test:
			./$(NAME) map_subject.cub

-include $(DEPS)

.PHONY: all clean fclean re
