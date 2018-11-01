-- Insercao em semestre
INSERT INTO semestre VALUES(1,'2016-08-05','2016-12-05');
INSERT INTO semestre VALUES(2,'2017-03-05','2017-07-19');
INSERT INTO semestre VALUES(3,'2017-08-05','2017-12-05');

-- Insercao em disciplina
INSERT INTO disciplina (descricaoDisc) VALUES('Calculo I');
INSERT INTO disciplina (descricaoDisc) VALUES('Introducao a Algoritmos');
INSERT INTO disciplina (descricaoDisc) VALUES('Circuitos Eletronicos');
INSERT INTO disciplina (descricaoDisc) VALUES('Introducao a Computacao');
INSERT INTO disciplina (descricaoDisc) VALUES('Geometria Analitica e Algebra Linear');
INSERT INTO disciplina (descricaoDisc) VALUES('Fisica B');


INSERT INTO disciplina (descricaoDisc) VALUES('Calculo II');
INSERT INTO disciplina (descricaoDisc) VALUES('Estrutura de Dados');
INSERT INTO disciplina (descricaoDisc) VALUES('Circuitos Digitais');
INSERT INTO disciplina (descricaoDisc) VALUES('Estatistica');
INSERT INTO disciplina (descricaoDisc) VALUES('Matematica Discreta');

INSERT INTO disciplina (descricaoDisc) VALUES('Calculo Numerico');
INSERT INTO disciplina (descricaoDisc) VALUES('Paradigmas de Linguagens de Programacao');
INSERT INTO disciplina (descricaoDisc) VALUES('Banco de Dados');
INSERT INTO disciplina (descricaoDisc) VALUES('Algoritmos em Grafos');
INSERT INTO disciplina (descricaoDisc) VALUES('Linguagens Formais e Automatos');
INSERT INTO disciplina (descricaoDisc) VALUES('Arquitetura');

-- Insercao em semestre-disc (grade)
-- Primeiro Semestre
INSERT INTO grade VALUES(1, 1);
INSERT INTO grade VALUES(1, 2);
INSERT INTO grade VALUES(1, 3);
INSERT INTO grade VALUES(1, 4);
INSERT INTO grade VALUES(1, 5);
INSERT INTO grade VALUES(1, 6);
-- Segundo Semestre
INSERT INTO grade VALUES(2, 7);
INSERT INTO grade VALUES(2, 8);
INSERT INTO grade VALUES(2, 9);
INSERT INTO grade VALUES(2, 10);
INSERT INTO grade VALUES(2, 11);
-- Terceiro Semestre
INSERT INTO grade VALUES(3, 12);
INSERT INTO grade VALUES(3, 13);
INSERT INTO grade VALUES(3, 14);
INSERT INTO grade VALUES(3, 15);
INSERT INTO grade VALUES(3, 16);
INSERT INTO grade VALUES(3, 17);

-- Contatos
-- Alunos 1 a 6
INSERT INTO contato (nomeContato, tipoContato) VALUES('Francisco','a');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Victor','a');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Alan','a');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Igor','a');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Icaro','a');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Fernando','a');

-- Monitores 7 a 15
INSERT INTO contato (nomeContato, tipoContato) VALUES('Gabriel','m');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Zuleide','m');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Roberta','m');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Sergio','m');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Aline','m');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Pedro','m');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Lucas','m');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Bruna','m');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Elisa','m');


-- Professor 16 a 22
INSERT INTO contato (nomeContato, tipoContato) VALUES('Schneider','p');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Bruno Abreu','p');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Denilson','p');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Roberto','p');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Gilva','p');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Antonio','p');
INSERT INTO contato (nomeContato, tipoContato) VALUES('Ricardo','p');

-- Monitor Disciplina
INSERT INTO monitoria (idMonitor, idDisc) VALUES(7,1);
INSERT INTO monitoria (idMonitor, idDisc) VALUES(8,3);
INSERT INTO monitoria (idMonitor, idDisc) VALUES(9,7);
INSERT INTO monitoria (idMonitor, idDisc) VALUES(10,10);
INSERT INTO monitoria (idMonitor, idDisc) VALUES(11,2);
INSERT INTO monitoria (idMonitor, idDisc) VALUES(12,8);
INSERT INTO monitoria (idMonitor, idDisc) VALUES(13,5);
INSERT INTO monitoria (idMonitor, idDisc) VALUES(14,16);
INSERT INTO monitoria (idMonitor, idDisc) VALUES(15,4);

