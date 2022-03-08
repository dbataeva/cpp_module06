NAME	=	ex02

SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

CPFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

.cpp.o:		A.hpp B.hpp C.hpp
			clang++ -std=c++98 $(CPFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			clang++ -std=c++98 $(CPFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)
			
.PHONY:		all clean fclean re