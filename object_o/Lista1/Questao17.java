import java.util.Scanner;
class Questao17{
	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		int a = ler.nextInt();
		int b = ler.nextInt();

		int i = 2;
		int divisor = 1;
		boolean mudou = false, parada = false;

		while(!parada){
			if((a % i == 0) && (b % i == 0)){
				a /= i;
				b /= i;
				mudou = false;
				divisor *= i;
			}
			else if((a % i != 0) && (b % i != 0) && (!mudou)){
				mudou = true;
				i++;
			}
			else{
				parada = true;
			}
		}
		System.out.println(divisor);
	}
}