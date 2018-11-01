import java.util.Scanner;
class Questao15{

	private String nome;
	private int idade;

	public Questao15(){}

	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		int n = ler.nextInt();
 	
 		Questao15[] objs = new Questao15[n];

 		int soma = 0;
		for (int i = 0; i < n; i++){
			objs[i] = new Questao15();
			ler.nextLine();
			objs[i].nome = ler.nextLine();
			objs[i].idade = ler.nextInt();
			soma += objs[i].idade;
		}
		int older = 0;
		int younger = 0;
		for (int i = 0; i < n; i++){
			if(objs[i].idade > objs[older].idade)
				older = i;
			if(objs[i].idade < objs[younger].idade)
				younger = i;
		}

		float media = ((float) soma)/((float) n);

		System.out.printf("%.2f\n",media);
		System.out.printf("Mais Velho, Nome: %s := Idade: %d \n", objs[older].nome, objs[older].idade);
		System.out.printf("Mais Jovem, Nome: %s := Idade: %d \n", objs[younger].nome, objs[younger].idade);
	}
}