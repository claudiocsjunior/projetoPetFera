/**
* @file   animal_silvestre.h
* @brief  Classe responsável por gerenciar os animais silvestres pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _ANIMALSILVESTRE_H_  /**< Verifica se a variável _ANIMALSILVESTRE_H_ foi definida*/
#define _ANIMALSILVESTRE_H_	 /**< Define a variável _ANIMALSILVESTRE_H_*/

#include <string>

class AnimalSilvestre 
{
protected:
	std::string ibama;	
public:
	AnimalSilvestre(); /**< Construtor padrão da Classe*/
	~AnimalSilvestre(); /**< Destrutor da Classe*/

	/**
	* @brief Método de acesso para o atributo ibama
	* @return atributo ibama
	*/
	std::string getIbama();
	/**
	* @brief Método de alteração para o atributo ibama
	* @return 
	*/
	void setIbama(std::string ibama);
};

#endif
																	