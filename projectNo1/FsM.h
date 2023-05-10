
#define total_chars 256
int Next_state(string p, int M, int st, int inp)
{

    if (st < M && inp == p[st])
        return st+1;

    for (int ns = st; ns > 0; ns--)
    {
        int i;

        if (p[ns-1] == inp)
        {
            for (i = 0; i < ns-1; i++)
                if (p[i] != p[st-ns+1+i])
                    break;
            if (i == ns-1)
                return ns;
        }
    }
    return 0;
}

//builds Finite Automata
void transaction_function(string p, int M, int tf[][total_chars])
{
    for (int st = 0; st<= M; st++)
        for (int inp = 0; inp < total_chars; inp++)
            tf[st][inp] = Next_state(p, M, st, inp);
}

//prints all occurrences of pattern in text
void FSM(string txt, string pat)
{
    int M = pat.size();
    int N = txt.size();
    auto tf = new int[M+1][total_chars];
    transaction_function(pat, M, tf);
    int i, st=0;
    for (i = 0; i < N; i++)
    {
        st = tf[st][txt[i]];
        if (st == M){
              //the condition when match is found in i-M+1
    }
    }
}
