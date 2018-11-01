package principal;

public class Principal {

	public static void main(String[] args) {
		float[] notas = new float[3];
		notas[0] = 7.60f;
		notas[1] = 7.30f;
		notas[2] = 9.50f;
		
		Aluno a = new Aluno("Zé das Couves", notas);
		
		System.out.println("Nome: " + a.getNome());
		for(int i = 0; i < notas.length; ++i) {
			System.out.println("Nota " + i + ": " + a.getNota(i));
		}
		System.out.printf("Média: %.2f Situacao: %s \n", a.obterMedia(), a.situacao());
		

	}

}
