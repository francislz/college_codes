/* 
   Trabalho de Paradigma Orientado Objetos
   Paradigmas de Linguagens de Programação
   Método de Gravação em arquivos usando Orientação a Obejtos
   Cadastro de Barras de Chocolate
   Copyright 2017 by Franciscone Luiz, Victor Hugo, Lucas Hideki 
   Arquivo com a classe Chocolate Preto. Abstração dos dados de um chocolate preto para um modelo computacional. 
   Descrição das funcionalidades nos comentários
*/
package trabalhoplp;

/**
 * Chocolate do tipo Preto, com uma Heranca dos metodos e atributos da classe Chocolate
 */
public class ChocolatePreto extends Chocolate{
    private float percCacau;
    //Construtor com todos os atributos da classe chocolatePreto
    public ChocolatePreto(float percCacau, String nomeC, String descricaoIngre, float pesoC, float valorNutC, float precoC, String origemC, Marca marca) {
        super(nomeC, descricaoIngre, pesoC, valorNutC, precoC, origemC, marca);//Chamada do contrutor da super classe
        this.percCacau = percCacau;
    }
    //Construtor vazio da classe ChocolatePreto
    public ChocolatePreto() {
        super();//Chamada do contrutor da super classe
    }
    /**
     * Os metodos abaixo sao os get's e os set's que fazer a alteração de forma indireta dos valores dos atributos
     * @return 
     */
    public float getPercCacau() {
        return percCacau;
    }

    public void setPercCacau(float percCacau) {
        this.percCacau = percCacau;
    }
    
    
}
