/* 
   Trabalho de Paradigma Orientado Objetos
   Paradigmas de Linguagens de Programação
   Método de Gravação em arquivos usando Orientação a Obejtos
   Cadastro de Barras de Chocolate
   Copyright 2017 by Franciscone Luiz, Victor Hugo, Lucas Hideki 
   Arquivo com a classe Arquivo que realiza as operações no Arquivo de dados. 
   Descrição das funcionalidades nos comentários
*/
package controle;

import java.io.*;
import static java.lang.System.in;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import trabalhoplp.*;

public class Arquivo implements Operacoes{
    private String nomeArq;
    private File arq;
    /**
     * Construtor da classe arquivo. Recebe o nome do arquivo via paramentro
     * @try Tenta criar o novo arquivo
     * @finally se o arquivo não existir ele criar o novo arquivo 
     *  Observação:
         * No arquivo cada chocolate esta salvo no seguinte formato:
         * tipo Chocolate/nome/DescricaoIngre/PesoC/ValorN/PercCacau/PrecoC/IdMarca/NomeMarca
         * onde cada atributo das classes chocolate são separados por /
     */
    public Arquivo(String nomeArq) throws FileNotFoundException, IOException {
        try{
            this.nomeArq = nomeArq;
            this.arq = new File(nomeArq);
        } finally{
            if(!arq.exists()){
                arq.createNewFile();
            }
        }
    }
    /**
     * Metodo que retorna todos os dados salvos no arquivo 
     * @return retorna um ArrayList com os dados salvos
     */
    @Override
    public ArrayList<Object> retornaTodos() {
        ArrayList<Object> chocolates = new ArrayList<>(); //ArrayList de chocolates
        try {
            BufferedReader leitura = new BufferedReader(new FileReader(arq)); //Buffer para leitura dos dados
            String dado; // String que vai ler cada linha do arquivo
            String array[] = null; //Array que recebe cada atributo em cada linha
            while((dado = leitura.readLine()) != null){ //Enquanto houver linhas é feita a leitura
                array = dado.split("/"); // divide a string dado a cada incidencia de uma /
                if(this.decodifica(array[0]).equals("preto")){ // Verifica o tipo do chocolate
                    ChocolatePreto choco = new ChocolatePreto();// Se for preto cria uma instancia desse tipo
                    //Salva todos os dados em cada atributo da classe
                    choco.setNomeC(this.decodifica(array[1]));
                    choco.setDescricaoIngre(this.decodifica(array[2]));
                    choco.setPesoC(Float.parseFloat(this.decodifica(array[3])));
                    choco.setValorNutC(Float.parseFloat(this.decodifica(array[4])));
                    choco.setOrigemC(this.decodifica(array[5]));
                    choco.setPercCacau(Float.parseFloat(this.decodifica(array[6])));
                    choco.setPrecoC(Float.parseFloat(this.decodifica(array[7])));
                    Marca marca = new Marca();
                    marca.setIdMarca(Integer.parseInt(this.decodifica(array[8])));
                    marca.setNomeMarca(this.decodifica(array[9]));
                    //Como os dados no arquivos estao criptografados o metodo this.decodifica() restaura o valor verdadeiro
                    //de cada atributo
                    choco.setMarca(marca);
                    chocolates.add(choco);
                }
                //Mesmo principio da classe acima mas para o chocolate tipo branco
                else if(this.decodifica(array[0]).equals("branco")){
                    ChocolateBranco choco = new ChocolateBranco();
                    choco.setNomeC(this.decodifica(array[1]));
                    choco.setDescricaoIngre(this.decodifica(array[2]));
                    choco.setPesoC(Float.parseFloat(this.decodifica(array[3])));
                    choco.setValorNutC(Float.parseFloat(this.decodifica(array[4])));
                    choco.setOrigemC(this.decodifica(array[5]));
                    choco.setPercManteigaC(Float.parseFloat(this.decodifica(array[6])));
                    choco.setPrecoC(Float.parseFloat(this.decodifica(array[7])));
                    Marca marca = new Marca();
                    marca.setIdMarca(Integer.parseInt(this.decodifica(array[8])));
                    marca.setNomeMarca(this.decodifica(array[9]));
                    choco.setMarca(marca);
                    chocolates.add(choco);
                }
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Arquivo.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Arquivo.class.getName()).log(Level.SEVERE, null, ex);
        }
        return chocolates; //Retorna o Array com todos os chocolates
    }
    
