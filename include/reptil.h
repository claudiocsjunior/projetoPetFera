/**
* @file   reptil.h
* @brief  Classe responsável por gerenciar os répteis pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  03/07/2018
* @date   03/07/2018
*/

#ifndef _REPTIL_H_  /**< Verifica se a variável _REPTIL_H_ foi definida*/
#define _REPTIL_H_	 /**< Define a variável _REPTIL_H_*/
#include <iostream>
#include "animal.h" /**< Inclusão da classe animal.h*/

class Reptil : public Animal
{
protected:
	bool venenoso;
	std::string tipo_veneno;
public:
	Reptil(); /**< Construtor padrão da Classe*/
	Reptil(std::string natureza); /**< Construtor padrão da Classe*/
	~Reptil(); /**< Destrutor da Classe*/
	/**
	* @brief Método de preenchimento dos atributos pertencente a classe anfibio
	* @return 
	*/	
	bool preencher_atributos_locais();
	/**
	* @brief Método de acesso para o atributo venenoso
	* @return atributo venenoso
	*/
	bool getVenenoso();
	/**
	* @brief Método de acesso para o atributo tipo veneno
	* @return atributo tipo veneno
	*/
	std::string getTipoVeneno();
	/**
	* @brief Efetua a impressão dos dados
	* @param[in] variável para o <<
	* @return valor do cout
	*/
	std::ostream& print(std::ostream &o);

};

#endif
																	