package br.ufla.dcc.ppoo.locadora;

public class Filme extends Midia{
	private int duracao;
	private float preco;
	
	public Filme(String titulo, int anoLancamento, int duracao, float preco) {
		super(titulo, anoLancamento);
		this.duracao = duracao;
		this.preco = preco;
	}
	
	public int getDuracao() {
		return duracao;
	}
	public void setDuracao(int duracao) {
		this.duracao = duracao;
	}
	public float getPreco() {
		return preco;
	}
	public void setPreco(float preco) {
		this.preco = preco;
	}

	@Override
	public String retornaDados() {
		return super.getTitulo() + " (" + duracao + " min) (R$ " + retornaPreco() + ")";
	}

	@Override
	public float retornaPreco() {
		return preco;
	}
}
