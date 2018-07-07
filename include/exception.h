#include <exception>
using std::exception;

class ErroBuscaTratador : public exception {
public:
	const char* what() {
	return "ERRO: NÃO FOI ENCONTRADO TRATADOR QUE FICARÁ RESPONSÁVEL PELO ANIMAL";
	}
};

class ErroNaoTratador : public exception {
public:
	const char* what() {
	return "ERRO: O FUNCIONÁRIO NÃO É UM TRATADOR";
	}
};

class ErroBuscaVeterinario : public exception {
public:
	const char* what() {
	return "ERRO: NÃO FOI ENCONTRADO VETERINARIO QUE FICARÁ RESPONSÁVEL PELO ANIMAL";
	}
};

class ErroNaoVeterinario : public exception {
public:
	const char* what() {
	return "ERRO: O FUNCIONÁRIO NÃO É UM VETERINARIO";
	}
};

class ArgumentoInvalido : public exception {
public:
	const char* what() {
	return "ERRO: ARGUMENTO INVALIDO. SELECIONE UM DOS INTEIROS LISTADOS";
	}
};

class ParametroForaDeEscopo : public exception {
public:
	const char* what() {
	return "ERRO: PARÂMETRO FORA DO ESCOPO DA LISTAGEM.";
	}
};

class CampoPreenchidoInadequedamente : public exception {
public:
	const char* what() {
	return "ERRO: ALGUM CAMPO FOI PREENCHIDO INADEQUADAMENTE.";
	}
};

class FuncionarioComMesmoCPFExistente : public exception {
public:
	const char* what() {
	return "ERRO: JÁ EXITE FUNCIONÁRIO CADASTRADO COM O MESMO CPF NO SISTEMA!";
	}
};

class SemFuncionariosCadastrados : public exception {
public:
	const char* what() {
	return "NÃO HÁ FUNCIONÁRIOS CADASTRADOS NO SISTEMA!";
	}
};

class CPFNaoEncontrado : public exception {
public:
	const char* what() {
	return "NÃO HÁ FUNCIONÁRIOS CADASTRADOS COM O CPF INFORMADO!";
	}
};

class ArgumentoInvalidoId : public exception {
public:
	const char* what() {
	return "ERRO: ARGUMENTO INVALIDO. INFORME UM INTEIRO PARA O ID";
	}
};

class ErroAberturaArquivoFuncionario : public exception {
public:
	const char* what() {
	return "ERRO: O ARQUIVO DE DADOS DOS FUNCIONÁRIOS NÃO FOI ENCONTRADO.";
	}
};

class ErroAberturaArquivoAnimal : public exception {
public:
	const char* what() {
	return "ERRO: O ARQUIVO DE DADOS DOS ANIMAIS NÃO FOI ENCONTRADO.";
	}
};