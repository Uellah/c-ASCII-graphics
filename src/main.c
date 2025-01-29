#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include <unistd.h>
#include <wchar.h>

#if 0
int main(){
  system("clear");
  char buf[H][W] = {0};
  int x = 10, y = 10;
  point cent = {x, y};
  int r = 8;
  circle c = {cent, r};
  int x_vel = 1;
  int y_vel = 1;
  buf_clean(buf);
  for(;;){
    if (x+x_vel+r > W || x+x_vel-r < 0){
      x_vel *= -1;
    }
    if (y+y_vel+r > H || y+y_vel-r < 0){
      y_vel *= -1;
    }
    y += y_vel;
    x += x_vel;
    buf_clean(buf);
    c.center.x = x;
    c.center.y = y;
    draw_circle(buf, c, 2);
    buf_print(buf);
    usleep(DELAY);
  }
    return 0;
}
#endif

int main(){
  system("clear");
  char buf[H][W] = {0};
  circle c = {{0, 0}, 3};
  buf_clean(buf);
  draw_circle(buf, c, 3);
buf_print(buf);
  return 0;
}
