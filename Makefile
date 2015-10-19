# Makefile for DISCOTANGO library.
# Copyright (c) 2015 Danny McClanahan, Richard Kerr

# DISCOTANGO is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# DISCOTANGO is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.

# You should have received a copy of the GNU Lesser General Public License
# along with DISCOTANGO.  If not, see <http://www.gnu.org/licenses/>.

.PHONY: all clean test

CC_OPTS := -std=c99 -Wall -Wextra -Werror
LINK_OPTS :=

BUILD_BASE := build

RELEASE ?= 0
ifeq ($(RELEASE),0)
CC_OPTS += -DDEBUG -g -O0
BUILD_DIR := $(BUILD_BASE)/debug
else
CC_OPTS += -DRELEASE -O3
BUILD_DIR := $(BUILD_BASE)/release
endif

CC := gcc

CODE_DIRS := opt common rng
TEST_DIR := test

DEPS := $(wildcard $(addsuffix /*.h,$(CODE_DIRS)))
IN := $(wildcard $(addsuffix /*.c,$(CODE_DIRS)))
OUT := $(addprefix $(BUILD_DIR)/,$(notdir $(IN:%.c=%.o)))

TEST_IN := $(wildcard $(TEST_DIR)/*.c)

# the $(OUT) transformation relies on every .c filename being unique within the
# codebase. this allows us to output all the .o files into build/{debug,release}
# in a single flat folder, and to use vpath
define \n


endef
wsort = $(words $(sort $(notdir $1)))
ifneq ($(call wsort,$(DEPS)),$(words $(DEPS)))
$(error DEPS is non-unique, ensure all .h files are unique:${\n}$(DEPS))
endif
ifneq ($(call wsort,$(IN)),$(words $(IN)))
$(error IN is non-unique, ensure all .c files are unique:${\n}$(IN))
endif

DYNAMIC := $(BUILD_DIR)/libdiscotango.so
STATIC := $(BUILD_DIR)/libdiscotango.a
TEST_BIN := $(BUILD_DIR)/test
BIN := $(STATIC) $(DYNAMIC) $(TEST_BIN)

all: $(BIN)

$(TEST_BIN): $(OUT) $(STATIC) $(TEST_IN)
	$(CC) $(CC_OPTS) $(LINK_OPTS) -o $@ $(TEST_IN) $(STATIC)

# search all code directories for build files
vpath %.h $(CODE_DIRS)
vpath %.c $(CODE_DIRS)
$(BUILD_DIR)/%.o: %.c $(DEPS)
	$(CC) -fPIC $(CC_OPTS) -o $@ -c $<

$(DYNAMIC): $(OUT)
	$(CC) -shared $(LINK_OPTS) -o $@ $^

$(STATIC): $(OUT)
	ar rcs $@ $^

clean:
	rm -f $(OUT) $(BIN)

test:
	exec $(TEST_BIN)
