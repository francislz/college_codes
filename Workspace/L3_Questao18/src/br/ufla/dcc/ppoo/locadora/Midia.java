package br.ufla.dcc.ppoo.locadora;

public abstract class Midia {
	private String titulo;
	private int anoLancamento;
	
	public Midia(String titulo, int anoLancamento) {
		super();
		this.titulo = titulo;
		this.anoLancamento = anoLancamento;
	}

	public int getAnoLancamento() {
		return anoLancamento;
	}

	public void setAnoLancamento(int anoLancamento) {
		this.anoLancamento = anoLancamento;
	}
	
	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public abstract String retornaDados();
	public abstract float retornaPreco();
}
