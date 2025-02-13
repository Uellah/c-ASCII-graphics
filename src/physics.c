#include "physics.h"

void update_velocity(struct object *obj){
  // Закон притяжениея))
  obj->vel.y += obj->m * g;
}

void update_locate(struct object *obj){
  obj->locate.x += obj->vel.x;
  obj->locate.y += obj->vel.y;
}

void check_border(struct object *obj){
  // Если обьект вышел за пределы экрана
  // то искусствено выталкиваем и обновляем скорость 
  // согласно обсолютно упругому столкновению со стеной
  if (obj->locate.x + obj->r >= W) {
    obj->vel.x = -obj->vel.x;
    obj->locate.x = (double) (W - obj->r - 1); // -1 потому что W конец массива
  }

  if (obj->locate.x - obj->r < 0){
    obj->vel.x = -obj->vel.x;
    obj->locate.x = (double) obj->r;
  }

  if (obj->locate.y + obj->r >= H) {
    obj->vel.y = -obj->vel.y;
    obj->locate.y = (double) (H - obj->r - 1); // -1 потому что W конец массива
  }

  if (obj->locate.y - obj-> r < 0){
    obj->vel.y = -obj->vel.y;
    obj->locate.y = (double) obj->r;
  }
}

void update(struct object *obj){
  update_velocity(obj);
  update_locate(obj);
  check_border(obj);
}

