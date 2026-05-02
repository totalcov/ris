#include <iostream>

#include "Figure.h"
#include "MArc.h"
#include "MLine.h"
#include "MObject.h"
#include "MSegment.h"
#include "MSector.h"
#include "OArc.h"
#include "OLine.h"
#include "OSector.h"
#include "OSegment.h"
#include "graphlib.h"

void Main(void){
  Figure* figures[10]{};

  figures[0] = new MLine({140.0f, 120.0f}, {0.0f, 0.0f}, {130.0f, 70.0f}, {1.0f, 0.2f, 0.2f});
  figures[1] = new MArc({420.0f, 150.0f}, {0.0f, 0.0f}, 70.0f, 30.0f, 260.0f, {0.2f, 1.0f, 0.2f});
  figures[2] = new MSegment({700.0f, 180.0f}, {0.0f, 0.0f}, 75.0f, 30.0f, 235.0f, {1.0f, 1.0f, 0.0f});
  figures[3] = new MSector({1000.0f, 180.0f}, {0.0f, 0.0f}, 70.0f, 210.0f, 330.0f, {0.0f, 1.0f, 1.0f});

  figures[4] = new OLine({170.0f, 420.0f}, {0.0f, 0.0f}, {110.0f, -50.0f}, {1.0f, 0.7f, 0.0f}, " 1");
  figures[5] = new OArc({430.0f, 430.0f}, {0.0f, 0.0f}, 55.0f, 120.0f, 330.0f, {0.7f, 0.5f, 1.0f}, " 1");
  figures[6] = new OSegment({720.0f, 430.0f}, {0.0f, 0.0f}, 70.0f, 10.0f, 220.0f, {1.0f, 0.4f, 0.7f});
  figures[7] = new OSector({1040.0f, 430.0f}, {0.0f, 0.0f}, 65.0f, 200.0f, 320.0f, {0.4f, 0.8f, 1.0f});

  MObject::printAll();

  wait4keyORmouse();

  figures[1]->setColor({1.0f, 1.0f, 1.0f});
  figures[5]->setColor({1.0f, 0.0f, 1.0f});

  wait4keyORmouse();

  for (int i = 0; i < 10; i++) {
    Figure* figure = figures[i];

    if (!figure) {
      continue;
    }
    figure->move(50.0f, 45.0f);
  }

  wait4keyORmouse();

  figures[2]->move(-80.0f, 100.0f);
  figures[7]->move(60.0f, -120.0f);

  wait4keyORmouse();

  for (int i = 0; i < 10; i++) {
    Figure* figure = figures[i];
    delete figure;
  }
}
