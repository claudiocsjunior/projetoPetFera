/**
* @file   anfibio_nativo.h
* @brief  Classe responsável por gerenciar os anfibios nativos pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _ANFIBIO_NATIVO_H_  /**< Verifica se a variável _ANFIBIO_NATIVO_H_ foi definida*/
#define _ANFIBIO_NATIVO_H_	 /**< Define a variável _ANFIBIO_NATIVO_H_*/

#include "anfibio.h" /**< Inclusão da classe anfibio.h*/
#include "nativo.h" /**< Inclusão da classe anfibio.h*/

class AnfibioNativo : public Anfibio, Nativo
{	
public:
	AnfibioNativo(); /**< Construtor padrão da Classe*/
	~AnfibioNativo(); /**< Destrutor da Classe*/
	/**
	* @brief Efetua a sobrecarga do operador >>
	* @param[in] variável para o >>
	* @param[in] Constante para guardar o objeto
	* @return valor do cin
	*/
	friend istream& operator>>(istream &i, AnfibioNativo &a);
	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend ostream& operator<<(ostream &e, AnfibioNativo &a);

};

#endif
																	