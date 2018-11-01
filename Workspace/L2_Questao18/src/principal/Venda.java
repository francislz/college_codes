package principal;

import java.util.Date;

public class Venda {
	private Carro carro;
	private Vendedor vendedor;
	private int desconto;
	private String data;
	
	public Venda(Carro carro, Vendedor vendedor, int desconto, String data) {
		this.carro = carro;
		this.vendedor = vendedor;
		this.data = data;
		if (desconto <= 10)
			this.desconto = desconto;
		else
			System.out.println("Desconto maior que o permitido! Erro!");
	}

	public Carro getCarro() {
		return carro;
	}

	public void setCarro(Carro carro) {
		this.carro = carro;
	}

	public Vendedor getVendedor() {
		return vendedor;
	}

	public void setVendedor(Vendedor vendedor) {
		this.vendedor = vendedor;
	}

	public int getDesconto() {
		return desconto;
	}

	
	public String getData() {
		return data;
	}

	public void setData(String data) {
		this.data = data;
	}

	public void setDesconto(int desconto) {
		if (desconto <= 10)
			this.desconto = desconto;
		else
			System.out.println("Desconto maior que o permitido! Erro!");
	}
	
	public void printVenda() {
		System.out.println("Vendedor: " + vendedor.getNome() + ", Carro: " + carro.getModelo());
	}
	
}
