package principal;

public class Principal {

	public static void main(String[] args) {
		Inquilino i = new Inquilino("Franciscone Luiz", "13095554637");
		Inquilino i2 = new Inquilino("João das Neves", "00000000000");
		
		Casa c = new Casa(100.0, 2, i, 20.0);
		Apartamento ap = new Apartamento(60.0, 2, i2, 4, 100.0f);
		
		System.out.println(c.getDados());
		System.out.println();
		System.out.println(ap.getDados());
	}
}
