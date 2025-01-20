
# Emparelhamento Máximo Estável 

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

Leitura de um arquivo de entrada `input.txt`, que segue o seguinte formato:

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


# Resultado das Iterações e Emparelhamento Máximo

Este documento apresenta os resultados das 10 iterações realizadas pelo algoritmo de emparelhamento. Cada iteração exibe as alocações realizadas, trocas efetuadas e o número de vagas preenchidas no final da iteração.

---

## **Iterações**

### **Iteração 1**
```plaintext
Inserindo aluno 71 no projeto 21.
Inserindo aluno 8 no projeto 6.
Inserindo aluno 17 no projeto 18.
Inserindo aluno 114 no projeto 24.
Inserindo aluno 25 no projeto 34.
Inserindo aluno 130 no projeto 43.
Inserindo aluno 69 no projeto 29.
Inserindo aluno 164 no projeto 30.
Inserindo aluno 159 no projeto 49.
Inserindo aluno 92 no projeto 36.
Inserindo aluno 149 no projeto 9.
Inserindo aluno 68 no projeto 36.
Inserindo aluno 132 no projeto 20.
Inserindo aluno 32 no projeto 2.
Inserindo aluno 177 no projeto 37.
Inserindo aluno 158 no projeto 47.
Inserindo aluno 93 no projeto 26.
Inserindo aluno 26 no projeto 40.
Trocando aluno 72 com o aluno 103 no projeto 20.
Inserindo aluno 191 no projeto 22.
Inserindo aluno 33 no projeto 3.
Inserindo aluno 185 no projeto 5.
Trocando aluno 160 com o aluno 75 no projeto 30.
Inserindo aluno 94 no projeto 3.
Inserindo aluno 174 no projeto 15.
Trocando aluno 144 com o aluno 28 no projeto 22.
Inserindo aluno 151 no projeto 14.
Inserindo aluno 47 no projeto 41.
Trocando aluno 66 com o aluno 195 no projeto 30.
Inserindo aluno 117 no projeto 7.
Inserindo aluno 35 no projeto 5.
Inserindo aluno 154 no projeto 15.
Inserindo aluno 95 no projeto 53.
Inserindo aluno 175 no projeto 35.
Trocando aluno 133 com o aluno 76 no projeto 35.
Inserindo aluno 24 no projeto 10.
Trocando aluno 58 com o aluno 193 no projeto 47.
Inserindo aluno 73 no projeto 45.
Inserindo aluno 96 no projeto 51.
Inserindo aluno 181 no projeto 17.
Trocando aluno 4 com o aluno 51 no projeto 5.
Trocando aluno 64 com o aluno 173 no projeto 30.
Trocando aluno 14 com o aluno 5 no projeto 15.
Inserindo aluno 100 no projeto 38.
Inserindo aluno 18 no projeto 8.
Inserindo aluno 127 no projeto 28.
Trocando aluno 62 com o aluno 71 no projeto 38.
Trocando aluno 44 com o aluno 120 no projeto 15.
Inserindo aluno 131 no projeto 14.
Trocando aluno 199 com o aluno 194 no projeto 49.
Inserindo aluno 99 no projeto 9.
Trocando aluno 6 com o aluno 38 no projeto 9.
Inserindo aluno 48 no projeto 26.
Inserindo aluno 84 no projeto 4.
Inserindo aluno 107 no projeto 41.
Trocando aluno 161 com o aluno 125 no projeto 17.
Trocando aluno 34 com o aluno 162 no projeto 4.
Inserindo aluno 104 no projeto 25.
Trocando aluno 197 com o aluno 57 no projeto 41.
Trocando aluno 137 com o aluno 78 no projeto 37.
Inserindo aluno 60 no projeto 53.
Trocando aluno 143 com o aluno 198 no projeto 14.
Trocando aluno 41 com o aluno 89 no projeto 14.
Inserindo aluno 200 no projeto 1.
Trocando aluno 157 com o aluno 40 no projeto 37.
Inserindo aluno 83 no projeto 27.
Trocando aluno 55 com o aluno 179 no projeto 35.
Inserindo aluno 1 no projeto 1.
Trocando aluno 61 com o aluno 192 no projeto 37.
Trocando aluno 82 com o aluno 150 no projeto 2.
Inserindo aluno 63 no projeto 39.
Trocando aluno 27 com o aluno 65 no projeto 41.
Inserindo aluno 187 no projeto 7.
Trocando aluno 85 com o aluno 135 no projeto 5.
Inserindo aluno 188 no projeto 8.
Inserindo aluno 31 no projeto 12.
Inserindo aluno 42 no projeto 16.
Inserindo aluno 81 no projeto 27.
Trocando aluno 2 com o aluno 119 no projeto 1.
Trocando aluno 43 com o aluno 36 no projeto 14.


 Emparelhamento atual - Vagas Preenchidas : 53
```

