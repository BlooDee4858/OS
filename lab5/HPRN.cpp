#include <iostream>
using namespace std;

struct Process{
    float length;
    int appear;
    int progress = 0;
    int number;
    bool done = false;
    float wait = 0;
};


int main() {
    int n, time = 0, min = 99999, k = 0;
    float max = 0;
    cout << "Enter the number of processes" << endl;
    cin >> n;
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
            if(p[j].appear == min)
            {
                if(p[j].length < p[k].length)
                {
                    min = p[j].appear;
                    k = j;
                }
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
        if(p[j].appear <= i)
        {
            for(int t = 0; t < n; t++)
            {
                if(!p[t].done && p[t].appear <= i && t != j)
                {
                    p[t].wait++;
                }
            }
            cout << "Process " << p[j].number << endl;
            p[j].progress++;
            if(p[j].progress == p[j].length)
            {
                p[j].done = true;
                for(int t = 0; t < n; t++)
                {
                    if(!p[t].done)
                    {
                        if( ((p[t].wait + p[t].length) / p[t].length) > max)
                        {
                            max = (p[t].wait + p[t].length) / p[t].length;
                            j = t;
                        }
                    }
                }
                max = 0;
            }
            count++;

        }
    }

    return 0;
}
