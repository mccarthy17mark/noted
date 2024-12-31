#FRAMEWORK_PATH = /Library/Frameworks
CXX      := -c++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror -Wno-c++11-extensions -std=c++11
LDFLAGS  := -L/usr/lib -lsfml-graphics -lsfml-window -lsfml-system #-framework sfml-graphics -framework sfml-window -framework sfml-system #-lsfml-graphics -lsfml-window -lsfml-system
LDLIBS   := -lm -lstdc++
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := program
INCLUDE  := -Iinclude/ #-Iinclude/Frameworks/SFML.framework/Headers -Finclude/Frameworks
SRC      :=                      \
   $(wildcard src/*.cxx)         \

OBJECTS  := $(SRC:%.cxx=$(OBJ_DIR)/%.o)
DEPENDENCIES \
         := $(OBJECTS:.o=.d)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cxx
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

.PHONY: all build clean debug release info

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

info:
	@echo "[*] Application dir: ${APP_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJECTS}     "
	@echo "[*] Dependencies:    ${DEPENDENCIES}"


#this makefile is from http://www.partow.net/programming/makefile/index.html


