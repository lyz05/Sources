var
procedure add(x,y:longint);
begin
	inc(tot);
	v[tot]:=y;
	next[tot]:=g[x];
	g[x]:=tot;
end;
function min(x,y:longint):longint;
begin
	if x<y then exit(x) else exit(y);
end;
function max(x,y:longint):longint;
begin
	if x>y then exit(x) else exit(y);
end;
procedure dfs(x,y:longint);
var i:longint;
begin
	i:=g[x];
	while i<>0 do begin
		if v[i]=y then begin
			i:=next[i];
			continue;
		end;
		deep[v[i]]:=deep[x]+1;
		fa[v[i],0]:=x;
		ma[v[i],0]:=max(a[v[i]],a[x]);
		mi[v[i],0]:=min(a[v[i]],a[x]);
		dfs(v[i],x);
		i:=next[i];
	end;
end;
begin
	readln(n);
	for i:=1 to n do readln(a[i]);
	for i:=1 to n-1 do begin
		readln(x,y);
		add(x,y);
		add(y,x);
	end;
	deep[1]:=1;
	dfs(1,0);
	lo:=ln(n-1)/ln(2);
	for j:=1 to lo do begin
		for i:=1 to n do begin
			fa[i,j]:=fa[fa[i,j-1],j-1];
			ma[i,j]:=max(ma[i,j-1],ma[fa[i,j-1],j-1]);
			mi[i,j]:=min(mi[i,j-1],mi[fa[i,j-1],j-1]);	
		end;
	end;
	readln(q);
	for q:=1 to q do begin
		readln(x,y);
		writeln(lca(x,y));
	end;
end.
