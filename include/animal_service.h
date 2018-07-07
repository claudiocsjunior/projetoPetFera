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
#include "mamifero_exotico.h"
#include "mamifero_nativo.h"
#include "reptil_exotico.h"
#include "reptil_nativo.h"
#include "ave_exotica.h"
#include "ave_nativa.h"
#include "nativo.h"
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
	T editar(T &animal, PetFera* petFera);
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
			Animal::contador_animal_id++;
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
T AnimalService<T>::editar (T &animal, PetFera* petFera) { 
   T animal_de_retorno_erro;
   try{
   		animal_de_retorno_erro.setId(0);
   		cout << "______________________________________________________________" << endl;
		cout << "DADOS ATUAIS DO ANIMAL:" << endl;
		cout << animal << endl;
		cout << "______________________________________________________________" << endl;

   		if(!petFera->buscar_responsaveis(animal))
			return animal_de_retorno_erro;
	
		cin >> animal;
		if(cin.fail()){
			cout << "______________________________________________________________" << endl;
			throw invalid_argument("ARGUMENTO INVALIDO. ALGUM CAMPO FOI PREENCHIDO INADEQUADAMENTE.");
		}else{
			return animal;
		}


		
	}catch(invalid_argument &ex){
		cin.clear();
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cerr<<"Erro: "<<ex.what()<<endl;
		return animal_de_retorno_erro;
	}  
} 


#endif