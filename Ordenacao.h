#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include "Partido.h"
#include "Candidato.h"

class Ordenacao{

public:
Ordenacao();


static bool ComparadorVotosDesempateMaiorIdadeCandidatos(Candidato c1, Candidato c2);


static bool ComparadorVotosDesempateMenorNumeroPartidarioCandidatos(Candidato c1, Candidato c2);


static bool ComparadorVotosPartidoDesempateMenorNumeroPartido(Partido p1, Partido p2);

static bool ComparadorVotosCadidatoMaisVotadoDesempateMenorNumeroCadidato(Partido p1, Partido p2);

void OrdenaCadidatosVotos(vector<Candidato>& candidatos);

void OrdenaPartidosVotos(vector<Partido>& partidos);

void OrdenaPartidosVotosCandidatoMaisVotado(vector<Partido>& partidos);

void OrdenaCandidatosVotosDesempateMenorNumeroPartido(vector<Candidato>& candidatos);

};

#endif
