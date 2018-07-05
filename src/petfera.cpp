/**
* @file   petfera.cpp
* @brief  Responsável por gerenciar as funcionalidades do PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#include "../include/petfera.h" /**< Inclusão da classe fruta.h*/
#include "../include/funcionario.h"
#include "../include/veterinario.h"
#include "../include/tratador.h"
#include "../include/animal.h"
#include "../include/anfibio.h"
#include "../include/mamifero.h"
#include "../include/reptil.h"
#include "../include/ave.h"
#include "../include/exception.h"
#include "iostream"
#include <typeinfo>
#include <limits>
#include <cstdlib>
#include <exception>	
#include "../include/adicionar_animal.h"

using namespace std;

/**
* @brief Construtor padrão do objeto
*/
PetFera::PetFera() {}

/**
* @brief Destrutor do objeto
*/
PetFera::~PetFera() {}

/**
* @brief método de inicio de petFera, resposável por gerenciar as funcionalidades
* @return
*/
void PetFera::funcionalidades(){
	int escolha;
	do{
		cout << "______________________________________________________________" << endl;
		cout << "---PETFERA FUNCIONALIDADES---" << endl;
		cout << endl;

		cout << " -- FUNCIONÁRIOS -- " << endl;
		cout << "	(1) +   ADMITIR" << endl;
		cout << "	(2) -   DEMITIR" << endl;
		cout << "	(3) =   LISTAR" << endl;
		cout << "	(4) *   ALTERAR DADOS" << endl;
		cout << endl;

		cout << " -- ANIMAIS -- " << endl;
		cout << "	(5) +   CADASTRAR NOVO" << endl;
		cout << "	(6) -   REMOVER (COMERCIALIZAR)" << endl;
		cout << "	(7) #   ALTERAR DADOS" << endl;
		cout << "	(8) =   CONSULTAR (ANIMAL OU CLASSE)" << endl;
		cout << "	(9) =   CONSULTAR (TRATADOR OU VETERINÁRIO)" << endl;
		cout << "	(10) =  LISTAR " << endl;

		cout << endl;
		cout << "	(0) SAIR" <<endl;
		cout << endl;

		cout << "OPÇÃO ESCOLHIDA: " ;
		try{

			cin >> escolha;
			if(cin.fail())
				throw invalid_argument("ARGUMENTO INVALIDO. SELECIONE UM DOS INTEIROS LISTADOS.");
			try{

				switch (escolha)
				{
					case 0:
						break;
					case 1:
						Adicionar_funcionario();
						break;
					case 2:
						remover_funcionario();
						break;
					case 3:
						listar_funcionarios();
						break;
					case 4:
						editar_funcionario();
						break;
					case 5:
						adicionar_animal();
						break;
					case 6:
						remover_comercializar_animal();
						break;
					case 7:
						editar_animal();
						break;
					case 8:
						consultar_filtro_animal_classe();
						break;
					case 9:
						break;
					case 10: 
						consultar_animais();
						break;		
					default:
						throw invalid_argument("ARGUMENTO INVALIDO. PARÂMETRO FORA DO ESCOPO DA LISTAGEM.");
				}
			}catch(invalid_argument &ex){
				system("clear");
				cout << "______________________________________________________________" << endl;
				cerr<<"Erro: "<<ex.what()<<endl;
			}
		}catch(invalid_argument &err){
			system("clear");
			cout << "______________________________________________________________" << endl;
			cerr<<"Erro: "<<err.what()<<endl;
			escolha = 10;
			cin.clear();
	    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}	

	}while(escolha > 0);
}

