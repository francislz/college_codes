exec('../Perceptron/perceptron.sci',-1);

function [W, b, VetorSEQ] = treina_perceptron(W, b, X, yd, alfa, max_epocas, tol)
    N = size(X); N = N(2);//Recebe o numero de colunas de X
    SEQ = tol; //Inicializa o SEQ com o valor da tolerancia;
    epoca = 1; //Inicializa a epoca
    VetorSEQ = []; //Inicializa o VetorSEQ
    while (epoca <= max_epocas) & (SEQ >= tol), //Enquanto nao atingir a epoca maxima e o erro nao for minimo
        SEQ = 0; //Reseta a Soma dos Erros Quadraticos
        for i = 1:N //Ate o tamanho de N ajustar os pesos
            y = perceptron(W, b, X(:,i)); //Recebe o valor do perceptron para os pesos atuais
            erro = yd(i) - y; // Erro da diferenca das funcoes
            W = W + (alfa*erro*X(:,i)'); //Ajusta os pesos
            b = b + alfa*erro; //Ajusta o Bias
            SEQ = SEQ + erro^2; //Soma do Erro
        end
        VetorSEQ = [VetorSEQ SEQ]; //Concatena no final o valor dos erros Quadraticos
        epoca = epoca + 1; //Incrementa a epoca
    end
endfunction