package principal;

public class Conjunto {
	private float[] numeros;

	public Conjunto(float[] numeros) {
		this.numeros = numeros;
	}
	
	public int getSize() {
		return numeros.length;
	}

	public void setNumeros(float[] numeros) {
		this.numeros = numeros;
	}

	public float obterElemento(int indice) {
		return numeros[indice];
	}
	
	public Conjunto obterUniao(Conjunto input) {
		float[] array = new float[input.getSize() + this.numeros.length];
		
		for(int i = 0; i < numeros.length; i++) {
			array[i] = numeros[i];
		}
		for(int i = 0; i < input.getSize(); i++) {
			array[i + input.getSize()] = input.obterElemento(i);
		}
		Conjunto c = new Conjunto(array);
		c.ordenar();
		return c;
	}
	
	public Conjunto obterIntersecao(Conjunto input) {
		float[] array;
		if(input.getSize() > this.numeros.length)
			array = new float[numeros.length];
		else
			array = new float[input.getSize()];
		
		int cont = 0;
		for(int i = 0; i < numeros.length; i++) {
			boolean achou = false;
			for(int i1 = 0; i1 < input.getSize() && !achou; i1++) {
				if(numeros[i] == input.obterElemento(i1)) {
					array[cont] = numeros[i];
					cont++;
					achou = true;
				}
			}
		}
		
		float[] aux = new float[cont];
		for(int i = 0; i < cont; i++) {
			aux[i] = array[i];
		}
		Conjunto c = new Conjunto(aux);
		c.ordenar();
		return c;
	}
	
	public Conjunto obterDiferenca(Conjunto input) {
		float[] array;
		if(input.getSize() > this.numeros.length)
			array = new float[numeros.length];
		else
			array = new float[input.getSize()];
		
		int cont = 0;
		for(int i = 0; i < numeros.length; i++) {
			boolean achou = false;
			for(int i1 = 0; i1 < input.getSize() && !achou; i1++) {
				if(numeros[i] == input.obterElemento(i1)) {
					achou = true;
				}
			}
			if(!achou) {
				array[cont] = numeros[i];
				cont++;
			}
		}
		
		float[] aux = new float[cont];
		for(int i = 0; i < cont; i++) {
			aux[i] = array[i];
		}
		Conjunto c = new Conjunto(aux);
		c.ordenar();
		return c;
	}
	
	public void ordenar() {
		for(int i = (this.numeros.length - 1); i >= 0; i--) {
			for(int j = 0; j < i; j++) {
				if(this.numeros[j] > this.numeros[j + 1]) {
					float aux = this.numeros[j];
					this.numeros[j] = this.numeros[j + 1];
					this.numeros[j + 1] = aux;
				}
			}
		}
	}
	
	public float media() {
		float soma = 0.0f;
		
		for(float f : numeros){
			soma += f;
		}
		return soma/numeros.length;
	}
	
	public float mediana() {
		this.ordenar();
		
		if(numeros.length % 2 == 0) {
			int ind = numeros.length / 2;
			
			return ((numeros[ind] + numeros[ind + 1])/2.0f);
		}
		else
			return numeros[numeros.length/2];
	}
	
	public void print() {
		for (float f : numeros) {
			System.out.print("========");
		}
		System.out.println();
		for (float f : numeros) {
			System.out.printf("%.2f => ", f);
		}
		System.out.println();
		for (float f : numeros) {
			System.out.print("========");
		}
		System.out.println();
	}
}
