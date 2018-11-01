/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package simulado.gui;

import java.awt.Component;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import simulado.exceptions.EmptyEmailException;
import simulado.exceptions.MaxLengthException;

/**
 *
 * @author franciscone
 */
public class Simulado extends JFrame{

    private JButton btnEnviar;
    private GridBagLayout gbl;
    private GridBagConstraints gbc;
    private JLabel lbEmail;
    private JTextField txtEmail;
    private JTextArea txtAreaMessage;

    public Simulado() {
        super("Escrever Mensagem");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        buildLayout();
        pack();
    }
    
    public void buildLayout(){
        gbl = new GridBagLayout();
        gbc = new GridBagConstraints();
        
        setLayout(gbl);
        
        btnEnviar = new JButton("Enviar");
        btnEnviar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                BufferedWriter bw = null;
                try{
                    bw = new BufferedWriter(new FileWriter("logs_email.txt", true));
                    Calendar cal = Calendar.getInstance();
                    SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyy HH:mm:ss");
                    
                    String email = getEmail();
                    String message = getMessage();
                    
                    String outputText = sdf.format(cal.getTime()) + " " + email + " ("
                            + message + " - " + message.length() + ")\n";
                    
                    bw.write(outputText);
                    
                    JOptionPane.showMessageDialog(null, "Messagem enviada com sucesso !");
                } catch (EmptyEmailException | MaxLengthException ex) {
                    JOptionPane.showMessageDialog(null, "Email de destino ou mensagem invalidos !");
                } catch (IOException ex) {
                    Logger.getLogger(Simulado.class.getName()).log(Level.SEVERE, null, ex);
                }finally{
                    if(bw != null){
                        try{
                            bw.close();
                        } catch (IOException ex) {
                            Logger.getLogger(Simulado.class.getName()).log(Level.SEVERE, null, ex);
                        }
                    }
                    cleanFields();
                }
            }
        });
        
        lbEmail = new JLabel("Email de destino:");
        txtEmail = new JTextField(20);
        txtAreaMessage = new JTextArea(5, 20);
        
        addComponent(lbEmail, GridBagConstraints.CENTER, GridBagConstraints.BOTH, 1, 1, 0, 0);
        addComponent(txtEmail, GridBagConstraints.CENTER, GridBagConstraints.BOTH, 1, 1, 1, 0);
        addComponent(txtAreaMessage, GridBagConstraints.CENTER, GridBagConstraints.BOTH, 1, 2, 0, 1);
        addComponent(btnEnviar, GridBagConstraints.CENTER, GridBagConstraints.NONE, 1, 2, 0, 2);
    }
    
    public void addComponent(Component c, int anchor, int fill, int gridh, int gridw, int gridx, int gridy){
        gbc.anchor = anchor;
        gbc.fill = fill;
        gbc.gridheight = gridh;
        gbc.gridwidth = gridw;
        gbc.gridx = gridx;
        gbc.gridy = gridy;
        gbc.insets = new Insets(2, 2, 2, 2);
        gbl.setConstraints(c, gbc);
        add(c);
    }
    
    public String getEmail() throws EmptyEmailException{
        if(txtEmail.getText().isEmpty()){
            throw new EmptyEmailException();
        }
        return txtEmail.getText();
    }
    
    public String getMessage() throws MaxLengthException{
        if(txtAreaMessage.getText().length() > 144){
            throw new MaxLengthException();
        }
        return txtAreaMessage.getText();
    }
    
    public void cleanFields(){
        txtAreaMessage.setText("");
        txtEmail.setText("");
    }
    
    public static void main(String[] args) {
        new Simulado().setVisible(true);
        
    }
    
}
