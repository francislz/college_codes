import java.util.Scanner;
class Questao10{
	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		int n = ler.nextInt();

		int soma = 0;
		for (int i = 0; i < n; i++){
			soma += ler.nextInt();
		}
		System.out.println(soma);
	}
}