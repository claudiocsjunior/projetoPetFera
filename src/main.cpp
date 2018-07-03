#include <iostream>
#include "../include/petfera.h"
#include <cstdlib>
#include "../include/funcionario.h"
#include "../include/animal.h"

using namespace std;

int Funcionario::contador_id = 0;
int Animal::contador_animal_id = 0;

int main(int argc, char const *argv[])
{

	system("clear");
	PetFera petfera;
	petfera.funcionalidades();
	return 0;
}