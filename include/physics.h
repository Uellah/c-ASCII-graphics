#ifndef H_PHYSICS
#define H_PHYSICS

#include "config.h"
#include "types.h"

#define g 9.81
#define G 6e-3

typedef struct vec_2d vec_2d;

struct vec_2d{
  double x;
  double y;
};

struct object{
  vec_2d locate; // Текущее местоположение
  vec_2d vel;    // Скорость
  double m;      // Масса
  int r;         // Радиус круга
};

void update(struct object *obj, int len);

#endif
