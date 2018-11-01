package br.dcc.ufla.ppoo.todolist.tarefa;

import java.io.Serializable;

public class Tarefa implements Serializable {
    private String tarefa;
    private String deadline;

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
