/**
* @file   anfibio.h
* @brief  Classe responsável por gerenciar os anfibios pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _ANFIBIO_H_  /**< Verifica se a variável _ANFIBIO_H_ foi definida*/
#define _ANFIBIO_H_	 /**< Define a variável _ANFIBIO_H_*/
#include <iostream>
#include "animal.h" /**< Inclusão da classe animal.h*/

class Anfibio : public Animal
{
protected:
	int total_mudas;
	std::string ultima_muda;
public:
	Anfibio(); /**< Construtor padrão da Classe*/
	~Anfibio(); /**< Destrutor da Classe*/
	/**
	* @brief Método de preenchimento dos atributos pertencente a classe anfibio
	* @return 
	*/	
	bool preencher_atributos_locais();
	/**
	* @brief Método de acesso para o atributo total mudas
	* @return atributo total mudas
	*/
	int getTotalMudas();
		/**
	* @brief Método de acesso para o atributo ultima muda
	* @return atributo ultima muda
	*/
	std::string getUltimaMuda();

};

#endif
																	