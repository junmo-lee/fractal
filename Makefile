.DEFAULT_GOAL := all

NAME	= fractol
NAME_B	= fractol_bouns

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -MMD -MP -O3

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INC		= fractal.h
INC_B	= fractal_bouns.h

LDFLAGS	= -L$(LIBFT_DIR) -framework OpenGL -framework AppKit
LDLIBS	= -lft -lmlx 

SRCS	= main.c \
			init.c parsing.c atoi_check_num.c \
			colormap.c \
			julia.c mandelbrot_set.c burning_ship.c \
			draw_fractal.c 
			
SRCS_B	= main_bonus.c \
			init_bonus.c parsing_bonus.c atoi_check_num_bonus.c \
			colormap_bonus.c \
			julia_bonus.c mandelbrot_set_bonus.c burning_ship_bonus.c \
			draw_fractal_bonus.c 

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

DEF		= $(SRCS:.c=.d) 
DEF_B	= $(SRCS_B:.c=.d)
-include $(DEF) $(DEF_B)

$(LIBFT) :
	make -C $(LIBFT_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) $(CDEF) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $(NAME) -I $(INC)

$(NAME_B): $(LIBFT) $(OBJS_B)
	cp $(LIBFT) $(NAME_B)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $(NAME_B) -I $(INC_B) $(LIBS)

all : $(NAME)
bonus : $(NAME_B)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(OBJS_B) $(DEF) $(DEF_B)

fclean :
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(OBJS) $(OBJS_B) $(DEF) $(DEF_B) $(NAME) $(NAME_B)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all bonus clean fclean re