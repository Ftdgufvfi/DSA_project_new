#include<bits/stdc++.h>
using namespace std;
int main()
{
    int lads;
    cin>>lads;
    map<int,int>lad;
    for(int i = 0;i<lads;i++)
    {
        int u,v;
        cin>>u>>v;
        lad[u]=v;
    }
    queue<int>qr;
    qr.push(1);
    int moves = 0;
    bool found = false;
    vector<int>vis(101,0);
    while(!qr.empty() and !found)
    {
        int size = qr.size();
        for(int i =0;i<size;i++)
        {
            int t = qr.front();
            qr.pop();
            for(int die = 1;die<=6;die++)
            {
                if(t+die <= 100 and lad[t+die] and !vis[lad[t+die]])
                {
                    vis[lad[t+die]] = true;
                    if((lad[t+die]) == 100)
                    {
                        found = true;
                    }
                    qr.push(lad[t+die]);
                }
                if(t+die <= 100 and !vis[t+die])
                {
                    vis[t+die] = true;
                    if((t+die) == 100)
                    {
                        found = true;
                    }
                    qr.push(t+die);
                }


            }
        }
        moves++;
    }
    if(found)
    {
        cout<<moves;
    }
    else
    {
        cout<<-1;
    }
    return 0;
}