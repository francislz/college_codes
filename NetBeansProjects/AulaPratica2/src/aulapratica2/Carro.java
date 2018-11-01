/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aulapratica2;

/**
 *
 * @author franciscone
 */
public class Carro {
    private String numChassi;
    private String marca;
    private String modelo;
    private int ano;
    private String tipo;
    private String cor;
    private boolean automatico;
    private float preco;

    public Carro(String numChassi, String marca, String modelo, int ano, String tipo, String cor, boolean automatico, float preco) {
        this.numChassi = numChassi;
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
        this.tipo = tipo;
        this.cor = cor;
        this.automatico = automatico;
        this.preco = preco;
    }
    
    
    
}
