package trabalhoppoo.structures;

import trabalhoppoo.exceptions.EmptyStructureException;
import trabalhoppoo.exceptions.FullStructureException;

public class Queue extends Structure{
    private Node first;
    private Node last;
    //padrao Singleton
    // funcionalidade no codigo:
    // não criar um novo objeto da estrutura em momento nenhum
    private static Queue instancia = null;
    public static Queue getInstancia(){
        if (instancia == null) {
            instancia = new Queue();
        }
        return instancia;
    }
    
    //Cria uma Fila de tamanho 0
    private Queue() {
        super(0);
        this.first = null;
        this.last = null;
    }
    
    @Override
    public String push(int value) throws FullStructureException{
        //Limita a fila a ate 7 elementos
        //Se a fila ja estiver cheia, lanca uma excessao
        if(super.getSize() == 6){
            throw new FullStructureException("Fila nao pode ultrapassar 6 nos");
        }
        //Senão, cria o nó e insere na fila
        else{
            //Insere no final
            Node newNode = new Node(value); 
            if(super.getSize() == 0){
                this.first = newNode;
                this.last = newNode;
            }
            else{
                last.setNext(newNode);
                this.last = newNode;
            }
            super.incrementSize();
        }
        //Retorna uma string com o valor inserido para mostrar na tela
        String aux = "Valor inserido: " + value + "\nInsercao na cauda\n";
        return aux;
    }

    @Override
    public String pop() throws EmptyStructureException {
        //Se a estrutura nao estiver vazia pode remover normalmente
        if(super.getSize() != 0){
            //Na fila remove-se o primeiro elemento
            Node aux = first;
            
            //Atualiza o primeiro como o proximo
            first = aux.getNext();

            //Decrementa o tamanho
            super.decrementSize();
            
            //Retorna a string com o valor
            String aux2 = "Valor removido: " + aux.getValue() + "\nRemoção da cabeça\n";
            return aux2;
        }
        else{ //Senao lanca uma excessao
            throw new EmptyStructureException();
        }
    }

    //Retorna o primeiro elemento da fila
    @Override
    public Node returnFirst() {
        return this.first;
    }
}
