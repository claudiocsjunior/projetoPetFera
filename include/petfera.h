/**
* @file   petfera.h
* @brief  Classe responsável por gerenciar as funcionalidades do PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _PETFERA_H_  /**< Verifica se a variável _PETFERA_H_ foi definida*/
#define _PETFERA_H_	 /**< Define a variável _PETFERA_H_*/

#include "../include/funcionario.h"
#include "../include/veterinario.h"
#include "../include/tratador.h"
#include "../include/animal.h"
#include "../include/anfibio.h"
#include "../include/mamifero.h"
#include "../include/reptil.h"
#include "../include/ave.h"
#include <string>
#include <map>

class PetFera
{

public:
	map<int, Funcionario> funcionarios;	
	map<int, Animal> animais;
	map<int, Anfibio> anfibios;
	map<int, Mamifero> mamiferos;
	map<int, Reptil> repteis;
	map<int, Ave> aves;

	PetFera(); /**< Construtor padrão da Classe*/
	~PetFera(); /**< Destrutor da Classe*/
	/**
	* @brief método de inicio de petFera, resposável por gerenciar as funcionalidades
	* @return
	*/
	void funcionalidades();
	/**
	* @brief método de adição de funcionários
	* @return
	*/
	void Adicionar_funcionario();
	/**
	* @brief método de adição de veterinários
	* @return booleano
	*/
	bool adicionar_veterinario();
	/**
	* @brief método de adição de tratador
	* @return booleano
	*/
	bool adicionar_tratador();
	/**
	* @brief método de listagem dos funcionários
	* @return 
	*/
	void listar_funcionarios();
	/**
	* @brief método de alteração dos dados dos funcionários
	* @return 
	*/
	void editar_funcionario();
	/**
	* @brief método de remoção dos funcionários
	* @return 
	*/
	void remover_funcionario();
	/**
	* @brief método de busca de funcionários por cpf
	* @return 
	*/
	int busca_funcionario_cpf(std::string cpf = "");
	/**
	* @brief método de adição de animais
	* @return
	*/
	void adicionar_animal();
	/**
	* @brief método de adição de anfíbios
	* @return
	*/
	void adicionar_anfibio();
	/**
	* @brief método de adição de um mamífero
	* @return 
	*/
	void adicionar_mamifero();
	/**
	* @brief método de adição de um réptil
	* @return 
	*/
	void adicionar_reptil();
	/**
	* @brief método de adição de uma ave
	* @return 
	*/
	void adicionar_ave();
	/**
	* @brief método que busca os responsaveis do animal
	* @return booleano
	*/
	bool buscar_responsaveis(Animal &animal);
	/**
	* @brief método de remoção de um animal
	* @return 
	*/
	void remover_comercializar_animal();
	/**
	* @brief método de consulta de um animal sem filtros
	* @return 
	*/
	void consultar_animais();
	/**
	* @brief método de alteração dos dados do animal
	* @return 
	*/
	void editar_animal();
	/**
	* @brief método de consulta com filtragem por animal ou por classe
	* @return 
	*/
	void consultar_filtro_animal_classe();
	/**
	* @brief método de consulta com filtragem por animal 
	* @return 
	*/
	void consultar_filtro_nome_animal();
	/**
	* @brief método de consulta com filtragem por classe 
	* @return 
	*/
	void consultar_filtro_classe();
		

};

#endif
																	