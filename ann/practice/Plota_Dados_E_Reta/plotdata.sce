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