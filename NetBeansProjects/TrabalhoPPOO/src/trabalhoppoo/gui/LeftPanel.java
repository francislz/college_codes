package trabalhoppoo.gui;

import java.awt.Color;

import java.awt.LayoutManager;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.concurrent.ThreadLocalRandom;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import trabalhoppoo.exceptions.EmptyStructureException;
import trabalhoppoo.exceptions.FullStructureException;
import trabalhoppoo.structures.*;

public class LeftPanel extends JPanel{
	//Atributos dos botoes que selecionam as estruturas
    private JButton btnStack;
    private JButton btnQueue;
    private JButton btnList;
    
    //Atributos que fazem as operações nas estruturas
    private JButton btnNewNode;
    private JButton btnDeleteNode;
    private JButton btnHome;
    
    //Rotulos para Identificar os botoes
    private JLabel lbStructures;
    private JLabel lbActions;
    
    //Referencia para o painel onde as estruturas serão desenhadas
    private RightPanel drawPanel;
    
    public LeftPanel(LayoutManager layout, RightPanel drawPanel) {
        //Seta o gerenciador de layout do painel de botoes
        super(layout);
        
        //Atribui referencia do painel de desenho
        this.drawPanel = drawPanel;
        
        //Cria o botao para a estrutura pilha e define seu icon
        btnStack = new JButton("PILHA", new  ImageIcon(getClass().getResource("img/stack.png")));
        //Add ação para click no botao
        btnStack.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                disableChoiceButtons(btnStack); //Desativa os botoes de escolha das estruturas
                drawPanel.setStruct(Stack.getInstancia()); //Usa o Singleton para pegar a estrutura ativa
                drawPanel.repaint();//Redesenha as formas no painel
                
            }
        });
        
        //Cria o botao para a estrutura fila e define seu icon
        btnQueue = new JButton("FILA", new  ImageIcon(getClass().getResource("img/queue.png")));
        //Add ação para click no botao
        btnQueue.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                disableChoiceButtons(btnQueue); //Desativa os botoes de escolha das estruturas
                drawPanel.setStruct(Queue.getInstancia());//Usa o Singleton para pegar a estrutura ativa
                drawPanel.repaint();//Redesenha as formas no painel
            }
        });
        
        //Cria o botao para a estrutura Lista e define seu icon
        btnList = new JButton("LISTA", new  ImageIcon(getClass().getResource("img/list.png")));
        //Add ação para click no botao
        btnList.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                disableChoiceButtons(btnList);//Desativa os botoes de escolha das estruturas
                drawPanel.setStruct(List.getInstancia());//Usa o Singleton para pegar a estrutura ativa
                drawPanel.repaint();//Redesenha as formas no painel
            }
        });
        
        //Cria o botao para adicionar um no e define suas configurações     
        btnNewNode = new JButton("INSERIR", new  ImageIcon(getClass().getResource("img/add_node.png")));
        //Add ação no botão
        btnNewNode.addActionListener(new ActionListener() {
            @Override
            //Tentar inserir na estrutura, se der erro pega a exceção e mostra na tela
            public void actionPerformed(ActionEvent e) {
                //Gera um valor aleatorio para inserção
                int value = ThreadLocalRandom.current().nextInt(0, 100);
                try {
                    //Insere na estrutura setada
                    drawPanel.getStruct().push(value);
                } catch (FullStructureException ex) {
                    //Exceção de estrutura cheia
                    JOptionPane.showMessageDialog(null, ex.getMessage(), "Estrutura Cheia", JOptionPane.ERROR_MESSAGE);
                }
                //Repaint a estrutura modificada
                drawPanel.repaint();
            }
        });
        
        //Cria o bota de remover o no com suas configuracoes
        btnDeleteNode = new JButton("REMOVER", new  ImageIcon(getClass().getResource("img/delete_node.png")));
        //Add a ação de remoção
        btnDeleteNode.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //Tenta realizar a remoção
                try {
                    drawPanel.getStruct().pop();
                    drawPanel.repaint();
                } catch (EmptyStructureException ex) {
                    //Se não for possivel mostra a exceção numa caixa de mensagem
                    JOptionPane.showMessageDialog(null, ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });
        
        //Cria o botao home com as suas configurações
        btnHome = new JButton("Home", new  ImageIcon(getClass().getResource("img/home.png")));
        //Cria a ação para reativar o menu principal e desativar os botoes de ação
        btnHome.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                drawPanel.setStruct(null);
                drawPanel.repaint();
                disableStructureButtons();
            }
        });
        //Cria as labels para identificar os botoes
        lbStructures = new JLabel("ESTRUTURAS");
        lbStructures.setForeground(Color.orange);
        lbActions = new JLabel("OPÇÕES");
        lbActions.setForeground(Color.orange);
        
        //Add cada component no painel de botoes
        add(lbStructures);
        add(btnStack);
        add(btnQueue);
        add(btnList);
        add(lbActions);
        add(btnNewNode);
        add(btnDeleteNode);
        add(btnHome);
        
    }
    
    //Metodo para configurar os botoes das estruturas
    public void disableStructureButtons(){
        btnNewNode.setEnabled(false);
        btnDeleteNode.setEnabled(false);
        btnHome.setEnabled(false);
        btnNewNode.setBackground(Color.orange);
        btnDeleteNode.setBackground(Color.orange);
        btnHome.setBackground(Color.orange);
        btnList.setEnabled(true);
        btnQueue.setEnabled(true);
        btnStack.setEnabled(true);
        DefaultButtons();
    }
    
    //Ativa os botoes de ações
    public void enableStructureButtons(){
        btnNewNode.setEnabled(true);
        btnDeleteNode.setEnabled(true);
        btnHome.setEnabled(true);
    }

    //Desativa os botoes de escolha das estruturas
    public void disableChoiceButtons(JButton button){
        btnList.setEnabled(false);
        btnQueue.setEnabled(false);
        btnStack.setEnabled(false);
        button.setBackground(Color.decode("#ffffe6"));
        enableStructureButtons();
    }

    //Configura as cores padroes
    public void DefaultButtons(){
        btnList.setBackground(Color.orange);
        btnList.setForeground(Color.black);
        btnQueue.setBackground(Color.orange);
        btnQueue.setForeground(Color.black);
        btnStack.setBackground(Color.orange);
        btnStack.setForeground(Color.black);
    }
}
