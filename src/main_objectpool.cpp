#include <iostream>
#include "object_pool.h"
#include "object_pool_stack.h"
#include "timer.h"
using namespace std;

class Node {
public:
  float x;
  float y;
  int num;
  int data;

public:
  Node(){
    x = y = 0.0f;
    num  = -1;
    data = -1;
  };
  ~Node(){
    x = y = 0.0f;
    num  = -1;
    data = -1;
  };
};


int main(){
  cout << "Object pool test." << endl;
  ObjectPool<Node> ob(1000);
  
  for(int i = 0; i < 6; ++i)
    Node* node0 = ob.getObject();

  ob.showRemainedMemory();

  ObjectPoolStack<Node> obs(2000);
  
  Node* node0 = obs.getObject();
  Node* node1 = obs.getObject();
  
  obs.returnObject(node0);

  obs.showRemainedMemory();

  return 0;
}
