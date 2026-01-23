#include <iostream>

int main()
{
  size_t * mtx = nullptr;

  try
  {
    mtx = new size_t[1];
  }
  catch (...)
  {
    return 1;
  }


  try
  {
    size_t a = 0;
    size_t n = 0;

    std::cin >> a;

    while (std::cin >> n)
    {
    }
  }
  catch(...)
  {
    delete[] mtx;
  }

  return 0;
}
