package principal;

public class Main {
	public static void main(String args[]) {
		Stack pilha = new Stack();
		pilha.push(1);
		pilha.push(4);
		pilha.push(2);
		pilha.push(3);
		pilha.push(10);
		pilha.push(7);
		pilha.print();
		pilha.pop();
		pilha.print();
	}
}
