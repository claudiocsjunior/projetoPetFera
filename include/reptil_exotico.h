/**
* @file   reptil_exotico.h
* @brief  Classe responsável por gerenciar os répteis exoticos pertencente ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _REPTIL_EXOTICO_H_  /**< Verifica se a variável _REPTIL_EXOTICO_H_ foi definida*/
#define _REPTIL_EXOTICO_H_	 /**< Define a variável _REPTIL_EXOTICO_H_*/

#include "reptil.h" /**< Inclusão da classe reptil.h*/
#include "exotico.h" /**< Inclusão da classe exotico.h*/

class ReptilExotico : public Reptil, Exotico
{	
public:
	ReptilExotico(); /**< Construtor padrão da Classe*/
	ReptilExotico(int id, std::string nome, std::string cientifico, std::string classe, char sexo, float tamanho,
		std::string natureza, std::string dieta, std::string batismo, Veterinario veterinario, Tratador tratador,
		bool venenoso, std::string tipo_veneno, std::string pais_origem, std::string ibama); /**< Construtor padrão da Classe*/
	~ReptilExotico(); /**< Destrutor da Classe*/
	/**
	* @brief Efetua a sobrecarga do operador >>
	* @param[in] variável para o >>
	* @param[in] Constante para guardar o objeto
	* @return valor do cin
	*/
	friend istream& operator>>(istream &i, ReptilExotico &a);
	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend ostream& operator<<(ostream &e, ReptilExotico &a);
	/**
	* @brief Efetua a impressão de dados no formato para arquivo
	* @return string para impressão
	*/
	std::string escreverArquivo();

};

#endif
																	