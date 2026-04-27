#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <windows.h>

#include "graphlib.h"

#include "Figure.h"
#include "MArc.h"
#include "MLine.h"
#include "MObject.h"
#include "MSector.h"
#include "MSegment.h"
#include "OArc.h"
#include "OLine.h"
#include "OSector.h"
#include "OSegment.h"

void moveAll(Figure** figura, int count, float dx, float dy) {
  for (int i = 0; i < count; i++) {
    if (figura[i]) {
      figura[i]->move(dx, dy);
    }
  }
}

void printAll(OLine* line, OArc* arc, OSegment* segment, OSector* sector, MNumber* number) {
  if (line) {
    line->print();
  }
  if (arc) {
    arc->print();
  }
  if (segment) {
    segment->print();
  }
  if (sector) {
    sector->print();
  }
  if (number) {
    number->print();
  }
  std::wcout << L'\n';
}

void Main(void)
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    _setmode(_fileno(stdout), _O_U16TEXT);

    Figure* figura[8];

    figura[0] = new MLine({90.0f, 130.0f}, {-35.0f, 10.0f}, {95.0f, 85.0f}, {1.0f, 0.1f, 0.1f});
    figura[1] = new MArc({285.0f, 210.0f}, {18.0f, -12.0f}, 92.0f, 35.0f, 250.0f, {1.0f, 0.4f, 0.1f});
    figura[2] = new OLine({470.0f, 110.0f}, {22.0f, -18.0f}, {132.0f, 76.0f}, {0.0f, 0.9f, 0.2f});
    figura[3] = new OArc({655.0f, 245.0f}, {-14.0f, 6.0f}, 84.0f, 210.0f, 20.0f, {0.2f, 0.9f, 0.4f});
    figura[4] = new MSegment({240.0f, 405.0f}, {10.0f, -8.0f}, 88.0f, 15.0f, 205.0f, {1.0f, 0.1f, 0.3f});
    figura[5] = new MSector({160.0f, 610.0f}, {-12.0f, 9.0f}, 104.0f, 300.0f, 55.0f, {0.9f, 0.2f, 0.0f});
    figura[6] = new OSegment({560.0f, 430.0f}, {6.0f, 0.0f}, 96.0f, 200.0f, 355.0f, {0.1f, 0.8f, 1.0f});
    figura[7] = new OSector({760.0f, 590.0f}, {-8.0f, -4.0f}, 108.0f, 120.0f, 255.0f, {0.0f, 1.0f, 0.5f});

    OLine* oLine = dynamic_cast<OLine*>(figura[2]);
    OArc* oArc = dynamic_cast<OArc*>(figura[3]);
    OSegment* oSegment = dynamic_cast<OSegment*>(figura[6]);
    OSector* oSector = dynamic_cast<OSector*>(figura[7]);
    MNumber number;

    if (oLine && oArc && oSegment && oSector) {
      std::wcout << L"dynamic_cast ok\n";
      printAll(oLine, oArc, oSegment, oSector, &number);
    }

    wait4keyORmouse();

    moveAll(figura, 8, 120.0f, 80.0f);
    wait4keyORmouse();

    figura[1]->move(-70.0f, 40.0f);
    figura[4]->move(55.0f, -35.0f);
    figura[5]->move(30.0f, -85.0f);
    figura[6]->setColor({1.0f, 1.0f, 0.0f});
    figura[6]->draw();
    figura[7]->setColor({0.2f, 1.0f, 1.0f});
    figura[7]->draw();
    wait4keyORmouse();

    for (int i = 0; i < 8; i++)
    {
        delete figura[i];
    }
    wait4keyORmouse();
}
