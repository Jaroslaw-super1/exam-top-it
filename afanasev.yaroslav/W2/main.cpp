#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char ** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments" << '\n';
    return 1;
  }

  for (size_t i = 0; i < argc - 3; i++)
  {
    std::ifstream input(argv[i + 3]);

    signed long long n = 0;

    while (!input.eof())
    {
      input >> n;
    }

    input.close();
  }
  

  return 0;
}