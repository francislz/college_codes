package trabalhoppoo.gui;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.LayoutManager;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;
import javax.swing.JPanel;
import trabalhoppoo.structures.*;

public class RightPanel extends JPanel{
    //Constantes dos Dimensões dos components
    //Dimensões texto (numero que representa o no)
    private int POS_TEXT_X = 20;
    private int POS_TEXT_Y = 40;
    //Dimensões do circulo
    private int POS_CIRCLE = 30;
    private int RADIUS = 30;
    //Dimensoes das imagens
    private int POS_IMG = POS_CIRCLE + 3;
    //Declaração dos atributos
    private Structure struct;
    //Imagens
    private BufferedImage arrow;
    private BufferedImage nullPointer;
    
    public RightPanel(LayoutManager layout) {
        super(layout);//Seta o layout
        struct = null;//Inicializa as estruturas
        
        try {
            //Carrega a imagem que e o ponteiro nulo
            nullPointer = ImageIO.read(new File("src/trabalhoppoo/gui/img/null_pointer.png"));
        } catch (IOException ex) {
            //Log de erro no carregamento
            System.out.println(ex.getMessage());
        }
        
    }
    
    protected void paintComponent(Graphics g){
        super.paintComponent(g);
        //setar a tela para vazio
        if (struct == null) {
            g.drawImage(null, (0 * (POS_CIRCLE + RADIUS)), POS_IMG, null);
        }
        else{
            if(struct instanceof Stack){
                POS_TEXT_X = 20;
                POS_TEXT_Y = 40;
                POS_CIRCLE = 30;
                RADIUS = 30;
                POS_IMG = POS_CIRCLE + 3;
                
                int i = 0;
                Node temp = struct.returnFirst();

                while(temp != null){
                    String value = String.valueOf(temp.getValue());
                    
                    //Calcula a posicao dos icones com base na posicao do no
                    int posCircleX = (i * (POS_CIRCLE + RADIUS));
                    int posTextX = (i * (POS_CIRCLE + RADIUS)) + POS_TEXT_X;
                    try {
                        //Carrega a seta do pointeiro
                        arrow = ImageIO.read(new File("src/trabalhoppoo/gui/img/arrowS.png"));
                    } catch (IOException ex) {
                        System.out.println(ex.getMessage());
                    }
                    g.setColor(Color.black);
                    g.drawOval( POS_CIRCLE,posCircleX, RADIUS, RADIUS);
                    g.drawString(value, POS_TEXT_Y, posTextX);
                    g.drawImage(arrow, POS_IMG, (posCircleX + RADIUS), null);
                    
                    i++;
                    temp = temp.getNext();
                }
                
                g.drawImage(nullPointer, POS_IMG, (i * (POS_CIRCLE + RADIUS)), null);
            }
        
            //para todas as estruturas
            else{
                //Para List e Queue
                POS_TEXT_X = 7;
                POS_TEXT_Y = 40;
                POS_CIRCLE = 20;
                RADIUS = 30;
                POS_IMG = POS_CIRCLE + 3;
                
                try {
                    arrow = ImageIO.read(new File("src/trabalhoppoo/gui/img/arrow.png"));
                } catch (IOException ex) {
                    Logger.getLogger(RightPanel.class.getName()).log(Level.SEVERE, null, ex);
                }
                int i = 0;
                Node temp = struct.returnFirst();

                while(temp != null){
                    String value = String.valueOf(temp.getValue());

                    int posCircleX = (i * (POS_CIRCLE + RADIUS));
                    int posTextX = (i * (POS_CIRCLE + RADIUS)) + POS_TEXT_X;

                    g.setColor(Color.black);
                    g.drawOval(posCircleX, POS_CIRCLE, RADIUS, RADIUS);
                    g.setColor(Color.black);
                    g.drawString(value, posTextX, POS_TEXT_Y);
                    g.drawImage(arrow, (posCircleX + RADIUS), POS_IMG, null);
                    i++;
                    temp = temp.getNext();
                }

                g.drawImage(nullPointer, (i * (POS_CIRCLE + RADIUS)), POS_IMG, null);
            }
        }
    }

    public Structure getStruct() {
        return struct;
    }

    public void setStruct(Structure struct) {
        this.struct = struct;
    }
}
