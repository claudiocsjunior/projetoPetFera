/**
* @file   mamifero_exotico.h
* @brief  Classe responsável por gerenciar os mamíferos exoticos pertencente ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _MAMIFERO_EXOTICO_H_  /**< Verifica se a variável _MAMIFERO_EXOTICO_H_ foi definida*/
#define _MAMIFERO_EXOTICO_H_	 /**< Define a variável _MAMIFERO_EXOTICO_H_*/

#include "mamifero.h" /**< Inclusão da classe anfibio.h*/
#include "exotico.h" /**< Inclusão da classe anfibio.h*/

class MamiferoExotico : public Mamifero, Exotico
{	
public:
	MamiferoExotico(); /**< Construtor padrão da Classe*/
	~MamiferoExotico(); /**< Destrutor da Classe*/
	/**
	* @brief Efetua a sobrecarga do operador >>
	* @param[in] variável para o >>
	* @param[in] Constante para guardar o objeto
	* @return valor do cin
	*/
	friend istream& operator>>(istream &i, MamiferoExotico &a);
	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend ostream& operator<<(ostream &e, MamiferoExotico &a);

};

#endif
																	