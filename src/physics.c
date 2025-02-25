#include "physics.h"
#include "math.h"

double get_distance(const vec_2d p1, const vec_2d p2){
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return sqrt(dx * dx + dy * dy);
}

double get_force(const struct object *obj1, const struct object *obj2){ 
  return obj1->m * obj2->m * G / get_distance(obj1->locate, obj2->locate);
}

double get_norm(const vec_2d vec){
  return sqrt(vec.x * vec.x + vec.y * vec.y);
}

vec_2d normalized(const vec_2d vec){
  vec_2d norm_vec;
  double norm;
  norm = get_norm(vec);
  norm_vec.x = vec.x / norm;
  norm_vec.y = vec.y / norm;
  return norm_vec;
}

void update_velocity(struct object *obj1, struct object *obj2){
  // Закон притяжениея))
  double force, acc1, acc2;
  vec_2d vec;
  force = get_force(obj1, obj2);
  acc1 = force / obj1->m;
  acc2 = force / obj2->m;
  
  vec.x = obj2->locate.x - obj1->locate.x;
  vec.y = obj2->locate.y - obj1->locate.y;

  vec = normalized(vec);

  obj1->vel.x += acc1 * vec.x;
  obj1->vel.y += acc1 * vec.y;

  obj2->vel.x -= acc2 * vec.x;
  obj2->vel.y -= acc2 * vec.y;
  
  return;
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

void update(struct object* all_object, int len){
  int i, j;
  for (i = 0; i < len; i++){
    for (j = i + 1; j < len; j++){
      update_velocity(&all_object[i], &all_object[j]);
    }
  }

  for (i = 0; i < len; i++){
    update_locate(&all_object[i]);
    check_border(&all_object[i]);
  }
}
