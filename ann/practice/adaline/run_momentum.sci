clear; warning off;
exec('../Classificacao_gaussiana/geragauss.sce',-1);
exec('../adaline/adaline.sce',-1);
exec('../adaline/treina_adaline.sce',-1);
exec('../adaline/treina_adaline_momentum.sce',-1);
exec('../Plota_Dados_E_Reta/plotdata.sce',-1);

W = [rand()];
b = rand();

// X = 1:0.5:10;
// Yd = 3*X + (rand(1,1,'normal'));
X = [];
Yd = [];
for i = 0:0.5:25,
	X = [X i];
	Yd = [Yd (2*i + (rand(1,1,'normal')))];
end
//Grafico de dados e da reta em duas dimensões para a função 1
scf(1);
title("1");
plotadc2d(X, Yd);
//plot(X, Yd);
// isoview(-0.2, 1.3, -0.2, 1.3);
[X Yd] = mixvalues(X, Yd);

alfa = 0.0001;
max_epocas = 1000;
tol = 0.000000001;
beta_ = 0.5; // 0.8

[W1, b1, VetorSEQM] = treina_adaline_momentum(W, b, X, Yd, alfa, beta_, max_epocas, tol);
Y1 = yadaline(W1, b1, X);
plot(X, Y1, '-r');

[W2, b2, VetorSEQ] = treina_adaline(W, b, X, Yd, alfa, max_epocas, tol);
Y2 = yadaline(W2, b2, X);
scf(2);
title("2");
plotadc2d(X, Yd);
plot(X, Y2, '-b');

//Plotar o Gráfico dos erros quadraticos.
scf(3);
title("Erros Quadraticos 1");
plot(VetorSEQM, '-r');
xlabel('Epoca');
ylabel('VetorSEQ');

//Plotar o Gráfico dos erros quadraticos.
// scf(4);
// title("Erros Quadraticos 2");
plot(VetorSEQ, '-b');
// xlabel('Epoca');
// ylabel('VetorSEQ');