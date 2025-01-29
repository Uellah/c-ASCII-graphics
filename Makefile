# Переменные
CC = gcc                # Компилятор
CFLAGS = -Wall -Wextra  # Флаги компиляции
SRC = src/main.c src/graphics.c # Файлы исходного кода
INCLUDE = -Iinclude     # Директория с заголовочными файлами
TARGET = ASCII_graphics     # Название выходного файла

# Правила сборки
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(INCLUDE)

clean:
	rm -f $(TARGET)

