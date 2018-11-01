package principal;

//(P; N1) Implemente em Java uma classe chamada Aquecedor. 
//Ela deve ter um único atributo chamado temperatura, cujo 
//tipo deve ser um ponto flutuante de precisão dupla. Defina 
//um construtor que não recebe parâmetros e inicializa a 
//temperatura em 20 graus. Crie os métodos aquecer e resfriar 
//que aumentam e diminuem a temperatura em 5 graus, respectivamente. 
//Defina um método para retornar o valor da temperatura.

public class Aquecedor {
	private double temperatura;
	private double tempMax;
	private double tempMin;
	private double fatorIncremento;
	
	public Aquecedor() {
		this.temperatura = 20.0;
		this.tempMax = 40.0;
		this.tempMin = 10.0;
		this.fatorIncremento = 5.0;
	}
	
	public Aquecedor(double temperatura) {
		this.temperatura = temperatura;
		this.tempMax = 40.0;
		this.tempMin = 10.0;
		this.fatorIncremento = 5.0;
	}
	
	public Aquecedor(double temperatura, double incremento) {
		this.temperatura = temperatura;
		this.tempMax = 40.0;
		this.tempMin = 10.0;
		this.fatorIncremento = incremento;
	}
	
	public void aquecer() {
		if((temperatura + fatorIncremento) < tempMax)
			temperatura += fatorIncremento;
		else
			System.out.println("Temperatura ja é máxima");
	}
	
	public void resfriar() {
		if((temperatura - fatorIncremento) > tempMax)
			temperatura -= fatorIncremento;
		else
			System.out.println("Temperatura ja é minima");
	}
	
	public double getTemperatura() {
		return temperatura;
	}
	
	public void setFatorIncremento(double fatorIncremento) {
		this.fatorIncremento = fatorIncremento;
	}
	
	public static void main(String[] args) {
		Aquecedor aq = new Aquecedor();
		aq.aquecer();
		System.out.println(aq.getTemperatura());
		aq.resfriar();
		System.out.println(aq.getTemperatura());
		aq.setFatorIncremento(7.0);
		aq.aquecer();
		System.out.println(aq.getTemperatura());
	}
}