package trabalhoppoo.structures;

import trabalhoppoo.exceptions.EmptyStructureException;
import trabalhoppoo.exceptions.FullStructureException;

public class Stack extends Structure{
    private Node top;
    //padrao Singleton
    // funcionalidade no codigo:
    // não criar um novo objeto da estrutura em momento nenhum
    private static Stack instancia = null;
    public static Stack getInstancia(){
        if (instancia == null) {
            instancia = new Stack();
        }
        return instancia;
    }
    
    private Stack() {
        super(0);
        this.top = null;
    }
    
    @Override
    public String push(int value) throws FullStructureException{
        if(super.getSize() == 5){
            throw new FullStructureException("Pilha nao pode ultrapassar 5 nos");
            //JOptionPane.showMessageDialog(null,"Pilha nao pode ultrapassar 5 nos","Pilha Cheia",JOptionPane.ERROR_MESSAGE);
        }
        else{
            
            //novo noh
            Node newNode = new Node(value); 
            //se a pilha esta vazia, topo aponta para novo noh
            if(super.getSize() == 0){
                this.top = newNode;
            }
            //se a pilha não esta vazia, novo noh aponta para o noh no topo 
            //e novo noh torna-se o topo
            else{
                newNode.setNext(top);
                this.top = newNode;
            }
            //incrementa
            super.incrementSize();
        }
            String aux = "Valor inserido: " + value + "\nInserção no Topo\n";
            return aux;
    }

    @Override
    public String pop() throws EmptyStructureException {
        //se a pilha nao esta vazia
        if(super.getSize() != 0){
            // noh aux aponta pro noh no topo
            Node aux = top;
            // topo atualiza para o noh sucessor do topo
            top = top.getNext();
            // decrementa o tamanho
            super.decrementSize();
            //retorna o valor desimpilhado
            String aux2 = "Valor removido: " + aux.getValue() + "\nRemoção do Topo\n";
            return aux2;
            
        }
        else{
            //se a pilha estiver vazia, retorna uma excessao
            throw new EmptyStructureException();
        }
    }

    @Override
    public Node returnFirst() {
        return this.top;
    }

   
}
