/**
* @file   ave.cpp
* @brief  Classe responsável por gerenciar as aves pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  03/06/2018
* @date   03/06/2018
*/

#include "../include/ave.h"
#include "../include/animal.h"
#include <iostream>

using namespace std;
Ave::Ave():Animal("Aves"){} /**< Construtor padrão da Classe*/
Ave::~Ave(){} /**< Destrutor da Classe*/
/**
* @brief Método de preenchimento dos atributos pertencente a classe anfibio
* @return 
*/
bool Ave::preencher_atributos_locais(){
	cout << "TAMANHO BICO: ";
	cin >> this->tamanho_bico;
	cout << "ENVERGADURA: ";
	cin >> this->envergadura;
	if(cin.fail())
		return false;

	return true;
}
/**
* @brief Método de acesso para o atributo tamanho bico
* @return atributo tamanho bico
*/
float Ave::getTamanhoBico(){
	return this->tamanho_bico;
}
/**
* @brief Método de acesso para o atributo envergadura
* @return atributo tipo envergadura
*/
float Ave::getEnvergadura(){
	return this->envergadura;
}
/**
* @brief Efetua a impressão dos dados
* @param[in] variável para o <<
* @return valor do cout
*/
std::ostream& 
Ave::print(std::ostream &o) {
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
	  << endl << "                -> DETALHES: " 
	  << "| TAMANHO BICO: " <<  this->tamanho_bico
	  << "| ENVERGADURA: " <<  this->envergadura
	  << endl;
	return o;
}

