#ifndef LEITOR_H
#define LEITOR_H

#include <string>
#include <list>
#include <vector>
#include "Candidato.h"
#include "Partido.h"

using namespace std;

class Leitor {

    public:
        Leitor();

        const vector<Candidato> LeCandidatos(ifstream& file, string strData) const;
        const vector<Partido> LePartidos(ifstream& file) const;
        struct tm stringToTm(string dataStr);
        int  calculaIdade(struct tm *data, struct tm *dataNascimento);
        Situacao parseSituacao(string situacao);	
        DestinoVoto parseDestinoVoto(string destinoVoto);
        Sexo parseSexo(string sexo) ;
};

#endif /* LEITOR_H */