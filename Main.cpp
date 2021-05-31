#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include <ctime>
//#include <locale.h>

#include "Partido.h"
#include "Candidato.h"
#include "Leitor.h"
#include "Relatorio.h"
#include "Ordenacao.h"

using namespace std;

int main (int argc, char* argv[]) {
    setlocale(LC_NUMERIC,"pt_BR.UTF-8");

    if(argc < 4)
        cout<< "Não foram fornecidas todas as informações."<< endl;
    
    string pathC = argv[1];
    string pathP = argv[2];
    string data =  argv[3];

    ifstream fileC;
    ifstream fileP;

    fileC.open (pathC);
    if(!fileC.is_open()) {
        cout<< "Não foi possível abrir o arquivo de Candidatos: "<< pathC<< endl;
        return 0;
    }

    fileP.open (pathP);
    if(!fileP.is_open()){ 
        cout<< "Não foi possível abrir o arquivo de Partidos: "<< pathP << endl;
        return 0;
    }


    Leitor leitor;
    Relatorio relatorio;
    Ordenacao ordenacao;
    vector<Candidato> candidatos =  leitor.LeCandidatos(fileC, data);
    vector<Partido> partidos = leitor.LePartidos(fileP);

    // Adiciona candidatos aos partidos
    for(int i=0; i< partidos.size(); i++)
        for(int j=0; j< candidatos.size(); j++)
            if(candidatos[j].getNumeroPartido() == partidos[i].getNumero())
                partidos[i].adicionaCandidato(candidatos[j]);
            
    //Imprime a quantidade de eleitos totais
    int vagas = relatorio.NumeroVagas(partidos);
    cout<< "Número de vagas: "<<  vagas <<endl;

    //Imprime os candidatos eleitos
    cout << "\nVereadores eleitos:" << endl;
    int i =0;
    for(Candidato c : relatorio.VereadoresEleitos(partidos, ordenacao))
        relatorio.printCandidato(++i, c, partidos);

    //Imprime os candidatos mais votados
    i=0;
    cout << "\nCandidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;
    for(Candidato c : relatorio.VereadoresMaisVotados(candidatos, vagas, ordenacao))
        relatorio.printCandidato(++i, c, partidos);

    //Imprime os candidatos mais votados não eleitos
	cout << "\nTeriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n"<<
	 						"(com sua posição no ranking de mais votados)" << endl;
    for(Candidato c : relatorio.VereadoresMaisVotadosNaoEleitos(candidatos, vagas, ordenacao))
	 	relatorio.printCandidato(relatorio.getIndexCandidato(relatorio.VereadoresMaisVotados(candidatos, vagas, ordenacao),c)+1, c, partidos);


    //Imprime os candidatos que se beneficiaram do sistema proporcional
    cout <<"\nEleitos, que se beneficiaram do sistema proporcional:\n" <<
            "(com sua posição no ranking de mais votados)"<< endl;
    for(Candidato c : relatorio.VereadoresEleitosBeneficiadosSistema(candidatos, partidos, vagas, ordenacao))
        relatorio.printCandidato(relatorio.getIndexCandidato(relatorio.VereadoresMaisVotados(candidatos, candidatos.size(), ordenacao),c)+1, c, partidos);


    //Imprime os resultados dos partidos
    cout <<"\nVotação dos partidos e número de candidatos eleitos:"<< endl;
    //TODO: fazer ordenacao funcionar
    ordenacao.OrdenaPartidosVotos(partidos);
    for(Partido p: partidos)
         relatorio.printPartido(relatorio.getIndexPartido(partidos,p)+1, p);


    //Imprime primeiro e ultimo colocado por partido
    cout << "\nPrimeiro e último colocados de cada partido:" << endl;
    ordenacao.OrdenaPartidosVotosCandidatoMaisVotado(partidos);
    int j = 1;
    for(Partido p: partidos)
        if(p.getVotosLegenda()>0){
             relatorio.printPartidoColocacoesCandidatos(j, p);	
             j++;	
     	}
	
    //Imprime faixa etaia dos eleitos
    cout<<"\nEleitos, por faixa etária (na data da eleição):"<< endl;
    relatorio.printCandidatosFaixaetaria(relatorio.VereadoresEleitos(partidos, ordenacao), vagas);
		
    //Imprime genero dos eleitos
     cout<<"\nEleitos, por sexo:"<< endl;
    relatorio.printCandidatosPorGenero(relatorio.VereadoresEleitos(partidos,ordenacao), vagas);
    
    //Imprime outros dados sobre votos
    relatorio.printTotaisVotos(partidos);


    fileC.close();
    fileP.close();
    return 0;
}
