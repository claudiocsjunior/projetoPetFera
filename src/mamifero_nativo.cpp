/**
* @file   mamifero_nativo.cpp
* @brief  Classe responsável por gerenciar os mamiferos nativos pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  28/06/2018
* @date   28/06/2018
*/

#include "../include/mamifero_nativo.h"
#include "../include/mamifero.h"
#include "../include/nativo.h"

MamiferoNativo::MamiferoNativo():Mamifero("Nativo"){} /**< Construtor padrão da Classe*/
MamiferoNativo::MamiferoNativo(int id, std::string nome, std::string cientifico, std::string classe, char sexo, 
		float tamanho, std::string natureza, std::string dieta, std::string batismo, Veterinario veterinario, 
		Tratador tratador, std::string cor_pelo, std::string uf_origem, std::string autorizacao, 
		std::string ibama):
		Mamifero(id, nome, cientifico, classe, sexo, tamanho, natureza, dieta, batismo, veterinario, tratador, 
			cor_pelo),
		Nativo(uf_origem, autorizacao, ibama){}
MamiferoNativo::~MamiferoNativo(){} /**< Destrutor da Classe*/


/**
* @brief Efetua a sobrecarga do operador >>
* @param[in] variável para o >>
* @param[in] Constante para guardar o objeto
* @return valor do cin
*/
istream& operator>>(istream &i, MamiferoNativo &a){
	cin.ignore();
	cout << "DiGITE AS INFORMAÇÕES PARA CADASTRO DO MAMÍFERO MATIVO:" << endl;
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

	cout << "COR PELO: ";
	getline(i, a.cor_pelo);

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
std::ostream& operator<< (std::ostream &o, MamiferoNativo &a) {
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
	  << "| COR PELO: " <<  a.cor_pelo
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
std::string MamiferoNativo::escreverArquivo(){
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
	  + this->cor_pelo + ";"
	  + this->uf_origem + ";"
	  + this->autorizacao + ";"
	  + this->ibama;
}	


																	