/**
* @file   animal.cpp
* @brief  Responsável por gerenciar os animais da PETFera
* @author Claudio da Cruz Silva Junior
* @since  28/06/2018
* @date   28/06/2018
*/

#include "../include/animal.h"
#include "../include/funcionario.h"
#include "../include/veterinario.h"
#include "../include/tratador.h"
#include "iostream"
#include <string>

using namespace std;

/**
* @brief Construtor padrão do objeto
*/
Animal::Animal() {
	this->id = contador_animal_id;
	this->classe = "";
	this->nome = "";
	this->cientifico = "";
	this->sexo = '\0';
	this->tamanho = 0;
	this->dieta = "";
	this->batismo = "";
}

/**
* @brief Construtor paramatrizado da Classe
*/
Animal::Animal(std::string classe){
	this->id = contador_animal_id;
	this->classe = classe;
	this->nome = "";
	this->cientifico = "";
	this->sexo = '\0';
	this->tamanho = 0;
	this->dieta = "";
	this->batismo = "";
}


/**
* @brief Destrutor do objeto
*/
Animal::~Animal() {}

/**
* @brief Método de acesso para o atributo id
* @return atributo id
*/
int Animal::getId(){
	return this->id;
}
/**
* @brief Método de acesso para o atributo classe
* @return atributo classe
*/
string Animal::getClasse(){
	return this->classe;
}
/**
* @brief Método de acesso para o atributo nome
* @return atributo nome
*/
string Animal::getNome(){
	return this->nome;
}

/**
* @brief Método de acesso para o atributo cietifico
* @return atributo cientifico
*/
string Animal::getCientifico(){
	return this->cientifico;
}
/**
* @brief Método de acesso para o atributo sexo
* @return atributo sexo
*/
char Animal::getSexo(){
	return this->sexo;
}
/**
* @brief Método de acesso para o atributo tamanho
* @return atributo tamanho
*/
int Animal::getTamanho(){
	return this->tamanho;
}
/**
* @brief Método de acesso para o atributo dieta
* @return atributo dieta
*/
string Animal::getDieta(){
	return this->dieta;
}
/**
* @brief Método de acesso para o atributo batismo
* @return atributo batismo
*/
string Animal::getBatismo(){
	return this->batismo;
}

/**
* @brief Método de alteração do veterinario
* @return 
*/
void Animal::setVeterinario(Veterinario &veterinario){
	this->veterinario = veterinario;
}
/**
* @brief Método de alteração do tratador
* @return 
*/
void Animal::setTratador(Tratador &tratador){
	this->tratador = tratador;
}
/**
* @brief Método de alteração do id
* @return 
*/
void Animal::setId(int id){
	this->id = id;
}

/**
* @brief Efetua a sobrecarga do operador >>
* @param[in] variável para o >>
* @param[in] Constante para guardar o objeto
* @return valor do cin
*/
istream& operator>>(istream &i, Animal &a){
	cin.ignore();
	cout << "DiGITE AS INFORMAÇÕES PARA CADASTRO DO ANIMAL:" << endl;
	cout << "NOME: ";
	getline(i, a.nome);

	cout << "NOME CIENTIFICO: ";
	i >> a.cientifico;

	cout << "SEXO: ";
	i >> a.sexo;

	cout << "TAMANHO: ";
	i >> a.tamanho;

	cout << "DIETA ";
	i >> a.dieta;
	
	cin.ignore();
	cout << "BATISTMO: ";
	getline(i, a.batismo);

	return i;
}


/**
* @brief Efetua a sobrecarga do operador <<
* @param[in] variável para o <<
* @param[in] Constante para guardar o objeto
* @return valor do cout
*/
ostream& operator<<(ostream &e, Animal &a){
	e << "ID: "<< a.id
	  << "| NOME: " << a.nome
	  << "| NOME CIENTIFICO: " <<  a.cientifico
	  << "| CLASSE: " <<  a.classe
	  << "| SEXO: " << a.sexo
	  << "| TAMANHO: " <<  a.tamanho
	  << "| DIETA: " <<  a.dieta
	  << "| BATISMO: " <<  a.batismo
	  << "| VETERINÁRIO: " <<  a.veterinario.getNome()
	  << "| TRATADOR: " <<  a.tratador.getNome()
	  << endl;
	return e;
}


/**
* @brief Efetua a sobrecarga do operador ==
* @param[in] Constante para guardar o objeto a ser comparado
* @return booleano
*/

bool Animal::operator ==(Animal &animal){
	if(this->nome.compare(animal.getNome()) == 0)
		return true;
	else
		return false;
}

