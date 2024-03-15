// divide number by 2
// store remainder and repeat process until n!=0;
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  float ans = 0;
  int i = 0;
  while (n != 0)
  {
    int bit = n & 1;
    ans = (bit * pow(10, i)) + ans;
    n = n >> 1; // right shift
    i++;
  }

  cout << "answer is " << ans << endl;

  return 0;
}