-- Horario Monitoria
INSERT INTO horarioMonitoria (idMonitor, dia, hora) VALUES(7,'Terca-feira',14);
INSERT INTO horarioMonitoria (idMonitor, dia, hora) VALUES(7,'Quinta-feira',14);
INSERT INTO horarioMonitoria (idMonitor, dia, hora) VALUES(8,'Segunda-feira',16);
INSERT INTO horarioMonitoria (idMonitor, dia, hora) VALUES(8,'Quarta-feira',13);
INSERT INTO horarioMonitoria (idMonitor, dia, hora) VALUES(9,'Quinta-feira',15);
INSERT INTO horarioMonitoria (idMonitor, dia, hora) VALUES(9,'Sexta-feira',17);
INSERT INTO horarioMonitoria (idMonitor, dia, hora) VALUES(10,'Segunda-feira',10);
INSERT INTO horarioMonitoria (idMonitor, dia, hora) VALUES(11,'Sexta-feira',15);
INSERT INTO horarioMonitoria (idMonitor, dia, hora) VALUES(12,'Terça-feira',11);
INSERT INTO horarioMonitoria (idMonitor, dia, hora) VALUES(13,'Sexta-feira',19);
INSERT INTO horarioMonitoria (idMonitor, dia, hora) VALUES(13,'Quinta-feira',13);
INSERT INTO horarioMonitoria (idMonitor, dia, hora) VALUES(14,'Sexta-feira',9);
INSERT INTO horarioMonitoria (idMonitor, dia, hora) VALUES(15,'Quarta-feira',17);
INSERT INTO horarioMonitoria (idMonitor, dia, hora) VALUES(15,'Terça-feira',17);

-- Telefones
INSERT INTO telefone (telefoneContato, idContato) VALUES (37998334451,1);
INSERT INTO telefone (telefoneContato, idContato) VALUES (37998334452,2);
INSERT INTO telefone (telefoneContato, idContato) VALUES (37998334453,3);
INSERT INTO telefone (telefoneContato, idContato) VALUES (37998334454,7);
INSERT INTO telefone (telefoneContato, idContato) VALUES (37998334455,8);
INSERT INTO telefone (telefoneContato, idContato) VALUES (37998334456,9);
INSERT INTO telefone (telefoneContato, idContato) VALUES (37998334457,4);
INSERT INTO telefone (telefoneContato, idContato) VALUES (37998334458,5);
INSERT INTO telefone (telefoneContato, idContato) VALUES (37998334459,11);
INSERT INTO telefone (telefoneContato, idContato) VALUES (35994314210, 20);
INSERT INTO telefone (telefoneContato, idContato) VALUES (35882313419, 22);

-- EMails

INSERT INTO email (idContato, emailcontato) VALUES (1, 'francisco@departamento.ufla.br');
INSERT INTO email (idContato, emailcontato) VALUES (2, 'victor@departamento.ufla.br');
INSERT INTO email (idContato, emailcontato) VALUES (3, 'alan@departamento.ufla.br');
INSERT INTO email (idContato, emailcontato) VALUES (7, 'gabriel@departamento.ufla.br');
INSERT INTO email (idContato, emailcontato) VALUES (8, 'Zuleide@departamento.ufla.br');
INSERT INTO email (idContato, emailcontato) VALUES (9, 'renata@departamento.ufla.br');
INSERT INTO email (idContato, emailcontato) VALUES (16, 'Schneider@departamento.ufla.br');
INSERT INTO email (idContato, emailcontato) VALUES (17, 'Bruno@departamento.ufla.br');
INSERT INTO email (idContato, emailcontato) VALUES (18, 'Denilson@departamento.ufla.br');
INSERT INTO email (idContato, emailcontato) VALUES (22, 'Ricardo@departamento.ufla.br');
INSERT INTO email (idContato, emailcontato) VALUES (21, 'Antonio@departamento.ufla.br');
INSERT INTO email (idContato, emailcontato) VALUES (20, 'gilva@departamento.ufla.br');