/**
* @brief método de adição de funcionários
* @return
*/
void PetFera::Adicionar_funcionario(){
	system("clear");
	cout << "______________________________________________________________" << endl;
	int escolha_tipo_funcionario;
	cout << "---FUNCIONÁRIOS---" << endl;
	cout << endl;

	cout << " -- SELECIONE A FUNÇÃO PARA ADMISSÃO -- " << endl;
	cout << "	(1) +  VETERINÁRIO" << endl;
	cout << "	(2) +  TRATADOR" << endl;
	cout << endl;

	cout << "	(0) VOLTAR" <<endl;
	cout << endl;

	cout << "opção escolhida: " ;
	try{
		cin >> escolha_tipo_funcionario;
		if(cin.fail())
			throw invalid_argument("ARGUMENTO INVALIDO. SELECIONE UM DOS INTEIROS LISTADOS.");
		try{


			switch (escolha_tipo_funcionario)
			{
				case 0:
					break;
				case 1:
					if(adicionar_veterinario()){
						system("clear");
						cout << "______________________________________________________________" << endl;
						cout << "DADOS CADASTRADOS COM SUCESSO!" << endl;
					}
					break;
				case 2:
					if(adicionar_tratador()){
						system("clear");
						cout << "______________________________________________________________" << endl;
						cout << "DADOS CADASTRADOS COM SUCESSO!" << endl;
					}
					break;
				default:
					throw invalid_argument("ARGUMENTO INVALIDO. PARÂMETRO FORA DO ESCOPO DA LISTAGEM.");
			}
		}catch(invalid_argument &ex){
			system("clear");
			cout << "______________________________________________________________" << endl;
			cerr<<"Erro: "<<ex.what()<<endl;
		}
	}catch(invalid_argument &err){
		system("clear");
		cin.clear();
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    	cout << "______________________________________________________________" << endl;
    	cerr<<"Erro: "<<err.what()<<endl;
    }
}

/**
* @brief método de adição de veterinários
* @return 
*/
bool PetFera::adicionar_veterinario(){
	system("clear");
	bool existe_igual = false;
	cout << "______________________________________________________________" << endl;
	Veterinario veterinario;
	try{
		cin >> veterinario;
		if(cin.fail()){
			system("clear");
			cout << "______________________________________________________________" << endl;
			throw invalid_argument("ARGUMENTO INVALIDO. ALGUM CAMPO FOI PREENCHIDO INADEQUADAMENTE.");
		}
		map<int,Funcionario>::iterator it;
		for (it = funcionarios.begin(); it != funcionarios.end(); ++it)
			if(it->second.getCpf() == veterinario.getCpf())
				existe_igual = true;
				
		if(!existe_igual){
			funcionarios[veterinario.getId()] = veterinario;
			Funcionario::contador_id++;
		}else{
			system("clear");
			cout << "______________________________________________________________" << endl;
			cout << "JÁ EXITE FUNCIONÁRIO CADASTRADO COM O MESMO CPF" << endl;
			return false;
		}
		return true;	
	}catch(invalid_argument &ex){
		cin.clear();
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cerr<<"Erro: "<<ex.what()<<endl;
		return false;
	}
	
}
/**
* @brief método de adição de tratador
* @return tratador
*/
bool PetFera::adicionar_tratador(){
	system("clear");
	bool existe_igual = false;
	cout << "______________________________________________________________" << endl;
	Tratador tratador;
	try{
		cin >> tratador;
		if(cin.fail()){
			system("clear");
			cout << "______________________________________________________________" << endl;
			throw invalid_argument("ARGUMENTO INVALIDO. ALGUM CAMPO FOI PREENCHIDO INADEQUADAMENTE.");
		}
		map<int,Funcionario>::iterator it;
		for (it = funcionarios.begin(); it != funcionarios.end(); ++it)
			if(it->second.getCpf() == tratador.getCpf())
				existe_igual = true;
				
		if(!existe_igual){
			funcionarios[tratador.getId()] = tratador;
			Funcionario::contador_id++;
		}else{
			system("clear");
			cout << "______________________________________________________________" << endl;
			cout << "JÁ EXITE FUNCIONÁRIO CADASTRADO COM O MESMO CPF" << endl;
			return false;
		}
		return true;	
	}catch(invalid_argument &ex){
		cin.clear();
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cerr<<"Erro: "<<ex.what()<<endl;
		return false;
	}
}

