CC = gcc
CFLAGS = -Wall -g 
DEP_OPT = -MM -MP
SRC_DIR = src
BUILD_DIR = .build
SOURCES = $(foreach d, $(SRC_DIR), $(wildcard $(addprefix $(d)/*, .c)))
DEPS = $(subst $(SRC_DIR), $(BUILD_DIR), $(SOURCES:.c=.d))
OBJS = $(subst $(SRC_DIR), $(BUILD_DIR), $(SOURCES:.c=.o))
PROGRAM = minesweeper
LIBS = -lcurses -lncurses

# Delete the default suffixes
.SUFFIXES:

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

.build:
	mkdir -p .build

# Generate dependence files
$(BUILD_DIR)/%.d: $(SRC_DIR)/%.c .build
	$(CC) $(CFLAGS) $(DEP_OPT) $< | sed -E 's;^(.*)\.o:;$(BUILD_DIR)/\1.o:;' > $@

# Generate objects files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

.PHONY: clean build try run tags

clean:
	rm -rf .build
	rm $(PROGRAM)

build: $(PROGRAM)

run: build
	./$(PROGRAM)


debug: build
	gdb $(PROGRAM)

try:
	$(info SRC_DIR=$(SRC_DIR))
	$(info SOURCES=$(SOURCES))
	$(info DEPS=$(DEPS))

tags:
	ctags -R .

