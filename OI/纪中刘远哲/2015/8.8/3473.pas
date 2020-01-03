const	maxn=100;maxm=11;
var	i,j,m,n,tot:longint;
	st:array[0..(1 shl maxm),0..1] of longint;
	dp:array[0..maxn,0..(1 shl maxm)] of longint;
procedure dfs(n,from,next:longint);
begin
	if (n>m) then begin
		exit;
	end;
	if (n=m) then begin
		st[tot][0]:=from;
		st[tot][1]:=next;
		inc(tot);
		exit;
	end;
	dfs(n+2,(from<<2)+3,(next<<2)+3);
	dfs(n+1,(from<<1)+1,(next<<1));
	dfs(n+1,(from<<1),(next<<1)+1);
end;
begin
	readln(n,m);
	if odd(n*m) then begin
		writeln(0);
		exit;
	end;
	
	tot:=0;
	dfs(0,0,0);
	dp[0][(1<<m)-1]:=1;
	for i:=1 to n do 
		for j:=0 to tot do begin
			inc(dp[i][st[j][1]],dp[i-1][st[j][0]]);
		end;
	writeln(dp[n][(1<<m)-1]);
end.
