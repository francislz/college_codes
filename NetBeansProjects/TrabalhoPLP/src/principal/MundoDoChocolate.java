/* 
   Trabalho de Paradigma Orientado Objetos
   Paradigmas de Linguagens de Programação
   Método de Gravação em arquivos usando Orientação a Obejtos
   Cadastro de Barras de Chocolate
   Copyright 2017 by Franciscone Luiz, Victor Hugo, Lucas Hideki 
   Arquivo com a classe Principal. Menu de opções. 
   Descrição das funcionalidades nos comentários
*/
package principal;

import controle.Menu;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import javax.swing.JOptionPane;
import trabalhoplp.Chocolate;

public class MundoDoChocolate {

    /**
     * Metodo principal do sistema
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
        JOptionPane.showMessageDialog(null, "Atenção! Utilize o formato decimal do seu Sitema Operacional. EX: 5,99 ou 5.99");
        Menu menu = new Menu("chocos.txt"); // Instancia de um novo menu de controle das funcoes
        Scanner entrada = new Scanner(System.in);//Instancia da classe que realiza a entrada padrao de dados
        int opc;
        do{
            String texto = "c - Cadastrar Chocolates \n"
                +"b - Buscar Chocolate \n"
                +"e - Excluir Chocolate \n"
                +"r - Recuperar Itens de um Arquivo \n";
            String escolha = JOptionPane.showInputDialog(null, texto);
            
            boolean continua = true;
            if(escolha == null)
                opc = 1;
            else if(escolha.length() == 0){
                JOptionPane.showMessageDialog(null, "Escolha uma opção ou clique em CANCELAR!");
                opc = 0;
            }
            else{
                switch(escolha.charAt(0)){
                    case 'c':{
                        menu.cadastro(); //Se o cadastro for selecionado o menu de cadastro é chamado
                        break;
                    }
                    case 'b':{ //Busca de dados
                        //Entrada do valor a ser buscado
                        String nomeChoco = JOptionPane.showInputDialog(null, "Entre com o nome do chocolate:");
                        ArrayList<Object> lista = menu.buscaChoco(nomeChoco); //Array com os dados encontrados
                        if(!lista.isEmpty()){ //Se fooi encontrado algum valor eles sao listados
                            texto = "Foram encontrados as seguintes correspondencias: \n";
                            for(int i = 0; i < lista.size(); i++){
                                Chocolate choco = (Chocolate) lista.get(i);
                                texto += choco.toString() + "\n";
                            }
                            JOptionPane.showMessageDialog(null, texto);
                        }
                        else //senao isso é informado
                            JOptionPane.showMessageDialog(null,"Nenhuma correspondencia foi encontrada !");
                        break;
                    }
                    case 'e':{//Opcao de exclusao    
                        //Entrada de chocolate a ser excluido
                        String nomeChoco = JOptionPane.showInputDialog(null, "Entre com o nome do chocolate:");
                        menu.remove(nomeChoco); //Chamada do procedimento de exclusao
                        break;
                    }
                    case 'r':{ //Opcao de recuperar os dados
                        //Entrada com o nome do arquivo a ser recuperado
                        String caminho = "Digite todo o caminho para o arquivo. Ex: /home/SEU-USUARIO/ARQUIVO.TXT \n";
                        String nomeArquivo = JOptionPane.showInputDialog(null, "Entre com o nome do arquivo a ser recuperado. \n" + caminho);
                        menu.recupera(nomeArquivo); //Chamada do procedimento de recuperacao
                        break;
                    }
                    default: //Caso uma outra letra seja digitada a mensagem de erro exibida
                        JOptionPane.showMessageDialog(null,"Opcao incorreta! Digite novamente");
                        break;
                }
                /**
                * O procedimento abaixo pergunta se o usuario quer fazer mais alguma operacao
                * no caso ele digita 1 para sim e 2 para nao
                */
                opc = JOptionPane.showConfirmDialog(null, "Deseja realizar outra operação ?");
            }
        }while(opc != 1);
    }
}
