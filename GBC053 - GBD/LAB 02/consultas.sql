Com base no esquema:

cliente(codcli, nome, sexo, endereco, cidade, cep, uf, cgc)
    PRIMARY KEY (codcli)
vendedor(codvend, nome, salfixo, faixacomis)
    PRIMARY KEY (codvend)
produto(codprod, descri, autor, valunit, chave_alternativa)
    PRIMARY KEY (codprod)
pedido(numped, prazoentr, codcli, codvend, valortotal, data)
    PRIMARY KEY (numped)
    FOREIGN KEY (codcli) REFERENCES cliente(codcli)
    FOREIGN KEY (codvend) REFERENCES vendedor(codvend)
itemped(numped, codprod, quant), PRIMARY KEY (numped, codprod)
    FOREIGN KEY (numped) REFERENCES pedido(numped)
    FOREIGN KEY (codprod) REFERENCES produto(codprod)

o c�digo disponibilizado cria um esquema de banco de dados no PostgreSQL e popula as tabelas.

Instru��es:

a) execute o script de cria��o de dados para a atividade de otimiza��o de consultas no PostgreSQL arquivo "Aula07b-OtimizacaoConsultas-SQL_Otimizacao-Atividade-postgresql-criacao-tabelas.sql"

  - ao executar em seu computador pessoal ou em uma maquina local, altere
    as chamadas "select gera_clientes(10000)" e "select gera_pedidos(100000)"
    considerando um parametro dez vezes maior.

b) responda os exerc�cios a seguir e apresente os resultados.

-----------------------------------------------------------------------------------------------------------
-- Exerc�cio 1
-- Ao executar o script, verifique na aba Messages do pgAdmin o andamento do processamento. Anote o tempo para execucao dos primeiros 1%, 2%, 3%... at� 5% do processo. O tempo cresce linearmente? Remova o coment�rio do comando CREATE INDEX presente na linha 47 e execute novamente. O tempo cresce linearmente? Comente os resultados e apresente capturas de telas no pgAdmin ou psql das duas execu��es ao chegar em 5%. Explique por que a cria��o do �ndice melhora o desempenho do script.

-----------------------------------------------------------------------------------------------------------
-- Exerc�cio 2
-- O atributo PEDIDO.VALORTOTAL � redundante pois cont�m valores calculados a partir de outros atributos.
-- Como o estagi�rio n�o criou um trigger para mant�-lo atualizado, atualmente cont�m valores que n�o condizem com o total de cada pedido.
-- Atualize em todos os pedidos o campo PEDIDO.VALORTOTAL com a agrega��o do ITEMPED.QUANT * PRODUTO.VALUNIT utilizando o update a seguir.

explain --analyze
update pedido P1
   set VALORTOTAL = (
            select sum(quant*valunit)
              from cliente c, pedido p, itemped i, produto pr
             where c.codcli = p.codcli
               and p.numped = i.numped
               and i.codprod = pr.codprod
               and p.numped = P1.numped); -- note que P1 referencia a tupla do update pedido P1

-- Analise o plano de consulta do comando UPDATE. Verifique se os indices de chave prim�ria s�o empregados. 
-- Verifique se a cria��o dos indices abaixo melhora o desempenho dessa atualiza��o e explique o resultado. Qual o tempo (em segundos) para executar a atualiza��o antes e depois de criar os indices? Apresente capturas de telas das execu��es no pgAdmin ou psql.
create index itemped_codprod_idx on itemped(codprod);
create index pedido_codcli_idx on pedido(codcli);

-----------------------------------------------------------------------------------------------------------
-- Exerc�cio 3
-- Selecione os clientes que compraram em um determinado m�s (entre 60 a 90 dias a partir de hoje), apresente o valor total 
-- dos pedidos por cliente e a quantidade de pedidos realizados por cliente.
-- Ordene o resultado em ordem descendente de valor total para permitir encontrar os maiores compradores.
-- N�o utilize no calculo o atributo PEDIDO.VALORTOTAL pois ainda n�o h� um trigger para mant�-lo atualizado.

explain --analyze
select c.nome, count(distinct(p.NUMPED)), sum(quant*valunit) as soma
from cliente c, pedido p, itemped i, produto pr
where c.codcli = p.codcli
and p.numped = i.numped
and i.codprod = pr.codprod
and p.data between current_date+60 and current_date+90
group by c.nome
order by soma desc;

-- Analise o plano de consulta do comando SELECT. Verifique se os indices de chave prim�ria s�o empregados. 
-- Verifique se a cria��o (ou a remo��o caso ele ja exista) do indice:
CREATE INDEX PEDIDO_DATA ON PEDIDO(DATA);
-- ou
DROP INDEX PEDIDO_DATA;
-- melhora (ou piora) o desempenho dessa consulta. Comente o resultado. 
-- Qual o tempo (em segundos) para executar a consulta sem o indice e com o indice?
-- Apresente capturas de telas das execu��es no pgAdmin ou psql.

-----------------------------------------------------------------------------------------------------------
-- Exerc�cio 4
-- crie um trigger para manter o atributo PEDIDO.VALORTOTAL atualizado. Ao inv�s de uma agrega��o, o trigger deve computar o total de modo incremental, ou seja, se o valor presente no atributo for nulo, deve considerar 0, e ao receber um insert, deve somar o valor, update deve subtrair o anterior e somar o atual, e para o delete deve subtrair o valor.
-- Observe que INSERT, UPDATE e DELETE em ITEMPED podem resultar em atualiza��o de PEDIDO.VALORTOTAL. Apresente o c�digo do trigger e capturas de telas das execu��es no pgAdmin ou psql.

-----------------------------------------------------------------------------------------------------------
-- Exerc�cio 5
-- Verifique se o Postgres utiliza o indice composto PEDIDO_PRAZO_DATA para execu��o da consulta abaixo considerando a existencia ou nao do indice PEDIDO_DATA. Comente o resultado. Apresente capturas de telas das execu��es no pgAdmin ou psql.

explain --analyze
select * from pedido where prazoentr between 15 and 25 and data between '15-10-2022' and '30-10-2022';

CREATE INDEX PEDIDO_PRAZO_DATA ON PEDIDO(DATA,PRAZOENTR);
DROP INDEX PEDIDO_PRAZO_DATA;

CREATE INDEX PEDIDO_DATA ON PEDIDO(DATA);
DROP INDEX PEDIDO_DATA;

