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
#include "../include/animal_service.h"
#include <vector> /**< Inclusão da lib vector*/
#include <memory> /**< Inclusão da lib memory*/

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
						consultar_filtro_veterinario_tratador();
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
	cout << "______________________________________________________________" << endl;
	int escolha_natureza;
	cout << "---ADICIONAR ANFIBIO---" << endl;
	cout << endl;

	cout << " -- SELECIONE A NATUREZA DO ANIMAL: -- " << endl;
	cout << "	(1) +  NATIVO" << endl;
	cout << "	(2) +  EXOTICO" << endl;
	cout << endl;

	cout << "	(0) VOLTAR" <<endl;
	cout << endl;

	cout << "opção escolhida: " ;
	try{
		cin >> escolha_natureza;
		if(cin.fail())
			throw invalid_argument("ARGUMENTO INVALIDO. SELECIONE UM DOS INTEIROS LISTADOS.");
		try{
			system("clear");
			if(escolha_natureza == 0)
				return;
			else if(escolha_natureza == 1){
				AnimalService<AnfibioNativo> animal;
				AnfibioNativo anfibio_nativo;
				AnfibioNativo anfibio_nativo_retorno = animal.adicionar(anfibio_nativo, this);
				if(anfibio_nativo_retorno.getId() != 0){
					anfibios_nativos[anfibio_nativo_retorno.getId()] = anfibio_nativo_retorno;
					Animal & animalBasico = static_cast<Animal&>(anfibio_nativo_retorno);
					mapeamento_busca[anfibio_nativo_retorno.getId()] = animalBasico;
				}


			}
			else if(escolha_natureza == 2){
				AnimalService<AnfibioExotico> animal;
				AnfibioExotico anfibio_exotico;
				AnfibioExotico anfibio_exotico_retorno = animal.adicionar(anfibio_exotico, this);
				if(anfibio_exotico_retorno.getId() != 0){
					anfibios_exoticos[anfibio_exotico_retorno.getId()] = anfibio_exotico_retorno;
					Animal & animalBasico = static_cast<Animal&>(anfibio_exotico_retorno);
					mapeamento_busca[anfibio_exotico_retorno.getId()] = animalBasico;
				}
			}	
			else{
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
* @brief método de adição de um mamífero
* @return 
*/
void PetFera::adicionar_mamifero(){
	system("clear");
	cout << "______________________________________________________________" << endl;
	int escolha_natureza;
	cout << "---ADICIONAR MAMIFERO---" << endl;
	cout << endl;

	cout << " -- SELECIONE A NATUREZA DO ANIMAL: -- " << endl;
	cout << "	(1) +  NATIVO" << endl;
	cout << "	(2) +  EXOTICO" << endl;
	cout << endl;

	cout << "	(0) VOLTAR" <<endl;
	cout << endl;

	cout << "opção escolhida: " ;
	try{
		cin >> escolha_natureza;
		if(cin.fail())
			throw invalid_argument("ARGUMENTO INVALIDO. SELECIONE UM DOS INTEIROS LISTADOS.");
		try{
			system("clear");
			if(escolha_natureza == 0)
				return;
			else if(escolha_natureza == 1){
				AnimalService<MamiferoNativo> animal;
				MamiferoNativo mamifero_nativo;
				MamiferoNativo mamifero_nativo_retorno = animal.adicionar(mamifero_nativo, this);
				if(mamifero_nativo_retorno.getId() != 0){
					mamiferos_nativos[mamifero_nativo_retorno.getId()] = mamifero_nativo_retorno;
					Animal & animalBasico = static_cast<Animal&>(mamifero_nativo_retorno);
					mapeamento_busca[mamifero_nativo_retorno.getId()] = animalBasico;
				}


			}
			else if(escolha_natureza == 2){
				AnimalService<MamiferoExotico> animal;
				MamiferoExotico mamifero_exotico;
				MamiferoExotico mamifero_exotico_retorno = animal.adicionar(mamifero_exotico, this);
				if(mamifero_exotico_retorno.getId() != 0){
					mamiferos_exoticos[mamifero_exotico_retorno.getId()] = mamifero_exotico_retorno;
					Animal & animalBasico = static_cast<Animal&>(mamifero_exotico_retorno);
					mapeamento_busca[mamifero_exotico_retorno.getId()] = animalBasico;
				}

			}	
			else{
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
* @brief método de adição de um réptil
* @return 
*/
void PetFera::adicionar_reptil(){
	system("clear");
	cout << "______________________________________________________________" << endl;
	int escolha_natureza;
	cout << "---ADICIONAR RÉPTIL---" << endl;
	cout << endl;

	cout << " -- SELECIONE A NATUREZA DO ANIMAL: -- " << endl;
	cout << "	(1) +  NATIVO" << endl;
	cout << "	(2) +  EXOTICO" << endl;
	cout << endl;

	cout << "	(0) VOLTAR" <<endl;
	cout << endl;

	cout << "opção escolhida: " ;
	try{
		cin >> escolha_natureza;
		if(cin.fail())
			throw invalid_argument("ARGUMENTO INVALIDO. SELECIONE UM DOS INTEIROS LISTADOS.");
		try{
			system("clear");
			if(escolha_natureza == 0)
				return;
			else if(escolha_natureza == 1){
				AnimalService<ReptilNativo> animal;
				ReptilNativo reptil_nativo;
				ReptilNativo reptil_nativo_retorno = animal.adicionar(reptil_nativo, this);
				if(reptil_nativo_retorno.getId() != 0){
					repteis_nativos[reptil_nativo_retorno.getId()] = reptil_nativo_retorno;
					Animal & animalBasico = static_cast<Animal&>(reptil_nativo_retorno);
					mapeamento_busca[reptil_nativo_retorno.getId()] = animalBasico;
				}


			}
			else if(escolha_natureza == 2){
				AnimalService<ReptilExotico> animal;
				ReptilExotico reptil_exotico;
				ReptilExotico reptil_exotico_retorno = animal.adicionar(reptil_exotico, this);
				if(reptil_exotico_retorno.getId() != 0){
					repteis_exoticos[reptil_exotico_retorno.getId()] = reptil_exotico_retorno;
					Animal & animalBasico = static_cast<Animal&>(reptil_exotico_retorno);
					mapeamento_busca[reptil_exotico_retorno.getId()] = animalBasico;
				}

			}	
			else{
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
* @brief método de adição de uma ave
* @return 
*/

void PetFera::adicionar_ave(){
	system("clear");
	cout << "______________________________________________________________" << endl;
	int escolha_natureza;
	cout << "---ADICIONAR AVE---" << endl;
	cout << endl;

	cout << " -- SELECIONE A NATUREZA DO ANIMAL: -- " << endl;
	cout << "	(1) +  NATIVO" << endl;
	cout << "	(2) +  EXOTICO" << endl;
	cout << endl;

	cout << "	(0) VOLTAR" <<endl;
	cout << endl;

	cout << "opção escolhida: " ;
	try{
		cin >> escolha_natureza;
		if(cin.fail())
			throw invalid_argument("ARGUMENTO INVALIDO. SELECIONE UM DOS INTEIROS LISTADOS.");
		try{
			system("clear");
			if(escolha_natureza == 0)
				return;
			else if(escolha_natureza == 1){
				AnimalService<AveNativa> animal;
				AveNativa ave_nativo;
				AveNativa ave_nativo_retorno = animal.adicionar(ave_nativo, this);
				if(ave_nativo_retorno.getId() != 0){
					aves_nativas[ave_nativo_retorno.getId()] = ave_nativo_retorno;
					Animal & animalBasico = static_cast<Animal&>(ave_nativo_retorno);
					mapeamento_busca[ave_nativo_retorno.getId()] = animalBasico;
				}


			}

			else if(escolha_natureza == 2){
				AnimalService<AveExotica> animal;
				AveExotica ave_exotica;
				AveExotica ave_exotica_retorno = animal.adicionar(ave_exotica, this);
				if(ave_exotica_retorno.getId() != 0){
					aves_exoticas[ave_exotica_retorno.getId()] = ave_exotica_retorno;
					Animal & animalBasico = static_cast<Animal&>(ave_exotica_retorno);
					mapeamento_busca[ave_exotica_retorno.getId()] = animalBasico;
				}

			}	
			else{
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
	system("clear");
	cout << "______________________________________________________________" << endl;
	cout << "---ANFIBIOS---" << endl;
		map<int,AnfibioExotico>::iterator ae;
			for (ae = anfibios_exoticos.begin(); ae != anfibios_exoticos.end(); ++ae)
				cout << ae->second << endl;
		map<int,AnfibioNativo>::iterator an;
			for (an = anfibios_nativos.begin(); an != anfibios_nativos.end(); ++an)
				cout << an->second << endl;	
	cout << "______________________________________________________________" << endl;
	cout << "______________________________________________________________" << endl;
	cout << "---MAMÍFEROS---" << endl;
		map<int,MamiferoExotico>::iterator me;
			for (me = mamiferos_exoticos.begin(); me != mamiferos_exoticos.end(); ++me)
				cout << me->second << endl;
		map<int,MamiferoNativo>::iterator mn;
			for (mn = mamiferos_nativos.begin(); mn != mamiferos_nativos.end(); ++mn)
				cout << mn->second << endl;	
	cout << "______________________________________________________________" << endl;
	cout << "______________________________________________________________" << endl;
	cout << "---RÉPTEIS---" << endl;
		map<int, ReptilExotico>::iterator re;
			for (re = repteis_exoticos.begin(); re != repteis_exoticos.end(); ++re)
				cout << re->second << endl;
		map<int,ReptilNativo>::iterator rn;
			for (rn = repteis_nativos.begin(); rn != repteis_nativos.end(); ++rn)
				cout << rn->second << endl;	
	cout << "______________________________________________________________" << endl;
	cout << "______________________________________________________________" << endl;
	cout << "---AVES---" << endl;
		map<int,AveExotica>::iterator ae1;
			for (ae1 = aves_exoticas.begin(); ae1 != aves_exoticas.end(); ++ae1)
				cout << ae1->second << endl;
		map<int,AveNativa>::iterator an1;
			for (an1 = aves_nativas.begin(); an1 != aves_nativas.end(); ++an1)
				cout << an1->second << endl;	
	cout << "______________________________________________________________" << endl;		
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
		if(!cin.fail()){
			map<int, Animal>::iterator it = mapeamento_busca.find(id);
			if (it != mapeamento_busca.end()){
				if(it->second.getClasse() == "Amphibia" && it->second.getNatureza() == "Nativo"){
					map<int, AnfibioNativo>::iterator an = anfibios_nativos.find(id);
					if (an != anfibios_nativos.end())
    					anfibios_nativos.erase(an);

				}else if(it->second.getClasse() == "Amphibia" && it->second.getNatureza() == "Exotico"){
					map<int, AnfibioExotico>::iterator ae = anfibios_exoticos.find(id);
					if (ae != anfibios_exoticos.end())
    					anfibios_exoticos.erase(ae);

				}else if(it->second.getClasse() == "Mammalia" && it->second.getNatureza() == "Nativo"){
					map<int, MamiferoNativo>::iterator mn = mamiferos_nativos.find(id);
					if (mn != mamiferos_nativos.end())
    					mamiferos_nativos.erase(mn);

				}else if(it->second.getClasse() == "Mammalia" && it->second.getNatureza() == "Exotico"){
					map<int, MamiferoExotico>::iterator me = mamiferos_exoticos.find(id);
					if (me != mamiferos_exoticos.end())
    					mamiferos_exoticos.erase(me);

				}else if(it->second.getClasse() == "Reptilia" && it->second.getNatureza() == "Nativo"){
					map<int, ReptilNativo>::iterator rn = repteis_nativos.find(id);
					if (rn != repteis_nativos.end())
    					repteis_nativos.erase(rn);

				}else if(it->second.getClasse() == "Reptilia" && it->second.getNatureza() == "Exotico"){
					map<int, ReptilExotico>::iterator re = repteis_exoticos.find(id);
					if (re != repteis_exoticos.end())
    					repteis_exoticos.erase(re);

				}else if(it->second.getClasse() == "Aves" && it->second.getNatureza() == "Nativo"){
					map<int, AveNativa>::iterator an = aves_nativas.find(id);
					if (an != aves_nativas.end())
    					aves_nativas.erase(an);

				}else if(it->second.getClasse() == "Aves" && it->second.getNatureza() == "Exotico"){
					map<int, AveExotica>::iterator aex = aves_exoticas.find(id);
					if (aex != aves_exoticas.end())
    					aves_exoticas.erase(aex);
				}	

				mapeamento_busca.erase(it);
				
				system("clear");
				cout << "______________________________________________________________" << endl;
				cout << "ANIMAL EXCLUIDO COM SUCESSO!" << endl;			
			}else{
				system("clear");
				cout << "______________________________________________________________" << endl;
				throw invalid_argument("ANIMAL NÃO ENCONTRADO."); 
			}
		}else{
			system("clear");
			cout << "______________________________________________________________" << endl;
			throw invalid_argument("ARGUMENTO INVALIDO. INFORME UM INTEIRO PARA O ID."); 
			

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
		if(!mapeamento_busca.empty()){
			int id;
			cout << "INFORME O ID DO ANIMAL PARA ALTERAÇÃO: " ;
			cin >> id;
			if(!cin.fail()){
				map<int, Animal>::iterator it = mapeamento_busca.find(id);
				if (it != mapeamento_busca.end()){
					if(it->second.getClasse() == "Amphibia" && it->second.getNatureza() == "Nativo"){
						map<int, AnfibioNativo>::iterator an = anfibios_nativos.find(id);
						AnimalService<AnfibioNativo> animal;
						AnfibioNativo anfibio_nativo_retorno = animal.editar(an->second, this);

						if(anfibio_nativo_retorno.getId() != 0){
							anfibios_nativos[anfibio_nativo_retorno.getId()] = anfibio_nativo_retorno;
							Animal & animalBasico = static_cast<Animal&>(anfibio_nativo_retorno);
							mapeamento_busca[anfibio_nativo_retorno.getId()] = animalBasico;
						}


					}else if(it->second.getClasse() == "Amphibia" && it->second.getNatureza() == "Exotico"){
						map<int, AnfibioExotico>::iterator ae = anfibios_exoticos.find(id);
						AnimalService<AnfibioExotico> animal;
						AnfibioExotico anfibio_exotico_retorno = animal.editar(ae->second, this);

						if(anfibio_exotico_retorno.getId() != 0){
							anfibios_exoticos[anfibio_exotico_retorno.getId()] = anfibio_exotico_retorno;
							Animal & animalBasico = static_cast<Animal&>(anfibio_exotico_retorno);
							mapeamento_busca[anfibio_exotico_retorno.getId()] = animalBasico;
						}

					}else if(it->second.getClasse() == "Mammalia" && it->second.getNatureza() == "Nativo"){
						map<int, MamiferoNativo>::iterator mn = mamiferos_nativos.find(id);
						AnimalService<MamiferoNativo> animal;
						MamiferoNativo mamifero_nativo_retorno = animal.editar(mn->second, this);

						if(mamifero_nativo_retorno.getId() != 0){
							mamiferos_nativos[mamifero_nativo_retorno.getId()] = mamifero_nativo_retorno;
							Animal & animalBasico = static_cast<Animal&>(mamifero_nativo_retorno);
							mapeamento_busca[mamifero_nativo_retorno.getId()] = animalBasico;
						}

					}else if(it->second.getClasse() == "Mammalia" && it->second.getNatureza() == "Exotico"){
						map<int, MamiferoExotico>::iterator me = mamiferos_exoticos.find(id);
						AnimalService<MamiferoExotico> animal;
						MamiferoExotico mamifero_exotico_retorno = animal.editar(me->second, this);

						if(mamifero_exotico_retorno.getId() != 0){
							mamiferos_exoticos[mamifero_exotico_retorno.getId()] = mamifero_exotico_retorno;
							Animal & animalBasico = static_cast<Animal&>(mamifero_exotico_retorno);
							mapeamento_busca[mamifero_exotico_retorno.getId()] = animalBasico;
						}

					}else if(it->second.getClasse() == "Reptilia" && it->second.getNatureza() == "Nativo"){
						map<int, ReptilNativo>::iterator rn = repteis_nativos.find(id);
						AnimalService<ReptilNativo> animal;
						ReptilNativo mamifero_nativo_retorno = animal.editar(rn->second, this);

						if(mamifero_nativo_retorno.getId() != 0){
							repteis_nativos[mamifero_nativo_retorno.getId()] = mamifero_nativo_retorno;
							Animal & animalBasico = static_cast<Animal&>(mamifero_nativo_retorno);
							mapeamento_busca[mamifero_nativo_retorno.getId()] = animalBasico;
						}

					}else if(it->second.getClasse() == "Reptilia" && it->second.getNatureza() == "Exotico"){
						map<int, ReptilExotico>::iterator re = repteis_exoticos.find(id);
						AnimalService<ReptilExotico> animal;
						ReptilExotico reptil_exotico_retorno = animal.editar(re->second, this);

						if(reptil_exotico_retorno.getId() != 0){
							repteis_exoticos[reptil_exotico_retorno.getId()] = reptil_exotico_retorno;
							Animal & animalBasico = static_cast<Animal&>(reptil_exotico_retorno);
							mapeamento_busca[reptil_exotico_retorno.getId()] = animalBasico;
						}

					}else if(it->second.getClasse() == "Aves" && it->second.getNatureza() == "Nativo"){
						map<int, AveNativa>::iterator an = aves_nativas.find(id);
						AnimalService<AveNativa> animal;
						AveNativa ave_nativa_retorno = animal.editar(an->second, this);

						if(ave_nativa_retorno.getId() != 0){
							aves_nativas[ave_nativa_retorno.getId()] = ave_nativa_retorno;
							Animal & animalBasico = static_cast<Animal&>(ave_nativa_retorno);
							mapeamento_busca[ave_nativa_retorno.getId()] = animalBasico;
						}

					}else if(it->second.getClasse() == "Aves" && it->second.getNatureza() == "Exotico"){
						map<int, AveExotica>::iterator aex = aves_exoticas.find(id);
						AnimalService<AveExotica> animal;
						AveExotica ave_exotica_retorno = animal.editar(aex->second, this);

						if(ave_exotica_retorno.getId() != 0){
							aves_exoticas[ave_exotica_retorno.getId()] = ave_exotica_retorno;
							Animal & animalBasico = static_cast<Animal&>(ave_exotica_retorno);
							mapeamento_busca[ave_exotica_retorno.getId()] = animalBasico;
						}
					}	

					mapeamento_busca.erase(it);
					
					system("clear");
					cout << "______________________________________________________________" << endl;
					cout << "ANIMAL EDITADO COM SUCESSO!" << endl;			
				}else{
					system("clear");
					cout << "______________________________________________________________" << endl;
					throw invalid_argument("ANIMAL NÃO ENCONTRADO."); 
				}
				
			}else{
				system("clear");
				cout << "______________________________________________________________" << endl;
				cout << "NÃO HÁ ANIMAIS CADASTRADOS" << endl;
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
	cout << "	(1) +  NOME" << endl;
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
	cout << endl;
	cout << "DADOS RETORNADOS:" << endl;
	if(!mapeamento_busca.empty()){
		for (it = mapeamento_busca.begin(); it != mapeamento_busca.end(); ++it){
			if(it->second.getNome() == nome){
				if(it->second.getClasse() == "Amphibia" && it->second.getNatureza() == "Nativo"){
					map<int, AnfibioNativo>::iterator an = anfibios_nativos.find(it->first);
					cout << an->second << endl;
    			}else if(it->second.getClasse() == "Amphibia" && it->second.getNatureza() == "Exotico"){
					map<int, AnfibioExotico>::iterator ae = anfibios_exoticos.find(it->first);
					cout << ae->second << endl;
				}else if(it->second.getClasse() == "Mammalia" && it->second.getNatureza() == "Nativo"){
					map<int, MamiferoNativo>::iterator mn = mamiferos_nativos.find(it->first);
					cout << mn->second << endl;
				}else if(it->second.getClasse() == "Mammalia" && it->second.getNatureza() == "Exotico"){
					map<int, MamiferoExotico>::iterator me = mamiferos_exoticos.find(it->first);
					cout << me->second << endl;
				}else if(it->second.getClasse() == "Reptilia" && it->second.getNatureza() == "Nativo"){
					map<int, ReptilNativo>::iterator rn = repteis_nativos.find(it->first);
					cout << rn->second << endl;
				}else if(it->second.getClasse() == "Reptilia" && it->second.getNatureza() == "Exotico"){
					map<int, ReptilExotico>::iterator re = repteis_exoticos.find(it->first);
					cout << re->second << endl;
				}else if(it->second.getClasse() == "Aves" && it->second.getNatureza() == "Nativo"){
					map<int, AveNativa>::iterator an = aves_nativas.find(it->first);
					cout << an->second << endl;
				}else if(it->second.getClasse() == "Aves" && it->second.getNatureza() == "Exotico"){
					map<int, AveExotica>::iterator aex = aves_exoticas.find(it->first);
					cout << aex->second << endl;
				}	
			}
			quantidade_achados++;				
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
			system("clear");
			cout << "______________________________________________________________" << endl;

				if(escolha_tipo_classe == 0){
					return;
				}
				else if(escolha_tipo_classe == 1){
					cout << "______________________________________________________________" << endl;
					cout << "---ANFIBIOS---" << endl;
						map<int,AnfibioExotico>::iterator ae;
							for (ae = anfibios_exoticos.begin(); ae != anfibios_exoticos.end(); ++ae)
								cout << ae->second << endl;
						map<int,AnfibioNativo>::iterator an;
							for (an = anfibios_nativos.begin(); an != anfibios_nativos.end(); ++an)
								cout << an->second << endl;	
					cout << "______________________________________________________________" << endl;
				}
				else if(escolha_tipo_classe == 2){
					cout << "______________________________________________________________" << endl;
					cout << "---RÉPTEIS---" << endl;
						map<int, ReptilExotico>::iterator re;
							for (re = repteis_exoticos.begin(); re != repteis_exoticos.end(); ++re)
								cout << re->second << endl;
						map<int,ReptilNativo>::iterator rn;
							for (rn = repteis_nativos.begin(); rn != repteis_nativos.end(); ++rn)
								cout << rn->second << endl;	
					cout << "______________________________________________________________" << endl;
				}
				else if(escolha_tipo_classe == 3){
					cout << "______________________________________________________________" << endl;
					cout << "---AVES---" << endl;
						map<int,AveExotica>::iterator ae1;
							for (ae1 = aves_exoticas.begin(); ae1 != aves_exoticas.end(); ++ae1)
								cout << ae1->second << endl;
						map<int,AveNativa>::iterator an1;
							for (an1 = aves_nativas.begin(); an1 != aves_nativas.end(); ++an1)
								cout << an1->second << endl;	
					cout << "______________________________________________________________" << endl;
				}
				else if(escolha_tipo_classe == 4){
					cout << "______________________________________________________________" << endl;
					cout << "---MAMÍFEROS---" << endl;
						map<int,MamiferoExotico>::iterator me;
							for (me = mamiferos_exoticos.begin(); me != mamiferos_exoticos.end(); ++me)
								cout << me->second << endl;
						map<int,MamiferoNativo>::iterator mn;
							for (mn = mamiferos_nativos.begin(); mn != mamiferos_nativos.end(); ++mn)
								cout << mn->second << endl;	
					cout << "______________________________________________________________" << endl;
				}else{
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
* @brief método de consulta com filtragem por veterinário ou tratador
* @return 
*/
void PetFera::consultar_filtro_veterinario_tratador(){
	system("clear");
	int id = 0;
	cout << "---ANIMAL FILTRAGEM POR FUNCIONÁRIO---" << endl;
	cout << endl;
	cout << "INFORME O ID DO VETERINÁRIO OU TRATADOR:" << endl;
	cin >> id;
	map<int, Funcionario>::iterator an = funcionarios.find(id);
	if (an == funcionarios.end()){
		system("clear");
		cout << "______________________________________________________________" << endl;
		cout << "NÃO HÁ FUNCIONÁRIO CADASTRADO COM O ID INFORMADO" << endl;
	}else{
		map<int, Animal>::iterator it;
		int quantidade_achados = 0;
		cout << endl;
		cout << "DADOS RETORNADOS:" << endl;
		if(!mapeamento_busca.empty()){
			for (it = mapeamento_busca.begin(); it != mapeamento_busca.end(); ++it){
				if(it->second.getVeterinario().getId() == id || it->second.getTratador().getId() == id){
					if(it->second.getClasse() == "Amphibia" && it->second.getNatureza() == "Nativo"){
						map<int, AnfibioNativo>::iterator an = anfibios_nativos.find(it->first);
						cout << an->second << endl;
	    			}else if(it->second.getClasse() == "Amphibia" && it->second.getNatureza() == "Exotico"){
						map<int, AnfibioExotico>::iterator ae = anfibios_exoticos.find(it->first);
						cout << ae->second << endl;
					}else if(it->second.getClasse() == "Mammalia" && it->second.getNatureza() == "Nativo"){
						map<int, MamiferoNativo>::iterator mn = mamiferos_nativos.find(it->first);
						cout << mn->second << endl;
					}else if(it->second.getClasse() == "Mammalia" && it->second.getNatureza() == "Exotico"){
						map<int, MamiferoExotico>::iterator me = mamiferos_exoticos.find(it->first);
						cout << me->second << endl;
					}else if(it->second.getClasse() == "Reptilia" && it->second.getNatureza() == "Nativo"){
						map<int, ReptilNativo>::iterator rn = repteis_nativos.find(it->first);
						cout << rn->second << endl;
					}else if(it->second.getClasse() == "Reptilia" && it->second.getNatureza() == "Exotico"){
						map<int, ReptilExotico>::iterator re = repteis_exoticos.find(it->first);
						cout << re->second << endl;
					}else if(it->second.getClasse() == "Aves" && it->second.getNatureza() == "Nativo"){
						map<int, AveNativa>::iterator an = aves_nativas.find(it->first);
						cout << an->second << endl;
					}else if(it->second.getClasse() == "Aves" && it->second.getNatureza() == "Exotico"){
						map<int, AveExotica>::iterator aex = aves_exoticas.find(it->first);
						cout << aex->second << endl;
					}	
				}
				quantidade_achados++;				
			}
			if(quantidade_achados == 0){
				system("clear");
				cout << "______________________________________________________________" << endl;
				cout << "NÃO HÁ ANIMAIS PARA O FUNCIONÁRIO INFORMADO" << endl;
			}	
		}else{
			system("clear");
			cout << "______________________________________________________________" << endl;
			cout << "NÃO HÁ ANIMAIS CADASTRADOS" << endl;
		}
	}
}
/**
* @brief método de recuperação das informações dos arquivos
* @return 
*/
/*
void PetFera::recuperar_informacoes_arquivo(){
	fstream arqFuncionarios;
	arqFuncionarios.open("funcionarios.csv");
	string line;

	if (arqFuncionarios.is_open())
	{
		while (!arqFuncionarios.eof())
		{
			 cout << "entrei" << endl;
			getline(arqFuncionarios, line);

		  	std::vector<std::string> result = split_string(line, ";");
		  	//string id = result[0];
		  	string funcao = result[1];
		  	string cpf = result[2];
		  	//int idade = result[3];
		  	string tipo_sanguineo = result[4];
		 	//char fatorRH = result[5];
			string especialidade = result[6];
			 //cout << funcao << endl;
		  //Fruta * fruta = new Fruta(_codigo, _descricao, _preco, _data, _validade);


		}
		arqFuncionarios.close();
	}else{
		cout << "Arquivo de funcionarios não foi encontrado. Verificar o caminho do arquivo." << endl;
	}
	
}
*/
/**
* @brief método para salvar informações em arquivos
* @return 
*/
/*
void PetFera::salvar_informacoes_arquivo(){
	fstream arqFuncionarios;
	arqFuncionarios.open("funcionarios.csv", ios::out);

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

	fstream arqAnimais;
	arqAnimais.open("animais.csv", ios::out);

	if (arqAnimais.is_open())
	{	
		map<int,Animal>::iterator an;
		for (an = animais.begin(); an != animais.end(); ++an){
			arqAnimais <<  an->second.getId() << ";" << 
					       an->second.getClasse() << ";" <<
						   an->second.getNome() << ";" <<
						   an->second.getCientifico() << ";" <<
						   an->second.getSexo() << ";" <<
						   an->second.getDieta() << ";" <<
						   an->second.getVeterinario().getId() << ";" <<
						   an->second.getTratador().getId() << ";" <<
						   an->second.getBatismo() << endl;	   
		}
	}else{
		cout << "Arquivo de funcionarios não foi encontrado. Verificar o caminho do arquivo." << endl;
	}
	arqAnimais.close();

}
*/
/**
* @brief Função que quebra a linha lida do arquivo
* @param[in] Recebe linha(str) do tipo string
* @param[in] Recebe valor que será procurado para quebra do tipo char
* @return result do tipo vetor
*/
/*
std::vector<std::string> PetFera::split_string(std::string str, const char* op) {
	std::vector<std::string> result;
	std::string rest = str, block;
	size_t operator_position = rest.find_first_of(op);
	while (operator_position != std::string::npos) {
		block = rest.substr(0, operator_position);
		rest = rest.substr(operator_position + 1);
		operator_position = rest.find_first_of(op);
		result.push_back(block);
	}

	if (rest.length() > 0)
		result.push_back(rest);

	return result;
}
*/
