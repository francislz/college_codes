// perceptron: function description
function y = perceptron(W, b, X)
    u = W * X + b;

    u(u >= 0) = 1;
    u(u < 0) = 0;
    y = u;
endfunction
