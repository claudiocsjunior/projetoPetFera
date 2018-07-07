/**
* @file   ave_nativa.h
* @brief  Classe responsável por gerenciar aves nativas pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _AVE_NATIVA_H_  /**< Verifica se a variável _AVE_NATIVA_H_ foi definida*/
#define _AVE_NATIVA_H_	 /**< Define a variável _AVE_NATIVA_H_*/

#include "ave.h" /**< Inclusão da classe anfibio.h*/
#include "nativo.h" /**< Inclusão da classe anfibio.h*/

class AveNativa : public Ave, Nativo
{	
public:
	AveNativa(); /**< Construtor padrão da Classe*/
	AveNativa(int id, std::string nome, std::string cientifico, std::string classe, char sexo, 
		float tamanho, std::string natureza, std::string dieta, std::string batismo, Veterinario veterinario, 
		Tratador tratador, float tamanho_bico, float envergadura, std::string uf_origem, std::string autorizacao, 
		std::string ibama);
	~AveNativa(); /**< Destrutor da Classe*/
	/**
	* @brief Efetua a sobrecarga do operador >>
	* @param[in] variável para o >>
	* @param[in] Constante para guardar o objeto
	* @return valor do cin
	*/
	friend istream& operator>>(istream &i, AveNativa &a);
	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend ostream& operator<<(ostream &e, AveNativa &a);
	/**
	* @brief Efetua a impressão de dados no formato para arquivo
	* @return string para impressão
	*/
	std::string escreverArquivo();

};

#endif
																	