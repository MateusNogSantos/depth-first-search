#include <iostream>
#include <vector>

using namespace std;

//Algoritmo que verifica a conexão entre dois vértices.
//A matriz criado pelo algoritimo de warshall é uma matriz de transitividades.
bool warshall(vector<vector<int>>& Matriz,int v1,int v2,int tam){

    vector<vector<int>> MatrizCopiada(tam,vector<int>(tam));

    //Copia a matriz dada para que as alterações não modifiquem a matriz original.
    MatrizCopiada = Matriz;

    //Primeiro vértice.
    for(int k = 0;k < tam;k++){

        //Vértice do meio.
        for(int i = 0;i < tam;i++){

            //Pela regra da transitividade,se não exitir a primeira relação,a relação entre o vértice inicial e final também não existe.
            if(MatrizCopiada[i][k]){

                //Vértice Final.
                for(int j = 0;j < tam;j++){

                    //Verifica a transitividade.
                    MatrizCopiada[i][j] = MatrizCopiada[i][j] || MatrizCopiada[k][j];

                }
            }
    
        }
    }

    return MatrizCopiada[v1][v2];

}

int main(){

    cout<< "Digite o tamanho do vetor:" << endl;
    int tam;

    cin >> tam;

    vector<vector<int>> matrizAdj(tam,vector<int>(tam));

    cout << "Digite a matriz:" << endl;

    for(int i = 0;i < tam;i++){

        for(int j = 0;j < tam;j++)cin >> matrizAdj[i][j];    
    }

    cout << "Digite os dois vértices à serem verificados:" << endl;

    int v1,v2;

    cin >> v1 >> v2;

    if(warshall(matrizAdj,v1,v2,tam)){

        cout << "Existe um caminho que conecta os dois vértices" << endl;

    }else{
        cout << "Não existe um caminho que conecta os dois vértices"<< endl;
    }
    

    return 0;
}