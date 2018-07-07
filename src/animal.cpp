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
	this->natureza = "";
}

/**
* @brief Construtor paramatrizado da Classe
*/
Animal::Animal(std::string classe, string natureza){
	this->id = contador_animal_id;
	this->classe = classe;
	this->nome = "";
	this->cientifico = "";
	this->sexo = '\0';
	this->tamanho = 0;
	this->dieta = "";
	this->batismo = "";
	this->natureza = natureza;
}

/**
* @brief Construtor paramatrizado da Classe
*/
Animal::Animal(int id, std::string nome, std::string cientifico, std::string classe, char sexo, 
		float tamanho, std::string natureza, std::string dieta, std::string batismo, Veterinario veterinario, 
		Tratador tratador){
	this->id = id;
	this->classe = classe;
	this->nome = nome;
	this->cientifico = cientifico;
	this->sexo = sexo;
	this->tamanho = tamanho;
	this->dieta = dieta;
	this->batismo = batismo;
	this->natureza = natureza;
	this->veterinario = veterinario;
	this->tratador = tratador;

	contador_animal_id = id +1;
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
* @brief Método de acesso para o atributo batismo
* @return atributo batismo
*/
string Animal::getNatureza(){
	return this->natureza;
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
* @brief Método de alteração do atributo cientifico
* @return 
*/
void Animal::setCientifico(string nome_cientifico){
	this->cientifico = nome_cientifico;
}
/**
* @brief Método de alteração para o atributo nome
* @return 
*/
void Animal::setNome(string nome){
	this->nome = nome;
}
/**
* @brief Método de alteração para o atributo sexo
* @return 
*/
void Animal::setSexo(char sexo){
	this->sexo = sexo;
}
/**
* @brief Método de alteração para o atributo tamanho
* @return 
*/
void Animal::setTamanho(float tamanho){
	this->tamanho = tamanho;
}
/**
* @brief Método de alteração para o atributo dieta
* @return 
*/
void Animal::setDieta(string dieta){
	this->dieta = dieta;
}
/**
* @brief Método de alteração para o atributo batismo
* @return 
*/
void Animal::setBatismo(string batismo){
	this->batismo = batismo;
}

/**
* @brief Método de acesso para o atributo veterinário
* @return atributo dieta
*/
Veterinario Animal::getVeterinario(){
	return this->veterinario;
}
/**
* @brief Método de acesso para o atributo tratador
* @return atributo batismo
*/
Tratador Animal::getTratador(){
	return this->tratador;	
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
std::ostream& operator<< (std::ostream &o, Animal &a) {
	return a.print(o);
}

 
/**
* @brief Efetua a impressão dos dados
* @param[in] variável para o <<
* @return valor do cout
*/
std::ostream& 
Animal::print(std::ostream &o) {
	o << "ID: "<< this->id
	  << "| NOME: " << this->nome
	  << "| NOME CIENTIFICO: " <<  this->cientifico
	  << "| CLASSE: " <<  this->classe
	  << "| SEXO (M | F): " << this->sexo
	  << "| TAMANHO: " <<  this->tamanho
	  << "| DIETA: " <<  this->dieta
	  << "| BATISMO: " <<  this->batismo
	  << "| VETERINÁRIO: " << "[ código: " << this->veterinario.getId() <<  " Nome: " << this->veterinario.getNome() << "]"
	  << "| TRATADOR: " << "[ código " << this->tratador.getId() <<  " Nome: " << this->tratador.getNome() << "]"
	  << endl;
	return o;
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

