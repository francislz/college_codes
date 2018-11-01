from functions import read_file
from functions import prepare_data
from functions import get_values_range
import neurolab as nl

# Le o arquivo de dados e retorna o nome de cada coluna (keys) e a matriz de dados (data)
[keys, data] = read_file()

# Pepara de forma adequada os dados para a RNA, convertendo variaveis categoricas em bits
# e nomalizando os dados em um intervalo de 0 a 1
data = prepare_data(data, keys)

# A ultima coluna sao os valores alvo, portanto os valores sao 
# recebidos e convertidos para de uma lista de lista para um array
target = [[int(row[len(row) - 1])] for row in data]

# As amostras sao convertidas para uma matriz (array de array)
samples = [row[0:(len(row) - 1)] for row in data]

# Valor maximo e minimo de cada entrada
values_range = get_values_range(samples)

number_of_neurons = int(len(samples[0]) * 1.5)

# Faz o treinamento de 10 Net para poder escolher qual a melhor a se usar
for i in range(1,11):
	str_net = "nets/bank" + str(i) + ".net"
	str_err = "errs/err" + str(i) + ".txt"

	file_err = open(str_err, 'w')
	
	# O numero de colunas na variavel values_range vai definir o numero de entradas
	# Cria uma rede de 3 camadas com o numero de neuronios definido pela operacao em : number_of_neuros
	net = nl.net.newff(values_range, [number_of_neurons, number_of_neurons, 1])

	# Faz o treinamento da RNA para um maximo de 1500 epocas
	err = net.train(samples, target, epochs = 1500, show=15)
	# Salva a rede treinada
	net.save(str_net)

	# Salva os valores do Vetor de erros no arquivo txt
	for error in err:
		file_err.write(str(error) + "\n")
	file_err.close()