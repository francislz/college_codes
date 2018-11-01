/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package principal;


/**
 *
 * @author franciscone
 */
public class JogoDaVelha {
    private char[][] tabuleiro;// = new int[3][3];

    public JogoDaVelha() {
        tabuleiro = new char[3][3];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                tabuleiro[i][j] = ' ';
            }
        }
    }
    
    public boolean fazJogada(char peca, int posL, int posC){
        if(tabuleiro[posL - 1][posC - 1] == ' '){
            tabuleiro[posL - 1][posC - 1] = peca;
            return true;
        }
        else
            return false;
    }
    
    public String verificaVencedor(){
        boolean igual = false;
        char valor = ' ';
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if((tabuleiro[i][0] == tabuleiro[i][j]) && (tabuleiro[i][0] != ' ')){
                    valor = tabuleiro[i][0];
                    igual = true;
                }
                else
                    igual = false;
            }
            if(igual){
                return "O jogador com " + valor + " venceu !";
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if((tabuleiro[0][i] == tabuleiro[j][i]) && (tabuleiro[0][i] != ' ')){
                    valor = tabuleiro[0][i];
                    igual = true;
                }
                else
                    igual = false;
            }
            if(igual){
                return "O jogador com " + valor + " venceu !";
            }
        }
        for(int i = 1; i < 3; i++){
            if((tabuleiro[0][0] == tabuleiro[i][i]) && (tabuleiro[0][0] != ' ')){
                valor = tabuleiro[0][0];
                igual = true;
            }
            else
                igual = false;
        }
        if(igual){
            return "O jogador com " + valor + " venceu !";
        }
        for(int i = 1; i < 3; i++){
            if((tabuleiro[0][2] == tabuleiro[i][2 - i]) && (tabuleiro[0][2] != ' ')){
                valor = tabuleiro[0][0];
                igual = true;
            }
            else
                igual = false;
        }
        if(igual){
            return "O jogador com " + valor + " venceu !";
        }
        return null;
    }
    
    public void printTab(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                System.out.print(tabuleiro[i][j]);
                if(j < 2){
                    System.out.print("|");
                }
            }
            System.out.println("");
            System.out.println("------");
        }
    }
    
    public boolean verificaVelha(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(tabuleiro[i][j] == ' '){
                    return true;
                }
            }
        }
        return false;
    }
    
}
