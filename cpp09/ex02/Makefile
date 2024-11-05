SRC = main.cpp PmergeMe.cpp utils.cpp
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
RM = rm -rf
MKDIR_P = mkdir -p


$(OBJ_DIR)%.o: %.cpp
	@$(MKDIR_P) $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled: $<"

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiled: $(NAME)"

all: $(NAME)

clean:
	@$(RM) $(OBJ_DIR)
	@echo "Cleaned object files"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

run: re
	@make clean
	@echo "Runing $(NAME) with arguments: 3 5 9 7 4"	
	@echo "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n"
	@./$(NAME) 3 5 9 7 4
	@echo "\n________________________________________"

.PHONY: all clean fclean re
