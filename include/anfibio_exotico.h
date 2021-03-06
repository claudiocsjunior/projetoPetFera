/**
* @file   anfibio_exotico.h
* @brief  Classe responsável por gerenciar os anfibios exoticos pertencente ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _ANFIBIO_EXOTICO_H_  /**< Verifica se a variável _ANFIBIO_EXOTICO_H_ foi definida*/
#define _ANFIBIO_EXOTICO_H_	 /**< Define a variável _ANFIBIO_EXOTICO_H_*/

#include "anfibio.h" /**< Inclusão da classe anfibio.h*/
#include "exotico.h" /**< Inclusão da classe anfibio.h*/

class AnfibioExotico : public Anfibio, Exotico
{	
public:
	AnfibioExotico(); /**< Construtor padrão da Classe*/
	AnfibioExotico(int id, std::string nome, std::string cientifico, std::string classe, char sexo, float tamanho,
		std::string natureza, std::string dieta, std::string batismo, Veterinario veterinario, Tratador tratador,
		int total_mudas, std::string ultima_muda, std::string pais_origem, std::string ibama); /**< Construtor padrão da Classe*/
	~AnfibioExotico(); /**< Destrutor da Classe*/
	/**
	* @brief Efetua a sobrecarga do operador >>
	* @param[in] variável para o >>
	* @param[in] Constante para guardar o objeto
	* @return valor do cin
	*/
	friend istream& operator>>(istream &i, AnfibioExotico &a);
	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend ostream& operator<<(ostream &e, AnfibioExotico &a);

	/**
	* @brief Efetua a impressão de dados no formato para arquivo
	* @return string para impressão
	*/
	std::string escreverArquivo();

};

#endif
																	