/**
* @file   ave_nativa.cpp
* @brief  Classe responsável por gerenciar os aves nativas pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  28/06/2018
* @date   28/06/2018
*/

#include "../include/ave_nativa.h"
#include "../include/ave.h"
#include "../include/nativo.h"

AveNativa::AveNativa():Ave("Nativo"){} /**< Construtor padrão da Classe*/
AveNativa::AveNativa(int id, std::string nome, std::string cientifico, std::string classe, char sexo, 
		float tamanho, std::string natureza, std::string dieta, std::string batismo, Veterinario veterinario, 
		Tratador tratador, float tamanho_bico, float envergadura, std::string uf_origem, std::string autorizacao, 
		std::string ibama):
		Ave(id, nome, cientifico, classe, sexo, tamanho, natureza, dieta, batismo, veterinario, 
		tratador, tamanho_bico, envergadura),
		Nativo(uf_origem, autorizacao, ibama){}
AveNativa::~AveNativa(){} /**< Destrutor da Classe*/


/**
* @brief Efetua a sobrecarga do operador >>
* @param[in] variável para o >>
* @param[in] Constante para guardar o objeto
* @return valor do cin
*/
istream& operator>>(istream &i, AveNativa &a){
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
	cout << "Uf ORIGEM: ";
	getline(i, a.uf_origem);

	cout << "AUTORIZAÇÃO: ";
	getline(i, a.autorizacao);

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
std::ostream& operator<< (std::ostream &o, AveNativa &a) {
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
	  << "| Uf ORIGEM: " <<  a.uf_origem
	  << "| AUTORIZAÇÃO: " <<  a.autorizacao
	  << "| IBAMA: " <<  a.ibama
	  << endl;
	return o;
}

/**
* @brief Efetua a impressão de dados no formato para arquivo
* @return string para impressão
*/
std::string AveNativa::escreverArquivo(){
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
	  + this->uf_origem + ";"
	  + this->autorizacao + ";"
	  + this->ibama;
}


																	