#include <iostream>

using namespace std;
void safe_free(int** p) 
{ 
  free(*p); 
  *p = 0; 
}

int main()
{
  int* p = (int*)malloc(sizeof(int));
  cout << "p:" << p << endl;
  *p = 42;
  safe_free(&p);
  cout << "p:" << p << endl;
}
