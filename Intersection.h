#ifndef INTERSECTION_H_
#define INTERSECTION_H_

#include "RunFind.h"

class Vertex{
 public:
  Vertex();
  Vertex(int x, int y);
  Vertex(int x, int y, int time);
  int x,y,time;
};

class Intersection{
 public:
  Intersection();
  int dv;
  int intersectionCount = 0;
  int adjCount = 0;
  bool known;
  Vertex adj[4];
};

#endif //INTERSECTION_H_