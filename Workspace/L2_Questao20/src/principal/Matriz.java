package principal;

public class Matriz {
	private float[][] matriz;

	public Matriz(int m, int n) {
		this.matriz = new float[m][n];
	}
	
	public float acessa(int i, int j) {
		return matriz[i][j];
	}
	
	public void atribui(int i, int j, float v) {
		matriz[i][j] = v;
	}
	
	public int getLinhas() {
		return matriz.length;
	}
	
	public int getColunas() {
		return matriz[0].length;
	}
}
