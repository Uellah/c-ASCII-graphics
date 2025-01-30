#ifndef H_GRAPHICS
#define H_GRAPHICS

#include "config.h"

typedef struct s_point point;
typedef struct s_circle circle;
typedef unsigned char u8;

static const unsigned DELAY = 1000000 / FPS;
static const u8 BR_LEVEL = 5;

struct s_point{
  int x;
  int y;
};

struct s_circle{
  point center;
  int r;
};

void copy(u8 from[H][W], u8 to[H][W]);
void buf_clean(u8 buf[H][W]);
void buf_print(u8 buf[H][W]);
void draw_circle(u8 buf[H][W], circle circ, u8 bright);
void draw_box(u8 buf[H][W]);
void end();
void init();
#endif
