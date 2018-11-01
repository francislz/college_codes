clear; warning off;
exec('plotdata.sce',-1);
exec('../Treinamento_Perceptron/treina_perceptron.sce',-1);

//Entradas Logicas
X = [[0, 1, 0, 1],
[0, 0, 1, 1]];

W = (rand(1,2) * 100)/100 ; //Pesos Aleatorios
b = 0.3; //Bias
yand = [0 0 0 1]; //Saidas Para Porta AND

max_epocas = 1000; //DEfine max de epocas
alfa = 1.2; // Alfa de ajuste
tol = 0.001; //Tolerancia

[Wand, band, VetorSEQ1] = treina_perceptron(W, b, X, yand, alfa, max_epocas, tol);
saida_and = perceptron(Wand, band, X); //Saida Perceptron AND
//Plotar o Gráfico dos erros quadraticos.
scf(1);
title("Erros Quadraticos AND");
plot(VetorSEQ1);
xlabel('Epoca');
ylabel('VetorSEQ');


yor = [1 1 1 0]; //Saidas Esperadas Porta OR
[Wor, bor, VetorSEQ2] = treina_perceptron(W, b, X, yor, alfa, max_epocas, tol);
saida_or = perceptron(Wor, bor, X); //Saida Perceptron OR
//Plotar o Gráfico dos erros quadraticos.
scf(2);
title("Erros Quadraticos OR");
plot(VetorSEQ2);
xlabel('Epoca');
ylabel('VetorSEQ')

//Grafico de dados e da reta em duas dimensões para a função AND
scf(3);
title("AND");
plotadc2d(X, yand);
isoview(-0.2, 1.3, -0.2, 1.3);
plotareta(Wand, band, [0.2 1.3]);

//Grafico de dados e da reta em duas dimensões para a função OR
scf(4);
title("OR");
plotadc2d(X, yor);
isoview(-0.2, 1.3, -0.2, 1.3);
plotareta(Wor, bor, [0.2 1.3]);