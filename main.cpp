#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <random>
#include <fstream>
#include <string>
#include <sstream>
 
using namespace std;
 
struct Projeto
{
    int id, vagas, nota_minima;
    vector<int> alocados; // lista de IDs dos alunos alocados ao projeto
 
    // Identificador único do projeto - id
    // número de vagas disponíveis - vagas
    // nota mínima necessária - nota_minima
};
 
struct Aluno
{
    int id, nota;
    bool alocado;
    vector<int> preferencias; // lista de  projetos preferidos pelo aluno (identificados pelos IDs)
 
    // o aluno tem um identificador único (id), uma nota (nota), um status de alocação
    // (alocado), e uma lista de preferências de projetos (preferenciais), onde a ordem
    // da lista indica a preferência do aluno pelos projetos (do mais preferido ao menos preferido)
};
 
bool linhaValida(const string &linha)
{
    if (linha.empty()) // se a linha estiver vazia
        return false;
    if (linha.find("//") == 0) // se a linha for um comentário (começa com "//")
        return false;
    return true;
}
 
// função para limpar os parênteses e espaços extras de uma string
void limparString(string &linha)
{
    linha.erase(remove(linha.begin(), linha.end(), '('), linha.end());
    linha.erase(remove(linha.begin(), linha.end(), ')'), linha.end());
    linha.erase(remove(linha.begin(), linha.end(), ' '), linha.end());
}
 
// função para ler os dados de entrada (projetos e alunos) a partir de um arqquivo
void lerEntrada(const string &arquivo, vector<Projeto> &projetos, vector<Aluno> &alunos)
{
    ifstream entrada(arquivo);
    if (!entrada.is_open()) // verifica se o arquivo foi aberto corretamente
    {
        cerr << "Erro ao abrir o arquivo " << arquivo << '\n';
        return;
    }
    string linha;
    int id_projeto = 0, id_aluno = 0, leitura_de_projetos = 0;
 
    while (getline(entrada, linha))
    {
        // checa se a linha é vazia ou se é um comentário.
        if (!linhaValida(linha))
            continue;
 
        // identifica se o tipo de leitura é para projetos ou alunos.
        leitura_de_projetos = !(linha.find("(A") != string::npos);
 
        if (leitura_de_projetos) // Leitura de projetos
        {
            // formato esperado: (P1, 2, '5')
            // extrair campos e remover parênteses
            limparString(linha); // Limpar a linha dos parênteses
            // P1, 2, 5
            vector<string> tokens;
            stringstream ss(linha);
            string temp;
            while (getline(ss, temp, ',')) // divide a Linha em tokens por vírgula
            {
                // Remove espaços
                limparString(temp);
                tokens.push_back(temp);
            }
            // tokens[0] = "P1", tokens[1] = "2", tokens[2] = "5"
            if (tokens.size() >= 3 && tokens[0].size() > 1) // Verifica se os dados estão completos
            {
                Projeto projeto_atual;
                projeto_atual.id = ++id_projeto;
                projeto_atual.vagas = stoi(tokens[1]), projeto_atual.nota_minima = stoi(tokens[2]);
                projetos.push_back(projeto_atual); // Adiciona o projeto à lista
            }
        }
        else
        {
            // Leitura de alunos
            // Formato esperado aluno: (A1):(P1, P30, P50) (5)
            // Dividir em partes
            // 1) (A1):
            // 2) (P1, P30, P50)
            // 3) (5)
            stringstream ss(linha);
            string parte_aluno, parte_projetos, parte_nota, proj_index;
 
            // ler até o ':' => parte_aluno
            // ler até o ')' => parte_projetos
            // ler o resto => parte_nota
            if (!getline(ss, parte_aluno, ':') || !getline(ss, parte_projetos, ')') || !getline(ss, parte_nota))
                continue;
 
            // Limpar parênteses e espaços
            // parte_aluno deve ter (A1)
            // parte_projetos deve ter (P1, P30, P50
            // parte_nota deve ter (5)
 
            limparString(parte_aluno);
            // Remove '(' e espaços de parte_projetos
            limparString(parte_projetos);
            // parte_nota, remover parênteses e espaços
            limparString(parte_nota);
 
            Aluno aluno_atual;
            aluno_atual.id = ++id_aluno, aluno_atual.alocado = false; // Inicializa o status de alocação como falso
            aluno_atual.nota = stoi(parte_nota);                      // Atribui a nota do aluno
 
            // parte_projetos deve ter algo como: P1,P30,P50
            stringstream ss_preferencias(parte_projetos);
            while (getline(ss_preferencias, proj_index, ',')) // Divide os projetos preferidos
            {
                // temp ex: "P1"
                // Remover 'P'
                aluno_atual.preferencias.push_back(stoi(proj_index.substr(1))); // Adiciona a preferência à lista
            }
            alunos.push_back(aluno_atual); // Adiciona o aluno à lista
        }
    }
    entrada.close();
}
 
