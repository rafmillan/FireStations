#include "Intersection.h"

Vertex::Vertex(int xi, int yi, int timei){
    x = xi;
    y = yi;
    time = timei;
}

Vertex::Vertex(int xi, int yi){
  x = xi;
  y = yi;
}

Vertex::Vertex(){
    x = 0;
    y = 0;
}

Intersection::Intersection(){
  dv = 999999999;
  known = false;
  adjCount = 0;

}