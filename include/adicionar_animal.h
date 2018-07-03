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
class Adicionar_animal : public PetFera
{
public:
	Adicionar_animal(); /**< Construtor padrão da Classe*/
	~Adicionar_animal(); /**< Destrutor da Classe*/
	T adicionar(T &anfibio);
};

template <typename T>
Adicionar_animal<T>::Adicionar_animal(){}

template <typename T>
Adicionar_animal<T>::~Adicionar_animal(){} /**< Destrutor da Classe*/

template <typename T>
T Adicionar_animal<T>::adicionar (T &animal) { 
   T animal_retorno;
   animal_retorno.setId(-1);
   try{
		cout << "DADOS DO ANIMAL A SER ADICIONADO:" << endl;

	
		cin >> animal;
		if(cin.fail()){
			cout << "______________________________________________________________" << endl;
			throw invalid_argument("ARGUMENTO INVALIDO. ALGUM CAMPO FOI PREENCHIDO INADEQUADAMENTE.");
			return animal_retorno;
		}

		if(animal.preencher_atributos_locais()){
			animais[animal.getId()] = animal;
			cout << animais[animal.getId()] << endl;
			cout << "TOTAL MUDAS: " << animal.getTotalMudas() << endl;
			return animal;
		}
		else{
			cout << "______________________________________________________________" << endl;
			throw invalid_argument("ARGUMENTO INVALIDO. ALGUM CAMPO FOI PREENCHIDO INADEQUADAMENTE.");
			return animal_retorno;
		}
	}catch(invalid_argument &ex){
		cin.clear();
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cerr<<"Erro: "<<ex.what()<<endl;
		return animal_retorno;
	}  
} 

#endif