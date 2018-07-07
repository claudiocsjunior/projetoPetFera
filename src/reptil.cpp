/**
* @file   reptil.cpp
* @brief  Classe responsável por gerenciar os répteis pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  03/06/2018
* @date   03/06/2018
*/

#include "../include/reptil.h"
#include "../include/animal.h"
#include <iostream>

using namespace std;
Reptil::Reptil(){} /**< Construtor padrão da Classe*/
Reptil::Reptil(string natureza):Animal("Reptilia", natureza){} /**< Construtor padrão da Classe*/
Reptil::Reptil(int id, std::string nome, std::string cientifico, std::string classe, char sexo, 
		float tamanho, std::string natureza, std::string dieta, std::string batismo, Veterinario veterinario, 
		Tratador tratador, bool venenoso, std::string tipo_veneno):
		Animal(id, nome, cientifico, classe, sexo, tamanho, natureza, dieta, batismo, veterinario, tratador),
		venenoso(venenoso), tipo_veneno(tipo_veneno){}
Reptil::~Reptil(){} /**< Destrutor da Classe*/
/**
* @brief Método de preenchimento dos atributos pertencente a classe anfibio
* @return 
*/
bool Reptil::preencher_atributos_locais(){
	cout << "Venenoso (1 - sim | 0 - false): ";
	cin >> this->venenoso;
	cout << "Tipo veneno: ";
	cin >> this->tipo_veneno;
	if(cin.fail())
		return false;

	return true;
}
/**
* @brief Método de acesso para o atributo venenoso
* @return atributo venenoso
*/
bool Reptil::getVenenoso(){
	return this->venenoso;
}
/**
* @brief Método de acesso para o atributo tipo veneno
* @return atributo tipo veneno
*/
string Reptil::getTipoVeneno(){
	return this->tipo_veneno;
}

/**
* @brief Método de alteração para o atributo venenoso
* @return 
*/
void Reptil::setVenenoso(int venenoso){
	this->venenoso = venenoso;
}
/**
* @brief Método de alteração para o atributo tipo veneno
* @return atributo tipo veneno
*/
void Reptil::setTipoVeneno(std::string tipo_veneno){
	this->tipo_veneno = tipo_veneno;
}

/**
* @brief Efetua a impressão dos dados
* @param[in] variável para o <<
* @return valor do cout
*/
std::ostream& 
Reptil::print(std::ostream &o) {
	string venenoso;
	venenoso = this->venenoso ? "V" : "F";
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
	  << "| VENENOSO: " <<  venenoso 
	  << "| TIPO VENENO: " <<  this->tipo_veneno
	  << endl;
	return o;
}


