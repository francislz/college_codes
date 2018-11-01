clear; warning off;
exec('geragauss.sce',-1);
exec('../Plota_Dados_E_Reta/plotdata.sce',-1);
exec('../Treinamento_Perceptron/treina_perceptron.sce',-1);
exec('../Perceptron/perceptron.sci',-1);

W = [rand() rand()];
b = rand();

nc = 2;
npc = [20 50];
mc = [3.6 2.1; 6.7 5.2];
varc = [ 0.1 0.2 ; 0.3 0.4];

[X Yd] = geragauss(nc, npc, mc, varc);
[X Yd] = mixvalues(X, Yd);

alfa = 1.2;
max_epocas = 1000;
tol = 0.001;

[W1, b1, VetorSEQ1] = treina_perceptron(W, b, X, Yd, alfa, max_epocas, tol);
Y = perceptron(W1, b1, X);
//Plotar o Gráfico dos erros quadraticos.
scf(1);
title("Erros Quadraticos 1");
plot(VetorSEQ1);
xlabel('Epoca');
ylabel('VetorSEQ');

//Grafico de dados e da reta em duas dimensões para a função 1
scf(2);
title("1");
plotadc2d(X, Y);
// isoview(-0.2, 1.3, -0.2, 1.3);
plotareta(W1, b1, [-1 7]);