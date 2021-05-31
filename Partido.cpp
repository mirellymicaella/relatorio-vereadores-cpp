#include "Partido.h"
#include <string>
#include <vector>

 Partido::Partido(string nome, string sigla, int numero, int votosLegenda){
    this->nome = nome;
	this->sigla = sigla;
	this->numero = numero;
	this->votosLegenda = votosLegenda;
}

string Partido::getNome() const{
    return nome;
}

void Partido::setNome(const string &nome){
    this->nome = nome;
}

string Partido::getSigla() const{
    return sigla;
}

void Partido::setSigla(const string &sigla){
    this->sigla = sigla;
}

int Partido::getNumero() const{
    return numero;
}

void Partido::setNumero(const int &numero){
    this->numero = numero;
}

int Partido::getVotosLegenda() const{
    return votosLegenda;
}

void Partido::setVotosLegenda(const int &votosLegenda){
    this->votosLegenda = votosLegenda;
}

const vector<Candidato> Partido::getCandidatos() const {
    return candidatos;
}

void Partido::adicionaCandidato(Candidato cand){
    //cout << sigla << " -- ";
    candidatos.push_back(cand);
    //cout << cand.getNome() << endl;
}  

// void Partido::criaPartido(const string &nome){
//     Partido *d = new Partido();
//     d->setNome(nome);
//     partidos.push_back(d);
// }

int Partido::getTotalVotosNominais() const{
	int total=0;
	for(Candidato c: candidatos){
		total+=c.getVotosNominais();
    }
        
		
	return total;
	}
	
int Partido::getTotalEleitos() const {
	int total=0;
	for(Candidato c: candidatos)
		if(c.getSituacao() == ELEITO)
			total++;
		
	return total;
}