// função que implementa o algoritmo de Gale-Shapley
void galeShapley(vector<Projeto> &projetos, vector<Aluno> &alunos, queue<int> filaAlunos)
{
    while (filaAlunos.size())
    {
        int alunoIndex = filaAlunos.front(); // obtém o índice do aluno na fila
        filaAlunos.pop();
        Aluno &aluno = alunos[alunoIndex];
 
        // para cada projeto preferido pelo aluno, tenta alocar
        for (int projetoPref : aluno.preferencias)
        {
            Projeto &projeto = projetos[projetoPref - 1];
            if (aluno.nota >= projeto.nota_minima)
            { // Verifica se o aluno tem nota suficiente
                // Se o projeto ainda tem vagas
                if (projeto.alocados.size() < projeto.vagas)
                {
                    cout << "Inserindo aluno " << aluno.id << " no projeto " << projeto.id << ".\n"; 
                    projeto.alocados.push_back(aluno.id);
                    aluno.alocado = true;
                    break;
                }
                else
                { // Se o projeto está cheio, faz uma troca
                    int menor_nota = aluno.nota, id_removido = -1;
                    // Verifica qual aluno será removido (o de menor nota)
                    for (auto &id_alocado : projeto.alocados)
                    {
                        if (alunos[id_alocado - 1].nota <= menor_nota)
                        {
                            id_removido = id_alocado;
                            menor_nota = alunos[id_alocado - 1].nota;
                        }
                    }
                    // se o aluno atual tem uma nota maior que o de menor nota alocado, faz a troca
                    if (id_removido != -1 && alunos[id_removido - 1].nota < aluno.nota)
                    {
                        projeto.alocados.erase(
                            find(projeto.alocados.begin(), projeto.alocados.end(), id_removido));
                        projeto.alocados.push_back(aluno.id);
                        aluno.alocado = true;
                        alunos[id_removido - 1].alocado = false;
                        filaAlunos.push(id_removido - 1);
                        cout << "Trocando aluno " << aluno.id  << " com o aluno " << alunos[id_removido - 1].id  << " no projeto " << projeto.id << ".\n";
                        break;
                    }
                }
            }
        }
    }
}

// comparador costumizado para ordenar alunos
bool comparadorOrdenacao(Aluno &a, Aluno &b) {
    if(a.nota != b.nota) {
        return a.nota > b.nota;
    }
    if(a.preferencias != b.preferencias) {
        return a.preferencias.size() < b.preferencias.size();
    }
    return a.id > b.id;
}

// função para printar no terminal resultado do emparelhamento
void printarResultado(vector<Projeto> &projetos) {

    // percorrer todos os projetos e salvar suas alocações
    for (auto &projeto : projetos)
    {
        cout << "Projeto " << projeto.id << ": ";
 
        if (projeto.alocados.empty())
        {
            cout << "Nenhum aluno alocado" << endl;
        }
        else
        {
            for (const auto &alunoId : projeto.alocados)
            {
                cout << "Aluno " << alunoId << " ";
            }
            cout << endl;
        }
    }
}
 
int main()
{
    vector<Projeto> projetos;
    vector<Aluno> alunos;
 
    // leitura entrada (dados dos projetos e alunos)
    lerEntrada("input.txt", projetos, alunos);

    random_device rd;
    mt19937 g(rd()); // gerador de números aletórios
 
    vector<int> perm(alunos.size());
    for (int i = 0; i < alunos.size(); i++)
        perm[i] = i;
 
    // ordena os alunos por suas notas(obs: os alunos de menor nota serão processados primeiro)
    sort(alunos.begin(), alunos.end(), comparadorOrdenacao);
 
    // variável pra armazenar emparelhamento máximo e lista de projetos do emparelhamento máximo.
    vector<Projeto> projetos_emparelhamento_maximo;
    int alocacao_maxima = 0;
 
    for (int iter = 0; iter < 10; iter++)
    {
        cout << "Iteração = " << iter + 1 << '\n' << '\n';
        shuffle(perm.begin(), perm.end(), g);
        // Cria a fila de alunos a partir dos indíces dos alunos embaralhados
        queue<int> filaAlunos;
        for (int &i : perm)
            filaAlunos.push(i);
        galeShapley(projetos, alunos, filaAlunos);
        cout << '\n';
        // contagem de vagas preenchidas do emparelhamento
        int alocacao_atual = 0;
        for(auto &projeto : projetos) {
            alocacao_atual += (int)projeto.alocados.size();
        }
        if(alocacao_atual > alocacao_maxima) {
            projetos_emparelhamento_maximo = projetos;
            alocacao_maxima = alocacao_atual;
        }
        for(auto &projeto : projetos) {
            projeto.alocados = vector<int>();
        }
        cout << "\n Emparelhamento atual - Vagas Preenchidas : " << alocacao_atual << '\n';
        cout << "============================================\n";
    }
    cout << '\n';
    cout << "====== EMPARELHAMENTO ESTÁVEL MÁXIMO ====== \n";
    cout << '\n';
    cout << "VAGAS PREENCHIDAS : " << alocacao_maxima << '\n';
    cout << '\n';
    printarResultado(projetos_emparelhamento_maximo);
    return 0;
}
