/**
* @file   anfibio_exotico.cpp
* @brief  Classe responsável por gerenciar os anfibios exoticos pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  28/06/2018
* @date   28/06/2018
*/

#include "../include/ave_exotica.h"
#include "../include/ave.h"
#include "../include/exotico.h"
#include <iostream>

AveExotica::AveExotica():Ave("Exotico"){} /**< Construtor padrão da Classe*/
AveExotica::AveExotica(int id, std::string nome, std::string cientifico, std::string classe, char sexo, 
		float tamanho, std::string natureza, std::string dieta, std::string batismo, Veterinario veterinario, 
		Tratador tratador, float tamanho_bico, float envergadura, std::string pais_origem, std::string ibama):
		Ave(id, nome, cientifico, classe, sexo, tamanho, natureza, dieta, batismo, veterinario, 
		tratador, tamanho_bico, envergadura),
		Exotico(pais_origem, ibama){}
AveExotica::~AveExotica(){} /**< Destrutor da Classe*/

/**
* @brief Efetua a sobrecarga do operador >>
* @param[in] variável para o >>
* @param[in] Constante para guardar o objeto
* @return valor do cin
*/
istream& operator>>(istream &i, AveExotica &a){
	cin.ignore();
	cout << "DiGITE AS INFORMAÇÕES PARA CADASTRO DO ANFIBIO EXÓTICO:" << endl;
	cout << "NOME: ";
	getline(i, a.nome);

	cout << "NOME CIENTIFICO: ";
	getline(i, a.cientifico);

	cout << "SEXO: ";
	i >> a.sexo;

	cout << "TAMANHO: ";
	i >> a.tamanho;

	cin.ignore();
	cout << "DIETA ";
	getline(i, a.dieta);	

	cout << "BATISTMO: ";
	getline(i, a.batismo);

	cout << "TAMANHO BICO: ";
	i >> a.tamanho_bico;

	cout << "ENVERGADURA: ";
	i >> a.envergadura;

	cin.ignore();
	cout << "PAÍS ORIGEM: ";
	getline(i, a.pais_origem);

	cout << "IBAMA: ";
	getline(i, a.ibama);

	return i;
}

/**
* @brief Efetua a sobrecarga do operador <<
* @param[in] variável para o <<
* @param[in] Constante para guardar o objeto
* @return valor do cout
*/
std::ostream& operator<< (std::ostream &o, AveExotica &a) {
	o << "ID: "<< a.id
	  << "| NOME: " << a.nome
	  << "| NOME CIENTIFICO: " <<  a.cientifico
	  << "| CLASSE: " <<  a.classe
	  << "| SEXO: " << a.sexo
	  << "| TAMANHO: " <<  a.tamanho
	  << "| NATUREZA: " << a.natureza
	  << "| DIETA: " <<  a.dieta
	  << "| BATISMO: " <<  a.batismo
	  << "| VETERINÁRIO: " << a.veterinario.getId()
	  << "| TRATADOR: " << a.tratador.getId() 
	  << "| TAMANHO BICO: " <<  a.tamanho_bico
	  << "| ENVERGADURA: " <<  a.envergadura
	  << "| PAÍS ORIGEM: " <<  a.pais_origem
	  << "| IBAMA: " <<  a.ibama
	  << endl;
	return o;
}
	
/**
* @brief Efetua a impressão de dados no formato para arquivo
* @return string para impressão
*/
std::string AveExotica::escreverArquivo(){
	return to_string(this->id) + ";"
	  + this->nome + ";"
	  + this->cientifico + ";"
	  + this->classe + ";"
	  + this->sexo + ";"
	  + to_string(this->tamanho) + ";"
	  + this->natureza + ";"
	  + this->dieta + ";"
	  + this->batismo + ";"
	  + to_string(this->veterinario.getId()) + ";"
	  + to_string(this->tratador.getId()) + ";"
	  + to_string(this->tamanho_bico) + ";"
	  + to_string(this->envergadura) + ";"
	  + this->pais_origem + ";"
	  + this->ibama;
}																				