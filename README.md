# Controle de Estoque (C)

Sistema simples de controle de estoque via terminal, com persistência em arquivo de texto (`inventory.txt`).

## Funcionalidades

- **Adicionar item** — cadastra nome e quantidade, gravando no final do arquivo.
- **Remover item** — busca o item pelo nome e subtrai a quantidade informada; remove o item da lista se a quantidade zerar.
- **Listar estoque** — exibe todos os itens cadastrados com suas quantidades.
- **Sair** — encerra o programa.

## Compilação

```bash
gcc -o estoque estoque.c
```

## Execução

```bash
./estoque
```

## Formato do arquivo `inventory.txt`

Cada item ocupa duas linhas: nome seguido da quantidade.

```
Parafuso
150
Martelo
8
```

O arquivo é criado automaticamente na primeira execução de "Adicionar Item", no mesmo diretório do executável.

## Limitações conhecidas

- Nomes de produto: buffer de até 99 caracteres em `remover_item` (`nomes[100]`) e até 499 em `adicionar_item` (`nome[500]`) — inconsistência entre as duas funções.
- Capacidade fixa de 500 itens em memória (`nomes_arquivo[500][100]`, `quantidades[500]`) em `remover_item`.
- Sem tratamento para nomes de produto duplicados (o primeiro encontrado é o único afetado).
- Sem validação de quantidade negativa na entrada.
