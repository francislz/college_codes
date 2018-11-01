/* 
   Trabalho de Paradigma Orientado Objetos
   Paradigmas de Linguagens de Programação
   Método de Gravação em arquivos usando Orientação a Obejtos
   Cadastro de Barras de Chocolate
   Copyright 2017 by Franciscone Luiz, Victor Hugo, Lucas Hideki 
   Arquivo com a classe Chocolate. Abstração dos dados de um chocolate para um modelo computacional. 
   Descrição das funcionalidades nos comentários
*/
package trabalhoplp;

import java.io.Serializable;
import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
/**
 * Abstracao de um chocolate para um classe com seus atributos mais importantes.
 */
public class Chocolate implements Serializable{
    private String nomeC;
    private String descricaoIngre;
    private float pesoC;
    private float valorNutC;
    private float precoC;
    private String origemC;
    private Marca marca; //Atributo tipo marca Marca Agrega o chocolate
    //Construtor vazio da classe Chocolate
    protected Chocolate(){}
    //Construtor com todos os atributos da classe chocolate
    public Chocolate(String nomeC, String descricaoIngre, float pesoC, float valorNutC, float precoC, String origemC, Marca marca) {
        this.nomeC = nomeC;
        this.descricaoIngre = descricaoIngre;
        this.pesoC = pesoC;
        this.valorNutC = valorNutC;
        this.precoC = precoC;
        this.origemC = origemC;
        this.marca = marca;
    }
    /**
     * Os metodos abaixo sao os get's e os set's que fazer a alteração de forma indireta dos valores dos atributos
     * @return 
     */
    public String getNomeC() {
        return nomeC;
    }

    public void setNomeC(String nomeC) {
        this.nomeC = nomeC;
    }

    public String getDescricaoIngre() {
        return descricaoIngre;
    }

    public void setDescricaoIngre(String descricaoIngre) {
        this.descricaoIngre = descricaoIngre;
    }

    public float getPesoC() {
        return pesoC;
    }

    public void setPesoC(float pesoC) {
        this.pesoC = pesoC;
    }

    public float getValorNutC() {
        return valorNutC;
    }

    public void setValorNutC(float valorNutC) {
        this.valorNutC = valorNutC;
    }

    public float getPrecoC() {
        return precoC;
    }

    public void setPrecoC(float precoC) {
        this.precoC = precoC;
    }

    public String getOrigemC() {
        return origemC;
    }

    public void setOrigemC(String origemC) {
        this.origemC = origemC;
    }

    public Marca getMarca() {
        return marca;
    }

    public void setMarca(Marca marca) {
        this.marca = marca;
    }
    //Metodo que imprime todos os dados do objeto como uma string
    @Override
    public String toString() {
        return "Nome Chocolate: " + nomeC + " -> " + marca.toString();
    }
    
    public boolean verificaNulos(){
        for (Field field : ChocolateBranco.class.getDeclaredFields()) {
            if (Modifier.isPrivate(field.getModifiers())) {
                if((String.class.isAssignableFrom(field.getType()))){
                    if(field == null)
                        return true;
                }
            }
        }
        return false;
    }
}
