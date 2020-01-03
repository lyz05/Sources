const	maxm=15+2;
var	i,j,n,m,ans,r,c:longint;
	lie:array[1..maxm] of longint;
	ch:char;
procedure dfs(x,y,z:longint);
var	i:longint;
begin
	if (x=n+1) then begin
		i:=1;
		while i<=m do begin
			if lie[i] and y=0 then inc(i)
			else begin
				inc(i,c);
				inc(z);
			end;
		end;
		if z<ans then ans:=z;
	end else begin
		dfs(x+1,y,z);
		if x>=n-r+2 then dfs(x+1,(1<<n-1-((1<<(n-x+1)-1) << (x-1)))and y,z+1)
		else dfs(x+1,(1<<n-1-((1<<r-1) << (x-1)))and y,z+1);
	end;
end;
begin
	assign(input,'3503.in');reset(input);
	
	readln(n,m);
	for i:=1 to n do begin
		for j:=1 to m do begin
			read(ch);
			if ch='X' then lie[j]:=lie[j] or (1 << (i-1));
		end;
		readln;
	end;
	readln(r,c);
	
	ans:=maxlongint;
	dfs(1,1<<n-1,0);
	writeln(ans);
end.
