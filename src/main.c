#include <stdlib.h>
#include <unistd.h>

#include "graphics.h"
#include "physics.h"

int main(){
  u8 buf[H][W] = {0};
  struct object objects[10];
  circle c;
  int i;

  for (i = 0; i < 2; ++i){
    objects[i].locate.x = i * 2;
    objects[i].locate.y = 4;
    objects[i].vel.x  = i * 5;
    objects[i].vel.y  = 0;
    objects[i].m = (i + 1) * 0.05;
    objects[i].r = 2 + (i % 5);
  }

  init();
  for(;;){
    buf_clean(buf);
    for (i = 0; i < 2; ++i){
    c.center.x = (int)objects[i].locate.x;
    c.center.y = (int)objects[i].locate.y;
    c.r = (int)objects[i].r;
    update(&objects[i]);
    draw_circle(buf, c, 4);
    }
    buf_print(buf);
    usleep(DELAY);
  }
    end();
    free(objects);
    return 0;
}

#if 0
int main(){
  u8 buf[H][W] = {0};
  struct object *objects = calloc(1, sizeof(struct object));
  circle c;
  objects ->locate.x = 10;
  objects ->locate.y = 10;
  objects ->vel.x  = 2;
  objects ->vel.y  = 0;
  objects ->m = 0.05;
  objects ->r = 4;
  init();
  for(;;){
    buf_clean(buf);
    c.center.x = (int)(objects -> locate.x);
    c.center.y = (int)(objects -> locate.y);
    c.r = 4;
    update(objects);
    draw_circle(buf, c, 4);
    buf_print(buf);
    usleep(DELAY);
  }
    end();
    free(objects);
    return 0;
}
#endif
