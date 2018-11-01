package principal;

public class Imovel {
	private double areaTotal;
	private int numeroQuartos;
	private Inquilino inquilino;
	
	public Imovel(double areaTotal, int numeroQuartos, Inquilino inquilino) {
		this.areaTotal = areaTotal;
		this.numeroQuartos = numeroQuartos;
		this.inquilino = inquilino;
	}
	
	public double gerarBoleto() {
		return 0;
	}
	
	public String getDados() {
		return null;
	}
	
	public double getAreaTotal() {
		return areaTotal;
	}
	
	public void setAreaTotal(double areaTotal) {
		this.areaTotal = areaTotal;
	}
	
	public int getNumeroQuartos() {
		return numeroQuartos;
	}
	
	public void setNumeroQuartos(int numeroQuartos) {
		this.numeroQuartos = numeroQuartos;
	}
	
	public Inquilino getInquilino() {
		return inquilino;
	}
	
	public void setInquilino(Inquilino inquilino) {
		this.inquilino = inquilino;
	}	
}
