package br.ufla.dcc.ppoo.todolist.gui;

import br.ufla.dcc.ppoo.todolist.tarefa.Tarefa;
import java.awt.Component;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.event.TableModelEvent;
import javax.swing.event.TableModelListener;
import javax.swing.table.DefaultTableModel;

public class TelaPrincipal extends JFrame {

    // Componentes referentes ao layout da tela
    private GridBagConstraints gbc;
    private GridBagLayout gbl;

    // Rótulos
    private JLabel lbDescricao;
    private JLabel lbDeadline;

    // Caixas de texto
    private JTextField tfTarefa;
    private JTextField tfDeadline;

    // Componentes necessários para uso da tabela de dados
    // Para saber mais sobre como usar JTable, acesse: https://www.devmedia.com.br/jtable-utilizando-o-componente-em-interfaces-graficas-swing/28857
    private JTable tbTarefas;
    private DefaultTableModel mdDados;
    private JScrollPane painelTarefas;

    // Botões
    private JButton btSalvar;
    private JButton btCopiar;
    private JButton btRemover;
    private JButton btLimpar;
    private JPanel painelBotoes; // container para os botões da tela

    public TelaPrincipal() {
        // Define o título da tela
        super("Lista de Tarefas");

        // Define que fechar a janela, a execução aplicação será encerrada
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Evita que a tela possa ser redimensionada pelo usuário
        setResizable(false);

        // Invoca o método que efetivamente constrói a tela
        construirTela();

        // Redimensiona automaticamente a tela, com base nos componentes existentes na mesma
        pack();
    }

