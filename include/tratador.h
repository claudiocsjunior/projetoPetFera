/**
* @file   tratdor.h
* @brief  Classe responsável por gerenciar os tratadores pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _TRATADOR_H_  /**< Verifica se a variável _TRATADOR_H_ foi definida*/
#define _TRATADOR_H_	 /**< Define a variável _TRATADOR_H_*/

#include "funcionario.h" /**< Inclusão da classe funcionario.h*/

class Tratador : public Funcionario
{
public:
	Tratador(); /**< Construtor padrão da Classe*/
	~Tratador(); /**< Destrutor da Classe*/

};

#endif