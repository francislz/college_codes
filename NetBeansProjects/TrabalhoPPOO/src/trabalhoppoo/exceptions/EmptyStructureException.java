package trabalhoppoo.exceptions;

// Classe para excessão de estrutura vazia
public class EmptyStructureException extends Exception{
    //Construtor Padrao com mensagem do sistema
    public EmptyStructureException() {
        super("Empty Structure");
    }

    //Construtor que recebe a mensagem personalizada
    public EmptyStructureException(String message) {
        super(message);
    }
}
