MAKEFLAGS += -rR

BUILD_DIR := build
SOURCE := $(firstword $(filter %.c %.cpp,$(shell ls -c)))
TARGET := $(SOURCE:.c=.out)
TARGET := $(BUILD_DIR)/$(TARGET:.cpp=.out)

ifeq ($(suffix $(SOURCE)),.c)
CC := gcc
else
CC := g++
endif

test: FORCE $(TARGET)
	@$(TARGET)

$(TARGET): $(SOURCE) | $(BUILD_DIR)
	@$(CC) -o $@ $^

clean: FORCE
	rm $(BUILD_DIR)/*.out

$(BUILD_DIR):
	mkdir $@

FORCE:

.PHONY: FORCE