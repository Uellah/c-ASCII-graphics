# Переменные
CC = gcc                # Компилятор
CFLAGS = -Wall -Wextra  # Флаги компиляции
SRC = src/main.c src/graphics.c # Файлы исходного кода
INCLUDE = -Iinclude     # Директория с заголовочными файлами
TARGET = ASCII_graphics     # Название выходного файла
LDFLAGS = -lncursesw -D_XOPEN_SOURCE_EXTENDED

# Правила сборки
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(INCLUDE) $(LDFLAGS)

clean:
	rm -f $(TARGET)

