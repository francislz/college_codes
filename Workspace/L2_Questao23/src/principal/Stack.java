package principal;

public class Stack {
	private int[] dados;
	private int tamanho;
	
	public Stack() {
		dados = new int[100];
		tamanho = 0;
	}
	
	public void push(int valor) {
		if(tamanho < 100) {
			dados[tamanho] = valor;
			tamanho++;
		}
		else {
			System.out.println("Stack Full");
		}
	}
	
	public int pop() {
		if(tamanho > 0) {
			int aux = dados[tamanho - 1];
			tamanho--;
			return aux;
		}
		else {
			System.out.println("Stack Empty, cannot remove a value!");
			return -1;
		}
	}
	
	public int top() {
		return dados[tamanho - 1];
	}
	
	public void print() {
		for (int i = 0; i < tamanho; i++) {
			System.out.printf("%d => ", dados[i]);
		}
		System.out.println();
	}
}
