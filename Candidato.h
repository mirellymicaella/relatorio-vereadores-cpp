#ifndef CANDIDATO_H
#define CANDIDATO_H

#include "Enum.cpp"
#include <string>
#include <list>

using namespace std;

class Candidato {
    int numero;
	int votosNominais;
	string nome;
	string nomeUrna;
	Situacao situacao;
	Sexo sexo;
    struct tm dataNascimento;
	DestinoVoto destinoVoto;
	int numeroPartido;
	int idade;

    public:
        Candidato(int numero, int votosNominais, string nome, string nomeUrna,
            Situacao situacao, Sexo sexo, struct tm dataNascimento, DestinoVoto destinoVoto,
            int numeroPartido, int idade);

        string getNome() const;
        void setNome(const string &nome);

        string getNomeUrna() const;
        void setNomeUrna(const string &nomeUrna);

        int getNumero() const;
        void setNumero(const int &numero);

        int getVotosNominais() const;
        void setVotosNominais(const int &votosNominais);

        int getNumeroPartido() const;
        void setNumeroPartido(const int &numeroPartido);

        int getIdade() const;
        void setIdade(const int &idade);
        
        Situacao getSituacao();
        void setSituacao(Situacao situacao);

        Sexo getSexo();
        void setSexo(Sexo sexo);

        struct tm getDataNascimento();
        void setDataNascimento(struct tm dataNascimento);

        DestinoVoto getDestinoVoto();
        void setDestinoVoto(DestinoVoto destinoVoto);

};

#endif /* CANDIDATO_H */