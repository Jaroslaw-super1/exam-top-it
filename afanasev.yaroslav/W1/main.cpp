#include <iostream>

int main()
{
  size_t * mtx = nullptr;

  size_t size = 0;
  long long summ = 0;
  size_t maxln = 0;
  size_t minln = 0;
  size_t negative = 0;
  size_t positive = 0;
  size_t empty = 0;

  try
  {
    mtx = new size_t[size];
  }
  catch (...)
  {
    return 1;
  }

  try
  {
    size_t a = 0;
    long long n = 0;

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

      size_t * tmp = nullptr;

      try
      {
        tmp = new size_t[size + a];
      }
      catch(...)
      {
        delete[] mtx;
        return 1;
      }

      for (size_t i = 0; i < size; i++)
      {
        tmp[i] = mtx[i];
      }
      delete[] mtx;
      mtx = tmp;

      maxln = std::max(a, maxln);
      if (size)
      {
        minln = std::min(a, minln);
      }
      else
      {
        minln = a;
      }
      if (!a)
      {
        empty++;
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

        summ += n;
        if (n < 0)
        {
          negative++;
        }
        else
        {
          positive++;
        }
        
        
        mtx[size - a + i] = n;
      }
    }
  }
  catch(...)
  {
    delete[] mtx;
  }
  delete[] mtx;

  if (!size)
  {
    return 3;
  }

  std::cout << "size: " << size << '\n';
  std::cout << "median: " << summ / size << '\n';
  std::cout << "maxln: " << maxln << '\n';
  std::cout << "maxseq: " << "<NOT SUPPORT>" << '\n';
  std::cout << "minln: " << minln << '\n';
  std::cout << "minseq: " << "<NOT SUPPORT>" << '\n';
  std::cout << "negative: " << negative << '\n';
  std::cout << "positive: " << positive << '\n';
  std::cout << "medianln: " << "<NOT SUPPORT>" << '\n';
  std::cout << "empty: " << empty << '\n';
  std::cout << "sum-negative: " << "<NOT SUPPORT>" << '\n';
  std::cout << "sum-positive: " << "<NOT SUPPORT>" << '\n';
  std::cout << "average: " << "<NOT SUPPORT>" << '\n';
  std::cout << "sigma: " << "<NOT SUPPORT>" << '\n';
  std::cout << "dobsov: " << "<NOT SUPPORT>" << '\n';
  std::cout << "all: " << "<NOT SUPPORT>" << '\n';



  return 0;
}
