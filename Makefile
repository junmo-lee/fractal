.DEFAULT_GOAL := all

NAME	= fractol
NAME_B	= fractol_bouns

DEBUG_NAME = debug.out
DEBUG_NAME_B = debug_bonus.out

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -O3
CDEF	= -MMD -MP

LIBFT = ./libft/libft.a
LIBFT_DIR = libft/

INC		= fractal.h
INC_B	= fractal_bouns.h

LIBS	= -L ./libft -lft -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

SRCS	= main.c \
			init.c parsing.c atoi_check_num.c \
			colormap.c \
			julia.c mandelbrot_set.c burning_ship.c \
			draw_fractal.c 
			
SRCS_B	= main_bonus.c

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

DEBUG_O = $(filter-out main.o, $(OBJS)) debug.o
DEBUG_B_O = $(filter-out main_bonus.o, $(OBJS_B)) debug_bonus.o

DEF		= $(SRCS:.c=.d) 
DEF_B	= $(SRCS_B:.c=.d)
-include $(DEP) $(DEF_B)

ifdef IGNORE_ERROR
    CFLAGS :=  # IGNORE_ERROR가 설정되었을 때, CFLAGS를 빈 값으로 덮어쓰기, 해당 명령에서만 사용됨
endif

ifdef DEBUG_FLAG
	CFLAGS += -g3
endif

$(LIBFT) :
	make -C $(LIBFT_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) $(CDEF) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(CDEF) $^ -o $(NAME) -I $(INC) $(LIBS)

$(NAME_B): $(LIBFT) $(OBJS_B)
	cp $(LIBFT) $(NAME_B)
	$(CC) $(CFLAGS) $(CDEF) $^ -o $(NAME_B) -I $(INC_B) $(LIBS)

$(DEBUG_NAME): $(LIBFT) $(DEBUG_O)
	cp $(LIBFT) $(DEBUG_NAME)
	$(CC) $(CFLAGS) $(CDEF) $^ -o $(DEBUG_NAME) -I $(INC) $(LIBS)

$(DEBUG_NAME_B): $(LIBFT) $(DEBUG_B_O)
	cp $(LIBFT) $(DEBUG_NAME_B)
	$(CC) $(CFLAGS) $(CDEF) $^ -o $(DEBUG_NAME_B) -I $(INC_B) $(LIBS)


all : $(NAME)
bonus : $(NAME_B)

debug : $(DEBUG_NAME)
debug_bonus : $(DEBUG_NAME_B)

clean :
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(OBJS_B) $(DEF) $(DEF_B)
	rm -f $(DEBUG_O) $(DEBUG_B_O)

fclean :
	make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS) $(OBJS_B) $(DEF) $(DEF_B) $(NAME) $(NAME_B)
	rm -f $(DEBUG_O) $(DEBUG_B_O) $(DEBUG_NAME) $(DEBUG_NAME_B)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re debug debug_bonus