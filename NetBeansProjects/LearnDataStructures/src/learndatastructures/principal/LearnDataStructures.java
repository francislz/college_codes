/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package learndatastructures.principal;

import javafx.geometry.Insets;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.SplitPane;
import javafx.scene.input.DragEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

public class LearnDataStructures extends Application {
    private GridPane gp;
    private Button btnQueue;
    private Button btnStack;
    private Button btnList;
    private Button btnNewNode;
    private Button btnDeleteNode;
    
    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Estruturas de Dados");
        
        btnQueue = new Button("Q");
        btnStack = new Button("S");
        btnList = new Button("L");
        btnNewNode = new Button("+");
        btnDeleteNode = new Button("-");
        
        gp = new GridPane();
        gp.setPadding(new Insets(5, 0, 0, 10));
        gp.setHgap(5);
        gp.setVgap(5);
        
        gp.add(btnQueue, 0, 0);
        GridPane.setFillWidth(btnQueue, Boolean.TRUE);
        GridPane.setFillHeight(btnQueue, Boolean.TRUE);
        
        gp.add(btnStack, 0, 1);
        GridPane.setFillWidth(btnStack, Boolean.TRUE);
        GridPane.setFillHeight(btnStack, Boolean.TRUE);
        
        gp.add(btnList, 0, 2);
        GridPane.setFillWidth(btnList, Boolean.TRUE);
        GridPane.setFillHeight(btnList, Boolean.TRUE);
        
        gp.add(btnNewNode, 0, 3);
        GridPane.setFillWidth(btnNewNode, Boolean.TRUE);
        GridPane.setFillHeight(btnNewNode, Boolean.TRUE);
        
        gp.add(btnDeleteNode, 0, 4);
        GridPane.setFillWidth(btnDeleteNode, Boolean.TRUE);
        GridPane.setFillHeight(btnDeleteNode, Boolean.TRUE);
        
        btnNewNode.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                Circle c = new Circle(0, 0, 10, Color.BROWN);
                c.setOnDragDetected(new EventHandler<MouseEvent>() {
                    @Override
                    public void handle(MouseEvent event) {
                        System.out.println("Pegou");
                    }
                });
                
                c.setOnDragDropped(new EventHandler<DragEvent>() {
                    @Override
                    public void handle(DragEvent event) {
                        System.out.println("Teste");
                    }
                });
                c.setOnDragDone(new EventHandler<DragEvent>() {
                    @Override
                    public void handle(DragEvent event) {
                        System.out.println("Soltou");
                    }
                });
                
                gp.add(c, 0, 5);
            }
        });
        
        Scene scene = new Scene(gp, 300, 250);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
