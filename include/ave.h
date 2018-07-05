/**
* @file   ave.h
* @brief  Classe responsável por gerenciar as aves pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  03/07/2018
* @date   03/07/2018
*/

#ifndef _AVE_H_  /**< Verifica se a variável _AVE_H_ foi definida*/
#define _AVE_H_	 /**< Define a variável _AVE_H_*/
#include <iostream>
#include "animal.h" /**< Inclusão da classe animal.h*/

class Ave : public Animal
{
protected:
	float tamanho_bico;
	float envergadura;
public:
	Ave(); /**< Construtor padrão da Classe*/
	~Ave(); /**< Destrutor da Classe*/
	/**
	* @brief Método de preenchimento dos atributos pertencente a classe anfibio
	* @return 
	*/	
	bool preencher_atributos_locais();
	/**
	* @brief Método de acesso para o atributo tamanho bico
	* @return atributo tamanho bico
	*/
	float getTamanhoBico();
	/**
	* @brief Método de acesso para o atributo envergadura
	* @return atributo tipo envergadura
	*/
	float getEnvergadura();
	/**
	* @brief Efetua a impressão dos dados
	* @param[in] variável para o <<
	* @return valor do cout
	*/
	std::ostream& print(std::ostream &o);

};

#endif
																	