#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Leitor.h"
#include "Partido.h"
#include "Candidato.h"
#include "Enum.cpp"

Leitor ::Leitor (){}

const vector<Candidato> Leitor::LeCandidatos(ifstream& file, string strData) const {
    Leitor leitor;

    struct tm data = leitor.stringToTm(strData);

    struct tm dataNascimento;
    int numero,
        votosNominais,
        numeroPartido,
        idade;
	string nome,
        nomeUrna,
        aux;

	Situacao situacao;
	Sexo sexo;
	DestinoVoto destinoVoto;

    list<Candidato> candidatos;

    getline(file,aux);
    while (! file.eof())  {
        getline (file,aux, ',' );
        if(aux.empty()) break;
        numero = stoi(aux);

        getline (file, aux, ',' );
        votosNominais = stoi(aux);

        getline (file, aux, ',' );
        situacao = leitor.parseSituacao(aux);

        getline (file, nome, ',' );

        getline (file, nomeUrna, ',' );

        getline (file, aux, ',' );
        sexo = leitor.parseSexo(aux);

        getline (file, aux, ',' );
        dataNascimento = leitor.stringToTm(aux);
        idade = leitor.calculaIdade(&data, &dataNascimento);

        getline (file, aux, ',' );
        destinoVoto = leitor.parseDestinoVoto(aux);

        getline (file, aux );
        numeroPartido = stoi(aux);

        if( destinoVoto == VALIDO) {
            Candidato candidato(numero, votosNominais, nome, nomeUrna, situacao,
                                sexo, dataNascimento, destinoVoto,numeroPartido,  idade);
            candidatos.push_back(candidato);
        }

    }

    vector<Candidato> cand2(candidatos.begin(),candidatos.end());

    return cand2;

}

const vector<Partido> Leitor::LePartidos(ifstream& file) const {
    int numero,
        votosLegenda;

    string nome,
        sigla,
        line,
        aux;
     

    list<Partido> partidos;

    getline(file,aux);
    while (! file.eof())  { 
        getline (file,aux, ',' );
        if(aux.empty()) break;
        numero = stoi(aux);

        getline (file, aux, ',' );
        votosLegenda = stoi(aux);

        getline (file, nome, ',' );
        getline (file, sigla );

        Partido partido(nome,sigla,numero,votosLegenda);       
        partidos.push_back(partido);
    }

    vector<Partido> part2(partidos.begin(),partidos.end());

    return part2;

}

struct tm Leitor::stringToTm(string dataStr) {

    int year, month, day;
    sscanf(dataStr.c_str(), "%d/%d/%d",  &day, &month, &year);

    struct tm  tm;
    time_t rawtime;
    time ( &rawtime );

    tm = *localtime ( &rawtime );
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;


    mktime(&tm);

    return tm;

}

int  Leitor:: calculaIdade(struct tm *data, struct tm *dataNascimento) {
    int idade = data->tm_year - dataNascimento->tm_year;

    /*
     * Verifica as condições para determinar se já fez aniversário.
     * Caso não tenha feito ainda, decrementamos a idade para compensar.
     */
    if (data->tm_mon < dataNascimento->tm_mon)
        idade -= 1;
    else if (data->tm_mon == dataNascimento->tm_mon)
        if (data->tm_mday < dataNascimento->tm_mday)
            idade -= 1;

    return idade;
} 

Situacao Leitor ::parseSituacao(string situacao) {
	if(!situacao.compare("Eleito"))return ELEITO;
	if(!situacao.compare("Não Eleito"))return NAO_ELEITO;
	return SUPLENTE ;
}

DestinoVoto Leitor ::parseDestinoVoto(string destinoVoto) {
if(!destinoVoto.compare("Válido"))return VALIDO;
if(!destinoVoto.compare("Anulado"))return ANULADO;
return ANULADO_SUB_JUD ;
}	

Sexo Leitor ::parseSexo(string sexo) {
	if(!sexo.compare("F"))return FEMININO;
	return MASCULINO;
}