/**
* @brief método de listagem dos funcionários
* @return 
*/
void PetFera::listar_funcionarios(){
	system("clear");
	cout << "______________________________________________________________" << endl;
	cout << "---FUNCIONÁRIOS CADASTRADOS---" << endl;
	cout << endl;
	if(funcionarios.empty()){
		system("clear");
		cout << "______________________________________________________________" << endl;
		cout << "NÃO HÁ FUNCIONÁRIOS CADASTRADOS" << endl;
	}else{
		map<int,Funcionario>::iterator it;
			for (it = funcionarios.begin(); it != funcionarios.end(); ++it)
				cout << it->second << endl;
	}
}

/**
* @brief método de alteração dos dados dos funcionários
* @return 
*/
void PetFera::editar_funcionario(){
	try{
		system("clear");
		cout << "______________________________________________________________" << endl;
		if(!funcionarios.empty()){
			int id = busca_funcionario_cpf();

			if(id != -1){			
				map<int, Funcionario>::iterator busca = funcionarios.find(id);
				cout << "VALORES ATUAIS:" << endl;
				cout << busca->second << endl; 

				string nome;
				string cpf;
				int idade;
				string tipo_sanguineo;
				char fatorRH;
				string especialidade;

				cout << "DIGITE AS INFORMAÇÕES PARA ALTERAR O FUNCIONÁRIO:" << endl;
				cin.ignore();
				cout << "NOME: ";
				getline(cin, nome);

				cout << "CPF: ";
				cin >> cpf;

				cout << "IDADE: ";
				cin >> idade;

				cout << "TIPO SANGUINEO: ";
				cin >> tipo_sanguineo;

				cout << "FATOR RH: ";
				cin >> fatorRH;

				cin.ignore();
				cout << "ESPECIALIDADE: ";
				getline(cin, especialidade);

				if(cin.fail()){
					cout << endl;
					system("clear");
					cout << "______________________________________________________________" << endl;
					throw invalid_argument("ARGUMENTO INVALIDO. ALGUM CAMPO FOI PREENCHIDO INADEQUADAMENTE.");
				}else{
					if(busca_funcionario_cpf(cpf) == -1 || cpf == busca->second.getCpf()){
						busca->second.setNome(nome);
						busca->second.setCpf(cpf);
						busca->second.setIdade(idade);
						busca->second.setTipoSanguineo(tipo_sanguineo);
						busca->second.setFatorRH(fatorRH);
						busca->second.setEspecialidade(especialidade);
						system("clear");
						cout << "______________________________________________________________" << endl;
						cout << "DADOS ALTERADOS COM SUCESSO!" << endl;
					}else{
						system("clear");
						cout << "______________________________________________________________" << endl;
						cout << "ERRO AO EDITAR. JÁ EXISTE O CPF INFORMADO CADASTRADO NO SISTEMA." << endl;	
					}
					
				}
			}else{
				system("clear");
				cout << "______________________________________________________________" << endl;
				cout << "NÃO HÁ FUNCIONÁRIOS COM O CPF INFORMADO" << endl;	
			}	

		}else{
			system("clear");
			cout << "______________________________________________________________" << endl;
			cout << "NÃO HÁ FUNCIONÁRIOS CADASTRADOS" << endl;
		}
	}catch(invalid_argument &ex){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cerr<<"Erro: "<<ex.what()<<endl;
	}
}

/**
* @brief método de remoção dos funcionários
* @return 
*/
void PetFera::remover_funcionario(){
	try{
		int id = busca_funcionario_cpf();
		if(id != -1){
			this->funcionarios.erase(id);
			system("clear");
			cout << "______________________________________________________________" << endl;
			cout << "FUNCIONÁRIO REMOVIDO COM SUCESSO!" << endl; 
		}else{
			system("clear");
			throw invalid_argument("NÃO HÁ FUNCIONÁRIOS COM O CPF INFORMADO");
		}

	}catch(invalid_argument &ex){
		system("clear");
		cout << "______________________________________________________________" << endl;
		cerr<<"ERRO: "<<ex.what()<<endl;
	}
}	

