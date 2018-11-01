package trabalhoppoo.gui;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JSplitPane;

public class Main extends JFrame{
    
    //Cria os paineis a serem usados
    private JSplitPane splitPane;
    private RightPanel rightP;
    private LeftPanel leftP; 
    
    //Construtor
    public Main() {
        super("Tela Principal");
        criarTela();
        setSize(500, 400);
    }
    
    private void criarTela(){
        //Seta o Layout
        setLayout(new GridLayout(1, 1));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        //Cria e configura os paineis
        rightP = new RightPanel(new FlowLayout());
        rightP.setBackground(Color.decode("#ffffe6"));
        leftP = new LeftPanel(new GridLayout(11, 1, 5, 5), rightP);
        leftP.setBackground(Color.black);
        leftP.disableStructureButtons();
        
        //Cria o painel de divisão
        splitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, leftP, rightP);
        //Adciona o painel como principal
        add(splitPane);
        //Desativa a opção de redimensionar
        setResizable(false);
        //Agrupa os componentes
        pack();
    }
    
    public static void main(String[] args) {
        //Cria uma nova tela
        new Main().setVisible(true);
    }
    
}
