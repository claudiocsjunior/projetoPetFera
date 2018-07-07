/**
* @file   anfibio_exotico.cpp
* @brief  Classe responsável por gerenciar os anfibios exoticos pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  28/06/2018
* @date   28/06/2018
*/

#include "../include/reptil_exotico.h"
#include "../include/reptil.h"
#include "../include/exotico.h"
#include <iostream>

ReptilExotico::ReptilExotico():Reptil("Exotico"){} /**< Construtor padrão da Classe*/
ReptilExotico::ReptilExotico(int id, std::string nome, std::string cientifico, std::string classe, char sexo, float tamanho,
		std::string natureza, std::string dieta, std::string batismo, Veterinario veterinario, Tratador tratador,
		bool venenoso, std::string tipo_veneno, std::string pais_origem, std::string ibama):
		Reptil(id, nome, cientifico, classe, sexo, tamanho, natureza, dieta, batismo, veterinario, tratador, 
			venenoso, tipo_veneno),
		Exotico(pais_origem, ibama){}
ReptilExotico::~ReptilExotico(){} /**< Destrutor da Classe*/

/**
* @brief Efetua a sobrecarga do operador >>
* @param[in] variável para o >>
* @param[in] Constante para guardar o objeto
* @return valor do cin
*/
istream& operator>>(istream &i, ReptilExotico &a){
	cin.ignore();
	cout << "DiGITE AS INFORMAÇÕES PARA CADASTRO DO RÉPTIL EXÓTICO:" << endl;
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

	cout << "VENENOSO (1 - SIM | 0 - FALSE): ";
	i >> a.venenoso;

	cout << "TIPO VENENO: ";
	i >> a.tipo_veneno;

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
std::ostream& operator<< (std::ostream &o, ReptilExotico &a) {
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
	  << "| VENENOSO: " << a.venenoso
	  << "| TIPO VENENO:  " << a.tipo_veneno
	  << "| PAÍS ORIGEM: " <<  a.pais_origem
	  << "| IBAMA: " <<  a.ibama
	  << endl;
	return o;
}

/**
* @brief Efetua a impressão de dados no formato para arquivo
* @return string para impressão
*/
std::string ReptilExotico::escreverArquivo(){
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
	  + to_string(this->venenoso) + ";"
	  + this->tipo_veneno + ";"
	  + this->pais_origem + ";"
	  + this->ibama;
}	
																	