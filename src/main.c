#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <ncursesw/ncurses.h>
#include <wchar.h>
#include "graphics.h"

int main(){
  init();
  u8 buf[H][W] = {0};
  circle c = {{10, 12}, 8};
  int x_vel = 1;
  int y_vel = 1;
  for(;;){
    if (c.center.x+x_vel+c.r >= W || c.center.x + x_vel-c.r < 0){
      x_vel *= -1;
    }
    if (c.center.y+y_vel+c.r >= H || c.center.y+y_vel-c.r < 0){
      y_vel *= -1;
    }
    c.center.y += y_vel;
    c.center.x += x_vel;

    buf_clean(buf);
    draw_circle(buf, c, 2);
    buf_print(buf);
    usleep(DELAY);
  }
    end();
    return 0;
}

