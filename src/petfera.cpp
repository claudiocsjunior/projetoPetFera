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
						break;
					case 7:
						break;
					case 8:
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

				cout << "DiGITE AS INFORMAÇÕES PARA ALTERAR O FUNCIONÁRIO:" << endl;
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
					if(busca_funcionario_cpf(cpf) == -1){
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
						cout << "ERRO AO ADITAR. JÁ EXISTE O CPF INFORMADO CADASTRADO NO SISTEMA." << endl;	
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

	cout << " -- SELECIONE A FUNÇÃO PARA ADMISSÃO -- " << endl;
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
					break;
				case 3:
					break;
				case 4:
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

void PetFera::adicionar_anfibio(){
	system("clear");
	Adicionar_animal<Anfibio> animal;
	Anfibio anfibio;
	if(!buscar_responsaveis(anfibio))
		return;

	auto animal_adicionar = animal.adicionar(anfibio);
	if(animal_adicionar.getId() != -1){
		animais[animal_adicionar.getId()] = animal_adicionar;
		Animal::contador_animal_id++;
		system("clear");
		cout << "______________________________________________________________" << endl;
		cout << "ANIMAL CADASTRADO COM SUCESSO" << endl;	
	}
	//
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
	cout << id_tratador << endl;
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
	cout << id_veterinario << endl;
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