---

### **Iteração 2**
```plaintext

Inserindo aluno 106 no projeto 40.
Inserindo aluno 1 no projeto 1.
Inserindo aluno 157 no projeto 37.
Inserindo aluno 100 no projeto 38.
Inserindo aluno 155 no projeto 45.
Inserindo aluno 97 no projeto 41.
Inserindo aluno 149 no projeto 29.
Inserindo aluno 135 no projeto 15.
Inserindo aluno 71 no projeto 21.
Inserindo aluno 24 no projeto 10.
Inserindo aluno 183 no projeto 30.
Inserindo aluno 47 no projeto 41.
Trocando aluno 53 com o aluno 115 no projeto 30.
Trocando aluno 197 com o aluno 130 no projeto 41.
Trocando aluno 69 com o aluno 38 no projeto 29.
Inserindo aluno 153 no projeto 43.
Trocando aluno 196 com o aluno 186 no projeto 43.
Inserindo aluno 14 no projeto 15.
Inserindo aluno 169 no projeto 9.
Inserindo aluno 31 no projeto 12.
Trocando aluno 73 com o aluno 189 no projeto 45.
Inserindo aluno 55 no projeto 35.
Inserindo aluno 6 no projeto 9.
Trocando aluno 107 com o aluno 65 no projeto 41.
Inserindo aluno 91 no projeto 24.
Inserindo aluno 131 no projeto 14.
Inserindo aluno 60 no projeto 53.
Inserindo aluno 188 no projeto 8.
Inserindo aluno 57 no projeto 18.
Trocando aluno 64 com o aluno 110 no projeto 30.
Inserindo aluno 168 no projeto 36.
Inserindo aluno 93 no projeto 26.
Inserindo aluno 142 no projeto 26.
Inserindo aluno 184 no projeto 25.
Inserindo aluno 161 no projeto 17.
Inserindo aluno 151 no projeto 14.
Inserindo aluno 117 no projeto 7.
Inserindo aluno 132 no projeto 20.
Trocando aluno 143 com o aluno 105 no projeto 26.
Inserindo aluno 68 no projeto 36.
Trocando aluno 98 com o aluno 89 no projeto 26.
Inserindo aluno 8 no projeto 6.
Inserindo aluno 158 no projeto 47.
Inserindo aluno 4 no projeto 3.
Inserindo aluno 187 no projeto 7.
Inserindo aluno 25 no projeto 34.
Inserindo aluno 63 no projeto 39.
Trocando aluno 104 com o aluno 126 no projeto 25.
Trocando aluno 10 com o aluno 19 no projeto 43.
Trocando aluno 154 com o aluno 39 no projeto 15.
Inserindo aluno 95 no projeto 53.
Inserindo aluno 199 no projeto 49.
Trocando aluno 159 com o aluno 118 no projeto 49.
Trocando aluno 130 com o aluno 103 no projeto 20.
Trocando aluno 174 com o aluno 5 no projeto 15.
Inserindo aluno 42 no projeto 16.
Inserindo aluno 48 no projeto 28.
Trocando aluno 66 com o aluno 140 no projeto 9.
Trocando aluno 128 com o aluno 123 no projeto 36.
Trocando aluno 137 com o aluno 192 no projeto 37.
Inserindo aluno 84 no projeto 4.
Inserindo aluno 44 no projeto 3.
Inserindo aluno 200 no projeto 1.
Inserindo aluno 85 no projeto 5.
Trocando aluno 114 com o aluno 120 no projeto 15.
Trocando aluno 181 com o aluno 3 no projeto 17.
Inserindo aluno 32 no projeto 2.
Trocando aluno 41 com o aluno 36 no projeto 14.
Trocando aluno 62 com o aluno 71 no projeto 38.
Inserindo aluno 35 no projeto 5.
Trocando aluno 61 com o aluno 40 no projeto 37.
Trocando aluno 58 com o aluno 193 no projeto 47.
Trocando aluno 33 com o aluno 149 no projeto 3.
Trocando aluno 82 com o aluno 150 no projeto 2.
Inserindo aluno 83 no projeto 27.
Trocando aluno 177 com o aluno 114 no projeto 37.
Inserindo aluno 96 no projeto 51.
Inserindo aluno 144 no projeto 22.
Inserindo aluno 26 no projeto 55.
Inserindo aluno 81 no projeto 27.
Trocando aluno 127 com o aluno 129 no projeto 28.
Trocando aluno 2 com o aluno 119 no projeto 1.
Trocando aluno 191 com o aluno 88 no projeto 22.
Trocando aluno 43 com o aluno 198 no projeto 14.
Trocando aluno 34 com o aluno 162 no projeto 4.
Inserindo aluno 18 no projeto 8.


 Emparelhamento atual - Vagas Preenchidas : 54
```

