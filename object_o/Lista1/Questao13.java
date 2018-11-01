import java.util.Scanner;
class Questao13{
	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		int x = ler.nextInt();
		int y = ler.nextInt();

		int resultado = x;
		for (int i = 1; i < y; i++){
			resultado *= x;
		}
		System.out.println(resultado);
	}
}