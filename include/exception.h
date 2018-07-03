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