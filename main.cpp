#include <iostream>
#include "graphlib.h"

#include "Figure.h"
#include "MArc.h"
#include "MLine.h"


void Main(void){
  Figure* figures[10]{};

  figures[0] = new MLine({150.0f, 120.0f}, {20.0f, 10.0f}, {120.0f, 70.0f}, {1.0f, 0.0f, 0.0f});
  figures[1] = new MLine({420.0f, 180.0f}, {-60.0f, 40.0f}, {50.0f, 100.0f}, {0.0f, 1.0f, 0.0f});
  figures[2] = new MArc({700.0f, 260.0f}, {40.0f, 30.0f}, 80.0f, 20.0f, 220.0f, {1.0f, 1.0f, 0.0f});
  figures[3] = new MArc({280.0f, 420.0f}, {-30.0f, 0.0f}, 60.0f, 180.0f, 330.0f, {0.0f, 1.0f, 1.0f});

   for (int i = 0; i < 10; i++) {
    Figure* figure = figures[i];
    
  
    if (!figure) {
      continue;
    }
    figure->draw();
  }

  wait4keyORmouse();

  for (int i = 0; i < 10; i++) {
    Figure* figure = figures[i];
    
    if (!figure) {
      continue;
    }
    figure->move(120.0f, 70.0f);
  }

  wait4keyORmouse();

  figures[0]->move(-80.0f, 100.0f);
  figures[2]->move(60.0f, -120.0f);

  wait4keyORmouse();

  for (int i = 0; i < 10; i++) {
    Figure* figure = figures[i];
    delete figure;
  }
}

/*
void Main(void){
  draw_line(0,0,00,250,255,128,128);
  draw_arc(400,400,90,0,180,0,255,0);
  std::cout<<"1"<<std::endl;

  wait4keyORmouse(); // SPACE BAR or LEFT MOUSE KEY

  draw_line(500,0,50,250,0,0,255);
  draw_arc(150,200,120,0,200,255,255,0);
  draw_line(300,0,50,350,0,255,0);
  draw_arc(250,300,50,100,360,255,255,255);
  draw_arc(250,300,100,0,180,255,255,0);
  draw_line(200,0,50,450,255,0,0);

  wait4keyORmouse();

  draw_line(300,0,50,350,0,0,0);
  draw_arc(100,100,90,45,90,0,0,0);
  draw_line(400,0,50,250,0,0,0);

  draw_line(200,0,250,250,255,255,255);
  draw_arc(100,100,80,33,180,0,255,255);
  draw_arc(250,300,50,0,360,0,0,0);

  wait4keyORmouse();


  draw_line(900,0,50,350,0,0,0);
  draw_arc(100,100,90,45,90,0,0,0);
  draw_line(400,0,50,250,0,0,0);

  draw_line(7000,0,250,250,255,255,255);
  draw_arc(100,100,80,33,180,0,255,255);
  draw_arc(250,300,50,0,360,0,0,0);

  wait4keyORmouse();
}
*/