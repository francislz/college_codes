/* 
   Trabalho de Paradigma Orientado Objetos
   Paradigmas de Linguagens de Programação
   Método de Gravação em arquivos usando Orientação a Obejtos
   Cadastro de Barras de Chocolate
   Copyright 2017 by Franciscone Luiz, Victor Hugo, Lucas Hideki 
   Arquivo com a classe ChocolateBranco. Abstração dos dados de um chocolate branco para um modelo computacional. 
   Descrição das funcionalidades nos comentários
*/
package trabalhoplp;

import java.lang.reflect.Field;
import java.lang.reflect.Modifier;

/**
 * Chocolate do tipo Branco, com uma Heranca dos metodos e atributos da classe Chocolate
 */
public class ChocolateBranco extends Chocolate{
    private float percManteigaC;
    //Construtor com todos os atributos da classe chocolateBranco
    public ChocolateBranco(float percManteigaC, String nomeC, String descricaoIngre, float pesoC, float valorNutC, float precoC, String origemC, Marca marca) {
        super(nomeC, descricaoIngre, pesoC, valorNutC, precoC, origemC, marca); //Chamada do contrutor da super classe
        this.percManteigaC = percManteigaC;
    }
    //Construtor vazio da classe ChocolateBranco
    public ChocolateBranco() {
        super(); //Chamada do contrutor da super classe
    }
    /**
     * Os metodos abaixo sao os get's e os set's que fazer a alteração de forma indireta dos valores dos atributos
     * @return 
     */
    public float getPercManteigaC() {
        return percManteigaC;
    }

    public void setPercManteigaC(float percManteigaC) {
        this.percManteigaC = percManteigaC;
    }
    
}
