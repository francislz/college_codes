package trabalhoppoo.exceptions;

// Classe para excessão de estrutura cheia
public class FullStructureException extends Exception{
    //Construtor Padrão
    public FullStructureException() {
        super("Full Structure");
    }
    
    //Construtor que recebe a mensagem personalizada pelo desenvolvedor
    public FullStructureException(String message){
        super(message);
    }
}
