package principal;

//Apartamentos possuem área total (em m2), número do andar, número de quartos, taxa de condomínio e inquilino

public class Apartamento extends Imovel{
	private int numeroAndar;
	private float taxaCondominio;
	
	public Apartamento(double areaTotal, int numeroQuartos, Inquilino inquilino, int numeroAndar,
			float taxaCondominio) {
		super(areaTotal, numeroQuartos, inquilino);
		this.numeroAndar = numeroAndar;
		this.taxaCondominio = taxaCondominio;
	}
	
	@Override
	public double gerarBoleto() {
		return ((20.0 * getAreaTotal()) + taxaCondominio) * 1.15;
	}
	
	@Override
	public String getDados() {
		String saida = "Inquilino: " + getInquilino().getNome() + "(CPF: " + getInquilino().getCpf() + ") \n";
				saida += "Tipo de imóvel: apartamento (" + getAreaTotal() + " m2 - tx cond: " + getTaxaCondominio() + " m2)\n";
				saida += "Valor a pagar: R$ " + gerarBoleto();
			return saida;
	}
	
	public int getNumeroAndar() {
		return numeroAndar;
	}

	public void setNumeroAndar(int numeroAndar) {
		this.numeroAndar = numeroAndar;
	}

	public float getTaxaCondominio() {
		return taxaCondominio;
	}

	public void setTaxaCondominio(float taxaCondominio) {
		this.taxaCondominio = taxaCondominio;
	}
	
	
}
