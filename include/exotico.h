/**
* @file   exotico.h
* @brief  Classe responsável por gerenciar os animais exoticos pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _EXOTICO_H_  /**< Verifica se a variável _exotico_H_ foi definida*/
#define _EXOTICO_H_	 /**< Define a variável _exotico_H_*/

#include "animal_silvestre.h" /**< Inclusão da classe funcionario.h*/
#include <string>

class Exotico : public AnimalSilvestre
{
protected:
	std::string pais_origem;
public:
	Exotico(); /**< Construtor padrão da Classe*/
	Exotico(std::string pais_origem, std::string ibama); /**< Construtor padrão da Classe*/
	~Exotico(); /**< Destrutor da Classe*/
	/**
	* @brief Método de acesso para o pais origem
	* @return atributo uf origem
	*/
	std::string getPaisOrigem();

	/**
	* @brief Método de alteração do pais de origem
	* @return 
	*/
	void setPaisOrigem(std::string pais_origem);
};

#endif
																	