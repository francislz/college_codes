package principal;

public class Main {

	public static void main(String[] args) {
		float[] num1 = {1.2f, 1.44f, 1.55f, 6.0f, 4.5f, 3.123f, 10.0f};
		float[] num2 = {1.2f, 1.42f, 1.55f, 6.4f, 4.8f, 3.123f, 10.0f};
		
		Conjunto c1 = new Conjunto(num1);
		Conjunto c2 = new Conjunto(num2);
		
		Conjunto c3 = c1.obterUniao(c2);
		Conjunto c4 = c1.obterIntersecao(c2);
		Conjunto c5 = c1.obterDiferenca(c2);
		
		c3.print();
		c4.print();
		c5.print();
		
	}

}
