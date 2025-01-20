
# Emparelhamento Máximo Estável - Variação do Gale-Shapley

Este projeto implementa uma solução para o problema de alocação de alunos em projetos financiados, utilizando uma variação do algoritmo de Gale-Shapley. O objetivo é alcançar um **emparelhamento máximo e estável** entre alunos e projetos, considerando as restrições de preferências e notas mínimas.

---

## **Descrição do Problema**

Uma universidade oferece 55 projetos, com um total de 74 vagas disponíveis. Os projetos têm:
- **Capacidade máxima e mínima** de alunos.
- **Nota mínima exigida** para participação.

Os 200 alunos que se candidataram possuem:
- **Notas agregadas inteiras** (3 - suficiente, 4 - muito boa, 5 - excelente).
- **Três preferências de projetos**, ordenadas por prioridade.

O algoritmo busca:
1. Alocar o maior número possível de alunos respeitando as restrições.
2. Garantir um emparelhamento estável, onde nenhum aluno ou projeto prefira trocar de parceiro.

---

## **Estratégia Implementada**

Este projeto utiliza uma **variação do algoritmo Gale-Shapley** para resolver o problema. As principais características da implementação são:

- **Troca por nota:** Se um projeto está cheio, o aluno com a menor nota é substituído caso outro aluno de maior nota prefira aquele projeto.
- **Permutações:** O programa realiza 10 iterações do algoritmo, embaralhando os alunos em cada iteração para explorar diferentes emparelhamentos.
- **Critério de estabilidade:** Garante que nenhum par projeto-aluno insatisfeito possa trocar e melhorar sua posição no emparelhamento.
- **Emparelhamento máximo:** O programa acompanha o emparelhamento de maior alocação entre as 10 iterações realizadas.

---

## **Entradas**

O programa lê um arquivo de entrada chamado `input.txt`, que segue o seguinte formato:

### **Projetos**
Cada linha representa um projeto no formato:
```
(P<ID>, <vagas>, <nota_minima>)
```
Exemplo:
```
(P1, 3, 4)
```

### **Alunos**
Cada linha representa um aluno no formato:
```
(A<ID>): (<P1>, <P2>, <P3>) (<nota>)
```
Exemplo:
```
(A1): (P1, P30, P50) (5)
```

