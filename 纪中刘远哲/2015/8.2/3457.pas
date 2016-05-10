const	maxn=4+1;maxm=20+1;
var	i,j,k,m,n,r,c,ans:longint;
	ch:char;
	map,p:array[1..maxm,1..maxn] of boolean;
	dir:array[1..4,1..2] of longint;
function dfs(x,y,limit:longint):boolean;
var	i,tx,ty:longint;
begin
	if limit<0 then exit(false);
	if y>n then begin
		inc(x);y:=1;
	end;
	if x>m then 
		exit(true);
	
	if map[x,y] then begin
		map[x,y]:=false;
		for i:=0 to 4 do begin
			if i=0 then begin
				if dfs(x,y+1,limit-1) then exit(true);
			end else begin
				tx:=x+dir[i,1];ty:=y+dir[i,2];
				if (tx>0) and (ty>0) and (tx<=m) and (ty<=n)
			       	and map[tx,ty] then begin
					map[tx,ty]:=false;
					p[tx,ty]:=true;
						if dfs(x,y+1,limit-1) then exit(true);
					p[tx,ty]:=false;
					map[tx,ty]:=true;
				end;
			end;
		end;
		map[x,y]:=true;
	end else begin
		if p[x,y] then begin
			p[x,y]:=false;
			for i:=0 to 4 do begin
				if i=0 then begin
					if dfs(x,y+1,limit) then exit(true);
				end else begin
					tx:=x+dir[i,1];ty:=y+dir[i,2];
					if (tx>0) and (ty>0) and (tx<=m) and (ty<=n)
				       	and map[tx,ty] then begin
						map[tx,ty]:=false;
						p[tx,ty]:=true;
							if dfs(x,y+1,limit) then exit(true);
						p[tx,ty]:=false;
						map[tx,ty]:=true;
					end;
				end;
			end;
			p[x,y]:=true;
		end else begin
			if dfs(x,y+1,limit) then exit(true);
		end;
	end;
	exit(false);
end;
begin
	assign(input,'3457.in');reset(input);	

	readln(m,n,r,c);
	dir[1,1]:=r;dir[2,1]:=r;dir[1,2]:=c;dir[2,2]:=-c;
	dir[3,1]:=c;dir[4,1]:=c;dir[3,2]:=r;dir[4,2]:=-r;
	for i:=1 to m do begin 
		for j:=1 to n do begin
			read(ch);
			if ch='.' then map[i,j]:=true else map[i,j]:=false;
		end;
		readln;
	end;
	for ans:=1 to m*n do begin
		if dfs(1,1,ans) then break;
	end;
	writeln(ans);
end.
