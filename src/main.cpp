#include <iostream>
#include "../include/petfera.h"
#include <cstdlib>
#include "../include/funcionario.h"
#include "../include/animal.h"

using namespace std;

int Funcionario::contador_id = 1;
int Animal::contador_animal_id = 1;

int main(int argc, char const *argv[])
{

	system("clear");
	PetFera petfera;
	petfera.recuperar_informacoes_arquivo();
	petfera.funcionalidades();
	petfera.salvar_informacoes_arquivo();
	return 0;
}