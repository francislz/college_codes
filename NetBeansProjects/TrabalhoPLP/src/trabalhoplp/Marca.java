/* 
   Trabalho de Paradigma Orientado Objetos
   Paradigmas de Linguagens de Programação
   Método de Gravação em arquivos usando Orientação a Obejtos
   Cadastro de Barras de Chocolate
   Copyright 2017 by Franciscone Luiz, Victor Hugo, Lucas Hideki 
   Arquivo com a classe Marca. Abstração dos dados de um marca para um modelo computacional. 
   Descrição das funcionalidades nos comentários
*/
package trabalhoplp;

import java.io.Serializable;

/**
 * Abstracao de uma Marca em uma classe com seus atributos e metodos
 */
public class Marca implements Serializable{
    private int idMarca;
    private String nomeMarca;
    //Construtor com todos os atributos da classe
    public Marca(int idMarca, String nomeMarca) {
        this.idMarca = idMarca;
        this.nomeMarca = nomeMarca;
    }
    //Construtor vazio da classe
    public Marca() {
    }
    /**
     * Os metodos abaixo sao os get's e os set's que fazer a alteração de forma indireta dos valores dos atributos
     * @return 
     */
    public int getIdMarca() {
        return idMarca;
    }

    public void setIdMarca(int idMarca) {
        this.idMarca = idMarca;
    }

    public String getNomeMarca() {
        return nomeMarca;
    }

    public void setNomeMarca(String nomeMarca) {
        this.nomeMarca = nomeMarca;
    }
    //Metodo que imprime todos os dados do objeto como uma string
    @Override
    public String toString() {
        return "Marca: " + "ID Marca: " + idMarca + ", Nome Marca: " + nomeMarca;
    }
    
}
