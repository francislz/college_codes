clc;
//Funcao para plotar a reta
function plotareta(W, b, intervalo)
    x1 = intervalo;
    x2 = -(x1*W(1) + b)/W(2); //Isola x2 para obter a equação da reta
    plot(x1, x2,'-b'); //Plota o grafico
    xlabel('x1'); //Define a label dos eixos
    ylabel('x2');
endfunction

function plotadc2d(X, Yd)
	simbolos = createSymbols(); //Obtem o vetor de simbolos
	sz = size(X);
	for i = 1:sz(2), //Plota para cada amosta de acordo com sua classe
		plot(X(1,i),X(2,i), simbolos((Yd(i) + 1)));
		//plot(X(1,i),Yd(1,i), simbolos(1));
	end
endfunction

function y = createSymbols() //Faz a combinacao dos simbolos para criar o vetor de classes 
	colour = ['k', 'r', 'b', 'c', 'm', 'y', 'g', 'w']; //Cores possiveis
	symbols = ['+','o','*','.','x','s','d','^','v','>','<','pentagram']; //Simbolos Possiveis
	
	szColour = size(colour);
	szSymbols = size(symbols);
	y = [];
	
	for i = 1:szColour(2)
		for j = 1:szSymbols(2)
			y = [y, symbols(j) + colour(i)]; //Cria o vetor
		end
	end
endfunction
// Classificador MLP para o problema do XOR

disp('Rede Neural de 2 camadas para resolver o problema do XOR');
// realiza sempre as mesmas condicoes iniciais
rand('seed',0);
disp('Lendo parametros...');
// numero de neuronios por camada, incluindo a entrada
N = [2 , 2 , 1];
// amostras de entrada
x = [0 , 1 , 0 , 1 ;
 0 , 0 , 1 , 1];
disp('Dados de entrada:');
disp(x);
// saida desejada, alvo
yd = [0 , 1 , 1 , 0];

disp('Dados de saida:');
disp(yd);
// parametros de treinamento: taxa de aprendizado
lp = [1 , 0];
// numero maximo de epocas para treinar
T = 1400;
disp('Inicializando a rede...');
W = ann_FF_init(N);

disp('Treinando a rede...');
W_out = ann_FF_Std_batch(x,yd,N,W,lp,T);

disp('Resultado da rede treinada:');
y_aux = ann_FF_run(x,N,W_out);
y = round(y_aux);
disp(y);

//VetorSEQ Sem momentum
disp('Calculando SEQ e SEQM...');
VetorSEQ = [];
W_error = W;
for i = 1:T
   W_error = ann_FF_Std_batch(x,yd,N,W_error,lp,1);
   y = ann_FF_run(x,N,W_error);
    
   VetorSEQ = [VetorSEQ, ann_sum_of_sqr(y, yd)];
end

// VetorSEQ Momentum
Delta_W = hypermat(size(W)');
VetorSEQM = [];
W_error = W;
lp_M = [1.2, 0, 0.9, 0];
for i = 1:T
   [W_error, Delta_W] = ann_FF_Mom_batch(x,yd,N,W_error,lp_M,1, Delta_W);
   y = ann_FF_run(x,N,W_error);
    
   VetorSEQM = [VetorSEQM, ann_sum_of_sqr(y, yd)];
end

scf(2);
title("Erros Quadraticos XOR");
plot(VetorSEQ,'-b');
plot(VetorSEQM,'-r');
xlabel('Epoca');
ylabel('VetorSEQ');

// Plot Amostras e retas de separacao de classes
scf(1);
title("Data");
plotadc2d(x, yd);
for i = 1:3,
	plotareta(W_out(:,i,1), W_out(1,i,2), [-0.2 1.2]);
end
isoview(-0.2, 1.2, -0.2, 1.2);