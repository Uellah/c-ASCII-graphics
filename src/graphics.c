#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

#include "graphics.h"

void copy(char from[H][W], char to[H][W]){
  int i, j;
  for (i = 0; i < H; ++i){
      for (j = 0; j < W; ++j){
        to[i][j] = from[i][j];
      }
    }
  return;
}

void set_pixel(char buf[H][W], int x, int y, char bright){
  if (x >= 0 && x < H && y >= 0 && y < W)
    buf[y][x] = bright % BR_LEVEL;
}

void draw_circle(char buf[H][W], circle circ, char bright) {
    int x = circ.r;
    int y = 0;
    int err = 0;
    const int cx = circ.center.x;
    const int cy = circ.center.y;

    while (x >= y) {
        // Рисуем горизонтальные линии между точками
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

void draw_box(char buf[H][W]);

void buf_clean(char buf[H][W]){
  int i, j;
  for (i = 0; i < H; ++i){
    for (j = 0; j < W; ++j){
      buf[i][j] = 0;
    }
  }

  return;
}

void buf_print(char buf[H][W]){
  int i, j;
  setlocale(LC_ALL, "");
  wprintf(L"\033[H");
  for (i = 0; i < H; ++i){
    for (j = 0; j < W; ++j){
      wprintf(L"%lc%lc", BRIGHT[buf[i][j]], BRIGHT[buf[i][j]]);
    }
    wprintf(L"\n");
  }
  return;
}

