#ifndef H_GRAPHICS
#define H_GRAPHICS

#include "config.h"

typedef struct s_point point;
typedef struct s_circle circle;

static const unsigned DELAY = 1000000 / FPS;
static const wchar_t *BRIGHT = L" ░▒▓█";
static const char BR_LEVEL = 5;

struct s_point{
  int x;
  int y;
};

struct s_circle{
  point center;
  int r;
};


void copy(char from[H][W], char to[H][W]);
void buf_clean(char buf[H][W]);
void buf_print(char buf[H][W]);
void draw_circle(char buf[H][W], circle circ, char bright);
void draw_box(char buf[H][W]);

#endif
