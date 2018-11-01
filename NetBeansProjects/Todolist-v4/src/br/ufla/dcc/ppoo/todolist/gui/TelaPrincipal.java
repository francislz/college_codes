package br.ufla.dcc.ppoo.todolist.gui;

import br.dcc.ufla.ppoo.todolist.tarefa.Tarefa;
import br.ufla.dcc.ppoo.todolist.excecoes.DeadlineInvalidoException;
import br.ufla.dcc.ppoo.todolist.excecoes.TarefaInvalidaException;
import java.awt.Color;
import java.awt.Component;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;
import javax.swing.Action;
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
    private JButton btExportar;
    private JButton btImportar;
    private JButton btToHTML;
    private JPanel painelBotoes; // container para os botões da tela
    private JPanel painelSecundario;

    public TelaPrincipal() {
        // Define o título da tela
        super("Lista de Tarefas");

        // Define que fechar a janela, a execução aplicação será encerrada
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Evita que a tela possa ser redimensionada pelo usuário
        setResizable(false);

        // Invoca o método que efetivamente constrói a tela
        construirTela();

        // carrega configurações do programa
        carregarConfiguracoes();

        // tenta ler tarefas já existentes em arquivo
        carregarTarefasDoArquivo();

        // Redimensiona automaticamente a tela, com base nos componentes existentes na mesma
        pack();

    }

    private void carregarConfiguracoes() {
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader("config.txt"));

            // Lê o título da janela
            if (br.ready()) {
                String titulo = br.readLine();
                setTitle(titulo);

                // Lê a cor de fundo da janela
                if (br.ready()) {
                    String cor = br.readLine();
                    switch (cor) {
                        case "AMARELO":
                            getContentPane().setBackground(Color.yellow);
                            break;
                        case "VERDE":
                            getContentPane().setBackground(Color.green);
                            break;
                        case "BRANCO":
                            getContentPane().setBackground(Color.white);
                            break;
                        case "PRETO":
                            getContentPane().setBackground(Color.black);
                            break;
                    }
                }
            }

        } catch (IOException e) {
            JOptionPane.showMessageDialog(this, "Arquivo de configurações não encontrado. O programa será executado\ncom as configurações padrão!",
                    "Ops... algo deu errado :(", JOptionPane.ERROR_MESSAGE);
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException ioex) {
                    JOptionPane.showMessageDialog(this, "Erro ao fechar o arquivo de configurações!",
                            "Ops... algo deu errado :(", JOptionPane.ERROR_MESSAGE);
                }
            }
        }
    }

    private List<Tarefa> obterListaTarefas() {
        List<Tarefa> tarefas = new ArrayList<Tarefa>();
        for (int i = 0; i < mdDados.getRowCount(); i++) {
            // Cria uma tarefa, a partir dos dados que estão na linha "i" 
            // da tabela de tarefas
            Tarefa t = new Tarefa(
                    (String) mdDados.getValueAt(i, 0),
                    (String) mdDados.getValueAt(i, 1));

            tarefas.add(t);
        }
        return tarefas;
    }

    private void incluirListaTarefas(List<Tarefa> tarefas) {
        for (Tarefa t : tarefas) {
            // Adiciona a tarefa na tabela.
            String[] dados = new String[2];
            dados[0] = t.getTarefa();
            dados[1] = t.getDeadline();
            mdDados.addRow(dados);
        }
    }

    private void salvarTarefasEmArquivo() {
        ObjectOutputStream oos = null;
        try {
            oos = new ObjectOutputStream(new FileOutputStream("tarefas.bin"));
            oos.writeObject(obterListaTarefas());
        } catch (IOException e) {
            JOptionPane.showMessageDialog(this, "Erro ao salvar tarefas em arquivo!",
                    "Ops... algo deu errado :(", JOptionPane.ERROR_MESSAGE);
        } finally {
            if (oos != null) {
                try {
                    oos.close();
                } catch (IOException ioex) {
                    JOptionPane.showMessageDialog(this, "Erro ao fechar o arquivo de tarefas!",
                            "Ops... algo deu errado :(", JOptionPane.ERROR_MESSAGE);
                }
            }
        }
    }

    private void carregarTarefasDoArquivo() {
        ObjectInputStream ois = null;
        try {
            ois = new ObjectInputStream(new FileInputStream("tarefas.bin"));
            List<Tarefa> tarefas = (List<Tarefa>) ois.readObject();
            incluirListaTarefas(tarefas);
        } catch (IOException | ClassNotFoundException e) {
            JOptionPane.showMessageDialog(this, "Erro ao ler tarefas do arquivo!",
                    "Ops... algo deu errado :(", JOptionPane.ERROR_MESSAGE);
        } finally {
            if (ois != null) {
                try {
                    ois.close();
                } catch (IOException ioex) {
                    JOptionPane.showMessageDialog(this, "Erro ao fechar o arquivo de tarefas!",
                            "Ops... algo deu errado :(", JOptionPane.ERROR_MESSAGE);
                }
            }
        }
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

        btSalvar = new JButton("Salvar");

        // Cria uma classe interna anônima para tratar o evento de clique sobre o botão "Salvar"
        btSalvar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                salvarTarefa();
            }
        });

        btCopiar = new JButton("Copiar");
        btCopiar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                copiarTarefa();
            }
        });

        btRemover = new JButton("Remover");
        btRemover.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                removerTarefa();
            }
        });
        
        btExportar = new JButton("Exportar");
        btExportar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                exportarDados();
            }
        });
        
        btImportar = new JButton("Importar");
        btImportar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                importarDados();
            }
        });
        
        btToHTML = new JButton("Gerar HTML");
        btToHTML.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                exportHTML();
            }
        });
        configurarBotoesEstadoInsercao();

        // Instancia o painel (container) de botões e adiciona os botões a ele
        painelBotoes = new JPanel(new GridLayout(1, 3, 5, 5));
        painelBotoes.add(btSalvar);
        painelBotoes.add(btCopiar);
        painelBotoes.add(btRemover);
        
        painelSecundario = new JPanel(new GridLayout(1, 3, 5, 5));
        painelSecundario.add(btExportar);
        painelSecundario.add(btImportar);
        painelSecundario.add(btToHTML);

        // Constrói o modelo de dados 
        mdDados = new DefaultTableModel(); // Toda tabela possui um modelo de dados, que é onde ficam as informações exibidas pela tabela

        // Adicionando colunas ao modelo de dados. 
        mdDados.addColumn("Tarefa");
        mdDados.addColumn("Deadline");

        mdDados.addTableModelListener(new TableModelListener() {
            @Override
            public void tableChanged(TableModelEvent tme) {
                salvarTarefasEmArquivo();
            }
        });

        // Constrói a tabela, com base no modelo de dados
        tbTarefas = new JTable(mdDados);
        tbTarefas.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent lse) {
                configurarBotoesEstadoSelecao();
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
        adicionarComponente(painelSecundario, GridBagConstraints.CENTER, GridBagConstraints.BOTH, 4, 0, 2, 1);
    }

    private void configurarBotoesEstadoInsercao() {
        btCopiar.setEnabled(false);
        btRemover.setEnabled(false);
        btSalvar.setEnabled(true);
    }

    private void configurarBotoesEstadoSelecao() {
        btCopiar.setEnabled(true);
        btRemover.setEnabled(true);
        btSalvar.setEnabled(false);
    }

    private void copiarTarefa() {
        // Captura a linha da tabela que foi selecionada pelo usuário
        int linhaSelecionada = tbTarefas.getSelectedRow();

        /* 
        * Obtém os dados daquela linha, a partir do modelo de dados.
        * A coluna 0 representa a descrição da tarefa e a coluna 1, seu deadline
        * Foi necessário fazer o casting explícito para a classe "String", pois
        * o método "getValueAt" retorna um objeto da classe "Object"
         */
        tfTarefa.setText((String) mdDados.getValueAt(linhaSelecionada, 0));
        tfDeadline.setText((String) mdDados.getValueAt(linhaSelecionada, 1));

        // Desmarca a linha selecionada na tabela pelo usuário
        tbTarefas.getSelectionModel().clearSelection();

        configurarBotoesEstadoInsercao();
    }

    private void removerTarefa() {
        if (JOptionPane.YES_OPTION == JOptionPane.showConfirmDialog(this, "Deseja realmente remover esta tarefa?",
                "Confirmar remoção ;)", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE)) {

            // Captura a linha da tabela que foi selecionada pelo usuário
            int linhaSelecionada = tbTarefas.getSelectedRow();

            mdDados.removeRow(linhaSelecionada);
        }

        // Desmarca a linha selecionada na tabela pelo usuário
        tbTarefas.getSelectionModel().clearSelection();
        configurarBotoesEstadoInsercao();
    }
    
    private void exportarDados(){
        BufferedWriter bw = null;
        
        try{
            bw = new BufferedWriter(new FileWriter("exported.txt"));
            for(int i = 0; i < mdDados.getRowCount(); ++i){
                bw.write((String) mdDados.getValueAt(i, 0) + "; " + (String) mdDados.getValueAt(i, 1) + "\n");
            }
        }catch(IOException e){
            System.out.println("Error: " + e.getMessage());
        } finally{
            if(bw != null){
                try{
                    bw.close();
                } catch(IOException e){
                    System.out.println("Error: " + e.getMessage());
                }
            }
        }
    }
    
    private void exportHTML(){
        BufferedWriter bw = null;
        try{
            bw = new BufferedWriter(new FileWriter("index.html"));
            String content = "<!DOCTYPE html><html><head>"
                + "<title>Desafio PPOO</title>"
                + "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\" integrity=\"sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u\" crossorigin=\"anonymous\">"
                + "</head>"
                + "<body>"
                + "<table border=\"1\" class=\"table\">"
                + "<tr>"
                + "<th colspan=\"3\">Lista de Tarefas</th>"
                + "</tr>"
                + "<tr>"
                + "<td scope = \"col\">#</td>"
                + "<td scope = \"col\">Tarefa</td>"
                + "<td scope = \"col\">Deadline</td>"
                + "</tr>";
            for(int i = 0; i < mdDados.getRowCount(); ++i){
                content += "<tr>"
                        + "<td scope = \"row\">" + (i + 1) + "</td>"
                        + "<td>" + (String) mdDados.getValueAt(i, 0) + "</td>"
                        + "<td>" + (String) mdDados.getValueAt(i, 1) + "</td>"
                        + "</tr>";
            }
            content += "</table>"
                + "</body>"
                + "</html>";
            bw.write(content);
        } catch(IOException e){
            System.out.println("Error: " + e.getMessage());
        } finally{
            if(bw != null){
                try{
                    bw.close();
                } catch(IOException e){
                    System.out.println("Error: " + e.getMessage());
                }
            }
        }
    }
    
    private void importarDados(){
        BufferedReader br = null;
        String file = JOptionPane.showInputDialog(null, "Digite o nome do arquivo a ser importado (.txt)");
        try{
            br = new BufferedReader(new FileReader(file));
            while(br.ready()){
                String line = br.readLine();
                String dados[] = line.split(";");
                
                boolean existe = false;
                for(int i = 0; i < mdDados.getRowCount() && !existe; ++i){
                    if(dados[0].equalsIgnoreCase((String) mdDados.getValueAt(i, 0))){
                        System.out.println("Valor ja existe !!");
                        existe = true;
                    }
                }
                
                boolean problemaNaData = false;
                String strDeadline = tfDeadline.getText();
                // Essa classe verifica se o deadline está no formato exigido, isto é, dia/mês/ano, e se é válida
                SimpleDateFormat ssf = new SimpleDateFormat("dd/MM/yyyy");
                // Exige que a data informada esteja exatamente em conformidade com o padrão estipulado, i. e, dd/MM/yyyy
                ssf.setLenient(false);
                try {
                    Date dtDeadline = ssf.parse(strDeadline);
                    Date dtAtual = obterDataAtual(); // pega a data atual do sistema
                    // O método "before", da classe Date, retornará "true", caso "dtDeadline" ocorra antes de "dtAtual"
                    if (dtDeadline.before(dtAtual)) {
                        System.out.println("Data menor que o sistema !");
                        problemaNaData = true;
                    }
                } catch (ParseException pex) {
                    problemaNaData = true;
                    System.out.println("Formato da data errado!");
                }
                if(!existe || !problemaNaData){
                    mdDados.addRow(dados);
                }
            }
        } catch(IOException e){
            System.out.println("Error: " + e.getMessage());
        } finally{
            if(br != null){
                try{
                    br.close();
                } catch(IOException e){
                    System.out.println("Error: " + e.getMessage());
                }
            }
        }
    }
    
    private String validarTarefa() throws TarefaInvalidaException {
        String descricao = tfTarefa.getText();
        if (descricao.trim().isEmpty()) {
            throw new TarefaInvalidaException("a descrição não pode estar vazia!");
        }
        // Só chega aqui se a "descricao" não for vazia
        if (descricao.length() > 50) {
            throw new TarefaInvalidaException("a descrição não pode conter mais do que 50 caracteres!");
        }
        // Só chega aqui se a "descricao" não for vazia e não tiver mais do que 50 caracteres
        return descricao;
    }

    /*
    * Esse método simplesmente retorna a data atual do sistema, sem considerar
    * o horário. Isso foi necessário, pois no programa, considera-se apenas a data
    * como deadline.
     */
    private Date obterDataAtual() {
        Calendar cal = Calendar.getInstance();
        cal.set(Calendar.HOUR_OF_DAY, 0);
        cal.set(Calendar.MINUTE, 0);
        cal.set(Calendar.SECOND, 0);
        cal.set(Calendar.MILLISECOND, 0);
        return cal.getTime();
    }

    private String validarDeadline() throws DeadlineInvalidoException {
        String strDeadline = tfDeadline.getText();
        // Essa classe verifica se o deadline está no formato exigido, isto é, dia/mês/ano, e se é válida
        SimpleDateFormat ssf = new SimpleDateFormat("dd/MM/yyyy");
        // Exige que a data informada esteja exatamente em conformidade com o padrão estipulado, i. e, dd/MM/yyyy
        ssf.setLenient(false);
        try {
            Date dtDeadline = ssf.parse(strDeadline);
            Date dtAtual = obterDataAtual(); // pega a data atual do sistema
            // O método "before", da classe Date, retornará "true", caso "dtDeadline" ocorra antes de "dtAtual"
            if (dtDeadline.before(dtAtual)) {
                throw new DeadlineInvalidoException(strDeadline, "não pode ser menor do que a data atual do sistema!");
            }
            return strDeadline;
        } catch (ParseException pex) {
            throw new DeadlineInvalidoException(strDeadline, "não está no formato \"dd/MM/yyyy\" ou\nnão é uma data existente no calendário!");
        }
    }

    private void salvarTarefa() {
        try {
            // Adiciona a tarefa na tabela.
            String[] dados = new String[2];
            dados[0] = validarTarefa();
            dados[1] = validarDeadline();
            mdDados.addRow(dados);

            // Limpa os campos de texto.
            tfTarefa.setText("");
            tfDeadline.setText("");

            // Configura estado dos botões
            configurarBotoesEstadoInsercao();

            // Envia mensagem na tela
            JOptionPane.showMessageDialog(this, "Tarefa adicionada com sucesso!",
                    "Parabéns :)", JOptionPane.INFORMATION_MESSAGE);
        } catch (DeadlineInvalidoException | TarefaInvalidaException ex) {
            // Envia mensagem de erro na tela
            JOptionPane.showMessageDialog(this, ex.getMessage(),
                    "Ops... algo deu errado :(", JOptionPane.ERROR_MESSAGE);
        }
        // Se o tratamento das exceções fosse diferente, precisaríamos de um bloco
        // catch para cada tipo de exceção.
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