-- Turmas
INSERT INTO turma (nomeTurma, descricaoTurma) VALUES('10A', 'Turma Computacao');
INSERT INTO turma (nomeTurma, descricaoTurma) VALUES('22A', 'Turma Automacao');
INSERT INTO turma (nomeTurma, descricaoTurma) VALUES('14A', 'Turma Sistemas');

-- Alocacao
-- Primeiro Semestre
INSERT INTO alocacao (codTurma, idDisc) VALUES (1, 1);
INSERT INTO alocacao (codTurma, idDisc) VALUES (1, 2);
INSERT INTO alocacao (codTurma, idDisc) VALUES (2, 3);
INSERT INTO alocacao (codTurma, idDisc) VALUES (3, 4);
INSERT INTO alocacao (codTurma, idDisc) VALUES (1, 5);
INSERT INTO alocacao (codTurma, idDisc) VALUES (1, 6);
-- Segundo Semestre
INSERT INTO alocacao (codTurma, idDisc) VALUES (1, 7);
INSERT INTO alocacao (codTurma, idDisc) VALUES (3, 8);
INSERT INTO alocacao (codTurma, idDisc) VALUES (1, 9);
INSERT INTO alocacao (codTurma, idDisc) VALUES (2, 10);
INSERT INTO alocacao (codTurma, idDisc) VALUES (3, 11);
-- Terceiro Semestre
INSERT INTO alocacao (codTurma, idDisc) VALUES (1, 12);
INSERT INTO alocacao (codTurma, idDisc) VALUES (1, 13);
INSERT INTO alocacao (codTurma, idDisc) VALUES (3, 14);
INSERT INTO alocacao (codTurma, idDisc) VALUES (3, 15);
INSERT INTO alocacao (codTurma, idDisc) VALUES (1, 16);
INSERT INTO alocacao (codTurma, idDisc) VALUES (2, 17);

