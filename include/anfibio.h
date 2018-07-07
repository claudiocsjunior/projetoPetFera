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
	Anfibio(std::string natureza); /**< Construtor padrão da Classe*/
	Anfibio(int id, std::string nome, std::string cientifico, std::string classe, char sexo, 
		float tamanho, std::string natureza, std::string dieta, std::string batismo, Veterinario veterinario, 
		Tratador tratador, int total_mudas, std::string ultima_muda);
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
	/**
	* @brief Método de alteração do total de mudas
	* @return 
	*/
	void setTotalmudas(int total_mudas);
	/**
	* @brief Método de alteração da ultima muda
	* @return 
	*/
	void setUltimaMuda(std::string ultima_muda);
	 
	/**
	* @brief Efetua a impressão dos dados
	* @param[in] variável para o <<
	* @return valor do cout
	*/
	std::ostream& print(std::ostream &o);

};

#endif
																	