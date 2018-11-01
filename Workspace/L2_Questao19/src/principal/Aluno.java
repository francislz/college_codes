package principal;

public class Aluno {
	private String nome;
	private float[] notas;
	
	public Aluno(String nome, float[] notas) {
		this.nome = nome;
		this.notas = notas;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public float getNota(int nota) {
		return notas[nota];
	}

	public void setNotas(float[] notas) {
		this.notas = notas;
	}
	
	public float obterMedia() {
		float media = 0.0f;
		
		for (float f : notas) {
			media += f;
		}
		return media/notas.length;
	}
	
	public String situacao() {
		if(obterMedia() >= 6.0)
			return "Aprovado";
		else
			return "Reprovado";
	}
}
