package br.ufla.dcc.ppoo.locadora;

import java.util.ArrayList;

public class Locacao {
	private Cliente cliente;
	private ArrayList<Midia> midias;
	private Data dataLoc;
	private Data dataDev;
	
	public Locacao(Cliente cliente, Data dataLoc, Data dataDev) {
		this.cliente = cliente;
		this.midias = new ArrayList<Midia>(5);
		this.dataLoc = dataLoc;
		this.dataDev = dataDev;
	}

	public Cliente getCliente() {
		return cliente;
	}

	public void setCliente(Cliente cliente) {
		this.cliente = cliente;
	}

	public ArrayList<Midia> getMidias() {
		return midias;
	}

	public void setMidias(ArrayList<Midia> midias) {
		this.midias = midias;
	}

	public Data getDataLoc() {
		return dataLoc;
	}

	public void setDataLoc(Data dataLoc) {
		this.dataLoc = dataLoc;
	}

	public Data getDataDev() {
		return dataDev;
	}

	public void setDataDev(Data dataDev) {
		this.dataDev = dataDev;
	}
	
	public void locarVideo(Midia midia) throws Exception {
		if(midias.size() == 5) {
			throw new Exception("Maximum size, can't add any other value!");
		}
		else {
			midias.add(midia);
		}
	}
	
	public String retornaDados() {
		String recibo = "Cliente: " + cliente.getNome() + " (" + cliente.getDataNasc().getData() + ")\n";
		recibo += "Locação: " + dataLoc.getData() + " à " + dataDev.getData() + "\n";
		recibo += "Vídeos: \n";
		float total = 0f;
		for (Midia midia : midias) {
			recibo += midia.retornaDados() + '\n';
			total += midia.retornaPreco();
		}
		recibo += "Valor total da locação: R$ " + total + "\n";
		return recibo;
	}
}
