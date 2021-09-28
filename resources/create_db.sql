CREATE TABLE title (
    id   BIGINT PRIMARY KEY
                NOT NULL,
    nome TEXT
);

CREATE TABLE produto (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nome TEXT,
    tipo TEXT,
    preco DOUBLE
);

INSERT INTO produto (nome, tipo, preco) VALUES("Macarrão", "Cesta basica", 5);
INSERT INTO produto (nome, tipo, preco) VALUES("Arroz", "Cesta basica", 5);
INSERT INTO produto (nome, tipo, preco) VALUES("Sabão", "Limpeza", 22);
INSERT INTO produto (nome, tipo, preco) VALUES("Maçã", "Horti-fruti", 3);
