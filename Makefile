CC = clang
C_OPTS = -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable
TEST_OPTS = -lcheck -fprofile-instr-generate -fcoverage-mapping -lm -lsubunit  # Додано -lm для математичних функцій

SRC_DIR = ./src
TEST_DIR = ./test
DIST_DIR = ./dist

# Очищення директорії dist
clean:
	rm -rf $(DIST_DIR)

# Створення директорії dist
prep:
	mkdir -p $(DIST_DIR)

# Компіляція головної програми
main.bin: $(SRC_DIR)/main.c $(SRC_DIR)/lib.c $(SRC_DIR)/lib.h
	$(CC) $(C_OPTS) -I$(SRC_DIR) $(SRC_DIR)/main.c $(SRC_DIR)/lib.c -o $(DIST_DIR)/main.bin

# Компіляція тестів
test.bin: $(TEST_DIR)/test.c $(SRC_DIR)/lib.c $(SRC_DIR)/lib.h
	$(CC) $(C_OPTS) -I$(SRC_DIR) $(TEST_DIR)/test.c $(SRC_DIR)/lib.c -o $(DIST_DIR)/test.bin $(TEST_OPTS)

# Компіляція всього
compile: main.bin test.bin

# Запуск програми
run: clean prep compile
	./$(DIST_DIR)/main.bin

# Запуск тестів з покриттям
test: clean prep compile
	LLVM_PROFILE_FILE="$(DIST_DIR)/test.profraw" ./$(DIST_DIR)/test.bin
	llvm-profdata merge -sparse $(DIST_DIR)/test.profraw -o $(DIST_DIR)/test.profdata
	llvm-cov report $(DIST_DIR)/test.bin -instr-profile=$(DIST_DIR)/test.profdata $(SRC_DIR)/*.c
	llvm-cov show $(DIST_DIR)/test.bin -instr-profile=$(DIST_DIR)/test.profdata $(SRC_DIR)/*.c --format html > $(DIST_DIR)/coverage.html

# Компількація всього, включаючи тестування
all: clean prep compile

