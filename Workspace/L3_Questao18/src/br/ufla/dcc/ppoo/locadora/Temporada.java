package br.ufla.dcc.ppoo.locadora;

public class Temporada extends Midia{
	private int qtdEp;
	private float precoPorEp;
	
	public Temporada(String titulo, int anoLancamento, int qtdEp, float precoPorEp) {
		super(titulo, anoLancamento);
		this.qtdEp = qtdEp;
		this.precoPorEp = precoPorEp;
	}

	public float getPrecoPorEp() {
		return precoPorEp;
	}

	public void setPrecoPorEp(float precoPorEp) {
		this.precoPorEp = precoPorEp;
	}

	public int getQtdEp() {
		return qtdEp;
	}

	public void setQtdEp(int qtdEp) {
		this.qtdEp = qtdEp;
	}

	@Override
	public String retornaDados() {
		return super.getTitulo() + " (" + qtdEp + " ep.) (" + qtdEp + " x R$ " + precoPorEp + " = R$ " + retornaPreco() + ")";
	}

	@Override
	public float retornaPreco() {
		return qtdEp * precoPorEp;
	}
}
