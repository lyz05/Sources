const	maxn=1000;maxm=maxn;maxk=10;
var	i,j,k,n,m,ans:longint;
	map:array[1..maxn,1..maxm] of longint;
	pp:array[1..maxn,1..maxm] of boolean;
	p:array[1..maxk] of longint;
	flag:boolean;
procedure dfs1(x,y:longint);
var	i:longint;
begin
	if (x>n) or (y>m) then exit;
	//if (x=n) and (y=m) then exit;
	for i:=0 to 1 do begin
		if p[map[x,y]]=0 then inc(p[map[x,y]]) else begin
			flag:=false;
			exit;
		end;
		if odd(i) then dfs1(x,y+1) else dfs1(x+1,y);
		dec(p[map[x,y]]);
		if not flag then exit;
	end;
end;
procedure dfs(x,y:longint);
var	i:longint;
begin
	if y=m+1 then begin
		inc(x);
		y:=1;
	end;
	if x=n+1 then begin
		flag:=true;
		dfs1(1,1);
		if flag then begin
			inc(ans);
		end;
		exit;
	end;
	if pp[x,y] then dfs(x,y+1) else begin
		for i:=1 to k do begin
			map[x,y]:=i;
			dfs(x,y+1);
			map[x,y]:=0;
		end;
	end;
end;
begin
	assign(input,'3.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m,k);
	for i:=1 to n do 
		for j:=1 to m do begin
			read(map[i,j]);
			if map[i,j]<>0 then pp[i,j]:=true;
		end;
	dfs(1,1);
	writeln(ans);
end.
