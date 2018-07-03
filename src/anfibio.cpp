/**
* @file   anfibio.cpp
* @brief  Classe responsável por gerenciar os anfibios pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  28/06/2018
* @date   28/06/2018
*/

#include "../include/anfibio.h"
#include "../include/animal.h"
#include <iostream>

using namespace std;
Anfibio::Anfibio():Animal("Amphibia"){} /**< Construtor padrão da Classe*/
Anfibio::~Anfibio(){} /**< Destrutor da Classe*/
/**
* @brief Método de preenchimento dos atributos pertencente a classe anfibio
* @return 
*/
bool Anfibio::preencher_atributos_locais(){
	cout << "TOTAL DE MUDAS: ";
	cin >> this->total_mudas;
	cout << "ULTIMA MUDA: ";
	cin >> this->ultima_muda;
	if(cin.fail())
		return false;

	return true;
}
/**		
* @brief Método de acesso para o atributo total mudas
* @return atributo total mudas
*/
int Anfibio::getTotalMudas(){
	return this->total_mudas;
}
/**
* @brief Método de acesso para o atributo ultima muda
* @return atributo ultima muda
*/
std::string Anfibio::getUltimaMuda(){
	return this->ultima_muda;
}

