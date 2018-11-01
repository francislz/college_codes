/* 
   Trabalho de Paradigma Orientado Objetos
   Paradigmas de Linguagens de Programação
   Método de Gravação em arquivos usando Orientação a Obejtos
   Cadastro de Barras de Chocolate
   Copyright 2017 by Franciscone Luiz, Victor Hugo, Lucas Hideki 
   Arquivo com a interface Operacoes. Implementacao de operacoes basicas em arquivo. 
   Descrição das funcionalidades nos comentários
*/
package trabalhoplp;

import java.util.ArrayList;

/**
 *
 * Interface que contem as funcoes basicas para manipulação de dados
 * A interface foi usada pois a principio esse sistema dados é apenas
 * em um arquivo de texto, mas caso fosse necessario extender isso
 * para outro tipo de armazenamento de dados como um banco de dados
 * as funcoes poderiam ser aproveitandas na classe que fizesse as 
 * operações de controle no banco de dados.
 * 
 */
public interface Operacoes {
    public void insere(Object objeto); //O metodo de inserir recebe um objeto generico e uma variavel boleana como parametro
    public ArrayList<Object> busca(String nomeC); //O metodo recebe um nome a ser buscado e retorna em uma Lista uma ou mais correspondencias
    public void remove(String nomeC); //Recebe um nome e remove ele dos cadastros
    public void recupera(String nome); //Recupera os dados salvos em um arquivo
    public ArrayList<Object> retornaTodos(); //Retorna Todos os dados salvos
    
}