    @Override
    public void insere(Object objeto) {//Metodo para insercao no arquivo
        try {
            /**
             * @try cria o buffer de escrita de dados
             * se a variavel naoSobreEscreve for verdadeira os dados sao sempre adicionados no final do arquivo
             * se for falsa todos os dados sao apagados e o arquivo é sobrescrito
             */
            try (BufferedWriter escrita = new BufferedWriter(new FileWriter(arq, true))) {
                if(objeto.getClass() == ChocolatePreto.class){ //Verifica o tipo da class passada
                    /**
                     * Cada linha abaixo escreve um atributo da classe Chocolate Preto no arrquivo
                     * indicando o tipo do chocolate e separando cada dado por /
                     * A chamada do metodo this.codifica() criptografa os dados no arquivo para que niguem
                     * , ao abrir o arquivo .txt entenda o que esta escrito
                     */
                    ChocolatePreto choco = (ChocolatePreto) objeto;
                    escrita.write(this.codifica("preto") + "/");
                    escrita.write(this.codifica(choco.getNomeC()) + "/");
                    escrita.write(this.codifica(choco.getDescricaoIngre())+ "/");
                    escrita.write(this.codifica(Float.toString(choco.getPesoC())) + "/");
                    escrita.write(this.codifica(Float.toString(choco.getValorNutC())) + "/");
                    escrita.write(this.codifica(choco.getOrigemC()) + "/");
                    escrita.write(this.codifica(Float.toString(choco.getPercCacau()))+ "/");
                    escrita.write(this.codifica(Float.toString(choco.getPrecoC())) + "/");
                    escrita.write(this.codifica(Integer.toString(choco.getMarca().getIdMarca())) + "/");
                    escrita.write(this.codifica(choco.getMarca().getNomeMarca()) + "/");
                    escrita.write("\n");
                    escrita.close();
                }
                else if(objeto.getClass() == ChocolateBranco.class){
                    // Mesmo principio do caso anterior so que para o Chocolate tipo branco
                    ChocolateBranco choco = (ChocolateBranco) objeto;
                    escrita.write(this.codifica("branco") + "/");
                    escrita.write(this.codifica(choco.getNomeC()) + "/");
                    escrita.write(this.codifica(choco.getDescricaoIngre())+ "/");
                    escrita.write(this.codifica(Float.toString(choco.getPesoC())) + "/");
                    escrita.write(this.codifica(Float.toString(choco.getValorNutC())) + "/");
                    escrita.write(this.codifica(choco.getOrigemC()) + "/");
                    escrita.write(this.codifica(Float.toString(choco.getPercManteigaC()))+ "/");
                    escrita.write(this.codifica(Float.toString(choco.getPrecoC())) + "/");
                    escrita.write(this.codifica(Integer.toString(choco.getMarca().getIdMarca())) + "/");
                    escrita.write(this.codifica(choco.getMarca().getNomeMarca()) + "/");
                    escrita.write("\n");
                    escrita.close();
                }
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Arquivo.class.getName()).log(Level.SEVERE, null, ex);
        } catch (UnsupportedEncodingException ex) {
            Logger.getLogger(Arquivo.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            JOptionPane.showMessageDialog(null, "Dados incorretos ou nulos, digite novamente");
        }
    }
   
    @Override
    public ArrayList<Object> busca(String nomeC) {    
        ArrayList<Object> chocolates = this.retornaTodos(); //Array com todos os dados do arquivo
        ArrayList<Object> achados = new ArrayList<Object>(); //Array que contem as correpondencia encontradas
        
        for(int i = 0; i < chocolates.size(); ++i){ // Para cada chocolate que esta no arquivo faca
            Chocolate choco = (Chocolate) chocolates.get(i); // Chocolate recebe um chocolate da lista
            if(choco.getNomeC().contains(nomeC)){ //Verifica se nesse chocolate contem a sub-string nomeC
                achados.add(choco); // se encontrar adiciona na lista de achados
            }
        }    
        return achados; // Retorna a lista de achados
    }

    @Override
    public void remove(String nomeC) { // metodo que remove um devido chocolate do arquivo de dados
        ArrayList<Object> chocolates = retornaTodos(); // Todos os dados são retornados.
        ArrayList<Object> lista = busca(nomeC); //Busca se existe alguma correspondecia do chocolate na lista
        if(lista.isEmpty()) //Se a lista de achados estiver vazia é mostrada a mensagem que nao foi encontrada correspondencia
            JOptionPane.showMessageDialog(null, "Nenhuma correspondencia foi encontrada !");
        else{ // Senao tem-se a opccao de remover
            /**
             * Sao listadas todas as correspondencias encontradas e o usuario escolhe aquela que ele desejar remover
             */
            String texto = "Foram encontrados as seguintes correspondencias: \n";
            for(int i = 0; i < lista.size(); i++){
                Chocolate choco = (Chocolate) lista.get(i);
                texto += i + " - " + choco.toString() + "\n";
            }
            texto += "Digite o numero do chocolate a ser removido:\n";
            int r = Integer.parseInt(JOptionPane.showInputDialog(null, texto));
            /**
             * Uma vez que o usuario escolhe o cholate a ser removido todos os outros sao sobrescritos no arquivo
             * exceto o que o usuario removeu
             */
            this.arq.delete();
            try {
                this.arq.createNewFile();
            } catch (IOException ex) {
                Logger.getLogger(Arquivo.class.getName()).log(Level.SEVERE, null, ex);
            }
            boolean naoSobrescreve = false;
            Chocolate remover = (Chocolate) lista.get(r);
            for(int i = 0; i < chocolates.size(); i++){
                Chocolate choco = (Chocolate) chocolates.get(i);
                if(!choco.getNomeC().equals(remover.getNomeC())){
                    System.out.println(chocolates.get(i).toString());
                    insere(chocolates.get(i));
                    naoSobrescreve = true;
                }
            }
        }
    }

    @Override
    public void recupera(String nome) { //Metodo que dado um arquivo os dados nele sao recuperados
        File arquivo2 = new File(nome);
        ArrayList<Object> chocolates = new ArrayList<>();
        /**
         * Analogo ao metodo de ler os dados, esse metodo le todos os dados em um arquivo de texto
         * e apos a leitura insere tudo no banco de dados original do sistema
         */
        try {
            BufferedReader leitura = new BufferedReader(new FileReader(arquivo2));
            String dado;
            String array[] = null;
            while((dado = leitura.readLine()) != null){
                array = dado.split("/");
                if(array[0].equals("preto")){ // Verifica o tipo do chocolate
                    ChocolatePreto choco = new ChocolatePreto();// Se for preto cria uma instancia desse tipo
                    //Salva todos os dados em cada atributo da classe
                    choco.setNomeC(array[1]);
                    choco.setDescricaoIngre(array[2]);
                    choco.setPesoC(Float.parseFloat(array[3]));
                    choco.setValorNutC(Float.parseFloat(array[4]));
                    choco.setOrigemC(array[5]);
                    choco.setPercCacau(Float.parseFloat(array[6]));
                    choco.setPrecoC(Float.parseFloat(array[7]));
                    Marca marca = new Marca();
                    marca.setIdMarca(Integer.parseInt(array[8]));
                    marca.setNomeMarca(array[9]);
                    //Como os dados no arquivos estao criptografados o metodo this.decodifica() restaura o valor verdadeiro
                    //de cada atributo
                    choco.setMarca(marca);
                    chocolates.add(choco);
                }
                //Mesmo principio da classe acima mas para o chocolate tipo branco
                else if(array[0].equals("branco")){
                    ChocolateBranco choco = new ChocolateBranco();
                    choco.setNomeC(array[1]);
                    choco.setDescricaoIngre(array[2]);
                    choco.setPesoC(Float.parseFloat(array[3]));
                    choco.setValorNutC(Float.parseFloat(array[4]));
                    choco.setOrigemC(array[5]);
                    choco.setPercManteigaC(Float.parseFloat(array[6]));
                    choco.setPrecoC(Float.parseFloat(array[7]));
                    Marca marca = new Marca();
                    marca.setIdMarca(Integer.parseInt(array[8]));
                    marca.setNomeMarca(array[9]);
                    choco.setMarca(marca);
                    chocolates.add(choco);
                }
            }
        } catch (FileNotFoundException ex) {
            JOptionPane.showMessageDialog(null, "Arquivo não encontrado!");
        } catch (IOException ex) {
            Logger.getLogger(Arquivo.class.getName()).log(Level.SEVERE, null, ex);
        }
        for(int i = 0; i < chocolates.size(); ++i){
            insere(chocolates.get(i));
        }
        
    }
    /**
     * Metodo que codifica os dados do arquivo,
     * o metodo recebe uma string como paramentro e retorna uma outra string
     * com a mesma informacao porem codificada
     * @param s
     * @return 
     */
    public String codifica(String s){
        char[] array = s.toCharArray();
        for(int i = 0; i < s.length(); ++i){
            array[i] += 2; //Cada caractere da String é somado em um valor de 2 para o processo de codificação
        }
        s = String.valueOf(array);
        return s;
    }
    /**
     * Metodo que decodifica os dados do arquivo,
     * o metodo recebe uma string como paramentro e retorna uma outra string
     * com a mesma informacao porem decodificada
     * @param s
     * @return 
     */
    public String decodifica(String s){
        char[] array = s.toCharArray();
        for(int i = 0; i < s.length(); ++i){
            array[i] -= 2; //Cada caractere da String é subtraido em um valor de 2 para o processo de codificação
        }
        s = String.valueOf(array);
        return s;
    }
}
