
using namespace std;
void search(string T, string P)
{
    int i, t=T.size();
    int j, p = P.size();
    for (i=0, j=0; i<t; i++)
    {

        if(T[i]==P[j])
            j++;
        else
        {
            i-=j;
            j=0;
        }
        if(j==p){
             // the condition when match is fount in i-m
        }
    }

}
