/**
* @file   adicionar_veterinario.h
* @brief  Classe responsável por gerenciar todas as adições de animais pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _ANIMAL_SERVICE_H_  /**< Verifica se a variável _ANIMAL_SERVICE foi definida*/
#define _ANIMAL_SERVICE_H_	 /**< Define a variável _ANIMAL_SERVICE*/

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
#include <string>
#include <map>
#include <fstream> /**< Inclusão da lib fstream*/
#include <vector> /**< Inclusão da lib vector*/
#include <memory> /**< Inclusão da lib memory*/

template <typename T>
class AnimalService
{
public:
	AnimalService(); /**< Construtor padrão da Classe*/
	~AnimalService(); /**< Destrutor da Classe*/
	T adicionar(T &animal, PetFera* petFera);
	bool alterar_detalhes(Animal &animal, T &tipo_animal,PetFera* petFera);
};

template <typename T>
AnimalService<T>::AnimalService(){}

template <typename T>
AnimalService<T>::~AnimalService(){} /**< Destrutor da Classe*/

template <typename T>
T AnimalService<T>::adicionar (T &animal, PetFera* petFera) { 
   T animal_de_retorno_erro;
   try{
   		animal_de_retorno_erro.setId(0);
   		if(!petFera->buscar_responsaveis(animal))
			return animal_de_retorno_erro;
		cout << "DADOS DO ANIMAL A SER ADICIONADO:" << endl;

	
		cin >> animal;
		if(cin.fail()){
			cout << "______________________________________________________________" << endl;
			throw invalid_argument("ARGUMENTO INVALIDO. ALGUM CAMPO FOI PREENCHIDO INADEQUADAMENTE.");
		}else{
			system("clear");
			cout << "______________________________________________________________" << endl;
			cout << "ANIMAL SALVO COM SUCESSO!" << endl;
			return animal;
		}

		
	}catch(invalid_argument &ex){
		cin.clear();
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cerr<<"Erro: "<<ex.what()<<endl;
		return animal_de_retorno_erro;
	}  
} 

template <typename T>
bool AnimalService<T>::alterar_detalhes (Animal &animal, T &iterador, PetFera* petFera) { 
	iterador->second.setNome(animal.getNome());
	iterador->second.setCientifico(animal.getCientifico());
	iterador->second.setSexo(animal.getSexo());
	iterador->second.setTamanho(animal.getTamanho());
	iterador->second.setDieta(animal.getDieta());
	iterador->second.setBatismo(animal.getBatismo());
	iterador->second.preencher_atributos_locais();
	system("clear");
	cout << "______________________________________________________________" << endl;
	return true;
} 

#endif