---

### **Iteração 3**
```plaintext
Inserindo aluno 129 no projeto 29.
Inserindo aluno 199 no projeto 49.
Inserindo aluno 52 no projeto 20.
Inserindo aluno 135 no projeto 15.
Inserindo aluno 200 no projeto 1.
Inserindo aluno 173 no projeto 30.
Inserindo aluno 100 no projeto 38.
Inserindo aluno 71 no projeto 21.
Inserindo aluno 18 no projeto 8.
Inserindo aluno 83 no projeto 27.
Trocando aluno 62 com o aluno 71 no projeto 38.
Inserindo aluno 81 no projeto 27.
Inserindo aluno 63 no projeto 39.
Inserindo aluno 43 no projeto 14.
Inserindo aluno 7 no projeto 41.
Inserindo aluno 96 no projeto 43.
Inserindo aluno 8 no projeto 6.
Inserindo aluno 95 no projeto 53.
Inserindo aluno 158 no projeto 47.
Trocando aluno 164 com o aluno 136 no projeto 30.
Inserindo aluno 117 no projeto 7.
Inserindo aluno 10 no projeto 10.
Inserindo aluno 17 no projeto 18.
Inserindo aluno 55 no projeto 35.
Inserindo aluno 6 no projeto 40.
Inserindo aluno 61 no projeto 37.
Inserindo aluno 91 no projeto 24.
Inserindo aluno 149 no projeto 9.
Inserindo aluno 169 no projeto 9.
Trocando aluno 177 com o aluno 114 no projeto 37.
Inserindo aluno 97 no projeto 41.
Inserindo aluno 92 no projeto 36.
Inserindo aluno 2 no projeto 1.
Inserindo aluno 181 no projeto 17.
Trocando aluno 183 com o aluno 75 no projeto 30.
Trocando aluno 107 com o aluno 17 no projeto 41.
Trocando aluno 133 com o aluno 115 no projeto 30.
Inserindo aluno 155 no projeto 45.
Inserindo aluno 84 no projeto 4.
Inserindo aluno 134 no projeto 25.
Trocando aluno 58 com o aluno 193 no projeto 47.
Inserindo aluno 60 no projeto 53.
Inserindo aluno 44 no projeto 3.
Trocando aluno 184 com o aluno 178 no projeto 25.
Inserindo aluno 93 no projeto 26.
Trocando aluno 26 com o aluno 140 no projeto 9.
Inserindo aluno 127 no projeto 28.
Trocando aluno 197 com o aluno 57 no projeto 41.
Inserindo aluno 168 no projeto 36.
Trocando aluno 153 com o aluno 179 no projeto 30.
Inserindo aluno 185 no projeto 5.
Trocando aluno 99 com o aluno 38 no projeto 9.
Inserindo aluno 82 no projeto 2.
Inserindo aluno 4 no projeto 3.
Trocando aluno 73 com o aluno 186 no projeto 30.
Trocando aluno 53 com o aluno 189 no projeto 45.
Trocando aluno 68 com o aluno 123 no projeto 36.
Inserindo aluno 48 no projeto 26.
Trocando aluno 161 com o aluno 125 no projeto 17.
Inserindo aluno 154 no projeto 15.
Trocando aluno 14 com o aluno 5 no projeto 15.
Inserindo aluno 144 no projeto 22.
Inserindo aluno 41 no projeto 14.
Inserindo aluno 31 no projeto 12.
Inserindo aluno 187 no projeto 7.
Trocando aluno 114 com o aluno 39 no projeto 15.
Inserindo aluno 35 no projeto 5.
Trocando aluno 1 com o aluno 119 no projeto 1.
Trocando aluno 143 com o aluno 51 no projeto 5.
Trocando aluno 85 com o aluno 89 no projeto 5.
Trocando aluno 191 com o aluno 88 no projeto 22.
Trocando aluno 157 com o aluno 78 no projeto 37.
Trocando aluno 27 com o aluno 65 no projeto 41.
Inserindo aluno 174 no projeto 34.
Trocando aluno 33 com o aluno 149 no projeto 3.
Trocando aluno 32 com o aluno 164 no projeto 2.
Trocando aluno 159 com o aluno 118 no projeto 49.
Trocando aluno 25 com o aluno 120 no projeto 34.
Trocando aluno 64 com o aluno 184 no projeto 30.
Trocando aluno 34 com o aluno 162 no projeto 4.
Trocando aluno 137 com o aluno 192 no projeto 37.
Inserindo aluno 42 no projeto 16.
Inserindo aluno 188 no projeto 8.
Trocando aluno 104 com o aluno 126 no projeto 25.


 Emparelhamento atual - Vagas Preenchidas : 52
```

