/**
* @file   veterinario.h
* @brief  Classe responsável por gerenciar os veterinários pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _VETERINARIO_H_  /**< Verifica se a variável _VETERINARIO_H_ foi definida*/
#define _VETERINARIO_H_	 /**< Define a variável _VETERINARIO_H_*/

#include "funcionario.h" /**< Inclusão da classe funcionario.h*/

class Veterinario : public Funcionario
{
public:
	Veterinario(); /**< Construtor padrão da Classe*/
	~Veterinario(); /**< Destrutor da Classe*/

};

#endif
																	