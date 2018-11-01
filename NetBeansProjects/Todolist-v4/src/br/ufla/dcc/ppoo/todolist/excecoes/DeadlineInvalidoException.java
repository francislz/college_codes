package br.ufla.dcc.ppoo.todolist.excecoes;

public class DeadlineInvalidoException extends Exception {
    public DeadlineInvalidoException(String data, String motivo) {
        super("A data \"" + data + "\" é inválida: " + motivo); 
    }
}
