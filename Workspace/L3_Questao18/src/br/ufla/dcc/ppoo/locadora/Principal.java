package br.ufla.dcc.ppoo.locadora;

public class Principal {

	public static void main(String[] args) throws Exception{
		Data dataNasc = new Data(28,06,1971);
		Cliente c = new Cliente("Elon Musk", dataNasc);
		
		Filme f = new Filme("Piratas do Vale do Silício", 1997, 120, 3.90f);
		Temporada t = new Temporada("The Big Bang Theory - Season 1", 2008, 10, 0.90f);
		
		Data dataLoc = new Data(11, 9, 2017);
		Data dataDev = new Data(13, 9, 2017);
		Locacao l = new Locacao(c, dataLoc, dataDev);
		l.locarVideo(f);
		l.locarVideo(t);
		
		System.out.println(l.retornaDados());

	}

}
