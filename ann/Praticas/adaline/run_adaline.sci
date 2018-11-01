clear; warning off;
exec('../Classificacao_gaussiana/geragauss.sce',-1);
exec('../adaline/adaline.sce',-1);
exec('../adaline/treina_adaline.sce',-1);
exec('../Plota_Dados_E_Reta/plotdata.sce',-1);

W = [rand()];
b = rand();

X = [];
Yd = [];
for i = 0:2:100,
	X = [X i];
	Yd = [Yd ((i + 2))];
end
//Grafico de dados e da reta em duas dimensões para a função 1
scf(1);
title("1");
plotadc2d(X, Yd);
//plot(X, Yd);
// isoview(-0.2, 1.3, -0.2, 1.3);
[X Yd] = mixvalues(X, Yd);

alfa = 0.0001;
max_epocas = 10000;
tol = 0.000000001;

[W1, b1, VetorSEQ1] = treina_adaline(W, b, X, Yd, alfa, max_epocas, tol);
Y = yadaline(W1, b1, X);
plot(X, Y, '-r');

//Plotar o Gráfico dos erros quadraticos.
scf(2);
title("Erros Quadraticos 1");
plot(VetorSEQ1);
xlabel('Epoca');
ylabel('VetorSEQ');