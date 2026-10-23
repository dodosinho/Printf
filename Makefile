# 1. Nom du résultat final demandé par le sujet
NAME		= libftprintf.a

# 2. Les fichiers sources (.c) que tu as créés
SRCS		= ft_printf.c ft_printf_utils.c ft_printf_put.c

# 3. Transformation automatique des noms .c en .o (fichiers objets compilés)
OBJS		= $(SRCS:.c=.o)

# 4. Le compilateur et les flags stricts obligatoires de 42
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# 5. La règle principale (par défaut)
all:		$(NAME)

# 6. Création de la bibliothèque (archive .a) à partir des fichiers .o
$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

# 7. Règle pour compiler les .c en .o individuels
%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

# 8. Nettoyage des fichiers objets temporaires (.o)
clean:
			$(RM) $(OBJS)

# 9. Nettoyage total (les .o + la bibliothèque .a)
fclean:		clean
			$(RM) $(NAME)

# 10. Re-compiler le projet à zéro (fclean puis all)
re:			fclean all

# 11. Sécurité pour éviter les conflits si un fichier porte le même nom qu'une règle
.PHONY:		all clean fclean re
