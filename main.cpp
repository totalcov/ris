#include <iostream>
#include "graphlib.h"



void Main(void){
  draw_line(0,0,500,250,255,128,128);
  draw_arc(400,400,90,0,180,0,255,0);
  std::cout<<"1"<<std::endl;

  wait4keyORmouse(); // SPACE BAR or LEFT MOUSE KEY

  draw_line(400,0,50,250,0,0,255);
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

}