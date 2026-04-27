#include <cstdio>
#include <fcntl.h>
#include <io.h>

#include "Figure.h"
#include "MLine.h"
#include "MArc.h"
#include "MObject.h"
#include "MSector.h"
#include "MSegment.h"
#include "graphlib.h"

void Main(void) {
  _setmode(_fileno(stdout), _O_U16TEXT);

  Figure* figures[10]{};

  figures[0] = new MLine({150.0f, 120.0f}, {20.0f, 10.0f}, {120.0f, 70.0f}, {1.0f, 0.0f, 0.0f});
  figures[1] = new MArc({420.0f, 180.0f}, {40.0f, 30.0f}, 80.0f, 20.0f, 220.0f, {0.0f, 1.0f, 0.0f});
  figures[2] = new MSector({700.0f, 260.0f}, {0.0f, 0.0f}, {90.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 90.0f},
                           {0.0f, 0.0f}, 90.0f, 0.0f, 90.0f, {1.0f, 1.0f, 0.0f});
  figures[3] = new MSegment({280.0f, 420.0f}, {-60.0f, 20.0f}, {60.0f, 20.0f}, {0.0f, 0.0f}, 65.0f, 20.0f,
                             160.0f, {0.0f, 1.0f, 1.0f});

  MNumber number;

  wait4keyORmouse();

  figures[1]->setColor({1.0f, 1.0f, 1.0f});
  figures[1]->draw();
  figures[2]->setColor({1.0f, 0.0f, 1.0f});
  figures[2]->draw();
  figures[3]->setColor({0.0f, 0.0f, 1.0f});
  figures[3]->draw();

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
  figures[2]->move(40.0f, -90.0f);
  figures[3]->move(-30.0f, -110.0f);

  wait4keyORmouse();

  for (int i = 0; i < 10; i++) {
    Figure* figure = figures[i];
    delete figure;
  }
}
