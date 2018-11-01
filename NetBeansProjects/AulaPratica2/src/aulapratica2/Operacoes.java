/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aulapratica2;

import java.util.ArrayList;

/**
 *
 * @author franciscone
 */
public interface Operacoes {
    public ArrayList<Carro> ler();
    public void insere(ArrayList<Carro> carros);
    public void excluir(String chassi);
}