#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

//Struct de cada vertice/linha da lista de adjacência.
struct vetorDoVertice{

    vector<int> vetores;
    int distancia;
    char cor;
    int pai;

};

//Função de busca em profundidade.
void depthFirstSearch(vector<vetorDoVertice>& adj,int source,int tam){

    //Inicializa todos os vértices da lista.
    for(int i = 0;i < tam;i++){

        //Inicializa os vértices com atributos ainda não conhecidos.
        adj[i].pai = -1;
        adj[i].distancia = -1;

        //Pinta o vértice de branco(ainda não explorado).
        adj[i].cor = 'b';


    }

    //Pinta a fonte de cinza(à ser explorado) e inicializa o atributo distância.
    adj[source].cor = 'c';
    adj[source].distancia = 0;

    //Inicialização da pilha de vértices e inserção da fonte na pilha.
    stack<int> pilhaVisita;
    pilhaVisita.push(source);

    //Enquanto a pilha não estiver vazia a iteração acontece.
    while(!pilhaVisita.empty()){

        //Possíveis casos:

        //O vértice não tem vizinhos.
        if(adj[pilhaVisita.top()].vetores.empty()){

            //Se o vértice não tem vizinhos,pinta de preto(já explorado por completo) e tira da pilha de vizitação.
            adj[pilhaVisita.top()].cor = 'p';
            pilhaVisita.pop();
        }

        //O vértice tem vizinhos.
        else{

            //Variável sentinela de controle.
            bool avancou = false;

            //Iteração para a exploração de todos os vizinhos de um vértice.
           for(int i = 0;i < adj[pilhaVisita.top()].vetores.size();i++){

                //Armazena em uma variável o vértice vizinho do explorado na iteração.
                int atual = adj[pilhaVisita.top()].vetores[i];

                //Achou um vértice vizinho branco.
                if(adj[atual].cor == 'b'){

                    //Pinta o vértice como cinza(à ser explorado) e calcula a distância de chegada no vértice.
                    adj[atual].distancia = adj[pilhaVisita.top()].distancia + 1;
                    adj[atual].cor = 'c';

                    //Coloca o vértice encontrado na pilha de execução.
                    pilhaVisita.push(atual);

                    //Forma de parar a execução do for sem usar break.
                    i = adj[pilhaVisita.top()].vetores.size();

                    //Sinaliza para a sentinela que achou o vértice branco.
                    avancou = true;

                }

           }

           //Caso a iteração ocorra e nenhum avanço seja feito,significa que o vertice tem vizinhos,mas já explorados.
            if(avancou == false){

                //Pinta de preto e tira da pilha de vizitação.
                adj[pilhaVisita.top()].cor = 'p';
                pilhaVisita.pop();
            }
            
        }

    }

}

//Função para ler e colocar os valores na lista de adjacência.
void lerVertice(vector<vetorDoVertice>& listaAdjacencia,int tamanho){

    //Valor temporário.
    int tempNum;

    //Leitura dos vértices.
    for(int i = 0;i < tamanho;i++){

        cout << "Digite os vértice que são vizinhos do vértice " << i << endl << "Digite '-1' para parar a leitura." << endl;

        cin >> tempNum;

        if(tempNum >= tamanho){

            cerr << "O número não representa um vértice válido!";
            exit(1);
        }

        //Para a leitura quando o valor for menor que 0.
        while(tempNum >= 0){

            listaAdjacencia[i].vetores.push_back(tempNum);

            cin >> tempNum;
        }
    }


}

int main(){

    cout << "Digite o tamanho da matriz(Ex: n X n tem tamanho n)." << endl;

    //inicializacao da lista de adjacencia
    int quantidadeVertices;
    cin >> quantidadeVertices;

    vector<vetorDoVertice> listaAdjacencia(quantidadeVertices);

    lerVertice(listaAdjacencia,quantidadeVertices);
    
    depthFirstSearch(listaAdjacencia,0,quantidadeVertices);

    //Imprime os valores.
    for(int i = 0;i < quantidadeVertices;i++){

        cout << i << " tem distancia: " << listaAdjacencia[i].distancia << endl; 
    }

    return 0;
}