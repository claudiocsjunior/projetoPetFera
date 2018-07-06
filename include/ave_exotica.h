/**
* @file   ave_exotica.h
* @brief  Classe responsável por gerenciar as aves exoticas pertencente ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _AVE_EXOTICA_H_  /**< Verifica se a variável _AVE_EXOTICA_H_ foi definida*/
#define _AVE_EXOTICA_H_	 /**< Define a variável _AVE_EXOTICA_H_*/

#include "ave.h" /**< Inclusão da classe anfibio.h*/
#include "exotico.h" /**< Inclusão da classe anfibio.h*/

class AveExotica : public Ave, Exotico
{	
public:
	AveExotica(); /**< Construtor padrão da Classe*/
	~AveExotica(); /**< Destrutor da Classe*/
	/**
	* @brief Efetua a sobrecarga do operador >>
	* @param[in] variável para o >>
	* @param[in] Constante para guardar o objeto
	* @return valor do cin
	*/
	friend istream& operator>>(istream &i, AveExotica &a);
	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend ostream& operator<<(ostream &e, AveExotica &a);

};

#endif
																	