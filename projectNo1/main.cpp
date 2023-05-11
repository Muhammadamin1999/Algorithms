#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <ctime>
#include "Sunday.h"
#include "Brute_Force.h"
#include "FsM.h"
#include "Robin_Karp.h"
#include "KMP.h"
#include "GusfieldZ.h"
using namespace std;

string RandomString(int len)
{
   string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   string newstr;
   int pos;
   while(newstr.size() != len) {
    pos = ((rand() % (str.size() - 1)));
    newstr += str.substr(pos,1);
   }
   return newstr;
}

int main()
{
    srand(time(nullptr));
    int N = 10000;
    using chrono::nanoseconds;

    auto begin = chrono::steady_clock::now();
    auto end = chrono::steady_clock::now();

    // time for random data
    nanoseconds total_brute_force(0), average_brute_force(0);
    nanoseconds total_sunday(0), average_sunday(0);
    nanoseconds total_rabin_karp(0), average_rabin_karp(0);
    nanoseconds total_FSM(0), average_FSM(0);
    nanoseconds total_KMP(0), average_KMP(0);
    nanoseconds total_GusfieldZ(0), average_GusfieldZ(0);
    int q = 101;
/*
    //reading from file
    ifstream file_("Text.txt");
    string s,text;
    file_>>s;
    text=s;
    while(file_>>s)
    {
    text=text+" "+s;
    }
 */
    cout << "Enter a string pattern to search:  ";
    string pat;
    std::getline(cin, pat);
    cout<<endl;

    cout << "\n Size\t Brute-Force\t Sunday\t Rabin-Karp\t FSM\t KMP \tGusfieldZ " << endl;
    cout << "------------------------------------------------------------------------------------------------------------\n";
    for (int j=N; j<1000000; j+=50000)
    {
        string text = RandomString(j);

        for(int t = 0; t < 100; t++)
        {

            begin = std::chrono::steady_clock::now();

            search(text, pat);

            end = chrono::steady_clock::now();
            nanoseconds time_brute_force(end - begin);
            total_brute_force += time_brute_force;

           begin = std::chrono::steady_clock::now();

            sunday(text, pat);

            end = chrono::steady_clock::now();
            nanoseconds time_sunday(end - begin);
            total_sunday += time_sunday;

            begin = std::chrono::steady_clock::now();

            RabinKarp(text, pat, q);
            end = chrono::steady_clock::now();
            nanoseconds time_rabin_Karp(end - begin);
            total_rabin_karp += time_rabin_Karp;

            begin = std::chrono::steady_clock::now();

            FSM(text, pat);

            end = chrono::steady_clock::now();
            nanoseconds time_FSM(end - begin);
            total_FSM += time_FSM;

            begin = std::chrono::steady_clock::now();

            KMP(text, pat);

            end = chrono::steady_clock::now();
            nanoseconds time_KMP(end - begin);
            total_KMP += time_KMP;

            begin = std::chrono::steady_clock::now();

            zAlgorithm(text, pat);

            end = chrono::steady_clock::now();
            nanoseconds time_GusfieldZ(end - begin);
            total_GusfieldZ += time_GusfieldZ;
        }

        // time for random data
        average_brute_force = total_brute_force/100;
        average_sunday= total_sunday/100;
        average_rabin_karp= total_rabin_karp/100;
        average_FSM= total_FSM/100;
        average_KMP= total_KMP/100;
        average_GusfieldZ = total_GusfieldZ/100;



             cout << j << " \t\t " << average_brute_force.count() << " \t\t " << average_sunday.count()<<  " \t\t "
             << average_rabin_karp.count() << " \t\t " << average_FSM.count() << " \t\t " << average_KMP.count()<< " \t\t " << average_GusfieldZ.count() << endl;



    }


    return 0;
}
