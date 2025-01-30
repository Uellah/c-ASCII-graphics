#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <ncursesw/ncurses.h>
#include <wchar.h>
#include "graphics.h"

static const wchar_t *BRIGHT = L" ░▒▓█";

void init(){
  // Инициализация локали для работы с широкими символами
  setlocale(LC_ALL, "");
    
  initscr();             // Старт режима curses
  cbreak();              // Отключаем буферизацию ввода
  noecho();              // Не отображаем вводимые символы
  keypad(stdscr, TRUE);  // Включаем обработку функциональных клавиш
  curs_set(0);           // Скрываем курсор
}

void copy(u8 from[H][W], u8 to[H][W]){
  int i, j;
  for (i = 0; i < H; ++i){
      for (j = 0; j < W; ++j){
        to[i][j] = from[i][j];
      }
    }
  return;
}

void set_pixel(u8 buf[H][W], int x, int y, u8 bright){
  if (x >= 0 && x < H && y >= 0 && y < W)
    buf[x][y] = bright % BR_LEVEL;
}

void draw_circle(u8 buf[H][W], circle circ, u8 bright) {
  int x = circ.r;
  int y = 0;
  int err = 0;
  const int cx = circ.center.x;
  const int cy = circ.center.y;

  while (x >= y) {
    // Алгоритм Брезенхейма для кругов
    for (int i = cx - x; i <= cx + x; i++) {
      set_pixel(buf, cy + y, i, bright);
      set_pixel(buf, cy - y, i, bright);
    }
    for (int i = cx - y; i <= cx + y; i++) {
      set_pixel(buf, cy + x, i, bright);
      set_pixel(buf, cy - x, i, bright);
    }

    y++;
    err += 1 + 2*y;
    if (2*(err - x) + 1 > 0) {
      x--;
      err += 1 - 2*x;
    }
  }
}

void draw_box(u8 buf[H][W]);

void buf_clean(u8 buf[H][W]){
  int i, j;
  for (i = 0; i < H; ++i){
    for (j = 0; j < W; ++j){
      buf[i][j] = 0;
    }
  }

  return;
}

void buf_print(u8 buf[H][W]) {
  wchar_t c;
  for (int i = 0; i < H; ++i) {
    wmove(stdscr, i, 0);
    for (int j = 0; j < W; ++j) {
      c = BRIGHT[buf[i][j]];
      waddnwstr(stdscr, (wchar_t[]){c, c}, 2);
    }
  }
    wrefresh(stdscr);
}

void end(){
  // Корректное завершение работы с ncurses
  endwin();
}
