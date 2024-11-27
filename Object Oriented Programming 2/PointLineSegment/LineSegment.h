#pragma once
#include "Point.h"

#include <string>
using namespace std;

namespace Geometry {

  class LineSegment {
    public:
      LineSegment(void);
      LineSegment(Point start, Point end);
      LineSegment(double x1, double y1, double x2, double y2);

      Point getStartPoint(void) const;
      Point getEndPoint(void) const;

      void setStartPoint(Point startPoint);
      void setEndPoint(Point endPoint);

      string getString(void) const;

    private:
      // compositie: indien geïnitialiseerd via constructor
      // aggregatie: indien niet geïnitialiseerd via constructor
      // en eventueel nadien aangemaakt via setters (optioneel)
      Point startPoint;
      Point endPoint;
      // indien dit hier niet zou staan en direct in de body van
      // constructor of methode zou staan, dan zou dit zelfs
      // associatie zijn

  };

};