...

### **Iteração 10**
```plaintext
Inserindo aluno 46 no projeto 43.
Inserindo aluno 158 no projeto 47.
Inserindo aluno 145 no projeto 21.
Inserindo aluno 2 no projeto 1.
Inserindo aluno 155 no projeto 45.
Inserindo aluno 116 no projeto 40.
Inserindo aluno 197 no projeto 41.
Inserindo aluno 104 no projeto 25.
Inserindo aluno 160 no projeto 30.
Trocando aluno 171 com o aluno 87 no projeto 21.
Trocando aluno 71 com o aluno 138 no projeto 21.
Inserindo aluno 91 no projeto 24.
Inserindo aluno 127 no projeto 28.
Inserindo aluno 157 no projeto 37.
Inserindo aluno 131 no projeto 14.
Inserindo aluno 92 no projeto 36.
Inserindo aluno 41 no projeto 14.
Inserindo aluno 84 no projeto 4.
Inserindo aluno 161 no projeto 17.
Inserindo aluno 82 no projeto 2.
Inserindo aluno 23 no projeto 9.
Inserindo aluno 25 no projeto 34.
Inserindo aluno 168 no projeto 36.
Inserindo aluno 135 no projeto 15.
Inserindo aluno 159 no projeto 49.
Inserindo aluno 152 no projeto 20.
Trocando aluno 61 com o aluno 192 no projeto 37.
Trocando aluno 72 com o aluno 12 no projeto 20.
Trocando aluno 164 com o aluno 195 no projeto 30.
Trocando aluno 64 com o aluno 75 no projeto 30.
Inserindo aluno 107 no projeto 41.
Inserindo aluno 4 no projeto 3.
Inserindo aluno 163 no projeto 29.
Inserindo aluno 10 no projeto 10.
Inserindo aluno 100 no projeto 38.
Trocando aluno 137 com o aluno 114 no projeto 37.
Inserindo aluno 85 no projeto 5.
Inserindo aluno 6 no projeto 9.
Inserindo aluno 22 no projeto 18.
Inserindo aluno 60 no projeto 53.
Inserindo aluno 185 no projeto 5.
Trocando aluno 53 com o aluno 189 no projeto 45.
Trocando aluno 169 com o aluno 29 no projeto 29.
Inserindo aluno 188 no projeto 8.
Trocando aluno 97 com o aluno 65 no projeto 41.
Inserindo aluno 200 no projeto 1.
Trocando aluno 35 com o aluno 51 no projeto 5.
Inserindo aluno 33 no projeto 3.
Inserindo aluno 98 no projeto 26.
Inserindo aluno 83 no projeto 27.
Inserindo aluno 95 no projeto 53.
Trocando aluno 149 com o aluno 140 no projeto 29.
Inserindo aluno 143 no projeto 26.
Inserindo aluno 174 no projeto 15.
Inserindo aluno 144 no projeto 22.
Inserindo aluno 42 no projeto 16.
Inserindo aluno 175 no projeto 35.
Trocando aluno 191 com o aluno 88 no projeto 22.
Inserindo aluno 31 no projeto 12.
Trocando aluno 68 com o aluno 123 no projeto 36.
Inserindo aluno 81 no projeto 27.
Inserindo aluno 63 no projeto 39.
Trocando aluno 199 com o aluno 194 no projeto 49.
Trocando aluno 48 com o aluno 89 no projeto 26.
Inserindo aluno 8 no projeto 6.
Trocando aluno 1 com o aluno 119 no projeto 1.
Trocando aluno 114 com o aluno 120 no projeto 15.
Trocando aluno 177 com o aluno 40 no projeto 37.
Trocando aluno 43 com o aluno 198 no projeto 14.
Trocando aluno 62 com o aluno 71 no projeto 38.
Inserindo aluno 117 no projeto 7.
Trocando aluno 181 com o aluno 3 no projeto 17.
Trocando aluno 96 com o aluno 193 no projeto 47.
Trocando aluno 154 com o aluno 39 no projeto 15.
Trocando aluno 55 com o aluno 76 no projeto 35.
Inserindo aluno 26 no projeto 55.
Trocando aluno 44 com o aluno 5 no projeto 15.
Trocando aluno 32 com o aluno 164 no projeto 2.
Trocando aluno 34 com o aluno 162 no projeto 4.
Trocando aluno 129 com o aluno 38 no projeto 29.
Inserindo aluno 187 no projeto 7.
Inserindo aluno 18 no projeto 8.


 Emparelhamento atual - Vagas Preenchidas : 53
```

