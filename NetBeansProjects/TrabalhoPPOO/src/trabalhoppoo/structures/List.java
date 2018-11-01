package trabalhoppoo.structures;

import java.util.concurrent.ThreadLocalRandom;
import trabalhoppoo.exceptions.EmptyStructureException;
import trabalhoppoo.exceptions.FullStructureException;


public class List extends Structure{
    private Node first;
    private Node last;
    //padrao Singleton
    // funcionalidade no codigo:
    // não criar um novo objeto da estrutura em momento nenhum
    private static List instancia = null;
    public static List getInstancia(){
        if (instancia == null) {
            instancia = new List();
        }
        return instancia;
    }
    
    private List() {
        super(0);
        first = null;
        last = null;
    }

   
    @Override
    public String push(int value) throws FullStructureException{
        if(super.getSize() == 6){
            throw new FullStructureException("Lista nao pode ultrapassar 6 nos");
        }
        else{
            //novo noh
            Node newNode = new Node(value);
            //posicao a ser inserido o novo noh
            int pos;
            //se tamanho igual diferente de 0, pos recebe um valor aleatorio 
            if(super.getSize() != 0){
                pos = ThreadLocalRandom.current().nextInt(0, super.getSize());
            }
            //se lista vazia, pos recebe 0
            else{
                pos = 0;
            }
            //insere na posicao 0
            if(pos == 0){
                newNode.setNext(first);
                first = newNode;
                if(super.getSize() == 0){
                    last = newNode;
                }
            }
            else{
                Node aux;
                //adicionando no fim

                if(pos == super.getSize()){
                    aux = last;
                    aux.setNext(newNode);
                    last = newNode;
                }
                //adicionar em alguma posiçao no meio
                else{
                    aux = first.getNext();
                    Node temp = first;
                    int i = 1;
                    // aux encontra o noh a ser removido
                    // temp encontra o noh anterior ao noh a ser removido
                    while(i < pos){
                        temp = aux;
                        aux = aux.getNext();
                        i++;
                    }
                    newNode.setNext(aux);
                    temp.setNext(newNode);

                }
            } 
            //incrementa o tamanho
            super.incrementSize();
            String aux = "Valor inserido: " + value + "\nPosicao: " + pos + "\n";
            return aux;
        }
        //return "";
    }

    @Override
    public String pop() throws EmptyStructureException {
        int pos;
        if(super.getSize() > 1){
            //posiçao aleatoria dentro das inseridas na lista
            pos = ThreadLocalRandom.current().nextInt(0, (super.getSize()-1));
        }
        else{
            //se a lista so' tem um elemento, posicao recebe 0
            pos = 0;
        }
        
        //se a lista nao esta vazia
        if(super.getSize() != 0){
            //aux recebe o primeiro
            Node aux = first;
            // testa se o valor a ser removido e' o primeiro
            if(pos == 0){
                //ponteiro para o primeiro aponta para o segundo
                first = aux.getNext();
                
            }
            else{
                //remover um elemento diferente do primeiro
                Node temp = null;
                int i = 0;
                // aux encontra o noh a ser removido
                // temp encontra o noh anterior ao noh a ser removido
                while(i < pos){
                    temp = aux;
                    aux = aux.getNext();
                    i++;
                }
                //testa se o noh a ser removido e' o ultimo 
                if(pos+1 == super.getSize()){
                    //temp.next aponta para nulo e ultimo aponta para temp
                    temp.setNext(null);
                    last.setNext(temp);
                }
                // o noh a ser removido nao e' o ultimo
                else{
                    //o noh anterior ao noh a ser removido aponta para o noh sucessor do noh removido
                    temp.setNext(aux.getNext());
                }
            }
            //decrementa o tamanho da lista
            super.decrementSize();
            //retorna o valor que foi removido
            //return aux.getValue();
            
            String aux2 = "Valor removido: " + aux.getValue() + "\nPosicao: " + pos + "\n";
            return aux2;
        }
        //se a lista estiver vazia retorna uma mensagem de erro
        else{
            throw new EmptyStructureException();
        }
        
    }

    @Override
    public Node returnFirst() {
        return first;
    }
    
}
