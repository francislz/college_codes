import java.util.Scanner;
class Questao20{
	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		int n = ler.nextInt();

		float[] temps = new float[n];
		for (int i = 0; i < n; i++){
			temps[i] = ler.nextFloat();
		}
		
		float media = 0.0f;
		for (int i = 0; i < (n - 1); i++){
			media += temps[i];
		}
		media /= (n - 1);

		float previsao = (media * 0.75f) + (temps[n - 1] * 0.25f);
		System.out.printf("%.2f\n",previsao);
	}
}

