#include <iostream>

int main()
{
  size_t * mtx = nullptr;

  size_t size = 0;
  size_t summ = 0;

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

    while (true)
    {
      std::cin >> a;

      if (std::cin.eof())
      {
        break;
      }
      if (std::cin.fail())
      {
        delete[] mtx;
        return 2;
      }

      size += a;

      for (size_t i = 0; i < a; i++)
      {
        std::cin >> n;

        if (std::cin.eof())
        {
          delete[] mtx;
          return 7;
        }
        if (std::cin.fail())
        {
          delete[] mtx;
          return 2;
        }

        
      }
      


      std::cout << a << '\n';
    }
  }
  catch(...)
  {
    delete[] mtx;
  }

  std::cout << "size: " << size << '\n';

  delete[] mtx;

  return 0;
}
