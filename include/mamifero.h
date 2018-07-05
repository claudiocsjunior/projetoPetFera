/**
* @file   mamifero.h
* @brief  Classe responsável por gerenciar os mamíferos pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  03/07/2018
* @date   03/07/2018
*/

#ifndef _MAMIFERO_H_  /**< Verifica se a variável _MAMIFERO_H_ foi definida*/
#define _MAMIFERO_H_	 /**< Define a variável _MAMIFERO_H_*/
#include <iostream>
#include "animal.h" /**< Inclusão da classe animal.h*/

class Mamifero : public Animal
{
protected:
	std::string cor_pelo;
public:
	Mamifero(); /**< Construtor padrão da Classe*/
	~Mamifero(); /**< Destrutor da Classe*/
	/**
	* @brief Método de preenchimento dos atributos pertencente a classe anfibio
	* @return 
	*/	
	bool preencher_atributos_locais();
	/**
	* @brief Método de acesso para o atributo com a cor do pelo
	* @return atributo cor pelo
	*/
	std::string getCorPelo();
	/**
	* @brief Efetua a impressão dos dados
	* @param[in] variável para o <<
	* @return valor do cout
	*/
	std::ostream& print(std::ostream &o);

};

#endif
																	