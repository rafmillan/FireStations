// Author Sean Davis

#include "FindMax.h"
#include <iostream>
#include "Intersection.h"

FindMax::FindMax(int citySize, const StreetBlock *streets, int numStreets)
{
  for(int i = 0; i < numStreets; i++){
    Intersection &startInt = intersections[streets[i].startX][streets[i].startY];
    startInt.adj[startInt.adjCount].x = streets[i].endX;
    startInt.adj[startInt.adjCount].y = streets[i].endY;
    startInt.adj[startInt.adjCount].time = (((abs((streets[i].startX - streets[i].endX) + (streets[i].startY - streets[i].endY)) * DIV_CONSTANT * 3600) / streets[i].speed));
    if(startInt.adjCount == 0)
      intCount++;
    startInt.adjCount++;

    Intersection &endInt = intersections[streets[i].endX][streets[i].endY];
    endInt.adj[endInt.adjCount].x = streets[i].startX;
    endInt.adj[endInt.adjCount].y = streets[i].startY;
    endInt.adj[endInt.adjCount].time = (((abs((streets[i].startX - streets[i].endX) + (streets[i].startY - streets[i].endY)) * DIV_CONSTANT *3600) / streets[i].speed));
    if(endInt.adjCount == 0)
      intCount++;
    endInt.adjCount++;


  }//end of street loop
 // std::cout << intersections[5][16].dv << std::endl;
} // FindMax()

void FindMax::find(Coordinate fireHouses[4], Coordinate *furthest, int *time) {
  //Fire house inserts
  BinaryHeap<Vertex> heap(10000);
  int knownIntCount = 0;
  int newTime = 0;
  int maxTime = 0;

  //insert firehouses into heap
  for(int f = 0; f < 4; f++){
    intersections[fireHouses[f].x][fireHouses[f].y].dv = 0;
    heap.insert(Vertex(fireHouses[f].x, fireHouses[f].y, 0));
  }

  while (!heap.isEmpty()) {
    Vertex V;
    heap.deleteMin(V);
    Intersection &inter = intersections[V.x][V.y];

    if(inter.known)
      continue;

    inter.known = true;
    knownIntCount++;

    if(inter.dv > maxTime){
      maxTime = inter.dv;
    }

    if(knownIntCount == intCount){
      furthest->x = V.x;
      furthest->y = V.y;
      *time = V.time/10000;
    }

    for (int i = 0; i < inter.adjCount; i++) {
      newTime = inter.dv + inter.adj[i].time;
      if (intersections[inter.adj[i].x][inter.adj[i].y].dv > newTime) {
        intersections[inter.adj[i].x][inter.adj[i].y].dv = newTime;
        heap.insert(Vertex(inter.adj[i].x, inter.adj[i].y, newTime));
      }
    }
  }

} // find()