/**
* @brief método de busca de funcionários por cpf
* @return 
*/
int PetFera::busca_funcionario_cpf(string cpf){
	int id = -1;
	if(cpf == ""){
		string cpf_novo = "";
		cout << "INFORME O CPF PARA BUSCA DO FUNCIONÁRIO:" << endl;
		cin >> cpf_novo;
		cpf = cpf_novo;
	}

	map<int,Funcionario>::iterator it;
	for (it = funcionarios.begin(); it != funcionarios.end(); ++it){
		if(it->second.getCpf() == cpf){
			id = it->second.getId();
			break;
		}
	}

	return id;
}

/**
* @brief método de adição de animais
* @return
*/
void PetFera::adicionar_animal(){
	system("clear");
	cout << "______________________________________________________________" << endl;
	int escolha_tipo_animal;
	cout << "---ANIMAIS---" << endl;
	cout << endl;

	cout << " -- SELECIONE O GRUPO AO QUAL O ANIMAL QUE SERÁ ADICIONADO, PERTENCE: -- " << endl;
	cout << "	(1) +  ANFÍBIO" << endl;
	cout << "	(2) +  MAMÍFERO" << endl;
	cout << "	(3) +  REPTIL" << endl;
	cout << "	(4) +  AVE" << endl;
	cout << endl;

	cout << "	(0) VOLTAR" <<endl;
	cout << endl;

	cout << "opção escolhida: " ;
	try{
		cin >> escolha_tipo_animal;
		if(cin.fail())
			throw invalid_argument("ARGUMENTO INVALIDO. SELECIONE UM DOS INTEIROS LISTADOS.");
		try{


			switch (escolha_tipo_animal)
			{
				case 0:
					break;
				case 1:
					adicionar_anfibio();
					break;
				case 2:
					adicionar_mamifero();
					break;
				case 3:
					adicionar_reptil();
					break;
				case 4:
					adicionar_ave();
					break;
				default:
					throw invalid_argument("ARGUMENTO INVALIDO. PARÂMETRO FORA DO ESCOPO DA LISTAGEM.");
			}
		}catch(invalid_argument &ex){
			system("clear");
			cout << "______________________________________________________________" << endl;
			cerr<<"Erro: "<<ex.what()<<endl;
		}
	}catch(invalid_argument &err){
		system("clear");
		cin.clear();
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    	cout << "______________________________________________________________" << endl;
    	cerr<<"Erro: "<<err.what()<<endl;
    }
}

/**
* @brief método de adição de um anfibio
* @return 
*/
void PetFera::adicionar_anfibio(){
	system("clear");
	Adicionar_animal<Anfibio> animal;
	Anfibio anfibio;
	Anfibio anfibio_retorno = animal.adicionar(anfibio, this);
	if(anfibio_retorno.getId() != -1)
		anfibios[anfibio_retorno.getId()] = anfibio_retorno;
}

/**
* @brief método de adição de um mamífero
* @return 
*/
void PetFera::adicionar_mamifero(){
	system("clear");
	Adicionar_animal<Mamifero> animal;
	Mamifero mamifero;
	Mamifero mamifero_retorno = animal.adicionar(mamifero, this);
	if(mamifero_retorno.getId() != -1)
		mamiferos[mamifero_retorno.getId()] = mamifero_retorno;
}
/**
* @brief método de adição de um réptil
* @return 
*/
void PetFera::adicionar_reptil(){
	system("clear");
	Adicionar_animal<Reptil> animal;
	Reptil reptil;
	Reptil reptil_retorno = animal.adicionar(reptil, this);
	if(reptil_retorno.getId() != -1)
		repteis[reptil_retorno.getId()] = reptil_retorno;
}

