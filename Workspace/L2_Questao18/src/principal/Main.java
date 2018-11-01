package principal;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		ArrayList<Carro> carros = new ArrayList<Carro>();
		ArrayList<Vendedor> vendedores = new ArrayList<Vendedor>();
		ArrayList<Venda> vendas = new ArrayList<Venda>();
		
		int opc;
		do {
			opc = 0;
			System.out.println("Escolha a opção desejada: ");
			System.out.println("1 - Cadastrar veiculos");
			System.out.println("2 - Cadastrar vendedores");
			System.out.println("3 - Realizar Venda");
			System.out.println("4 - Listar Vendas");
			System.out.println("0 - Sair");
			opc = ler.nextInt();
			
			switch(opc) {
				case 1:{
					ler.nextLine();
					System.out.println("Digite o modelo do carro:");
					String modelo = ler.nextLine();
					System.out.println("Digite a marca do carro:");
					String marca = ler.nextLine();
					System.out.println("Digite o preco do carro:");
					float preco = ler.nextFloat();
					ler.nextLine();
					System.out.println("Digite o estado do carro, (novo, usado, etc):");
					String estado = ler.nextLine();
					
					Carro c = new Carro(modelo, marca, preco, estado);
					carros.add(c);
					break;
				}
				case 2:{
					ler.nextLine();
					System.out.println("Digite o nome do vendedor:");
					String nome = ler.nextLine();
					System.out.println("Digite o CPF do vendedor:");
					String cpf = ler.nextLine();
					
					Vendedor v = new Vendedor(nome, cpf);
					vendedores.add(v);
					break;
				}
				case 3:{
					ler.nextLine();
					System.out.println("Digite o modelo do carro a ser vendido:");
					String modelo = ler.nextLine();
					
					Carro c = null;
					for (Carro carro : carros) {
						if(carro.getModelo().equalsIgnoreCase(modelo)) {
							c = carro;
							break;
						}
					}
					System.out.println("Digite o nome do vendedor:");
					String nome = ler.nextLine();
					
					Vendedor v = null;
					for (Vendedor vendedor : vendedores) {
						if(vendedor.getNome().equalsIgnoreCase(nome)) {
							v = vendedor;
							break;
						}
					}
					
					if(v == null || c == null) {
						System.out.println("Dados nao encontrados, tente novamente!");
					}
					else {
						Venda venda = new Venda(c, v, 5, "30/05/2016");
						vendas.add(venda);
					}
					break;
				}
				case 4:{
					for (Venda venda : vendas) {
						venda.printVenda();
					}
					break;
				}
				case 0:{
					System.out.println("Bye!");
					break;
				}
				default:
					System.out.println("Erro! Opcao invalidade, tente novamente!");
					break;
			}
		}while(opc != 0);

	}

}
