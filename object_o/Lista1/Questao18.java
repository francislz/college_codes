import java.util.Scanner;
class Questao18{

	private float max;
	private float min;
	private float dif;

	public Questao18(){}

	public static float abs(float value){
		if(value < 0)
			return value * (-1.0f);
		else
			return value;
	}

	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		int n = ler.nextInt();

		Questao18[] temp = new Questao18[n];

		for (int i = 0; i < n; i++){
			temp[i] = new Questao18();
			temp[i].min = ler.nextFloat();
			temp[i].max = ler.nextFloat();
			temp[i].dif = (temp[i].max - abs(temp[i].min));
		}

		int iMin = 0;
		int iMax = 0;
		int iDif = 0;
		for (int i = 0; i < n; i++){
			if(temp[i].min < temp[iMin].min)
				iMin = i;
			if(temp[i].max > temp[iMax].max)
				iMax = i;
			if(temp[i].dif > temp[iDif].dif)
				iDif = i;
		}

		System.out.println(temp[iMin].min);
		System.out.println(temp[iMax].max);
		System.out.println(temp[iDif].dif);
	}
}
