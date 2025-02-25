#include <stdlib.h>
#include <unistd.h>

#include "graphics.h"
#include "physics.h"

#if 0
int main(){
  u8 buf[H][W] = {0};
  struct object objects1, objects2;
  circle c;

  objects1.locate.x = 120;
  objects1.locate.y = 60;
  objects1.vel.x  = 0;
  objects1.vel.y  = -0.6;
  objects1.m = 1e8;
  objects1.r = 4;

  objects2.locate.x = 60;
  objects2.locate.y = 60;
  objects2.vel.x  = 0;
  objects2.vel.y  = 0.6;
  objects2.m = 1e8;
  objects2.r = 4;

  init();
  for(;;){
    buf_clean(buf);
    update(&objects1, &objects2);

      c.center.x = (int)objects1.locate.x;
      c.center.y = (int)objects1.locate.y;
      c.r = (int)objects1.r;
      draw_circle(buf, c, 4);

      c.center.x = (int)objects2.locate.x;
      c.center.y = (int)objects2.locate.y;
      c.r = (int)objects2.r;
      draw_circle(buf, c, 4);

    buf_print(buf);
    usleep(DELAY);
  }
    end();
    return 0;
}
#endif

#if 0
int main(){
  u8 buf[H][W] = {0};
  struct object objects[10];
  circle c;
  int i;

  for (i = 0; i < 2; ++i){
    objects[i].locate.x = i * 10;
    objects[i].locate.y = 6;
    objects[i].vel.x  = i * 2;
    objects[i].vel.y  = (i+1);
    objects[i].m = (i + 1) * 10000000;
    objects[i].r = 2 + (i % 5);
  }

  init();
  for(;;){
    buf_clean(buf);
    update(&objects[0], &objects[1]);
    for (i = 0; i < 2; ++i){
      c.center.x = (int)objects[i].locate.x;
      c.center.y = (int)objects[i].locate.y;
      c.r = (int)objects[i].r;
      draw_circle(buf, c, 4);
    }
    buf_print(buf);
    usleep(DELAY);
  }
    end();
    free(objects);
    return 0;
}

#endif
#if 0
int main(){
  u8 buf[H][W] = {0};
  struct object *objects = calloc(15, sizeof(struct object));
  circle c;
  int i;

  for (i = 0; i < 15; ++i){
    objects[i].locate.x = i * 10;
    objects[i].locate.y = i * 6;
    objects[i].vel.x  = 0;
    objects[i].vel.y  = 0.3;
    objects[i].m = 1e3;
    objects[i].r = 1;
  }
  objects[14].locate.x = 120;
  objects[14].locate.y = 60;
  objects[14].vel.x  = 0;
  objects[14].vel.y  = 0;
  objects[14].m = 1e8;
  objects[14].r = 5;

  init();
  for(;;){
    buf_clean(buf);
    update(objects, 15);
    for (i = 0; i < 15; ++i){
      c.center.x = (int)objects[i].locate.x;
      c.center.y = (int)objects[i].locate.y;
      c.r = (int)objects[i].r;
      draw_circle(buf, c, 4);
    }
    draw_circle(buf, c, 4);
    buf_print(buf);
    usleep(DELAY);
  }
    end();
    free(objects);
    return 0;
}
#endif
#if 0

int main() {
    u8 buf[H][W] = {0};
    struct object *objects = calloc(6, sizeof(struct object));
    circle c;
    int i;

    // Инициализация 5 небольших объектов на орбитах
    // Объект 0: Восточная орбита (R=40)
    objects[0].locate.x = 160;  // 120 + 40
    objects[0].locate.y = 60;
    objects[0].vel.x = 0;
    objects[0].vel.y = 0.8;   // Орбитальная скорость для R=40
    objects[0].m = 1e5;
    objects[0].r = 2;

    // Объект 1: Западная орбита (R=40)
    objects[1].locate.x = 80;   // 120 - 40
    objects[1].locate.y = 60;
    objects[1].vel.x = 0;
    objects[1].vel.y = -0.8;  // Противоположное направление
    objects[1].m = 1e5;
    objects[1].r = 2;
    
    // Объект 1: Западная залупа (R=40)
    objects[5].locate.x = 76;   // 120 - 30
    objects[5].locate.y = 60;
    objects[5].vel.x = 0;
    objects[5].vel.y = -0.8;  // Противоположное направление
    objects[5].m = 1e3;
    objects[5].r = 1;
    
    // Объект 2: Северная орбита (R=40)
    objects[2].locate.x = 120;
    objects[2].locate.y = 20;   // 60 - 40
    objects[2].vel.x = 0.7;
    objects[2].vel.y = 0;
    objects[2].m = 1e5;
    objects[2].r = 2;

    // Объект 3: Южная орбита (R=40)
    objects[3].locate.x = 120;
    objects[3].locate.y = 100;  // 60 + 40
    objects[3].vel.x = -0.8;
    objects[3].vel.y = 0;
    objects[3].m = 1e7;
    objects[3].r = 2;

    // Центральное тело
    objects[4].locate.x = 120;
    objects[4].locate.y = 60;
    objects[4].vel.x = 0;
    objects[4].vel.y = 0;
    objects[4].m = 1e7;
    objects[4].r = 5;

    init();
    for(;;) {
        buf_clean(buf);
        update(objects, 6);
        for (i = 0; i < 6; ++i) {
            c.center.x = (int)objects[i].locate.x;
            c.center.y = (int)objects[i].locate.y;
            c.r = (int)objects[i].r;
            draw_circle(buf, c, 4);
        }
        buf_print(buf);
        usleep(DELAY);
    }
    end();
    free(objects);
    return 0;
}

#endif

#if 1

int main() {
    unsigned char buf[H][W] = {0};
    struct object *objects = calloc(3, sizeof(struct object));
    circle c;

    // Солнце (большое тело)
    objects[0] = (struct object){
        .locate = {W/2, H/2}, // Центр экрана
        .vel = {0, 0},
        .m = 1000, // Масса большая
        .r = 10   // Радиус большой
    };

    // Земля (среднее тело)
    objects[1] = (struct object){
        .locate = {W/2 + 50, H/2}, // Начинаем справа от Солнца
        .vel = {0, 2},             // Начальная скорость для орбиты
        .m = 10,                   // Масса средняя
        .r = 5                     // Радиус средний
    };

    // Луна (маленькое тело)
    objects[2] = (struct object){
        .locate = {objects[1].locate.x + 10, objects[1].locate.y}, // Рядом с Землёй
        .vel = {0, 1.5},                                          // Начальная скорость для орбиты
        .m = 1,                                                   // Масса маленькая
        .r = 2                                                    // Радиус маленький
    };

    init();
    for(;;) {
        buf_clean(buf);
        update(objects, 3);

        // Рисуем объекты
        for (int i = 0; i < 3; ++i) {
            c = (circle){
                .center = {(int)objects[i].locate.x, (int)objects[i].locate.y},
                .r = objects[i].r
            };
            draw_circle(buf, c, 4);
        }

        buf_print(buf);
        usleep(DELAY);
    }

    end();
    free(objects);
    return 0;
}
#endif
