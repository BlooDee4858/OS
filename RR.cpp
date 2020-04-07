#include <iostream>
using namespace std;

struct Process{
    int length;
    int appear;
    int progress = 0;
    int number;
    bool done = false;
};


int main() {
    int n, reserv, time = 0, min = 99999, k = 0;
    cout << "Enter the number of processes" << endl;
    cin >> n;
    cout << "Enter the reservation time" << endl;
    cin >> reserv;
    Process temp;
    Process *p = new Process[n];


    //initialization
    for(int i = 0; i < n; i++)
    {
        cout << "Enter the length of process " << i << endl;
        cin >> p[i].length;
        time += p[i].length;
        cout << "Enter the time of appear process " << i << endl;
        cin >> p[i].appear;
        p[i].number = i;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
           if(p[j].appear < min) {
               min = p[j].appear;
               k = j;
           }
        }
        temp = p[i];
        p[i] = p[k];
        p[k] = temp;
        min = 999999;
    }


    int j = 0;
    int count = 0;
    for(int i = 1; i <= time; i++)
    {
        cout << "Quantum " << i << ": ";
        for(int r = 0; r < n; r++)
        {
            if(p[j].done)
            {
                j++;
                j %= n;
            }
        }
        if(p[j].appear <= i && !p[j].done)
        {
            cout << "Process " << p[j].number << endl;
            p[j].progress++;
            if(p[j].progress == p[j].length)
            {
                p[j].done = true;
            }
            count++;
            if(count == reserv || p[j].done)
            {
                j++;
                j %= n;
                count = 0;
            }
        }
    }

    return 0;
}
