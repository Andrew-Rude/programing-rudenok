CC = clang
CFLAGS = -std=c11 -g -Wall
SRC = src/main.c
TARGET = main

# Ціль по замовчуванню
all: $(TARGET)

# Правило для створення виконуваного файлу
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Ціль для очищення (видалення виконуваного файлу)
clean:
	rm -f $(TARGET)

