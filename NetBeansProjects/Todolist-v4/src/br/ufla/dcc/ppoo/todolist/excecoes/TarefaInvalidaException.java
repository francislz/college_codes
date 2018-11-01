package br.ufla.dcc.ppoo.todolist.excecoes;

public class TarefaInvalidaException extends Exception {
    public TarefaInvalidaException(String motivo) {
        super("Tarefa inválida: " + motivo); 
    }
}
