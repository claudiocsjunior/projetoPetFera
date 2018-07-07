/**
* @file   petfera.h
* @brief  Classe responsável por gerenciar as funcionalidades do PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _PETFERA_H_  /**< Verifica se a variável _PETFERA_H_ foi definida*/
#define _PETFERA_H_	 /**< Define a variável _PETFERA_H_*/

#include "funcionario.h"
#include "veterinario.h"
#include "tratador.h"
#include "animal.h"
#include "anfibio.h"
#include "mamifero.h"
#include "reptil.h"
#include "ave.h"
#include "anfibio_exotico.h"
#include "anfibio.h"
#include "exotico.h"
#include "anfibio_nativo.h"
#include "animal_silvestre.h"
#include "mamifero_exotico.h"
#include "mamifero_nativo.h"
#include "reptil_exotico.h"
#include "reptil_nativo.h"
#include "ave_exotica.h"
#include "ave_nativa.h"
#include <string>
#include <map>
#include <fstream> /**< Inclusão da lib fstream*/
#include <vector> /**< Inclusão da lib vector*/
#include <memory> /**< Inclusão da lib memory*/

class PetFera
{

public:
	map<int, Funcionario> funcionarios;	
	map<int, AnfibioNativo> anfibios_nativos;
	map<int, AnfibioExotico> anfibios_exoticos;
	map<int, MamiferoNativo> mamiferos_nativos;
	map<int, MamiferoExotico> mamiferos_exoticos;
	map<int, ReptilNativo> repteis_nativos;
	map<int, ReptilExotico> repteis_exoticos;
	map<int, AveNativa> aves_nativas;
	map<int, AveExotica> aves_exoticas;
	map<int, Animal> mapeamento_busca;
	
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
	/**
	* @brief método de consulta com filtragem por veterinário ou tratador
	* @return 
	*/
	void consultar_filtro_veterinario_tratador();

	/**
	* @brief método de recuperação das informações dos arquivos
	* @return 
	*/
	void recuperar_informacoes_arquivo();
	/**
	* @brief método para salvar informações em arquivos
	* @return 
	*/
	void salvar_informacoes_arquivo();

	/**
	* @brief Função que quebra a linha lida do arquivo
	* @param[in] Recebe linha(str) do tipo string
	* @param[in] Recebe valor que será procurado para quebra do tipo char
	* @return result do tipo vetor
	*/
	std::vector<std::string> split_string(std::string str, const char* op); 
		

};

#endif
																	