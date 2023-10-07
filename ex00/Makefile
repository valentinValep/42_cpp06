NAME := exec
TEST_NAME := test_exec

CXX := c++

CXXFLAGS := -Wall -Werror -Wextra -std=c++98 -MMD -g3

OBJ :=	ScalarConverter.o \
	utils.o \

MAIN_OBJ := main.o
TEST_OBJ := test.o

INCLUDES := -I.

DEPS := ${OBJ:.o=.d}

RM := rm -f

#############################################################################

$(NAME): $(OBJ) $(MAIN_OBJ)
	$(CXX) $(OBJ) $(MAIN_OBJ) -o $(NAME)

$(TEST_NAME): $(OBJ) $(TEST_OBJ)
	$(CXX) $(OBJ) $(TEST_OBJ) -o $(TEST_NAME)

test: $(TEST_NAME)
	@valgrind ./$(TEST_NAME); \
	if [ $$? -eq 0 ]; then \
		echo "\033[32m[Tests passed]\033[0m"; \
		rm $(TEST_NAME); \
	else \
		echo "\033[31m[Tests failed]\033[0m"; \
	fi

all: $(NAME)

clean:
	$(RM) $(DEPS)
	$(RM) $(OBJ)
	$(RM) $(MAIN_OBJ)
	$(RM) $(TEST_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test

-include $(DEPS)