/**
* @brief método de adição de uma ave
* @return 
*/
void PetFera::adicionar_ave(){
	system("clear");
	Adicionar_animal<Ave> animal;
	Ave ave;
	Ave ave_retorno = animal.adicionar(ave, this);
	if(ave_retorno.getId() != -1)
		aves[ave_retorno.getId()] = ave_retorno;
}

/**
* @brief método que busca os responsaveis do animal
* @return booleano
*/
bool PetFera::buscar_responsaveis(Animal &animal){
	int adicionados = 0;
	cout << "______________________________________________________________" << endl;
	cout << "ADICIONAR TRATADOR RESPONSÁVEL (obrigatório):" << endl;
	int id_tratador = busca_funcionario_cpf();
	try{
		if(id_tratador != -1){
			map<int, Funcionario>::iterator busca = funcionarios.find(id_tratador);
			try{
				if(busca->second.getFuncao() != "Tratador")
					throw ErroNaoTratador();
			}catch(ErroNaoTratador &er){
				cout << "______________________________________________________________" << endl;
				cerr<<er.what()<<endl;
				return false;
			}	
			cout << "DADOS DO TRATADOR ADICIONADO:" << endl;
			cout << busca->second << endl;
			Tratador & t = static_cast<Tratador&>(busca->second);
			animal.setTratador(t);
			
			adicionados++; 
		}else{
			throw ErroBuscaTratador();
		}
	}catch(ErroBuscaTratador &er){
		cout << "______________________________________________________________" << endl;
		cerr<<er.what()<<endl;
		return false;
	}

	cout << "______________________________________________________________" << endl;
	cout << "ADICIONAR VETERINÁRIO RESPONSÁVEL (obrigatório):" << endl;
	int id_veterinario = busca_funcionario_cpf();
	try{
		if(id_veterinario != -1){
			map<int, Funcionario>::iterator busca = funcionarios.find(id_veterinario);
			try{
				if(busca->second.getFuncao() != "Veterinario")
					throw ErroNaoVeterinario();
			}catch(ErroNaoVeterinario &er){
				cout << "______________________________________________________________" << endl;
				cerr<<er.what()<<endl;
				return false;
			}	
			cout << "DADOS DO VETERINÁRIO ADICIONADO:" << endl;
			cout << busca->second << endl; 
			Veterinario & v = static_cast<Veterinario&>(busca->second);
			animal.setVeterinario(v);
			adicionados++; 
		}else{
			throw ErroBuscaVeterinario();
		}
	}catch(ErroBuscaVeterinario &er){
		cout << "______________________________________________________________" << endl;
		cerr<<er.what()<<endl;
		return false;
	}

	if(adicionados == 2)
		return true;

	return false;
}

/**
* @brief método de consulta de um animal sem filtros
* @return 
*/
void PetFera::consultar_animais(){
	system("clear");
	cout << "______________________________________________________________" << endl;
	cout << "---ANIMAIS DA PETFERA---" << endl;
	cout << endl;
	if(animais.empty()){
		system("clear");
		cout << "______________________________________________________________" << endl;
		cout << "NÃO HÁ ANIMAIS CADASTRADOS" << endl;
	}else{
		map<int,Animal>::iterator it;
			for (it = animais.begin(); it != animais.end(); ++it)
				cout << it->second << endl;
	}
}

/**
* @brief método de remoção de um animal
* @return 
*/
void PetFera::remover_comercializar_animal(){
	try{
		system("clear");
		cout << "______________________________________________________________" << endl;
		int id;
		cout << "INFORME O ID DO ANIMAL PARA EXCLUSÃO: " ;
		cin >> id;
		if(cin.fail())
			throw invalid_argument("ARGUMENTO INVALIDO. INFORME UM INTEIRO PARA O ID."); 
		
		bool encontrado = false; 

		map<int,Animal>::iterator it;
		for (it = animais.begin(); it != animais.end(); ++it){
			if(it->first == id){
				encontrado = true;
				break;
			}
		}
		if(encontrado){
			this->animais.erase(id);
			system("clear");
			cout << "______________________________________________________________" << endl;
			cout << "ANIMAL REMOVIDO/COMERCIALIZADO COM SUCESSO!" << endl; 
		}else{
			system("clear");
			throw invalid_argument("NÃO HÁ ANIMAL COM O ID INFORMADO");
		}

	}catch(invalid_argument &ex){
		system("clear");
		cout << "______________________________________________________________" << endl;
		cerr<<"ERRO: "<<ex.what()<<endl;
	}
}	

