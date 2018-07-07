/**
* @file   funcionario.cpp
* @brief  Responsável por gerenciar os funcionários da PETFera
* @author Claudio da Cruz Silva Junior
* @since  28/06/2018
* @date   28/06/2018
*/

#include "../include/funcionario.h"
#include "iostream"
#include <string>

using namespace std;

/**
* @brief Construtor padrão do objeto
*/
Funcionario::Funcionario() {
	this->id = contador_id;
	this->nome = "";
	this->cpf = "";
	this->idade = 0;
	this->tipo_sanguineo = '\0';
	this->fatorRH = '\0';
	this->especialidade = "";
	this->funcao = "";
}

/**
* @brief Construtor paramatrizado da Classe
*/
Funcionario::Funcionario(std::string funcao){
	this->id = contador_id;
	this->nome = "";
	this->cpf = "";
	this->idade = 0;
	this->tipo_sanguineo = '\0';
	this->fatorRH = '\0';
	this->especialidade = "";
	this->funcao = funcao;

}
Funcionario::Funcionario(int id, string funcao, string nome, string cpf, int idade, string tipo_sanguineo, char fatorRH, string especialidade){
	this->id = id;
	this->nome = nome;
	this->cpf = cpf;
	this->idade = idade;
	this->tipo_sanguineo = tipo_sanguineo;
	this->fatorRH = fatorRH;
	this->especialidade = especialidade;
	this->funcao = funcao;
	contador_id = id + 1;
}

/**
* @brief Destrutor do objeto
*/
Funcionario::~Funcionario() {}

/**
* @brief Método de acesso para o atributo id
* @return atributo id
*/
int Funcionario::getId(){
	return this->id;
}
/**
* @brief Método de acesso para o atributo nome
* @return atributo nome
*/
string Funcionario::getNome(){
	return this->nome;
}
/**
* @brief Método de acesso para o atributo cpf
* @return atributo cpf
*/
std::string Funcionario::getCpf(){
	return this->cpf;
}
/**
* @brief Método de acesso para o atributo idade
* @return atributo idade
*/
short Funcionario::getIdade(){
	return this->idade;
}
/**
* @brief Método de acesso para o atributo tipo sanguineo
* @return atributo tipo sanguineo
*/
string Funcionario::getTipoSanguineo(){
	return this->tipo_sanguineo;
}
/**
* @brief Método de acesso para o atributo fator RH
* @return atributo fator RH
*/
char Funcionario::getFatorRH(){
	return this->fatorRH;
}
/**
* @brief Método de acesso para o atributo especialidade
* @return atributo especialidade
*/
std::string Funcionario::getEspecialidade(){
	return this->especialidade;
}
/**
* @brief Método de acesso para o atributo funcao
* @return atributo funcao
*/
std::string Funcionario::getFuncao(){
	return this->funcao;
}

/**
* @brief Método para modificar o atributo nome
* @return 
*/
void Funcionario::setNome(std::string nome){
	this->nome = nome;
}
/**
* @brief Método para modificar o atributo cpf
* @return 
*/
void Funcionario::setCpf(std::string cpf){
	this->cpf = cpf;
}
/**
* @brief Método para modificar o atributo idade
* @return 
*/
void Funcionario::setIdade(int idade){
	this->idade = idade;
}
/**
* @brief Método para modificar o atributo tipo sanguineo
* @return 
*/
void Funcionario::setTipoSanguineo(std::string tipo_sanguineo){
	this->tipo_sanguineo = tipo_sanguineo;
}
/**
* @brief Método para modificar o atributo fator RH
* @return 
*/
void Funcionario::setFatorRH(char fatorRH){
	this->fatorRH = fatorRH;
}
/**
* @brief Método para modificar o atributo especialidade
* @return 
*/
void Funcionario::setEspecialidade(std::string especialidade){
	this->especialidade = especialidade;
}
/**
* @brief Efetua a sobrecarga do operador >>
* @param[in] variável para o >>
* @param[in] Constante para guardar o objeto
* @return valor do cin
*/
istream& operator>>(istream &a, Funcionario &f){
	cin.ignore();
	cout << "DiGITE AS INFORMAÇÕES PARA CADASTRO DO FUNCIONÁRIO:" << endl;
	cout << "NOME: ";
	getline(a, f.nome);

	cout << "CPF: ";
	a >> f.cpf;

	cout << "IDADE: ";
	a >> f.idade;

	cout << "TIPO SANGUINEO: ";
	a >> f.tipo_sanguineo;

	cout << "FATOR RH: ";
	a >> f.fatorRH;
	
	cin.ignore();
	cout << "ESPECIALIDADE: ";
	getline(a, f.especialidade);

	return a;
}


/**
* @brief Efetua a sobrecarga do operador <<
* @param[in] variável para o <<
* @param[in] Constante para guardar o objeto
* @return valor do cout
*/
ostream& operator<<(ostream &e, Funcionario const f){
	e << "ID: "<< f.id
	  << "| NOME: " << f.nome
	  << "| CPF: " <<  f.cpf
	  << "| IDADE: " << f.idade
	  << "| TIPO SANGUINEO: " <<  f.tipo_sanguineo
	  << "| FATOR RH: " <<  f.fatorRH
	  << "| ESPECIALIDADE: " <<  f.especialidade
	  << "| FUNÇÃO: " <<  f.funcao
	  << endl;
	return e;
}


/**
* @brief Efetua a sobrecarga do operador ==
* @param[in] Constante para guardar o objeto a ser comparado
* @return booleano
*/

bool Funcionario::operator ==(Funcionario& funcionario){
	if(this->cpf.compare(funcionario.getCpf()) == 0)
		return true;
	else
		return false;
}

