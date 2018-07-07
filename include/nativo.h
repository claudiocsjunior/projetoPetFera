/**
* @file   nativo.h
* @brief  Classe responsável por gerenciar os animais nativos pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _NATIVO_H_  /**< Verifica se a variável _NATIVO_H_ foi definida*/
#define _NATIVO_H_	 /**< Define a variável _NATIVO_H_*/

#include "animal_silvestre.h" /**< Inclusão da classe funcionario.h*/
#include <string>

class Nativo : public AnimalSilvestre
{
protected:
	std::string uf_origem;
	std::string autorizacao;
public:
	Nativo(); /**< Construtor padrão da Classe*/
	Nativo(std::string uf_origem, std::string autorizacao, std::string ibama); /**< Construtor padrão da Classe*/
	~Nativo(); /**< Destrutor da Classe*/
	/**
	* @brief Método de acesso para o uf origem
	* @return atributo uf origem
	*/
	std::string getUfOrigem();
	/**
	* @brief Método de acesso para o autorizacao
	* @return atributo autorizacao
	*/
	std::string getAutorizacao();

	/**
	* @brief Método de alteração da uf origem
	* @return 
	*/
	void setUfOrigem(std::string uf_origem);
	/**
	* @brief Método de alteração da autorizacao
	* @return 
	*/
	void setAutorizacao(std::string autorizacao);

};

#endif
																	