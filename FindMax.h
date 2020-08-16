#ifndef _FINDMAX_H
#define	_FINDMAX_H
#include "RunFind.h"
#include "Intersection.h"
#include "BinaryHeap.h"

class FindMax {
public:
  FindMax(int citySize, const StreetBlock *streets, int numStreets);
  const int DIV_CONSTANT = 1000;
  Intersection intersections[1000][1000];
  int intCount;
  void find(Coordinate fireHouses[4], Coordinate *furthest, int *time);
}; // class FindMax

#endif	/* _FINDMAX_H */

