-- Links uteis:
-- Slides Curso => https://drive.google.com/open?id=1sp_JWJUPGCFi-wGrcCoTy5hiuvUdhVUrlGVOg3wFVRk
-- Site oficial PostgreSQL => https://www.postgresql.org/

-- Instalar o PostgreSQL no Linux:
-- Debian/Ubuntu: sudo apt install postgresql

-- Acesso ao postgres PgAdmin (interface grapfica bonitinha):
-- Tutorial: https://linuxhint.com/install-pgadmin4-ubuntu/

-- Acesso ao postgres Terminal :
-- abrir um terminal no linux
-- digitar: sudo su - postgres

-- Criação do banco de dados:
-- createdb <db nome>

-- Acesso ao db: psql <db nome>

-- Agora so copiar e colar esse script para criar as tabelas :)

-- O comando create table cria a tabela no branco de dados
-- A sintaxe basica do comando é create table <nome da tabela> (<campos>)
-- a definição de um campo segue a regra: <nome campo> <tipo> <propriedades>
create table if not exists contato (
  idContato serial primary key, -- Nessa tabela é criado o idContato que é um tipo contador (serial)
                                -- e também um campo tipo chave
  nomeContato varchar(45) null, -- varchar é o tipo string e null define que o campo pode ter valor nulo
  tipoContato CHAR(1) not null -- Char é um campo de caracteres
);

create table if not exists email (
  idContato int, -- A tabela email referência a tabela contato (Conceito de relações), logo precisa
                -- de um atributo para referenciar a mesma
  emailContato varchar(100) unique not null,
  primary key (emailContato, idContato), -- Criação de uma chave composta
  constraint fk_email_1                  -- Constraint são usadas para especificar regras, no caso a regra
                                          -- de chave estrangeira
    foreign key (idContato) -- aqui é definido qual o campo da tabela email é a chave estrangeira
    references contato (idContato) -- aqui é difinido qual tabela é referenciada pela chave e qual o campo
    on delete cascade -- Restrições de integridade:
    on update cascade -- são basicamente o que vai acontecer com essa tabela caso a outra seja deletada ou 
    -- modificada
);

-- As demais tabelas seguem a mesma logica
create table if not exists telefone (
  telefoneContato bigint primary key,
  idContato int not null,
  constraint fk_telefone_1
    foreign key (idContato)
    references contato (idContato)
    on delete cascade
    on update cascade
);

create table if not exists disciplina (
  idDisc serial primary key,
  descricaoDisc varchar(45) not null,
  idProfessor int null UNIQUE,
  constraint fk_disciplina_1
    foreign key (idProfessor)
    references contato (idContato)
    on delete SET null
    on update cascade
);

create table if not exists monitoria (
  idMonitor int not null UNIQUE,
  idDisc int not null UNIQUE,
  constraint fkMonitorContato
    foreign key (idMonitor)
    references contato (idContato)
    on delete cascade
    on update cascade,
  constraint fkMonitorDisciplina
    foreign key (idDisc)
    references disciplina (idDisc)
    on delete cascade
    on update cascade
);

create table if not exists horarioMonitoria (
  idMonitor int not null,
  dia varchar(45) not null,
  hora int not null,
  primary key(idMonitor, dia),
  constraint fkHorarioMonitoria
    foreign key (idMonitor)
    references monitoria (idMonitor)
    on delete cascade
    on update no action
);

create table if not exists semestre (
  numSemestre int primary key,
  dataInicio date not null,
  dataFim date not null
);

create table if not exists grade (
  numSemestre int not null,
  idDisc int not null,
  primary key (numSemestre, idDisc),
  constraint fkGradeSemestre
    foreign key (numSemestre)
    references semestre (numSemestre)
    on delete cascade
    on update cascade,
  constraint fkGradeDisciplina
    foreign key (idDisc)
    references disciplina (idDisc)
    on delete cascade
    on update cascade
);

create table if not exists turma (
  codTurma serial primary key,
  nomeTurma varchar(45) not null,
  descricaoTurma varchar(45)
);

create table if not exists alocacao (
  codTurma int not null,
  idDisc int not null,
  local varchar(20) not null,
  horario int not null,
  primary key (codTurma, idDisc),
  constraint fkAlocacaoTurma
    foreign key (codTurma)
    references turma (codTurma)
    on delete cascade
    on update cascade,
  constraint fkAlocacaoDisc
    foreign key (idDisc)
    references disciplina (idDisc)
    on delete cascade
    on update cascade
);

create table if not exists avaliacao (
  idAvaliacao serial primary key,
  data date not null,
  hora int not null,
  nota FLOAT not null,
  idDisc int not null,
  constraint fkAvaliacao
    foreign key (idDisc)
    references disciplina (idDisc)
    on delete RESTRICT
    on update RESTRICT
);

create table if not exists anotacao (
  idAnotacao serial primary key,
  data date not null,
  texto text not null
);

create table if not exists anotacaoAva (
  idAnotacao int not null primary key,
  idAvaliacao int not null,
  constraint fkAnotacaoAva1
    foreign key (idAnotacao)
    references anotacao (idAnotacao)
    on delete cascade
    on update cascade,
  constraint fkAnotacaoAva2
    foreign key (idAvaliacao)
    references avaliacao (idAvaliacao)
    on delete cascade
    on update cascade
);

create table if not exists dadosPessoais (
  nome varchar(45) not null primary key,
  email varchar(45) not null,
  rua varchar(45) not null,
  numero int not null,
  bairro varchar(20) not null,
  cidade varchar(25) not null,
  estado varchar(25) not null
);

create table if not exists despesa (
  idDespesa serial primary key,
  descricao varchar(45) not null,
  valor FLOAT not null,
  data date not null
);

create table if not exists horaExtra (
  idHoraExtra serial primary key,
  descricao varchar(45) not null,
  qtdeDias int not null,
  qtdeHoras int not null
);

create table if not exists evento (
  idEve serial primary key,
  nomeEve varchar(45) not null,
  descricaoEve varchar(45) not null,
  dataEve date not null,
  horaInicioEve int not null,
  horaTerminoEve int not null
);

create table if not exists anotacaoDesp(
  idAnotacao int not null,
  idDespesa int not null,
  primary key (idAnotacao, idDespesa),
  constraint fkAnotacaoDesp1
    foreign key (idAnotacao)
    references anotacao (idAnotacao)
    on delete cascade
    on update cascade,
  constraint fkAnotacaoDesp2
    foreign key (idDespesa)
    references despesa (idDespesa)
    on delete cascade
    on update cascade
);

create table if not exists anotacaoEve(
  idAnotacao int not null,
  idEve int not null,
  primary key (idAnotacao, idEve),
  constraint fkAnotacaoEve1
    foreign key (idAnotacao)
    references anotacao (idAnotacao)
    on delete cascade
    on update cascade,
  constraint fkAnotacaoEve2
    foreign key (idEve)
    references evento (idEve)
    on delete cascade
    on update cascade
);

alter table alocacao drop COLUMN local;
alter table alocacao drop COLUMN horario;
alter table avaliacao add COLUMN valor float;
alter table avaliacao alter column nota drop not null;
