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
/**
* @brief Método de alteração do total de mudas
* @return 
*/
void Anfibio::setTotalmudas(int total_mudas){
	this->total_mudas = total_mudas;
}
/**
* @brief Método de alteração da ultima muda
* @return 
*/
void Anfibio::setUltimaMuda(std::string ultima_muda){
	this->ultima_muda = ultima_muda;
}

/**
* @brief Efetua a impressão dos dados
* @param[in] variável para o <<
* @return valor do cout
*/
std::ostream& 
Anfibio::print(std::ostream &o) {
	o << "ID: "<< this->id
	  << "| NOME: " << this->nome
	  << "| NOME CIENTIFICO: " <<  this->cientifico
	  << "| CLASSE: " <<  this->classe
	  << "| SEXO: " << this->sexo
	  << "| TAMANHO: " <<  this->tamanho
	  << "| DIETA: " <<  this->dieta
	  << "| BATISMO: " <<  this->batismo
	  << "| VETERINÁRIO: " << "[ código: " << this->veterinario.getId() <<  " Nome: " << this->veterinario.getNome() << "]"
	  << "| TRATADOR: " << "[ código " << this->tratador.getId() <<  " Nome: " << this->tratador.getNome() << "]"
	  << endl << "                  -> DETALHES: " 
	  << "| TOTAL DE MUDAS: " <<  this->total_mudas
	  << "| ULTIMA MUDA: " <<  this->ultima_muda
	  << endl;
	return o;
}