/**
* @brief método de alteração dos dados do animal
* @return 
*/
void PetFera::editar_animal(){
	try{
		system("clear");
		cout << "______________________________________________________________" << endl;
		if(!animais.empty()){
			int id;
			cout << "INFORME O ID DO ANIMAL PARA ALTERAÇÃO: " ;
			cin >> id;
			bool encontrado = false;
			map<int,Animal>::iterator it;
			for (it = animais.begin(); it != animais.end(); ++it){
				if(it->first == id){
					encontrado = true;
					break;
				}
			}
			if(encontrado){			
				map<int, Animal>::iterator busca = animais.find(id);
				cout << "VALORES ATUAIS:" << endl;
				cout << busca->second << endl; 

				string nome;
				string cientifico;
				char sexo;
				float tamanho;
				string dieta;
				string batismo;

				cout << "DIGITE AS INFORMAÇÕES PARA ALTERAR O ANIMAL:" << endl;
				cin.ignore();
				cout << "NOME: ";
				getline(cin, nome);

				cout << "CIENTIFICO: ";
				cin >> cientifico;

				cout << "SEXO: ";
				cin >> sexo;

				cout << "TAMANHO: ";
				cin >> tamanho;

				cout << "DIETA: ";
				cin >> dieta;

				cin.ignore();
				cout << "BATISMO: ";
				getline(cin, batismo);

				if(cin.fail()){
					cout << endl;
					system("clear");
					cout << "______________________________________________________________" << endl;
					throw invalid_argument("ARGUMENTO INVALIDO. ALGUM CAMPO FOI PREENCHIDO INADEQUADAMENTE.");
				}else{
					busca->second.setNome(nome);
					busca->second.setCientifico(cientifico);
					busca->second.setSexo(sexo);
					busca->second.setTamanho(tamanho);
					busca->second.setDieta(dieta);
					busca->second.setBatismo(batismo);

					cout << "______________________________________________________________" << endl;
					cout << "DADOS ALTERADOS COM SUCESSO!" << endl << endl;

					cout << "ALTERAR DETALHES: " << endl;
					bool detalhes_alterados = false;
					if(busca->second.getClasse() == "Amphibia"){
						map<int, Anfibio>::iterator busca_anfibio = anfibios.find(busca->second.getId());
						Adicionar_animal<map<int, Anfibio>::iterator> animal;
						detalhes_alterados = animal.alterar_detalhes(busca->second, busca_anfibio, this);
					}
					else if(busca->second.getClasse() == "Reptilia"){
						map<int, Reptil>::iterator busca_reptil = repteis.find(busca->second.getId());
						Adicionar_animal<map<int, Reptil>::iterator> animal;
						detalhes_alterados = animal.alterar_detalhes(busca->second, busca_reptil, this);
					}
					else if(busca->second.getClasse() == "Aves"){
						map<int, Ave>::iterator busca_ave = aves.find(busca->second.getId());
						Adicionar_animal<map<int, Ave>::iterator> animal;
						detalhes_alterados = animal.alterar_detalhes(busca->second, busca_ave, this);
					}
					else if(busca->second.getClasse() == "Mammalia"){
						map<int, Mamifero>::iterator busca_mamifero = mamiferos.find(busca->second.getId());
						Adicionar_animal<map<int, Mamifero>::iterator> animal;
						detalhes_alterados = animal.alterar_detalhes(busca->second, busca_mamifero, this);
					}	

					if(detalhes_alterados)
						cout << "DADOS ALTERADOS COM SUCESSO!" << endl;
					else
						cout << "ERRO NA ALTERAÇÃO DOS DADOS. ALGUM CAMPO COM ERRO DE PREENCHIMENTO." << endl;
				}
			}else{
				system("clear");
				cout << "______________________________________________________________" << endl;
				cout << "NÃO HÁ ANIMAIS COM ID INFORMADO" << endl;	
			}	

		}else{
			system("clear");
			cout << "______________________________________________________________" << endl;
			cout << "NÃO HÁ ANIMAIS CADASTRADOS" << endl;
		}
	}catch(invalid_argument &ex){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cerr<<"Erro: "<<ex.what()<<endl;
	}
}

