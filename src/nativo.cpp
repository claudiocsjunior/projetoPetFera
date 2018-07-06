/**
* @file   nativo.cpp
* @brief  Classe responsável por gerenciar os animais nativos pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  28/06/2018
* @date   28/06/2018
*/

#include "../include/nativo.h"
#include "../include/animal_silvestre.h"

Nativo::Nativo(){} /**< Construtor padrão da Classe*/
Nativo::~Nativo(){} /**< Destrutor da Classe*/
/**
* @brief Método de acesso para o uf origem
* @return atributo uf origem
*/
std::string Nativo::getUfOrigem(){
	return this->uf_origem;
}
/**
* @brief Método de acesso para o autorizacao
* @return atributo autorizacao
*/
std::string Nativo::getAutorizacao(){
	return this->autorizacao;
}

/**
* @brief Método de alteração da uf origem
* @return 
*/
void Nativo::setUfOrigem(std::string uf_origem){
	this->uf_origem = uf_origem;
}
/**
* @brief Método de alteração da autorizacao
* @return 
*/
void Nativo::setAutorizacao(std::string autorizacao){
	this->autorizacao = autorizacao;
}