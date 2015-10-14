# Makefile for DISCOTANGO library.
# Copyright (c) 2015 Danny McClanahan, Richard Kerr

# This program is free software; you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation; either version 3 of the License, or (at your option) any later
# version.

# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
# details.

# You should have received a copy of the GNU General Public License along with
# this program; if not, write to the Free Software Foundation, Inc., 59 Temple
# Place, Suite 330, Boston, MA 02111-1307 USA

.PHONY: all clean distclean test

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

CODE_DIRS := opt common csp

DEPS := $(wildcard $(addsuffix /*.h,$(CODE_DIRS)))
IN := $(wildcard $(addsuffix /*.c,$(CODE_DIRS)))
OUT := $(addprefix $(BUILD_DIR)/,$(notdir $(IN:%.c=%.o)))

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
BIN := $(STATIC) $(DYNAMIC)

all: $(BIN)

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

distclean: clean

test:
	@echo 'no test target defined!'
	@exit -1