/**
* @brief método de consulta com filtragem por animal ou por classe
* @return 
*/
void PetFera::consultar_filtro_animal_classe(){
	system("clear");
	cout << "______________________________________________________________" << endl;
	int escolha_tipo_filtro;
	cout << "---ANIMAIS---" << endl;
	cout << endl;

	cout << " -- SELECIONE UM FILTRO PARA CONSULTA -- " << endl;
	cout << "	(1) +  ANIMAL" << endl;
	cout << "	(2) +  CLASSE" << endl;
	cout << endl;

	cout << "	(0) VOLTAR" <<endl;
	cout << endl;

	cout << "opção escolhida: " ;
	try{
		cin >> escolha_tipo_filtro;
		if(cin.fail())
			throw invalid_argument("ARGUMENTO INVALIDO. SELECIONE UM DOS INTEIROS LISTADOS.");
		try{
			switch (escolha_tipo_filtro)
			{
				case 0:
					break;
				case 1:
					consultar_filtro_nome_animal();
					break;
				case 2:
					consultar_filtro_classe();
					break;
				default:
					throw invalid_argument("ARGUMENTO INVALIDO. PARÂMETRO FORA DO ESCOPO DA LISTAGEM.");
			}
		}catch(invalid_argument &ex){
			system("clear");
			cout << "______________________________________________________________" << endl;
			cerr<<"Erro: "<<ex.what()<<endl;
		}
	}catch(invalid_argument &err){
		system("clear");
		cin.clear();
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    	cout << "______________________________________________________________" << endl;
    	cerr<<"Erro: "<<err.what()<<endl;
    }
}
/**
* @brief método de consulta com filtragem por animal 
* @return 
*/
void PetFera::consultar_filtro_nome_animal(){
	system("clear");
	string nome = "";
	cout << "INFORME O NOME DE BUSCA PARA O ANIMAL:" << endl;
	cin >> nome;
	map<int, Animal>::iterator it;
	int quantidade_achados = 0;
	if(!animais.empty()){
		for (it = animais.begin(); it != animais.end(); ++it){
			if(it->second.getNome() == nome){
				if(it->second.getClasse() == "Amphibia"){
					map<int, Anfibio>::iterator busca_anfibio = anfibios.find(it->second.getId());
					cout << busca_anfibio->second << endl;
				}
				else if(it->second.getClasse() == "Reptilia"){
					map<int, Reptil>::iterator busca_reptil = repteis.find(it->second.getId());
					cout << busca_reptil->second << endl;
				}
				else if(it->second.getClasse() == "Aves"){
					map<int, Ave>::iterator busca_ave = aves.find(it->second.getId());
					cout << busca_ave->second << endl;
				}
				else if(it->second.getClasse() == "Mammalia"){
					map<int, Mamifero>::iterator busca_mamifero = mamiferos.find(it->second.getId());
					cout << busca_mamifero->second << endl;
				}	
				
				quantidade_achados++;
			}
				
		}
		if(quantidade_achados == 0){
			system("clear");
			cout << "______________________________________________________________" << endl;
			cout << "NÃO HÁ ANIMAIS COM O NOME INFORMADO" << endl;
		}	
	}else{
		system("clear");
		cout << "______________________________________________________________" << endl;
		cout << "NÃO HÁ ANIMAIS CADASTRADOS" << endl;
	}
}

