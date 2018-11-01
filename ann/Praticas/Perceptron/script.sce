// perceptron: funcao para o perceptron 
function y = perceptron(W, b, X)
    u = W * X + b; // Multiplicacao dos pesos com as amostras da entrada X e soma com o escalar bias(b)
    y = u;

    //Aplicacao da funcao degrau
    y(y >= 0) = 1; // para u >= 0 => y = 1
    y(y < 0) = 0; // para u < 0 => y = 0
endfunction

//Dados tipo AND
X1 = [[0, 1, 0, 1],
[0, 0, 1, 1]];

W1 = [0.4 0.4];
b1 = -0.6;

//Dados tipo OR
X2 = [[0, 1, 0, 1],
[0, 0, 1, 1]];

W2 = [0.5 0.6];
b2 = -0.3;

y1 = perceptron(W1, b1, X1);
disp('Valor para o AND');
disp(y1);

y2 = perceptron(W2, b2, X2);
disp('Valor para o OR');
disp(y2);