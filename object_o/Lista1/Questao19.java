import java.util.Scanner;
class Questao19{
	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		int n = ler.nextInt();

		int i = 1;
		for (int cont = 1; cont <= n;){
			boolean primo = true;
			for (int j = 2; j < i && primo; j++) {
				if(i % j == 0)
					primo = false;
			}
			if(primo){
				System.out.println(i);
				cont++;
			}
			i++;
		}
		
	}
}
