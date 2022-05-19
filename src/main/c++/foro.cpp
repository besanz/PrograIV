#include <fstream>  // Para ofstream
#include <iostream> // Para cout
using namespace std;

int main()
{
  ofstream fich("ejemplo.dat");
  if (!fich)
  {
    cout << "Error al abrir ejemplo.dat\n";
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < 10; ++i)
    fich << i << endl;
}