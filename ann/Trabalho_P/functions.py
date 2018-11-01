import csv
import numpy as np
import neurolab as nl

# Funcao de normalizacao retirada de: Fonte
def normalize(value, oldMin, oldMax, newMin = -1, newMax = 1):
	return (((value - oldMin) * (newMax - newMin))/(oldMax - oldMin)) + newMin

# Funcao que le o arquivo de dados
def read_file(file = "bank.csv"):
	# Abre o arquivo cvs de dados
	csvfile = open('bank.csv','r')
	# Le a primeira linha que contem as colunas
	aux = csvfile.readline()
	keys = aux.split(";") # Array com o Nome de cada Coluna
	keys = [row.replace("\"","") for row in keys] # Remove uma " que esta na string
	keys = [row.replace("\n","") for row in keys] # Remove um \n que esta na string
	
	array = []
	# Le os valores restantes
	for row in csvfile: # Para cada linha faca
		aux = row.split(";") # Divida a linha da string por ; (o ; separa cada dado)
		arr = []
		for x in aux:
			arr.append(x.replace("\"","")) # Remove aspas extras que estao nos dados
		array.append(arr)
	csvfile.close()

	return keys, array # Retorna as duas listas para as variveis

# Funcao que retorna as keys para mapear as variaveis categoricas para bits
def get_keys():
	job = {
		'admin.': [0,0,0,0],
		'blue-collar': [0,0,0,1],
		'entrepreneur': [0,0,1,0],
		'housemaid': [0,0,1,1],
		'management': [0,1,0,0],
		'retired': [0,1,0,1],
		'self-employed': [0,1,1,0],
		'services': [0,1,1,1],
		'student': [1,0,0,0],
		'technician': [1,0,0,1],
		'unemployed': [1,0,1,0],
		'unknown': [1,0,1,1]
	}
	marital = {
		'single': [0,0],
		'married': [0,1],
		'divorced': [1,0]
	}
	education = {
		'primary': [0,0],
		'secondary': [0,1],
		'tertiary': [1,0],
		'unknown': [1,1]
	}
	yes_no = {
		'no':[0],
		'yes':[1]
	}
	contact = {
		'cellular': [0,0],
		'telephone': [0,1],
		'unknown': [1,0]
	}
	month = {
		'jan':[0,0,0,0],
		'feb':[0,0,0,1],
		'mar':[0,0,1,0],
		'apr':[0,0,1,1],
		'may':[0,1,0,0],
		'jun':[0,1,0,1],
		'jul':[0,1,1,0],
		'aug':[0,1,1,1],
		'sep':[1,0,0,0],
		'oct':[1,0,0,1],
		'nov':[1,0,1,0],
		'dec':[1,0,1,1]
	}
	poutcome = {
		'failure':[0,0],
		'success':[0,1],
		'other':[1,0],
		'unknown':[1,1]	
	}
	maping_values = {
		'job': job,
		'marital':marital,
		'education':education,
		'default':yes_no,
		'housing':yes_no,
		'loan':yes_no,
		'contact':contact,
		'month':month,
		'poutcome': poutcome,
		'y':yes_no
	}
	return maping_values

# Funcao que retorna o maximo e o minimo de cada entrada
def get_values_range(array):
	# Valor maximo e minimo de cada entrada
	values_range = []
	for x in np.array(array).T:
		values_range.append([min(x), max(x)])
	return values_range

# Funcao que prepara os dados
def prepare_data(array, keys):
	# Remove uma quebra de linha (\n) que tem no final da string 
	i = 0
	# Loop para remover o \n que esta nas strings
	for x in array:
		j = 0
		for y in x:
			if '\n' in y:
				array[i][j] = y.replace("\n","")
			j+=1
		i+=1
	# Recebe o maximo e o minimo dos valores para a normalizacao
	values_range = get_values_range(array)
	# Recebe o dicionario com as chaves de mapeamento
	maping_values = get_keys()

	# Cria uma lista auxiliar vazia
	aux_list = [[] for row in array]
	i = 0
	# Percorre as keys e procura uma incidencia na matriz de dados
	for x in keys:
		# Se o valor de x for um valor a ser mapeado entao a variavel categorica e convertida para bits
		if x in maping_values:
			j = 0
			for row in array:
				aux = maping_values[x]
				for value in aux[row[i]]:
					aux_list[j].append(value)
				j+=1
		# Senao o valor que ja e numero e apenas normalizado seguindo a funcao normalize
		else:
			j = 0
			for row in array:
				aux_list[j].append(round(normalize(int(row[i]), int(values_range[i][0]),int(values_range[i][1]), 0, 1), 4))
				j+=1
		i+=1
	return aux_list