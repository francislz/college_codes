package br.ufla.dcc.ppoo.todolist.tarefa;

public class Tarefa {
    private String tarefa;
    private String deadline; // posteriormente, aprenderemos a usar a classe "Date" para trabalhar com datas.

    public Tarefa(String tarefa, String deadline) {
        this.tarefa = tarefa;
        this.deadline = deadline;
    }

    public String getTarefa() {
        return tarefa;
    }

    public String getDeadline() {
        return deadline;
    }
    
    
}
