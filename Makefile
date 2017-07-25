PROJECT_NAME           := ansi++
PROJECT_VERSION_MAJOR  := 0
PROJECT_VERSION_MINOR  := 1
LIBRARY_NAME           := lib$(PROJECT_NAME)
LIBRARY_LINKER_NAME    := $(LIBRARY_NAME).so
LIBRARY_SO_NAME        := $(LIBRARY_LINKER_NAME).$(PROJECT_VERSION_MAJOR)
LIBRARY_FILE_NAME      := $(LIBRARY_SO_NAME).$(PROJECT_VERSION_MINOR)
BIN_DIR                := bin
LIB_DIR                := lib
SOURCES                := $(shell find src -name "*.cpp")
OBJECTS                := $(SOURCES:.cpp=.o)
OUTPUT                 := $(LIB_DIR)/$(LIBRARY_FILE_NAME)
CXX                    := g++
CXFLAGS                := -Iinclude/ -Wall -Wextra -std=c++14
LDFLAGS                :=

%.o: %.cpp
	@echo -e "\033[1;37mCompiling `basename $<`... \033[0m"
	@$(CXX) $(CXFLAGS) -c -o $@ $<
all: $(OUTPUT)
$(OUTPUT): $(OBJECTS)
	@echo -e "\033[1;37mLinking $(PROJECT_NAME)... \033[0m"
	@$(CXX) $(CXFLAGS) $(LDFLAGS) -o "$@" $^
	@ldconfig -n $(LIB_DIR)
clean:
	@echo -e "\033[1;37mCleaning $(PROJECT_NAME)... \033[0m"
	@rm $(OBJECTS)

.PHONY: all clean
