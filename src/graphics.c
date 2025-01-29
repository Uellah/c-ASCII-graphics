#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

#include "graphics.h"
#include "config.h"

void copy(wchar_t from[H][W], wchar_t to[H][W]){
  int i, j;
  for (i = 0; i < H; ++i){
      for (j = 0; j < W; ++j){
        to[i][j] = from[i][j];
      }
    }
  return;
}

int valid_check(int i, int j){
  return i >= 0 && i < H && j >=0 && j < W;
}

void draw_circle(wchar_t buf[H][W], circle circ, char bright){
  int i, j;
  const int r_ = circ.r * circ.r;
  const char true_br = bright % BR_LEVEL;

  for (i = circ.center.y + circ.r; i >= circ.center.y - circ.r; i--){

    if (!valid_check(i, circ.center.x)) continue;
    buf[i][circ.center.x] = true_br;

    for (j = 1; j * j  + (i - circ.center.y) * (i - circ.center.y) <= r_; j++){

      if (valid_check(i, circ.center.x + j))
      buf[i][circ.center.x + j] = true_br;

      if (valid_check(i, circ.center.x - j))
      buf[i][circ.center.x - j] = true_br;
    }
  }
}

void buf_clean(wchar_t buf[H][W]){
  int i, j;
  for (i = 0; i < H; ++i){
    for (j = 0; j < W; ++j){
      buf[i][j] = 0;
    }
  }

  return;
}

void buf_print(wchar_t buf[H][W]){
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

