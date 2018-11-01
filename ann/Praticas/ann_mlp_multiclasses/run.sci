clc; warning off;
exec('../Classificacao_gaussiana/geragauss.sce',-1);
exec('../Plota_Dados_E_Reta/plotdata.sce',-1);

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

function [Treino, Teste] = run()
    nc = 3;
    npc = [120 150 140];
    mc = [1.2 3.3 6.5; 4.1 1.7 4.5];
    varc = [1.89 1.15 1.51; 1.21 2.14 1.32];

    [X Yd] = geragauss(nc, npc, mc, varc);
    [X Yd] = mixvalues(X, Yd);

    N = size(X);
    N = N(2);

    TR = N * 0.8;
    TE = N * 0.2;

    ind = grand(1, "prm", (1:TR));

    X_TR = [];
    Yd_TR = [];
    for i = 1:TR,
        aux = X(:,ind(i));
        X_TR = [X_TR aux];
        aux = Yd(ind(i));
        Yd_TR = [Yd_TR aux];
    end

    X_TE = [];
    Yd_TE = [];
    for i = 1:N,
        naoEsta = 1;
        for j = 1:TR,
            if i == ind(j),
                naoEsta = 0;
            end
        end
        if naoEsta == 1,
            aux = X(:,i);
            X_TE = [X_TE aux];
            aux = Yd(i);
            Yd_TE = [Yd_TE aux];
        end
    end

    Yd_BIN = de2bi(Yd_TR);

    disp('Configurando parametros...');
    // numero de neuronios por camada, incluindo a entrada
    N_ = [2, 9 , 3];

    // parametros de treinamento: taxa de aprendizado
    lp = [0.05 , 0];
    // numero maximo de epocas para treinar
    T = 400;
    disp('Inicializando a rede...');
    W = ann_FF_init(N_);

    disp('Treinando a rede...');
    W_out = ann_FF_Std_online(X_TR,Yd_BIN,N_,W,lp,T);

    //VetorSEQ Sem momentum
    disp('Calculando SEQ..');
    VetorSEQ = [];
    VetorTESTE = [];
    W_error = W;
    for i = 1:T
       W_error = ann_FF_Std_online(X_TR,Yd_BIN,N_,W_error,lp,1);
       y = ann_FF_run(X_TR,N_,W_error);

       VetorTESTE = [VetorTESTE, ann_sum_of_sqr(ann_FF_run(X_TE,N_,W_error), de2bi(Yd_TE))];
       VetorSEQ = [VetorSEQ, ann_sum_of_sqr(y, Yd_BIN)];
    end
    aux = round(ann_FF_run(X_TR,N_,W_out)) == Yd_BIN;
    Treino = length(aux(aux == %t));

    aux = round(ann_FF_run(X_TE,N_,W_out)) == de2bi(Yd_TE);
    Teste = length(aux(aux == %t));
endfunction

Teste = [];
Treino = [];

for i = 1:10,
    [teste, treino] = run();
    Teste = [Teste teste];
    Treino = [Treino treino];
end
    // scf(1);
    // title("Erros Quadraticos");
    // plot(VetorSEQ,'-b');
    // plot(VetorTESTE,'-r');
    // xlabel('Epoca');
    // ylabel('VetorSEQ');


    // // Grafico de dados e da reta em duas dimensões para a função 1
    // scf(2);
    // title("Dados Originais");
    // plotadc2d(X, Yd);

    // // Grafico de dados e da reta em duas dimensões para a função 1
    // scf(3);
    // title("Dados Reclassificados");
    // plotadc2d(X_TR, ann_FF_run(X_TR,N_,W_out));
    // plotadc2d(X_TE, ann_FF_run(X_TE,N_,W_out));

    // // Grafico de dados e da reta em duas dimensões para a função 1
    // scf(2);
    // title("Dados Treinamento");
    // plotadc2d(X_TR, Yd_TR);

    // // Grafico de dados e da reta em duas dimensões para a função 1
    // scf(3);
    // title("Dados Teste");
    // plotadc2d(X_TE, Yd_TE);
    // // for i = 1:nc,
    // //     plotareta(Wout(i,:), bout(i,:), [0 5]);
    // // end
