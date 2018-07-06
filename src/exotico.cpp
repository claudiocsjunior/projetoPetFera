/**
* @file   exotico.cpp
* @brief  Classe responsável por gerenciar os animais exoticos pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  28/06/2018
* @date   28/06/2018
*/

#include "../include/exotico.h"
#include "../include/animal_silvestre.h"

Exotico::Exotico(){} /**< Construtor padrão da Classe*/
Exotico::~Exotico(){} /**< Destrutor da Classe*/
/**
* @brief Método de acesso para o pais origem
* @return atributo uf origem
*/
std::string Exotico::getPaisOrigem(){
	return this->pais_origem;
}

/**
* @brief Método de alteração do pais de origem
* @return 
*/
void Exotico::setPaisOrigem(std::string pais_origem){
	this->pais_origem = pais_origem;
}