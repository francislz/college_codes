package principal;

public class Carro {
	private String modelo;
	private String marca;
	private float preco;
	private String estado;
	
	public Carro(String modelo, String marca, float preco, String estado) {
		super();
		this.modelo = modelo;
		this.marca = marca;
		this.preco = preco;
		this.estado = estado;
	}

	public String getModelo() {
		return modelo;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public String getMarca() {
		return marca;
	}

	public void setMarca(String marca) {
		this.marca = marca;
	}

	public float getPreco() {
		return preco;
	}

	public void setPreco(float preco) {
		this.preco = preco;
	}

	public String getEstado() {
		return estado;
	}

	public void setEstado(String estado) {
		this.estado = estado;
	}
	
}