-- Avaliacoes
-- Primeiro semestre
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-09-05', '00', '33', 1);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-09-12', '00', '33', 2);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-09-14', '00', '33', 3);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-09-20', '00', '33', 4);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-09-21', '00', '33', 5);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-09-20', '00', '33', 6);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-10-05', '00', '33', 1);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-10-12', '00', '33', 2);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-10-14', '00', '33', 3);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-10-20', '00', '33', 4);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-10-21', '00', '33', 5);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-10-20', '00', '33', 6);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-11-05', '00', '34', 1);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-11-12', '00', '34', 2);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-11-14', '00', '34', 3);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-11-20', '00', '34', 4);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-11-21', '00', '34', 5);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2016-11-20', '00', '34', 6);
-- Segundo semestre
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-04-05', '00', '33', 7);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-04-07', '00', '33', 8);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-04-11', '00', '33', 9);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-04-14', '00', '33', 10);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-04-13', '00', '33', 11);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-05-05', '00', '33', 7);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-05-07', '00', '33', 8);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-05-11', '00', '33', 9);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-05-14', '00', '33', 10);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-05-13', '00', '33', 11);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-06-05', '00', '34', 7);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-06-07', '00', '34', 8);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-06-11', '00', '34', 9);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-06-14', '00', '34', 10);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-06-13', '00', '34', 11);
-- Terceiro semestre
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-09-05', '00', '33', 12);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-09-12', '00', '33', 13);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-09-14', '00', '33', 14);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-09-20', '00', '33', 15);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-09-21', '00', '33', 16);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-09-20', '00', '33', 17);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-10-05', '00', '33', 12);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-10-12', '00', '33', 13);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-10-14', '00', '33', 14);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-10-20', '00', '33', 15);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-10-21', '00', '33', 16);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-10-20', '00', '33', 17);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-11-05', '00', '34', 12);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-11-12', '00', '34', 13);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-11-14', '00', '34', 14);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-11-20', '00', '34', 15);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-11-21', '00', '34', 16);
INSERT INTO avaliacao (data, hora, valor, idDisc) VALUES('2017-11-20', '00', '34', 17);
-- Despesas
INSERT INTO despesa (descricao, valor, data) VALUES('Conta de Agua','25.50', '2016-09-21');
INSERT INTO despesa (descricao, valor, data) VALUES('Internet','40.00', '2016-09-05');
INSERT INTO despesa (descricao, valor, data) VALUES('Energia','21.45', '2016-09-15');
INSERT INTO despesa (descricao, valor, data) VALUES('Mercado 1','91.06', '2016-09-02');
INSERT INTO despesa (descricao, valor, data) VALUES('Gas','15.00', '2016-11-07');
INSERT INTO despesa (descricao, valor, data) VALUES('Conta de Agua','27.33', '2016-10-21');
INSERT INTO despesa (descricao, valor, data) VALUES('Internet','40.00', '2016-10-05');
INSERT INTO despesa (descricao, valor, data) VALUES('Energia','22.55', '2016-10-15');
INSERT INTO despesa (descricao, valor, data) VALUES('Mercado 1','97.13', '2016-10-02');
INSERT INTO despesa (descricao, valor, data) VALUES('Conta de Agua','21.23', '2016-11-21');
INSERT INTO despesa (descricao, valor, data) VALUES('Internet','40.00', '2016-11-05');
INSERT INTO despesa (descricao, valor, data) VALUES('Energia','27.43', '2016-11-15');
INSERT INTO despesa (descricao, valor, data) VALUES('Mercado 1','88.03', '2016-11-02');
INSERT INTO despesa (descricao, valor, data) VALUES('Conta de Agua','23.54', '2016-12-21');
INSERT INTO despesa (descricao, valor, data) VALUES('Internet','40.00', '2016-12-05');
INSERT INTO despesa (descricao, valor, data) VALUES('Energia','18.40', '2016-12-15');
INSERT INTO despesa (descricao, valor, data) VALUES('Mercado 1','80.59', '2016-12-02');
INSERT INTO despesa (descricao, valor, data) VALUES('Conta de Agua','15.40', '2017-01-21');
INSERT INTO despesa (descricao, valor, data) VALUES('Internet','40.00', '2017-01-05');
INSERT INTO despesa (descricao, valor, data) VALUES('Energia','21.45', '2017-01-15');
INSERT INTO despesa (descricao, valor, data) VALUES('Mercado 1','97.06', '2017-01-02');
INSERT INTO despesa (descricao, valor, data) VALUES('Conta de Agua','25.50', '2017-02-21');
INSERT INTO despesa (descricao, valor, data) VALUES('Internet','40.00', '2017-02-05');
INSERT INTO despesa (descricao, valor, data) VALUES('Energia','21.45', '2017-02-15');
INSERT INTO despesa (descricao, valor, data) VALUES('Mercado 1','97.06', '2017-02-02');
INSERT INTO despesa (descricao, valor, data) VALUES('Conta de Agua','25.50', '2017-03-21');
INSERT INTO despesa (descricao, valor, data) VALUES('Internet','40.00', '2017-03-05');
INSERT INTO despesa (descricao, valor, data) VALUES('Energia','21.45', '2017-03-15');
INSERT INTO despesa (descricao, valor, data) VALUES('Mercado 1','97.06', '2017-03-02');

-- Anotacoes
INSERT INTO anotacao (data, texto) VALUES('2017-04-15', 'Conta paga com atraso');
INSERT INTO anotacao (data, texto) VALUES('2017-04-15', 'Levar cartaz para apresentacao');
INSERT INTO anotacao (data, texto) VALUES('2017-04-15', 'Avaliacao Pratica');

-- Anotacoes com campos
INSERT INTO anotacaoDesp VALUES (1, 3);
INSERT INTO anotacaoAva VALUES (2, 4);

-- Dados pessoais Usuario
INSERT INTO dadosPessoais VALUES (
    'Carlos Henrique Junior', 
    'carlos.henrique@gmail.com',
    'Rua Saturnino de Padua',
    650,
    'Dos Ipes',
    'Lavras',
    'MG');
