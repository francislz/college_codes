clear;
exec('treina_perceptron.sce',-1);

//Entradas Logicas
X = [[0, 1, 0, 1],
[0, 0, 1, 1]];

W = (rand(1,2) * 100)/100 ; //Pesos
b = 0.3; //Bias
yand = [0 0 0 1]; //Saidas Para Porta AND

max_epocas = 1000; //DEfine max de epocas
alfa = 1.2; // Alfa de ajuste
tol = 0.001; //Tolerancia

[Wand, band, VetorSEQ1] = treina_perceptron(W, b, X, yand, alfa, max_epocas, tol);
saida_and = perceptron(Wand, band, X); //Saida Perceptron AND
plot(VetorSEQ1);
xlabel('Epoca');
ylabel('VetorSEQ');


yor = [1 1 1 0]; //Saidas Esperadas Porta OR
[Wor, bor, VetorSEQ2] = treina_perceptron(W, b, X, yor, alfa, max_epocas, tol);
saida_or = perceptron(Wor, bor, X); //Saida Perceptron OR
plot(VetorSEQ2);
xlabel('Epoca');
ylabel('VetorSEQ')
