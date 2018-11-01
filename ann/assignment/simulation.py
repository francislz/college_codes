from functions import read_file
from functions import prepare_data
from functions import get_values_range
from random import randint
import neurolab as nl
import numpy
import pylab as pl

# Le o arquivo de dados e retorna o nome de cada coluna (keys) e a matriz de dados (data)
[keys, data] = read_file()

# Pepara de forma adequada os dados para a RNA, convertendo variaveis categoricas em bits
# e nomalizando os dados em um intervalo de 0 a 1
data = prepare_data(data, keys)

# As amostras sao convertidas para uma matriz (array de array)
samples = [row[0:(len(row) - 1)] for row in data]

# A ultima coluna sao os valores alvo, portanto os valores sao 
# recebidos e convertidos para de uma lista de lista para um array
target = [[int(row[len(row) - 1])] for row in data]

# Seleciona 20% da quantidade total de valores para teste das redes neurais
qtd_ind = int(len(samples) * 0.2)

# Gera um vetor de indices aleatorios para selecionar 20% do conjunto total de samples
ind = []
i = 0
while i < qtd_ind:
	value = randint(0,len(samples) - 1)
	if value not in ind:
		ind.append(value)
		i+=1

# Com base nos indices, e separada o conjunto de valores de amostra
test_samples = []
for i in ind:
	test_samples.append(samples[i])

# Os valores esperados para essas amostras tambem sao selecionados
test_target = []
for i in ind:
	test_target.append(target[i])

# Salva os dados no excel para fazer os calculos estatisticos
# Cria os titulos de cada coluna
statis = open('data.xls','w')
statis.write("Net  number \t")
statis.write("Minimum error \t")
statis.write("Size sample\t")
statis.write("Total Hits \t")
statis.write("Diff \t")
statis.write("Percent \n")

for x in range(1,11):
	# Seleciona as string para os arquivos
	str_net = "nets/bank" + str(x) + ".net"
	str_err = "errs/err" + str(x) + ".txt"
	str_gaph  = "imgs/gaph_" + str(x) + ".png"
	# Carrega a rede neural ja treinada
	net = nl.load(str_net)
	# Calcula a saida para aquela rede
	output = net.sim(test_samples)

	# Conta a quantidade de valores iguais na saida da rede e nos valores esperados
	cont_equals = 0
	i = 0
	while i < len(test_target):
		if test_target[i] == [int(numpy.round(output[i]))]:
			cont_equals+=1
		i+=1

	# Le o valor do err do arquivo de erros da rede neural em questao
	file = open(str_err,'r')
	err = []
	for line in file:
		err.append(float(line))
	file.close()

	# Escreve os dados para o excel
	statis.write(str(x) + "\t")
	statis.write(str(round(err[len(err) - 1],4)) + "\t")
	statis.write(str(len(test_samples)) + "\t")
	statis.write(str(cont_equals) + "\t")
	statis.write(str(len(test_samples) - cont_equals) + "\t")
	statis.write(str(round((100 * cont_equals)/len(test_samples),4)) + "\n")

	# Plot os dados no grafico
	pl.clf()
	pl.cla()
	pl.plot(err)
	pl.xlabel('Epoch number')
	pl.ylabel('Error')
	pl.legend(["error_net_" + str(x)])
	pl.savefig(str_gaph)
statis.close() # Fecha o arquivo de dados estatisticos