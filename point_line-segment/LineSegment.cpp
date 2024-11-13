#include "LineSegment.h"
#include <sstream>

namespace Geometry {

  LineSegment::LineSegment(void) {}

  LineSegment::LineSegment(Point startPoint, Point endPoint) : startPoint(startPoint), endPoint(endPoint) {
  }

  LineSegment::LineSegment(double x1, double y1, double x2, double y2)
    : LineSegment(Point(x1, y1), Point(x2, y2)) {
  }

  void LineSegment::setStartPoint(Point startPoint) {
    this->startPoint = startPoint;
  }

  void LineSegment::setEndPoint(Point endPoint) {
    this->endPoint = endPoint;
  }

  Point LineSegment::getStartPoint(void) const {
    return startPoint;
  }

  Point LineSegment::getEndPoint(void) const {
    return endPoint;
  }

  std::string LineSegment::getString(void) const {
    return getStartPoint().getString() + " => " + getEndPoint().getString();
  }

};