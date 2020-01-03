uses	math;
const	dir:array[1..4,1..2] of longint=((0,1),(0,-1),(1,0),(-1,0));
	maxn=100;
var	i,j,k,m,n:longint;
	ans:longint;
	flag:array[1..maxn,1..maxn] of boolean;
	map:array[1..maxn,1..maxn] of longint;
procedure dfs(x,y,minn,maxx:longint);
var	i,tx,ty,tmin,tmax:longint;
begin
	flag[x][y]:=true;
	if maxx-minn>=ans then begin
		flag[x][y]:=false;
		exit;
	end;
	if (x=n) and (y=m) then begin
		ans:=maxx-minn;
		flag[x][y]:=false;
		exit;
	end;
	for i:=1 to 4 do begin
		tx:=x+dir[i,1];ty:=y+dir[i,2];
		if (tx<1) or (ty<1) or (tx>n) or (ty>m) then 
			continue;
		tmin:=min(map[tx,ty],minn);
		tmax:=max(map[tx,ty],maxx);
		if not flag[tx][ty] then 
			dfs(tx,ty,tmin,tmax);
	end;
	flag[x][y]:=false;
end;
begin
	//assign(input,'2.in');reset(input);
	readln(n,m);
	for i:=1 to n do 
		for j:=1 to m do
			read(map[i][j]);
	
	ans:=maxlongint>>1;
	dfs(1,1,map[1][1],map[1][1]);
	writeln(ans);
end.
