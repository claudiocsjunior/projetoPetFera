/**
* @file   mamifero_nativo.h
* @brief  Classe responsável por gerenciar os mamiferos nativos pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _MAMIFERO_NATIVO_H_  /**< Verifica se a variável _MAMIFERO_NATIVO_H_ foi definida*/
#define _MAMIFERO_NATIVO_H_	 /**< Define a variável _MAMIFERO_NATIVO_H_*/

#include "mamifero.h" /**< Inclusão da classe anfibio.h*/
#include "nativo.h" /**< Inclusão da classe anfibio.h*/

class MamiferoNativo : public Mamifero, Nativo
{	
public:
	MamiferoNativo(); /**< Construtor padrão da Classe*/
	MamiferoNativo(int id, std::string nome, std::string cientifico, std::string classe, char sexo, 
		float tamanho, std::string natureza, std::string dieta, std::string batismo, Veterinario veterinario, 
		Tratador tratador, std::string cor_pelo, std::string uf_origem, std::string autorizacao, 
		std::string ibama);
	~MamiferoNativo(); /**< Destrutor da Classe*/
	/**
	* @brief Efetua a sobrecarga do operador >>
	* @param[in] variável para o >>
	* @param[in] Constante para guardar o objeto
	* @return valor do cin
	*/
	friend istream& operator>>(istream &i, MamiferoNativo &a);
	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend ostream& operator<<(ostream &e, MamiferoNativo &a);
	/**
	* @brief Efetua a impressão de dados no formato para arquivo
	* @return string para impressão
	*/
	std::string escreverArquivo();

};

#endif
																	