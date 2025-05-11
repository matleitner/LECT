CREATE TABLE contacts(
    nome TEXT,
    numeroTelefone INTEGER
);

INSERT INTO contacts VALUES ("João Maria", 925832555);
INSERT INTO contacts VALUES ("Joao Pedro",123123123);
INSERT INTO contacts VALUES ("Lopes Antonio", 999999999);



INSERT INTO contacts(nome) VALUES ( "Martim Leitner" );

SELECT * FROM contacts
ORDER BY numeroTelefone ASC;

SELECT numeroTelefone FROM contacts WHERE nome ="Martim Leitner";
