#ifndef RELATORIO_H
#define RELATORIO_H

#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include "Candidato.h"
#include "Partido.h"
#include "Ordenacao.h"

using namespace std;

class Relatorio {

    public:
        Relatorio();

        int NumeroVagas(vector<Partido> partidos);
        vector<Candidato> VereadoresEleitos(vector<Partido> partidos, Ordenacao ordenacao);
        vector<Candidato> VereadoresMaisVotados(vector<Candidato> candidatos,int vagas, Ordenacao ordenacao);	
        vector<Candidato> VereadoresMaisVotadosNaoEleitos(vector<Candidato> candidatos, int vagas, Ordenacao ordenacao);	
        vector<Candidato> VereadoresEleitosBeneficiadosSistema(vector<Candidato> candidatos,vector<Partido>  partidos,int vagas, Ordenacao ordenacao);	
        vector<Candidato> PrimeiroEUltimoColocados(Partido p);

        int  getIndexCandidato(vector<Candidato> candidatos,Candidato candidato);
        int  getIndexPartido(vector<Partido> partidos,Partido partido);
        void printTotaisVotos(vector<Partido> partidos);
        void printPartidoColocacoesCandidatos(int index, Partido p);
        
        void printCandidatosPorGenero(vector<Candidato> candidatos,int vagas);
        void printCandidatosFaixaetaria(vector<Candidato> candidatos, int vagas);
        string formatedCandidatoSimples(Candidato c) ;
        void printPartido(int index,Partido p);
        void printCandidato(int index,Candidato c,vector<Partido>  partidos);
        string  getPartidoByNumber(int numero, vector<Partido>  partidos) ;
};
#endif /* RELATORIO_H */