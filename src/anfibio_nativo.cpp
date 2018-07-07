/**
* @file   anfibio_nativo.cpp
* @brief  Classe responsável por gerenciar os anfibios nativos pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  28/06/2018
* @date   28/06/2018
*/

#include "../include/anfibio_nativo.h"
#include "../include/anfibio.h"
#include "../include/nativo.h"

AnfibioNativo::AnfibioNativo():Anfibio("Nativo"){} /**< Construtor padrão da Classe*/
AnfibioNativo::AnfibioNativo(int id, std::string nome, std::string cientifico, std::string classe, char sexo, 
		float tamanho, std::string natureza, std::string dieta, std::string batismo, Veterinario veterinario, 
		Tratador tratador, int total_mudas, std::string ultima_muda, std::string uf_origem, 
		std::string autorizacao, std::string ibama):
		Anfibio(id, nome, cientifico, classe, sexo, tamanho, natureza, dieta, batismo, veterinario, tratador, 
			total_mudas, ultima_muda),
		Nativo(uf_origem, autorizacao, ibama){}
AnfibioNativo::~AnfibioNativo(){} /**< Destrutor da Classe*/


/**
* @brief Efetua a sobrecarga do operador >>
* @param[in] variável para o >>
* @param[in] Constante para guardar o objeto
* @return valor do cin
*/
istream& operator>>(istream &i, AnfibioNativo &a){
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

	cout << "TOTAL DE MUDAS: ";
	i >> a.total_mudas;

	cin.ignore();
	cout << "ULTIMA MUDA: ";
	getline(i, a.ultima_muda);

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
std::ostream& operator<< (std::ostream &o, AnfibioNativo &a) {
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
	  << "| TOTAL DE MUDAS: " <<  a.total_mudas
	  << "| ULTIMA MUDA: " <<  a.ultima_muda
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
std::string AnfibioNativo::escreverArquivo(){
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
	  + to_string(this->total_mudas) + ";"
	  + this->ultima_muda + ";"
	  + this->uf_origem + ";"
	  + this->autorizacao + ";"
	  +  this->ibama;
}															


																	