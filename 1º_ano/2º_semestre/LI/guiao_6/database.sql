--Exercicio 6.1
--database.db

CREATE TABLE contacts(
    nome TEXT,
    numeroTelefone INTEGER
);
--TEXT: Texto.
--INTEGER: Números inteiros.
--REAL: Números reais.
--BLOB: Um qualquer conteúdo (ex, uma imagem).


--Exercicio 6.2
INSERT INTO contacts VALUES ("João Maria", "925832555");
INSERT INTO contacts VALUES ("Joao Pedro",123123123);
INSERT INTO contacts VALUES ("Lopes Antonio", 999999999);



INSERT INTO contacts(nome) VALUES ( "Martim Leitner" );

--Exercicio 6.3
SELECT * FROM contacts
--Exercicio 6.4
SELECT * FROM contacts ORDER BY numeroTelefone ASC;

SELECT numeroTelefone FROM contacts WHERE nome ="Martim Leitner";

--Exercicio 6.5
UPDATE contacts SET numeroTelefone = 967674370 WHERE nome="Bia Baby";

DELETE FROM contacts WHERE numeroTelefone = 925832555;

--Exercicio 6.6
CREATE TABLE companies (
    name TEXT,
    adress TEXT,
    vatnumber INTEGER
);

--Exercicio 6.7
-- (no terminal) sqlite3 database1.db

CREATE TABLE companies (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    adress TEXT,
    vatnumber INTEGER
);

--Exercicio 6.8
CREATE TABLE contacts (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    firstname TEXT,
    middlename TEXT,
    lastname TEXT,
    email TEXT,
    phone INTEGER,
    company_id INTEGER
);
INSERT INTO contacts (firstname, middlename, lastname, email, phone, company_id) VALUES (1,"Gonçalves", "Leitner", "bia@gmail.com", 923123111, 1);

--alternativa para inserir vários
INSERT INTO companies (name, adress, vatnumber) VALUES 
("MaxiPlano", "Aveiro", 123123123123),
("Luís Manuel & filhos", "Águeda", 54534343435),
("ProDesign", "Porto", 54534343435);

--Exercicio 6.8
INSERT INTO contacts (firstname, middlename, lastname, email, phone, company_id) VALUES
("João", "Manuel", "Fonseca", "jmf@gmail.com", 912345654, 3),
("Pedro", "Albuquerque", "Silva", "pedro23@gmail.com", 932454349, 2),
("Maria", "Carreira", "Dinis", "mariadi@ua.pt", 234958673, 1),
("Catarina", "Alexandra", "Rodrigo", "calexro@sapo.pt", 963343386, 1);

INSERT INTO companies(name, adress, vatnumber) VALUES ("Leitner Inc", "Aveiro", 999999999 );
INSERT INTO contacts (firstname, middlename, lastname, email, phone, company_id) VALUES
("Martins", "Batista", "Leitner", "leitnerpvp@gmail.com", 912345654, 4);
--Exercicio 6.9

SELECT contacts.*
FROM contacts,companies
WHERE contacts.company_id = companies.id
AND companies.adress = "Aveiro";


