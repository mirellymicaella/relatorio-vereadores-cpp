#include "Candidato.h"
#include "Enum.cpp"

Candidato::Candidato(int numero, int votosNominais, string nome,  string nomeUrna,
					Situacao situacao, Sexo sexo, struct tm dataNacimento, 
					DestinoVoto destinoVoto, int numeroPartido, int idade){
    this->numero = numero;
		this->votosNominais = votosNominais;
		this->nome = nome;
		this->nomeUrna = nomeUrna;
		this->situacao = situacao;
		this->sexo = sexo;
		this->dataNascimento = dataNascimento;
		this->destinoVoto = destinoVoto;
		this->numeroPartido = numeroPartido;
		this->idade = idade;
}

string Candidato::getNome() const{
    return nome;
}

void Candidato::setNome(const string &nome){
    this->nome = nome;
}

string Candidato::getNomeUrna() const{
    return nomeUrna;
}

void Candidato::setNomeUrna(const string &nomeUrna){
    this->nomeUrna = nomeUrna;
}

int Candidato::getNumero() const{
    return numero;
}

void Candidato::setNumero(const int &numero){
    this->numero = numero;
}

int Candidato::getVotosNominais() const{
    return votosNominais;
}

void Candidato::setVotosNominais(const int &votosNominais){
    this->votosNominais = votosNominais;
}

int Candidato::getNumeroPartido() const{
    return numeroPartido;
}

void Candidato::setNumeroPartido(const int &numeroPartido){
    this->numeroPartido = numeroPartido;
}

int Candidato::getIdade() const{
    return idade;
}

void Candidato::setIdade(const int &idade){
    this->idade = idade;
}

Situacao Candidato::getSituacao() {
	return situacao;
}


void Candidato::setSituacao(Situacao situacao) {
	this->situacao = situacao;
}


Sexo Candidato::getSexo() {
	return sexo;
}


void Candidato::setSexo(Sexo sexo) {
	this->sexo = sexo;
}


struct tm Candidato::getDataNascimento() {
	return dataNascimento;
}


void Candidato::setDataNascimento(struct tm dataNascimento) {
	this->dataNascimento = dataNascimento;
}

DestinoVoto Candidato::getDestinoVoto() {
	return destinoVoto;
}


void Candidato::setDestinoVoto(DestinoVoto destinoVoto) {
	this->destinoVoto = destinoVoto;
}


