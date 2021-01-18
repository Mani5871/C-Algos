#include<bits/stdc++.h>
using namespace std;

void dungeon(vector<int>adj[], int sr, int sc, int r, int c)
{
	queue<int> qr, qc;
	qr.push(sr);
	qc.push(sc);

	bool end = false;

	int dr[] = [1, -1, 0, 0];
	int dc[] = [0, 0, 1, -1];

	bool visit[r][c] = {false};

	qr.push(sr);
	qc.push(sc);
	visit[sr][sc] = true;

	while(qr.empty != 0)
	{
		sr = qr.front();
		sc = qc.front();

		qr.pop();
		qc.pop();

		if(adj[sr][sc] == 'E')
		{
			end = true;
			break;
		}

		for(int i = 0; i < 4; i ++)
		{
			int rr = sr + dr[i];
			int cc = sc + dc[i];

			if(rr < 0 || cc < 0)
				continue;
			if(rr > r || cc > c)
				continue;
			if(visit[rr][cc] == true)
				continue;
			qr.push(rr);
			qc.push(cc);

			visit[rr][cc] = true;

			nodes_in_next_layer ++;
			


		}
	}
}