/**
* @brief método de consulta com filtragem por classe 
* @return 
*/
void PetFera::consultar_filtro_classe(){
	system("clear");
	cout << "______________________________________________________________" << endl;
	int escolha_tipo_classe;
	cout << "---ANIMAIS---" << endl;
	cout << endl;

	cout << " -- SELECIONE A CLASSE PARA EFETUAR A FILTRAGEM -- " << endl;
	cout << "	(1) +  AMPHIBIA" << endl;
	cout << "	(2) +  REPTILIA" << endl;
	cout << "	(3) +  AVES" << endl;
	cout << "	(4) +  MAMMALIA" << endl;
	cout << endl;

	cout << "	(0) VOLTAR" <<endl;
	cout << endl;

	cout << "opção escolhida: " ;
	try{
		cin >> escolha_tipo_classe;
		if(cin.fail())
			throw invalid_argument("ARGUMENTO INVALIDO. SELECIONE UM DOS INTEIROS LISTADOS.");
		try{
			int quantidade_achados = 0;
			system("clear");
			cout << "______________________________________________________________" << endl;

				if(escolha_tipo_classe == 0){
					return;
				}
				else if(escolha_tipo_classe == 1){
					map<int, Anfibio>::iterator it;
					for (it = anfibios.begin(); it != anfibios.end(); ++it){
						cout << it->second << " ";	
						quantidade_achados++;
					}
				}
				else if(escolha_tipo_classe == 2){
					map<int,Reptil>::iterator it;
					for (it = repteis.begin(); it != repteis.end(); ++it){
						cout << it->second << " ";	
						quantidade_achados++;
					}
				}
				else if(escolha_tipo_classe == 3){
					map<int,Ave>::iterator it;
					for (it = aves.begin(); it != aves.end(); ++it){
						cout << it->second << " ";	
						quantidade_achados++;
					}
				}
				else if(escolha_tipo_classe == 4){
					map<int,Mamifero>::iterator it;
					for (it = mamiferos.begin(); it != mamiferos.end(); ++it){
						cout << it->second << " ";	
						quantidade_achados++;
					}	
				}else{
					throw invalid_argument("ARGUMENTO INVALIDO. PARÂMETRO FORA DO ESCOPO DA LISTAGEM.");
				}	

			 quantidade_achados > 0 ? cout << "" << endl : cout << "NÃO HÁ ANIMAIS CADASTRADOS PARA ESSA CLASSE" << endl;
		}catch(invalid_argument &ex){
			system("clear");
			cout << "______________________________________________________________" << endl;
			cerr<<"Erro: "<<ex.what()<<endl;
		}
	}catch(invalid_argument &err){
		system("clear");
		cin.clear();
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    	cout << "______________________________________________________________" << endl;
    	cerr<<"Erro: "<<err.what()<<endl;
    }
}
/**
* @brief método de recuperação das informações dos arquivos
* @return 
*/
void PetFera::recuperar_informacoes_arquivo(){
	cout << "AINDA NÃO HÁ DADOS" << endl;
}
/**
* @brief método para salvar informações em arquivos
* @return 
*/
void PetFera::salvar_informacoes_arquivo(){
	fstream arqFuncionarios;
	arqFuncionarios.open("funcionarios.csv");

	if (arqFuncionarios.is_open())
	{
		map<int,Funcionario>::iterator it;
		for (it = funcionarios.begin(); it != funcionarios.end(); ++it){
			arqFuncionarios << it->second.getId() << ";" << 
							   it->second.getFuncao() << ";" <<
							   it->second.getNome() << ";" <<
							   it->second.getCpf() << ";" <<
							   it->second.getIdade() << ";" <<
							   it->second.getTipoSanguineo() << ";" <<
							   it->second.getFatorRH() << ";" <<
							   it->second.getEspecialidade() << endl;	   
		}
	}else{
		cout << "Arquivo de funcionarios não foi encontrado. Verificar o caminho do arquivo." << endl;
	}
	arqFuncionarios.close();

	//criar a dos animais
}


