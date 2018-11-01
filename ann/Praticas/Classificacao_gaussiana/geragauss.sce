function [X, Yd] = geragauss(nc, npc, mc, varc)
	X = [];
	Yd = [];
	for i = 1:nc,
		clear classes;
		aux = rand(2, npc(i), 'normal');
		for j = 1:npc(i),
			for k = 1:2,
				aux(k,j) = aux(k,j) * varc(k,i);
				aux(k,j) = aux(k,j) + mc(k,i);
			end
		end
		X = [X aux]
		classes(1, 1:npc(i)) = i - 1;
		Yd = [Yd classes];
	end
endfunction

function [X, Yd] = mixvalues(Xin, Ydin)
	ind = grand(1, "prm", (1:length(Ydin))')';

	for i = 1:length(ind),
		X(:,i) = Xin(:,ind(i));
		Yd(1,i) = Ydin(1,ind(i));
	end
endfunction