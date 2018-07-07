/**
* @file   reptil_nativo.h
* @brief  Classe responsável por gerenciar os répteis nativos pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _REPTIL_NATIVO_H_  /**< Verifica se a variável _REPTIL_NATIVO_H_ foi definida*/
#define _REPTIL_NATIVO_H_	 /**< Define a variável _REPTIL_NATIVO_H_*/

#include "reptil.h" /**< Inclusão da classe anfibio.h*/
#include "nativo.h" /**< Inclusão da classe anfibio.h*/

class ReptilNativo : public Reptil, Nativo
{	
public:
	ReptilNativo(); /**< Construtor padrão da Classe*/
	ReptilNativo(int id, std::string nome, std::string cientifico, std::string classe, char sexo, float tamanho,
		std::string natureza, std::string dieta, std::string batismo, Veterinario veterinario, Tratador tratador,
		bool venenoso, std::string tipo_veneno,  std::string uf_origem, std::string autorizacao, 
		std::string ibama); /**< Construtor padrão da Classe*/
	~ReptilNativo(); /**< Destrutor da Classe*/
	/**
	* @brief Efetua a sobrecarga do operador >>
	* @param[in] variável para o >>
	* @param[in] Constante para guardar o objeto
	* @return valor do cin
	*/
	friend istream& operator>>(istream &i, ReptilNativo &a);
	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend ostream& operator<<(ostream &e, ReptilNativo &a);
	/**
	* @brief Efetua a impressão de dados no formato para arquivo
	* @return string para impressão
	*/
	std::string escreverArquivo();

};

#endif
																	