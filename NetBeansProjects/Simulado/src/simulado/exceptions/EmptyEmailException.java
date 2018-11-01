/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package simulado.exceptions;

/**
 *
 * @author franciscone
 */
public class EmptyEmailException extends Exception{

    public EmptyEmailException() {
        super("The text field email is empty");
    }
    
}
