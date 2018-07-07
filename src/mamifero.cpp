/**
* @file   mamifero.cpp
* @brief  Classe responsável por gerenciar os mamíferos pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  03/06/2018
* @date   03/06/2018
*/

#include "../include/mamifero.h"
#include "../include/animal.h"
#include <iostream>

using namespace std;
Mamifero::Mamifero(){} /**< Construtor padrão da Classe*/
Mamifero::Mamifero(string natureza):Animal("Mammalia", natureza){} /**< Construtor padrão da Classe*/
Mamifero::Mamifero(int id, std::string nome, std::string cientifico, std::string classe, char sexo, 
		float tamanho, std::string natureza, std::string dieta, std::string batismo, Veterinario veterinario, 
		Tratador tratador, std::string cor_pelo):
		Animal(id, nome, cientifico, classe, sexo, tamanho, natureza, dieta, batismo, veterinario, tratador),
		cor_pelo(cor_pelo){}
Mamifero::~Mamifero(){} /**< Destrutor da Classe*/
/**
* @brief Método de preenchimento dos atributos pertencente a classe anfibio
* @return 
*/
bool Mamifero::preencher_atributos_locais(){
	cout << "COR DA PELO: ";
	cin >> this->cor_pelo;
	if(cin.fail())
		return false;

	return true;
}
/**		
* @brief Método de acesso para o atributo cor pelo
* @return atributo cor pelo
*/
string Mamifero::getCorPelo(){
	return this->cor_pelo;
}

/**
* @brief Método de alteração para o atributo cor do pelo
* @return 
*/
void Mamifero::setCorPelo(std::string cor_pelo){
	this->cor_pelo = cor_pelo;
}

/**
* @brief Efetua a impressão dos dados
* @param[in] variável para o <<
* @return valor do cout
*/
std::ostream& 
Mamifero::print(std::ostream &o) {
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
	  << "| COR PELO: " <<  this->cor_pelo
	  << endl;
	return o;
}
