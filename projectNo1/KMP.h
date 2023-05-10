using namespace std;
void CreateLPS(string, int, int*);

void KMP(string txt, string pat)
{
    int M = pat.size();
    int N = txt.size();

    int* lps = new int[M];
    CreateLPS(pat, M, lps);

    int i=0, j=0;

    while(i<N)
    {
        if(txt[i]==pat[j])
        {
            i++;
            j++;
        }

        if(j==M)
        {
            //the condition when match is found in i-j

            j= lps[j-1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

}
void CreateLPS(string pat, int m, int* lps)
{
    lps[0] = 0;
    int value = 0, i=1;

    while(i<m)
    {
        if(pat[i]==pat[value])
        {
            value++;
            pat[i] = value;
            i++;
        }
        else
        {
            if(value!=0)
            {
                value = lps[value-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