---

## **Emparelhamento Estável Máximo**

No final das 10 iterações, o emparelhamento estável máximo encontrado foi o seguinte:

### **Vagas Preenchidas: 55**

```plaintext
Projeto 1: Aluno 2 Aluno 1
Projeto 2: Aluno 32
Projeto 3: Aluno 94 Aluno 33
Projeto 4: Aluno 34
Projeto 5: Aluno 4 Aluno 35
Projeto 6: Aluno 8
Projeto 7: Aluno 117 Aluno 187
Projeto 8: Aluno 188 Aluno 18
Projeto 9: Aluno 23 Aluno 69
Projeto 10: Aluno 24
Projeto 11: Nenhum aluno alocado
Projeto 12: Aluno 31
Projeto 13: Nenhum aluno alocado
Projeto 14: Aluno 41 Aluno 43
Projeto 15: Aluno 44 Aluno 114
Projeto 16: Aluno 42
Projeto 17: Aluno 161
Projeto 18: Aluno 57
Projeto 19: Nenhum aluno alocado
Projeto 20: Aluno 72
Projeto 21: Aluno 71
Projeto 22: Aluno 191
Projeto 23: Aluno 197
Projeto 24: Aluno 91
Projeto 25: Aluno 104
Projeto 26: Aluno 93 Aluno 48
Projeto 27: Aluno 83 Aluno 81
Projeto 28: Aluno 127
Projeto 29: Aluno 129
Projeto 30: Aluno 64
Projeto 31: Nenhum aluno alocado
Projeto 32: Nenhum aluno alocado
Projeto 33: Nenhum aluno alocado
Projeto 34: Aluno 111
Projeto 35: Aluno 55
Projeto 36: Aluno 92 Aluno 68
Projeto 37: Aluno 157
Projeto 38: Aluno 62
Projeto 39: Aluno 63
Projeto 40: Aluno 6
Projeto 41: Aluno 27 Aluno 7
Projeto 42: Nenhum aluno alocado
Projeto 43: Aluno 10
Projeto 44: Nenhum aluno alocado
Projeto 45: Aluno 53
Projeto 46: Nenhum aluno alocado
Projeto 47: Aluno 98
Projeto 48: Nenhum aluno alocado
Projeto 49: Aluno 199
Projeto 50: Nenhum aluno alocado
Projeto 51: Aluno 96
Projeto 52: Nenhum aluno alocado
Projeto 53: Aluno 60 Aluno 95
Projeto 54: Nenhum aluno alocado
Projeto 55: Aluno 26
```


