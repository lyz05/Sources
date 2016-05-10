const	maxn=500+5;
var	i,j,k,m,n,cnt,d:longint;
	map,ans,tmp:array[1..maxn,1..maxn] of longint;
	flag:boolean;
procedure dfs(x,y,limit:longint;var h:longint);
begin
	if (x<1) or (y<1) or (x>n) or (y>m)
		or (tmp[x,y]=1) or (map[x,y]<=limit) then exit;
	tmp[x,y]:=1;
	if h>map[x,y] then ans[x,y]:=2;
	if h=map[x,y] then ans[x,y]:=3;
	if h<map[x,y] then flag:=false;

	dfs(x+1,y,limit,h);
	dfs(x-1,y,limit,h);
	dfs(x,y+1,limit,h);
	dfs(x,y-1,limit,h);
end;
procedure work;
var	x,y:longint;
begin
	for x:=1 to n do
		for y:=1 to m do begin
			if ans[x,y]=3 then
				if flag then begin
					ans[x,y]:=1;
					inc(cnt);
				end else ans[x,y]:=2;
		end;
end;
begin
	assign(input,'2.in');reset(input);

	readln(n,m,d);
	for i:=1 to n do
		for j:=1 to m do read(map[i,j]);
	cnt:=0;
	for i:=1 to n do
		for j:=1 to m do begin
			if ans[i,j]=0 then begin
				fillchar(tmp,sizeof(tmp),0);
				flag:=true;
				dfs(i,j,map[i,j]-d,map[i,j]);
				work;
			end;
		end;
	writeln(cnt);
end.
