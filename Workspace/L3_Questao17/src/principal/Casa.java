package principal;

public class Casa extends Imovel{
	private double areaExterna;

	public Casa(double areaTotal, int numeroQuartos, Inquilino inquilino, double areaExterna) {
		super(areaTotal, numeroQuartos, inquilino);
		this.areaExterna = areaExterna;
	}
	
	@Override
	public double gerarBoleto() {
		return (20.0 * getAreaTotal()) * 1.1;
	}
	
	@Override
	public String getDados() {
		String saida = "Inquilino: " + getInquilino().getNome() + "(CPF: " + getInquilino().getCpf() + ") \n";
				saida += "Tipo de imóvel: casa (" + getAreaTotal() + " m2 - área externa: " + getAreaExterna() + " m2)\n";
				saida += "Valor a pagar: R$ " + gerarBoleto();
			return saida;
	}
	
	public double getAreaExterna() {
		return areaExterna;
	}

	public void setAreaExterna(double areaExterna) {
		this.areaExterna = areaExterna;
	}
}
