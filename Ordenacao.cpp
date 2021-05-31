
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include "Ordenacao.h"
#include "Partido.h"
#include "Candidato.h"
#include "Relatorio.h"

Ordenacao::Ordenacao(){}
 
bool Ordenacao::ComparadorVotosDesempateMaiorIdadeCandidatos(Candidato c1, Candidato c2){
	int votosC1 = c1.getVotosNominais() ;
	int votosC2 = c2.getVotosNominais() ;
	
	if(votosC1 == votosC2)
		return c2.getIdade()<(c1.getIdade());
	
	return votosC2 < votosC1;
}

bool Ordenacao::ComparadorVotosDesempateMenorNumeroPartidarioCandidatos(Candidato c1, Candidato c2){
		int votosC1 = c1.getVotosNominais() ;
		int votosC2 = c2.getVotosNominais() ;
		
		if(votosC1 == votosC2) {
			int numC1 = c1.getNumeroPartido();
			int numC2 = c2.getNumeroPartido();
			
			if(numC1 == numC2) 
				return c2.getIdade() < c1.getIdade();
			
			return numC1 < numC2;
		}
			
		return votosC2 < votosC1;
}

bool Ordenacao::ComparadorVotosPartidoDesempateMenorNumeroPartido(Partido p1, Partido p2){
	int totalP1 = p1.getTotalVotosNominais()+p1.getVotosLegenda();
	int totalP2 = p2.getTotalVotosNominais()+p2.getVotosLegenda();
		
	if(totalP1==totalP2) 
		return p2.getNumero() > p1.getNumero();
		
	return totalP2<totalP1;
}

bool Ordenacao::ComparadorVotosCadidatoMaisVotadoDesempateMenorNumeroCadidato(Partido p1, Partido p2) {
		Relatorio relatorio;

		if(relatorio.PrimeiroEUltimoColocados(p1).size() < 1) return true;
		if(relatorio.PrimeiroEUltimoColocados(p2).size() < 1) return false;
		
		int totalP1 =relatorio.PrimeiroEUltimoColocados(p1)[0].getVotosNominais();	
		int totalP2 =relatorio.PrimeiroEUltimoColocados(p2)[0].getVotosNominais();
				
		if(totalP1==totalP2) {
			
			int numeroP1 = relatorio.PrimeiroEUltimoColocados(p1)[0].getNumero();
			int numeroP2 = relatorio.PrimeiroEUltimoColocados(p2)[0].getNumero();
			
			return numeroP1 < numeroP2;
		}
					
		return totalP2 < totalP1;
}

void Ordenacao::OrdenaCadidatosVotos(vector<Candidato>& candidatos){
    std::sort(candidatos.begin(), candidatos.end(), ComparadorVotosDesempateMaiorIdadeCandidatos);
}

void Ordenacao::OrdenaPartidosVotos(vector<Partido>& partidos){
	std::sort(partidos.begin(),partidos.end(),ComparadorVotosPartidoDesempateMenorNumeroPartido);
}

void Ordenacao::OrdenaPartidosVotosCandidatoMaisVotado(vector<Partido>& partidos){
	std::sort(partidos.begin(),partidos.end(),ComparadorVotosCadidatoMaisVotadoDesempateMenorNumeroCadidato);
}

void Ordenacao::OrdenaCandidatosVotosDesempateMenorNumeroPartido(vector<Candidato>& candidatos){
	std::sort(candidatos.begin(), candidatos.end(), ComparadorVotosDesempateMenorNumeroPartidarioCandidatos);
}

