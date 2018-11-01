exec('adaline.sce',-1);

function [W_atual, b_atual, VetorSEQ] = treina_adaline_momentum(W, b, X, yd, alfa, beta_,  max_epocas, tol)
    N = size(X); N = N(2);//Recebe o numero de colunas de X
    SEQ = tol; //Inicializa o SEQ com o valor da tolerancia;
    epoca = 1; //Inicializa a epoca
    VetorSEQ = []; //Inicializa o VetorSEQ

    W_atual = W;
    W_anterior = W;
    b_atual = b;
    b_anterior = b;

    while (epoca <= max_epocas) & (SEQ >= tol), //Enquanto nao atingir a epoca maxima e o erro nao for minimo
        SEQ = 0; //Reseta a Soma dos Erros Quadraticos
        for i = 1:N //Ate o tamanho de N ajustar os pesos
            y = yadaline(W_atual, b_atual, X(:,i)); //Recebe o valor do perceptron para os pesos atuais
            erro = yd(i) - y; // Erro da diferenca das funcoes

            W_futuro = W_atual + (alfa*erro*X(:,i)') + (beta_ * (W_atual - W_anterior)); //Ajusta os pesos
            b_futuro = b_atual + (alfa*erro) + (beta_ * (b_atual - b_anterior)); //Ajusta o Bias

            W_anterior = W_atual;
            W_atual = W_futuro;
            
            b_anterior = b_atual;
            b_atual = b_futuro;

            SEQ = SEQ + erro^2; //Soma do Erro
        end
        VetorSEQ = [VetorSEQ SEQ]; //Concatena no final o valor dos erros Quadraticos
        epoca = epoca + 1; //Incrementa a epoca
    end
endfunction