/**
* @file   animal.h
* @brief  Classe responsável por gerenciar os animais pertencentes a PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _ANIMAL_H_  /**< Verifica se a variável _ANIMAL_H_ foi definida*/
#define _ANIMAL_H_	 /**< Define a variável _ANIMAL_H_*/

#include <string>
#include "veterinario.h"
#include "tratador.h"

using namespace std; /**<Usa namespace std*/

class Animal
{

protected:
	int id;
	string classe;
	string nome;
	string cientifico;
	char sexo;
	float tamanho;
	string dieta;
	Veterinario veterinario;
	Tratador tratador;
	string batismo;
	
public:
	static int contador_animal_id;	
	Animal(); /**< Construtor padrão da Classe*/
	Animal(std::string classe); /**< Construtor paramatrizado da Classe*/
	virtual ~Animal(); /**< Destrutor da Classe*/
	/**
	* @brief Método de acesso para o atributo id
	* @return atributo id
	*/
	int getId();
	/**
	* @brief Método de acesso para o atributo classe
	* @return atributo classe
	*/
	string getClasse();
	/**
	* @brief Método de acesso para o atributo cientifico
	* @return atributo cientifico
	*/
	string getCientifico();
	/**
	* @brief Método de acesso para o atributo nome
	* @return atributo nome
	*/
	string getNome();
	/**
	* @brief Método de acesso para o atributo sexo
	* @return atributo sexo
	*/
	char getSexo();
	/**
	* @brief Método de acesso para o atributo tamanho
	* @return atributo tamanho
	*/
	int getTamanho();
	/**
	* @brief Método de acesso para o atributo dieta
	* @return atributo dieta
	*/
	string getDieta();
	/**
	* @brief Método de acesso para o atributo batismo
	* @return atributo batismo
	*/
	string getBatismo();
	/**
	* @brief Método de alteração do veterinario
	* @return 
	*/
	void setVeterinario(Veterinario &veterinario);
	/**
	* @brief Método de alteração do tratador
	* @return 
	*/
	void setTratador(Tratador &tratador);
	/**
	* @brief Método de alteração do id
	* @return 
	*/
	void setId(int id);
	/**
	* @brief Efetua a sobrecarga do operador >>
	* @param[in] variável para o >>
	* @param[in] Constante para guardar o objeto
	* @return valor do cin
	*/
	friend istream& operator>>(istream &i, Animal &a);

	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend ostream& operator<<(ostream &e, Animal &a);
	/**
	* @brief Efetua a sobrecarga do operador ==
	* @param[in] Constante para guardar o objeto a ser comparado
	* @return booleano
	*/
	bool operator ==(Animal &animal);

};


#endif