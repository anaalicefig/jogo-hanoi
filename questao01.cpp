#include <iostream>

using namespace std;

int soma(int n)
{
  int result = 0;

  result = result + n;

  if(n == 0)
    return soma(n-1);

  return result;
}

int main()
{
  cout << soma(5) << endl;
}