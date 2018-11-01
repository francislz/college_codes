/* 
   Trabalho de Paradigma Orientado Objetos
   Paradigmas de Linguagens de Programação
   Método de Gravação em arquivos usando Orientação a Obejtos
   Cadastro de Barras de Chocolate
   Copyright 2017 by Franciscone Luiz, Victor Hugo, Lucas Hideki 
   Arquivo com a classe Menu. 
   Descrição das funcionalidades nos comentários
*/
package controle;

import controle.Arquivo;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import javax.swing.JOptionPane;
import trabalhoplp.*;

public class Menu {
    private Arquivo arq; // Atributo de um objeto do tipo arquivo
    
    public Menu(String nomeArq) throws IOException {
        arq = new Arquivo(nomeArq); //instancia de arquivo com o construtor
    }
    
    public ArrayList<Object> buscaChoco(String nomeChoco){
        return arq.busca(nomeChoco); //Uso da funcao de busca na classe arquivo
    }    
    
    public void cadastro() throws IOException{ // Menu de Cadastro com as opcoes
        Scanner entrada = new Scanner(System.in);
        String texto = "Escolha o tipo de chocolate a ser cadastrado \n" + 
              "1 - Chocolate Preto \n" +
              "2 - Chocolate Branco \n\n" +
              "Ou clique no botão Cancelar para abortar a operação\n";
        String saida = null;
        saida = JOptionPane.showInputDialog(null, texto);
        boolean continua = true;
        if(saida == null)
            continua = false;
        else if(saida.length() == 0){
            JOptionPane.showMessageDialog(null, "Escolha uma opção ou clique em CANCELAR!");
            this.cadastro();
        }
        else{
            while (continua) {
                switch (saida.charAt(0)) {
                    case '1': {
                        this.cadChocoPreto();
                        continua = false;
                        break;
                    }
                    case '2': {
                        this.cadChocoBranco();
                        continua = false;
                        break;
                    }
                    default: {
                        JOptionPane.showMessageDialog(null, "Opcao invalida!");
                        continua = true;
                        break;
                    }
                }
            }   
        }
    }
    public  void cadChocoPreto() throws IOException{ // Metodo que recebe a entrada de dados de um ChocolatePreto
        float pesoC = 0, valorNutC = 0, percCacau = 0, precoC = 0;
        String nomeC = JOptionPane.showInputDialog(null,"Digite o nome do chocolate:");
        String descricaoIngre = JOptionPane.showInputDialog(null,"Digite a descricao dos ingredientes do chocolate:");
        try{ //Trata a excecao de tipo numerico
            pesoC = Float.parseFloat(JOptionPane.showInputDialog(null,"Digite o peso do chocolate.\n Apenas números:"));
            valorNutC = Float.parseFloat(JOptionPane.showInputDialog(null, "Digite o valor nutricional do chocolate.\n Apenas números:"));
            percCacau = Float.parseFloat(JOptionPane.showInputDialog(null,"Digite o percentual de cacau do chocolate.\n Apenas números:"));
            precoC = Float.parseFloat(JOptionPane.showInputDialog(null, "Digite o preco do chocolate.\n Apenas números:"));
        }catch(NumberFormatException e){
            JOptionPane.showMessageDialog(null, "Campo numerico, digite apenas numeros!");
        }
        String origemC = JOptionPane.showInputDialog(null,"Digite a origem do chocolate:");
        Marca marca = new Marca();
        marca.setIdMarca(Integer.parseInt(JOptionPane.showInputDialog(null,"Digite o ID da marca.\n Apenas números:")));
        marca.setNomeMarca(JOptionPane.showInputDialog(null,"Digite o nome da marca"));
        ChocolatePreto choco = new ChocolatePreto(percCacau, nomeC, descricaoIngre, pesoC, valorNutC, precoC, origemC, marca);
        arq.insere(choco);
    }
    
    public void cadChocoBranco() throws IOException{ // Metodo que recebe a entrada de dados de um ChocolateBranco
        float pesoC = 0, valorNutC = 0, percManteigaC = 0, precoC = 0;
        String nomeC = JOptionPane.showInputDialog(null,"Digite o nome do chocolate:");
        String descricaoIngre = JOptionPane.showInputDialog(null,"Digite a descricao dos ingredientes do chocolate:");
        try{ //Trata exceção de tipo numerico
            pesoC = Float.parseFloat(JOptionPane.showInputDialog(null,"Digite o peso do chocolate.\n Apenas números:"));
            valorNutC = Float.parseFloat(JOptionPane.showInputDialog(null, "Digite o valor nutricional do chocolate.\n Apenas números:"));
            precoC = Float.parseFloat(JOptionPane.showInputDialog(null, "Digite o preco do chocolate.\n Apenas números:"));
            percManteigaC = Float.parseFloat(JOptionPane.showInputDialog(null,"Digite o percentual de manteiga de cacau do chocolate:"));
        }catch(NumberFormatException e){
            JOptionPane.showMessageDialog(null, "Campo numerico, digite apenas numeros!");
        }
        String origemC = JOptionPane.showInputDialog(null,"Digite a origem do chocolate:");
        Marca marca = new Marca();
        marca.setIdMarca(Integer.parseInt(JOptionPane.showInputDialog(null,"Digite o ID da marca.\n Apenas números:")));
        marca.setNomeMarca(JOptionPane.showInputDialog(null,"Digite o nome da marca"));
        ChocolateBranco choco = new ChocolateBranco(percManteigaC, nomeC, descricaoIngre, pesoC, valorNutC, precoC, origemC, marca);
        arq.insere(choco);
    }
    
    public void remove(String nomeChoco){
        arq.remove(nomeChoco); //Chamada da funcao de remocao
    }
    
    public void recupera(String nomeArq){
        arq.recupera(nomeArq); //Chamada da funcao de recuperar
    }
}
