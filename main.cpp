#include <iostream>
#include <vector>

using namespace std;

int main() {
    int  exec, m, n;
    bool safe = false;

    cout << endl <<"Podaj ilosc zasobów: ";
    cin >> m;

    cout << endl << "Podaj ilosc procesow: ";
    cin>>n;

    int Allocation[n][m];
    int Max[n][m];
    int Available[m];
    int AllRes[m];
    int Running[n];
    int AllocatedRes[m];
    int count = n;
    vector<int> SafeOrder;

    for(int i=0; i<n; i++)
        Running[i] = 1;
    for(int i=0; i<n; i++)
	    AllocatedRes[i] = 0;

    cout << endl << "Wpisz ilosc wszystkich zasobow w systemie" << endl;
    for (int i = 0; i < m; i++)
        cin >> AllRes[i];

    cout << endl << "Wpisz tablice zaalokowanych zasobow" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P[" << i << "] ";
        for (int j = 0; j < m  ; j++)
            cin >> Allocation[i][j];
    }

    cout << endl << "Podaj tablice zasobow potrzebnych do zakonczenia sie procesow" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P[" << i <<"] ";
        for (int j = 0; j < m; j++)
            cin >> Max[i][j];
    }

    cout << endl << "Tablica zasobow w systemie" << endl;
    for (int i = 0; i < m; i++)
        cout << AllRes[i] << " ";
    cout << endl;

    cout << endl << "Tablica zaalokowanych zasobow" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P[" << i << "] ";
        for (int j = 0; j < m; j++)
            cout << "\t" <<  Allocation[i][j] << " ";
        cout << endl;
    }

    cout << endl <<"Tablica zasobow potrzebnych do zakonczenia sie procesow" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P[" << i << "] ";
        for (int j = 0; j < m; j++)
            cout << "\t" << Max[i][j];
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            AllocatedRes[j] += Allocation[i][j];

    cout << endl << "Zaalokowane zasoby"<<endl;
    for (int i = 0; i < m; i++)
        cout << AllocatedRes[i] << " ";

    for (int i = 0; i < m; i++)
        Available[i] = AllRes[i] - AllocatedRes[i];

    cout << endl << "Dostepne zasoby"<<endl;
    for (int i = 0; i < m; i++)
        cout << Available[i] << " ";
    cout << endl;

    int i;
    while (count != 0) {
        safe = false;
        for (i = 0; i < n; i++) {
            if (Running[i]) {
                exec = 1;
                for (int j = 0; j < m; j++) {
                    if (Max[i][j] - Allocation[i][j] > Available[j]) {
                        exec = 0;
                        break;
                    }
                }

                if (exec) {
                    cout << endl <<"Wykonywanie procesu nr: " << i << endl;
                    Running[i] = 0;
                    count--;
                    safe = true;
                    for (int j = 0; j < m; j++)
                        Available[j] += Allocation[i][j];
                    break;
                }
            }
        }

        if (!safe) {
            cout << "Procesy sa w stanie zakleszczenia" << endl;
            break;
        }
        SafeOrder.push_back(i);
        cout << endl << "Dostepne zasoby"<<endl;
        for (int i = 0; i < m; i++)
            cout << Available[i] << " ";
    }

    cout << endl << "Stan - Bezpieczny: " << endl;

    for(unsigned int i=0; i<SafeOrder.size(); i++)
    {
        cout << "P[" << SafeOrder[i] << "], ";
    }
    cout << endl;

    return 0;
}
