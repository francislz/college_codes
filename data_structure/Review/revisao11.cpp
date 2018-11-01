#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
    int m, n;
    cin >> m >> n;
    int vet[m], vet1[n];

    for(int i = 0; i < m; ++i){
        cin >> vet[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> vet1[i];
    }

    int excluidos[n], cont = 0;
    bool naoTem = true;
    for(int i = 0; i < m; ++i){
        bool naoAchou = true;
        for(int j = 0; j < n and naoAchou; ++j){
            if(vet[i] == vet1[j]){
                cout << vet[i] << " ";
                excluidos[cont] = vet1[j];
                cont++;
                naoAchou = false;
                naoTem = false;
            }
        }
    }

    if(!naoTem){
        cout << endl;
        for(int i = 0; i < m; ++i){
            cout << vet[i] << " ";
        }
        for(int i = 0; i < n; ++i){
            bool naoAchou = true;
            for (int j = 0; j < cont and naoAchou; ++j){
                if(vet1[i] == excluidos[j])
                    naoAchou = false;
            }
            if(naoAchou)
                cout << vet1[i] << " ";
        }
    }
    else{
        cout << -1 << endl;
        for(int i = 0; i < m; ++i){
            cout << vet[i] << " ";
        }
        for(int i = 0; i < n; ++i){
            cout << vet1[i] << " ";
        }
    }
    cout << endl;
    return 0;
}