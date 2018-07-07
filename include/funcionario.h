/**
* @file   funcionario.h
* @brief  Classe responsável por gerenciar os funcionários pertencentes a PETFera
* @author Claudio da Cruz Silva Junior
* @since  27/06/2018
* @date   27/06/2018
*/

#ifndef _FUNCIONARIO_H_  /**< Verifica se a variável _FUNCIONARIO_H_ foi definida*/
#define _FUNCIONARIO_H_	 /**< Define a variável _FUNCIONARIO_H_*/

#include <string>

using namespace std; /**<Usa namespace std*/

class Funcionario
{

protected:
	int id;
	std::string nome;
	std::string cpf;
	short idade;
	std::string tipo_sanguineo;
	char fatorRH;
	std::string especialidade;
	std::string funcao;
	
public:
	static int contador_id;	
	Funcionario(); /**< Construtor padrão da Classe*/
	Funcionario(std::string funcao); /**< Construtor paramatrizado da Classe*/
	Funcionario(int id, string funcao, string nome, string cpf, int idade, string tipo_sanguineo, char fatorRH, string especialidade); /**< Construtor paramatrizado da Classe*/
	virtual ~Funcionario(); /**< Destrutor padrão da Classe*/
	/**
	* @brief Método de acesso para o atributo id
	* @return atributo id
	*/
	int getId();
	/**
	* @brief Método de acesso para o atributo nome
	* @return atributo nome
	*/
	std::string getNome();
	/**
	* @brief Método de acesso para o atributo cpf
	* @return atributo cpf
	*/
	std::string getCpf();
	/**
	* @brief Método de acesso para o atributo idade
	* @return atributo idade
	*/
	short getIdade();
	/**
	* @brief Método de acesso para o atributo tipo sanguineo
	* @return atributo tipo sanguineo
	*/
	std::string getTipoSanguineo();
	/**
	* @brief Método de acesso para o atributo fator RH
	* @return atributo fator RH
	*/
	char getFatorRH();
	/**
	* @brief Método de acesso para o atributo especialidade
	* @return atributo especialidade
	*/
	std::string getEspecialidade();
	/**
	* @brief Método de acesso para o atributo funcao
	* @return atributo funcao
	*/
	std::string getFuncao();
	/**
	* @brief Método para modificar o atributo nome
	* @return 
	*/
	void setNome(std::string nome);
	/**
	* @brief Método para modificar o atributo cpf
	* @return 
	*/
	void setCpf(std::string cpf);
	/**
	* @brief Método para modificar o atributo idade
	* @return 
	*/
	void setIdade(int idade);
	/**
	* @brief Método para modificar o atributo tipo sanguineo
	* @return 
	*/
	void setTipoSanguineo(std::string tipo_sanguineo);
	/**
	* @brief Método para modificar o atributo fator RH
	* @return 
	*/
	void setFatorRH(char fatorRH);
	/**
	* @brief Método para modificar o atributo especialidade
	* @return 
	*/
	void setEspecialidade(std::string especialidade);
	/**
	* @brief Efetua a sobrecarga do operador >>
	* @param[in] variável para o >>
	* @param[in] Constante para guardar o objeto
	* @return valor do cin
	*/
	friend istream& operator>>(istream &a, Funcionario &f);

	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend ostream& operator<<(ostream &e, Funcionario const c);
	/**
	* @brief Efetua a sobrecarga do operador ==
	* @param[in] Constante para guardar o objeto a ser comparado
	* @return booleano
	*/
	bool operator==(Funcionario &funcionario);
	/**
	* @brief Método para validação de alguns campos
	* @return 
	*/
	bool validarCampos();

};


#endif