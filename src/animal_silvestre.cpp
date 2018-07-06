/**
* @file   animal_silvestre.cpp
* @brief  Classe responsável por gerenciar os animais silvestres pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  28/06/2018
* @date   28/06/2018
*/

#include "../include/animal_silvestre.h"
#include <string>

using namespace std;

AnimalSilvestre::AnimalSilvestre(){} /**< Construtor padrão da Classe*/
AnimalSilvestre::~AnimalSilvestre(){} /**< Destrutor da Classe*/

/**
* @brief Método de acesso para o atributo ibama
* @return atributo ibama
*/
string AnimalSilvestre::getIbama(){
	return this->ibama;
}
/**
* @brief Método de alteração para o atributo ibama
* @return 
*/
void AnimalSilvestre::setIbama(std::string ibama){
	this->ibama = ibama;
}

																	