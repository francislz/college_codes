import java.util.Scanner;
class Questao12{
	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		int x = ler.nextInt();
		int y = ler.nextInt();

		if(x > y)
			System.out.println("X deve ser menor que Y");
		for (int i = x; i <= y; i++){
			if((i % 2 == 0) && (i % 3 == 0))
				System.out.println(i);
		}
	}
}