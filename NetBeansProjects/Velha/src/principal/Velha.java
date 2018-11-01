/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package principal;

import static java.lang.System.in;
import java.util.Scanner;

/**
 *
 * @author franciscone
 */
public class Velha {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        JogoDaVelha novo = new JogoDaVelha();
        Scanner ent = new Scanner(System.in);
        boolean velha = true;
        int i = 0;
        do{
           if(i % 2 == 0){
               System.out.println("Vez do jogador 1: ");
               System.out.println("Digite a linha para preencher:");
               int lin = ent.nextInt();
               System.out.println("Digite a coluna para preencher:");
               int col = ent.nextInt();
               novo.fazJogada('X', lin, col);
           } 
           else{
               System.out.println("Vez do jogador 2: ");
               System.out.println("Digite a linha para preencher:");
               int lin = ent.nextInt();
               System.out.println("Digite a coluna para preencher:");
               int col = ent.nextInt();
               novo.fazJogada('O', lin, col);
           }
           i++;
           novo.printTab();
           String venceu = novo.verificaVencedor();
           if(venceu == null){
               if(!novo.verificaVelha()){
                   System.out.println("Deu velha");
                   velha = false;
               }
           }
           else{
               System.out.println(venceu);
               velha = false;
           }
        }while(velha);
    }
    
}