    private void construirTela() {
        // Instancia os objetos de layout da tela
        gbc = new GridBagConstraints();
        gbl = new GridBagLayout();

        // Configura o layout da tela
        setLayout(gbl);

        // Instancia os objetos referentes aos componentes da tela
        lbDescricao = new JLabel("Tarefa");
        lbDeadline = new JLabel("Deadline");

        tfTarefa = new JTextField(29); // 15 refere-se ao tamanho da caixa de texto
        
        tfDeadline = new JTextField(7); // 15 refere-se ao tamanho da caixa de texto

        btSalvar = new JButton("Salvar", new ImageIcon(getClass().getResource("img/salvar.png")));

        // Cria uma classe interna anônima para tratar o evento de clique sobre o botão "Salvar"
        btSalvar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                salvarTarefa();
            }
        });

        btCopiar = new JButton("Copiar", new ImageIcon(getClass().getResource("img/copiar.png")));
        btCopiar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                copiarTarefa();
            }
        });

        btRemover = new JButton("Remover", new ImageIcon(getClass().getResource("img/lixo.png")));
        btRemover.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                removerTarefa();
            }
        });
        
        btLimpar = new JButton("Limpar", new ImageIcon(getClass().getResource("img/limpar.png")));
        btLimpar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int opc = JOptionPane.showConfirmDialog(null, "Tem certeza ?");
                if(opc == JOptionPane.YES_OPTION){
                    mdDados.setRowCount(0);
                }
                configurarBotoesEstadoInsercao();
            }
        });
        btLimpar.setEnabled(false);
        
        configurarBotoesEstadoInsercao();

        // Instancia o painel (container) de botões e adiciona os botões a ele
        painelBotoes = new JPanel(new GridLayout(1, 4, 5, 5));
        painelBotoes.add(btSalvar);
        painelBotoes.add(btCopiar);
        painelBotoes.add(btRemover);
        painelBotoes.add(btLimpar);

        // Constrói o modelo de dados 
        mdDados = new DefaultTableModel(); // Toda tabela possui um modelo de dados, que é onde ficam as informações exibidas pela tabela

        // Adicionando colunas ao modelo de dados. 
        mdDados.addColumn("Tarefa");
        mdDados.addColumn("Deadline");

        // Constrói a tabela, com base no modelo de dados
        tbTarefas = new JTable(mdDados);
        tbTarefas.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent lse) {
                configurarBotoesEstadoSelecao();
            }
        });
        
        mdDados.addTableModelListener(new TableModelListener() {
            @Override
            public void tableChanged(TableModelEvent e) {
                if(mdDados.getRowCount() > 0){
                    btLimpar.setEnabled(true);
                }
                else{
                    btLimpar.setEnabled(false);
                }
            }
        });

        // Configura o tamanho das colunas da tabela
        tbTarefas.getColumnModel().getColumn(0).setMaxWidth(400);
        tbTarefas.getColumnModel().getColumn(1).setMaxWidth(100);

        // Uma tabela precisam estar inserida em um componente JScrollPane, para que barras de rolagem sejam adicionadas a ela
        painelTarefas = new JScrollPane(tbTarefas);

        // Adicionando os componentes recém-criados à tela
        adicionarComponente(lbDescricao, GridBagConstraints.CENTER, GridBagConstraints.NONE, 0, 0, 1, 1);
        adicionarComponente(lbDeadline, GridBagConstraints.CENTER, GridBagConstraints.NONE, 0, 1, 1, 1);
        adicionarComponente(tfTarefa, GridBagConstraints.EAST, GridBagConstraints.BOTH, 1, 0, 1, 1);
        adicionarComponente(tfDeadline, GridBagConstraints.EAST, GridBagConstraints.BOTH, 1, 1, 1, 1);
        adicionarComponente(painelBotoes, GridBagConstraints.CENTER, GridBagConstraints.BOTH, 2, 0, 2, 1);
        adicionarComponente(painelTarefas, GridBagConstraints.CENTER, GridBagConstraints.BOTH, 3, 0, 2, 1);
    }

    private void configurarBotoesEstadoInsercao() {
        btCopiar.setEnabled(false);
        btRemover.setEnabled(false);
        btSalvar.setEnabled(true);
        //btLimpar.setEnabled(false);
        
    }

    private void configurarBotoesEstadoSelecao() {
        btCopiar.setEnabled(true);
        btRemover.setEnabled(true);
        btSalvar.setEnabled(false);
        //btLimpar.setEnabled(true);
    }

    private void adicionarTarefa(Tarefa t) {
        String[] dados = new String[2];
        dados[0] = t.getTarefa();
        dados[1] = t.getDeadline();
        mdDados.addRow(dados);
    }

    private void copiarTarefa() {
        Tarefa t = obterTarefaSelecionada();
        if (t != null) {
            tfTarefa.setText(t.getTarefa());
            tfDeadline.setText(t.getDeadline());

            // Desmarca a linha selecionada na tabela pelo usuário
            tbTarefas.getSelectionModel().clearSelection();

            configurarBotoesEstadoInsercao();
        }
    }

    private void removerTarefa() {
        // Captura a linha da tabela que foi selecionada pelo usuário
        int linhaSelecionada = tbTarefas.getSelectedRow();

        // Garante que a linha seleciona está dentro de um limite aceito: [0, quantidade de linhas - 1]
        if (linhaSelecionada >= 0 && linhaSelecionada < mdDados.getRowCount()) {
            if (JOptionPane.YES_OPTION == JOptionPane.showConfirmDialog(this, "Deseja realmente remover esta tarefa?",
                    "Confirmar remoção", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE)) {
                mdDados.removeRow(linhaSelecionada);

                // Desmarca a linha selecionada na tabela pelo usuário
                tbTarefas.getSelectionModel().clearSelection();

                configurarBotoesEstadoInsercao();
            }
        }
    }

    private Tarefa obterTarefaSelecionada() {
        // Captura a linha da tabela que foi selecionada pelo usuário
        int linhaSelecionada = tbTarefas.getSelectedRow();

        // Garante que a linha seleciona está dentro de um limite aceito: [0, quantidade de linhas - 1]
        if (linhaSelecionada < 0 || linhaSelecionada >= mdDados.getRowCount()) {
            return null;
        }

        /* 
        * Obtém os dados daquela linha, a partir do modelo de dados.
        * A coluna 0 representa a descrição da tarefa e a coluna 1, seu deadline
        * Foi necessário fazer o casting explícito para a classe "String", pois
        * o método "getValueAt" retorna um objeto da classe "Object"
         */
        Tarefa t = new Tarefa(
                (String) mdDados.getValueAt(linhaSelecionada, 0),
                (String) mdDados.getValueAt(linhaSelecionada, 1)
        );

        return t;
    }

    private void salvarTarefa() {
        /* 
        * Verifica se a descrição ou o deadline da tarefa não foram informados pelo usuário.
        * O método getText() retorna uma string que representa o texto digitado pelo usuário na caixa de texto.
        * O método trim() remove espaços em branco do início e do fim de uma string.
        * O método isEmpty() retorna "true" caso uma string esteja vazia (sem caracteres) e "false", caso contrário.
         */
        if (!tfTarefa.getText().trim().isEmpty() && !tfDeadline.getText().trim().isEmpty()) {
            
               
            if(tfTarefa.getText().length() > 50){
                JOptionPane.showMessageDialog(null, "Descrição da tarefa não pode"
                        + " ter mais que 50 caracteres");
            }
            else{
                boolean repete = false;
                for(int i = 0; i < mdDados.getRowCount() && !repete; ++i){
                    repete = tfTarefa.getText().equalsIgnoreCase((String) mdDados.getValueAt(i, 0)) && 
                            tfDeadline.getText().equalsIgnoreCase((String) mdDados.getValueAt(i, 1));
                }
                 if(repete){
                    JOptionPane.showMessageDialog(null, "Erro, Item ja adicionado!");
                }
                else{
                    Tarefa t = new Tarefa(tfTarefa.getText(), tfDeadline.getText());

                    // Adiciona a tarefa na tabela.
                    adicionarTarefa(t);

                    // Limpa os campos de texto.
                    tfTarefa.setText("");
                    tfDeadline.setText("");

                    // Configura estado dos botões
                    configurarBotoesEstadoInsercao();

                    // Envia mensagem na tela
                    JOptionPane.showMessageDialog(this, "Tarefa adicionada com sucesso!",
                            "Parabéns", JOptionPane.INFORMATION_MESSAGE);
                }
            }
        }
    }

    private void adicionarComponente(Component comp, int anchor, int fill, int linha, int coluna, int larg, int alt) {
        gbc.anchor = anchor; // posicionamento do componente na tela (esquerda, direita, centralizado, etc)
        gbc.fill = fill; // define se o tamanho do componente será expandido ou não
        gbc.gridy = linha; // linha do grid onde o componente será inserido
        gbc.gridx = coluna; // coluna do grid onde o componente será inserido
        gbc.gridwidth = larg; // quantidade de colunas do grid que o componente irá ocupar
        gbc.gridheight = alt; // quantidade de linhas do grid que o componente irá ocupar
        gbc.insets = new Insets(3, 3, 3, 3); // espaçamento (em pixels) entre os componentes da tela
        gbl.setConstraints(comp, gbc); // adiciona o componente "comp" ao layout com as restrições previamente especificadas
        add(comp); // efetivamente insere o componente na tela
    }

    public static void main(String[] args) {
        // Instancia um objeto da classe principal, que é uma janela, e torna a janela visível para o usuário
        new TelaPrincipal().setVisible(true);
    }

}
