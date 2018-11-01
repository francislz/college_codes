clear; warning off;
exec('../Classificacao_gaussiana/geragauss.sce',-1);
exec('../Plota_Dados_E_Reta/plotdata.sce',-1);
exec('../Treinamento_Perceptron/treina_perceptron.sce',-1);
exec('../Perceptron/perceptron.sci',-1);

max_epocas = 100; //DEfine max de epocas
alfa = 1.2; // Alfa de ajuste
tol = 10; //Tolerancia

function bits = de2bi(Yd)
    str = dec2bin(Yd);
    bits = []
    sz = size(str)
    for i=1:sz(2),
        if Yd(i) ~= 0
        	bits(1,i) = 0;
        	bits(2,i) = strtod(part(str(i),1));
        	bits(3,i) = strtod(part(str(i),2));
        else
            bits(1,i) = 1;
            bits(2,i) = strtod(part(str(i),1));
            bits(3,i) = strtod(part(str(i),2));
        end
    end
endfunction

nc = 3;
npc = [20 50 40];
mc = [1.2 3 4.7; 1.1 3.1 5.1];
varc = [0.1 0.1 0.1; 0.1 0.1 0.1];

[X Yd] = geragauss(nc, npc, mc, varc);
[X Yd] = mixvalues(X, Yd);

W = [];
b = [];
for i=1:nc,
	aux = [rand() rand()];
	W = [W; aux];
	b = [b; rand()];
end

Yd_ = de2bi(Yd);

for i = 1:nc,
	[Wout(i,:), bout(i,:), VetorSEQ] = treina_perceptron(W(i,:), b(i), X, Yd_(i,:), alfa, max_epocas, tol);
    //Plotar o Gráfico dos erros quadraticos.
    scf(1);
    title("Erros Quadraticos 1");
    plot(VetorSEQ);
    xlabel('Epoca');
    ylabel('VetorSEQ');
end



// Grafico de dados e da reta em duas dimensões para a função 1
scf(2);
title("1");
plotadc2d(X, Yd);
for i = 1:nc,
	plotareta(Wout(i,:), bout(i,:), [0 5]);
end