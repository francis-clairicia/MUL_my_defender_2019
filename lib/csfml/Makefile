##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## execute programs
##

SRC		= 	button.c 					\
			init_objects.c 				\
			scale_object.c 				\
			clock.c 					\
			init_text.c					\
			draw_text.c					\
			init_texture_and_sprite.c	\
			init_window.c				\
			usefull_functions.c			\
			invisible_button.c			\
			invisible_button_event.c	\
			img_button.c				\
			img_button_draw.c			\
			img_button_move.c			\
			img_button_event.c

OBJ		=	$(SRC:.c=.o)

LIB		=	libcsfml.a

HEAD	=	include/struct.h

all: $(LIB)

$(LIB): $(OBJ)
	ar rc $(LIB) $(OBJ)
	cp -u $(LIB) ../
	cp -u $(HEAD) ../../include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(LIB)
	rm -f ../$(LIB)
	rm -f ../$(HEAD)

re: fclean all
