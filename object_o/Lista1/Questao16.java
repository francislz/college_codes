import java.util.Scanner;
class Questao16{
	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		int n = ler.nextInt();

		int tam = 0;
		int i = 1;
		boolean parada = false;

		while(!parada){
			if(i < n){
				tam++;
				i *= 10;
			}else{
				parada = true;
			}
		}
		int div = 1;
		for (i = 0; i < tam; i++) {
			div *= 10;
		}

		int soma = 0;
		parada = false;
		while(!parada){
			soma += n / div;
			n = n % div;
			div /= 10;

			if(n < 10){
				parada = true;
				soma += n;
			}

		}
		System.out.println(soma);
	}
}