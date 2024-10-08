################################################################################
##                                   COLORS                                   ##
################################################################################

DEFAULT     := \033[0;39m
GRAY        := \033[0;90m
RED         := \033[0;91m
GREEN       := \033[0;92m
YELLOW      := \033[0;93m
BLUE        := \033[0;94m
MAGENTA     := \033[0;95m
CYAN        := \033[0;96m
WHITE       := \033[0;97m
	
################################################################################
##                                  WHATEVER                                  ##
################################################################################

NAME							:= whatever
CXX								:= c++
RM								:= rm -rf
	
################################################################################
##                                DIRECTORIES                                 ##
################################################################################

OBJ_DIR						:= obj
SRC_DIR						:= src
INC_DIR						:= include

vpath %.cpp $(SRC_DIR)
vpath %.hpp $(INC_DIR)
vpath %.o $(OBJ_DIR)

HEADERS						:= whatever.hpp colors.hpp
SOURCE						:= main.cpp
OBJECTS						:= $(addprefix $(OBJ_DIR)/, $(SOURCE:.cpp=.o))
	
################################################################################
##                                   FLAGS                                    ##
################################################################################

CXXFLAGS					:= -Wall -Wextra -Werror -std=c++98
INCLUDE						:= -I $(INC_DIR)
	
################################################################################
##                                PROGRESS_BAR                                ##
################################################################################

NUM_SRC_FILES			:= $(words $(SOURCE))
NUM_OBJ_FILES			:= $(words $(OBJECTS))
NUM_TO_COMPILE		= $(shell expr $(NUM_SRC_FILES) - $(NUM_OBJ_FILES))

ifeq ($(shell test $(NUM_TO_COMPILE) -le 0; echo $$?), 0)
	NUM_TO_COMPILE	= $(NUM_SRC_FILES)
endif

COMPILED_FILES		= 0
COMPILATION_PCT		= $(shell expr 100 \* $(COMPILED_FILES) / $(NUM_TO_COMPILE))
	
################################################################################
##                                COMPILATION                                 ##
################################################################################

all: $(NAME)

$(NAME): $(OBJECTS)
	@printf "\n$(MAGENTA)[$(NAME)] $(DEFAULT)Linking "
	@printf "($(BLUE)$(NAME)$(DEFAULT))..."
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@printf "\r%100s\r$(MAGENTA)[$(NAME)] $(GREEN)Compilation success "
	@printf "🎉!$(DEFAULT)\n"

$(OBJ_DIR)/%.o: %.cpp $(HEADERS) | $(OBJ_DIR)
	@$(eval COMPILED_FILES = $(shell expr $(COMPILED_FILES) + 1))
	@printf "$(MAGENTA)\r%100s\r[$(NAME)] $(GREEN)[ %d/%d (%d%%) ]" \
			"" $(COMPILED_FILES) $(NUM_TO_COMPILE) $(COMPILATION_PCT) 
	@printf " $(DEFAULT)Compiling ($(BLUE)$<$(DEFAULT))..."
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@printf "$(MAGENTA)[$(NAME)] $(DEFAULT)Creating objects directory "
	@printf "($(BLUE)$(OBJ_DIR)$(DEFAULT))..."
	@mkdir -p $(OBJ_DIR)
	@printf "\r%100s\r$(MAGENTA)[$(NAME)] $(DEFAULT)($(BLUE)$(OBJ_DIR)/$(DEFAULT)) "
	@printf "Created successfully!\n"

clean:
	@printf "$(MAGENTA)[$(NAME)] $(DEFAULT)Cleaning up objects files in "
	@printf "($(RED)$(OBJ_DIR)$(DEFAULT))..."
	@$(RM) $(OBJ_DIR)
	@printf "\r%100s\r$(MAGENTA)[$(NAME)] $(YELLOW)Objects clean success "
	@printf "🧹🧹$(DEFAULT)\n"

fclean: clean
	@printf "$(MAGENTA)[$(NAME)] $(DEFAULT)Cleaning up "
	@printf "($(RED)$(NAME)$(DEFAULT))..."
	@$(RM) $(NAME)
	@printf "\r%100s\r$(MAGENTA)[$(NAME)] $(YELLOW)Full clean success "
	@printf "🧹🧹$(DEFAULT)\n"

re: fclean all

.PHONY: all clean fclean re
