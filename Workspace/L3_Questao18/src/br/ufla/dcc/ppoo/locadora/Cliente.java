package br.ufla.dcc.ppoo.locadora;

public class Cliente {
	private String nome;
	private Data dataNasc;
	
	public Cliente(String nome, Data dataNasc) {
		super();
		this.nome = nome;
		this.dataNasc = dataNasc;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public Data getDataNasc() {
		return dataNasc;
	}

	public void setDataNasc(Data dataNasc) {
		this.dataNasc = dataNasc;
	}
}
