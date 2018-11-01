
-- selecionar a descricao de todas as disciplinas (com o nome dos seus respectivos
-- professores) que estao no semestre 3 ordenadas pelo nome do professor
-- ta funcionando

SELECT D.descricaoDisc, P.nomeContato
FROM ((disciplina D LEFT JOIN contato P ON D.idProfessor = P.idContato) 
JOIN grade G ON D.idDisc = G.idDisc)
WHERE G.numSemestre = 3
Order by P.nomeContato; -- ORDENAR PELO NOME DO PROFESSOR

-- deleta todas as despesas com valor menor que 10 e que tem data menor que 2017
DELETE FROM despesa
WHERE valor < 10 and data < '2017-01-01';

-- listar o numero do semestre, a descricao das disciplinas e o nome dos professores
-- dos semestres que tenham mais de 5 disciplinas, ordenando pelo numero do semestre

SELECT G.numSemestre, D.descricaoDisc, C.nomeContato
FROM(grade G JOIN disciplina D ON G.idDisc = D.idDisc)
LEFT JOIN contato C ON D.idProfessor = C.idContato
WHERE G.numSemestre IN (SELECT G.numSemestre
FROM grade G JOIN disciplina D ON G.idDisc = D.idDisc 
GROUP BY G.numSemestre 
HAVING Count(D.idDisc) > 5)
ORDER BY G.numSemestre;

-- descricao e horario de monitoria das disciplinas que o monitor
-- que tem o email 'zuleide@departamento.ufla.br' monitora
SELECT D.descricaoDisc, H.hora, H.dia
FROM (((horarioMonitoria H JOIN monitoria M ON H.idMonitor = M.idMonitor) 
JOIN disciplina D ON M.idDisc = D.idDisc) JOIN contato C ON M.idMonitor = C.idContato) 
JOIN email E ON C.idContato = E.idContato
WHERE E.emailContato = 'zuleide@departamento.ufla.br';


-- descricao da disciplina e quantidade de avaliaçoes das disciplinas que tenham monitoria

SELECT  D.descricaoDisc, COUNT(A.idAvaliacao) AS quantidadeAvaliacoes
FROM disciplina D LEFT JOIN avaliacao A ON D.idDisc = A.idDisc
WHERE EXISTS (SELECT * FROM disciplina E, monitoria M
WHERE E.idDisc = M.idDisc AND E.idDisc = D.idDisc)
GROUP BY D.idDisc;


-- VALOR DA SOMA DE TODAS AS DESPESAS, MAIOR DESPESA, MENOR DESPESA E MEDIA

SELECT SUM(D.valor), MAX(D.valor), MIN(D.valor), AVG(D.valor)
FROM despesa D;

-- despesas acima da media

SELECT D.valor
FROM despesa D
GROUP BY D.idDesp
HAVING D.valor > AVG(D.valor);

-- deleta evento que não tenha anotacao
DELETE FROM evento
WHERE idEve NOT IN (SELECT E.idEve FROM evento E JOIN anotacaoEve A ON E.idEve = A.idEve);

-- anotacao dos eventos que aconteceram nas datas do intervalo
DELETE FROM anotacaoEve
WHERE idEve IN (SELECT A.idEve FROM anotacaoEve A JOIN evento E ON A.idEven = E.idEve 
WHERE dataEve BETWEEN '2010-01-01' AND '2014-12-31');