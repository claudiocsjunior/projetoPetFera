/**
* @file   adicionar_veterinario.h
* @brief  Classe responsável por gerenciar todas as adições de animais pertencentes ao PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _ADICIONAR_ANIMAL_H_  /**< Verifica se a variável _ADICIONAR_ANIMAL_H_ foi definida*/
#define _ADICIONAR_ANIMAL_H_	 /**< Define a variável _ADICIONAR_ANIMAL_H_*/

#include "petfera.h" /**< Inclusão da classe fruta.h*/
#include "funcionario.h"
#include "veterinario.h"
#include "tratador.h"
#include "animal.h"
#include "anfibio.h"
#include "iostream"
#include <typeinfo>
#include <limits>
#include <cstdlib>
#include <exception>	

template <typename T>
class Adicionar_animal
{
public:
	Adicionar_animal(); /**< Construtor padrão da Classe*/
	~Adicionar_animal(); /**< Destrutor da Classe*/
	T adicionar(T &animal, PetFera* petFera);
	bool alterar_detalhes(Animal &animal, T &tipo_animal,PetFera* petFera);
};

template <typename T>
Adicionar_animal<T>::Adicionar_animal(){}

template <typename T>
Adicionar_animal<T>::~Adicionar_animal(){} /**< Destrutor da Classe*/

template <typename T>
T Adicionar_animal<T>::adicionar (T &animal, PetFera* petFera) { 
   T animal_de_retorno_erro;
   try{
   		animal_de_retorno_erro.setId(-1);
   		if(!petFera->buscar_responsaveis(animal))
			return animal_de_retorno_erro;
		cout << "DADOS DO ANIMAL A SER ADICIONADO:" << endl;

	
		cin >> animal;
		if(cin.fail()){
			cout << "______________________________________________________________" << endl;
			throw invalid_argument("ARGUMENTO INVALIDO. ALGUM CAMPO FOI PREENCHIDO INADEQUADAMENTE.");
		}

		if(animal.preencher_atributos_locais()){
			petFera->animais[animal.getId()] = animal;
			Animal::contador_animal_id++;
			
			system("clear");
			cout << "______________________________________________________________" << endl;
			cout << "ANIMAL CADASTRADO COM SUCESSO" << endl;
			return animal;	
		}
		else{
			cout << "______________________________________________________________" << endl;
			throw invalid_argument("ARGUMENTO INVALIDO. ALGUM CAMPO FOI PREENCHIDO INADEQUADAMENTE.");
			return animal_de_retorno_erro;
		}
	}catch(invalid_argument &ex){
		cin.clear();
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cerr<<"Erro: "<<ex.what()<<endl;
		return animal_de_retorno_erro;
	}  
} 

template <typename T>
bool Adicionar_animal<T>::alterar_detalhes (Animal &animal, T &iterador, PetFera* petFera) { 
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