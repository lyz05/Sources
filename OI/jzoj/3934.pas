const	maxn=10000;maxm=200000;
type	node=record
		y,next:longint;
	end;
var	i,j,k,m,n,t,s,x,y,tot:longint;
	b,p:array[1..maxn] of boolean;
	d,a,e:array[1..maxn] of longint;
	h:array[1..maxm] of node;
procedure add(x,y:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].next:=e[x];
	e[x]:=tot;
end;
procedure bfs(x,la:longint);
var	i,j,l,r:longint;
begin
	l:=0;
	r:=1;
	a[1]:=x;
	fillchar(p,sizeof(p),false);
	p[x]:=true;
	fillchar(d,sizeof(d),127);
	d[x]:=0;
	while l<r do begin
		inc(l);
		x:=a[l];
		i:=e[x];
		while i<>0 do begin
			j:=h[i].y;
			if (not p[j]) and b[j] then begin
				p[j]:=true;
				inc(r);
				d[j]:=d[x]+1;
				if j=la then exit;
				a[r]:=j;
			end;
			i:=h[i].next;
		end;
	end;
end;
procedure del;
var	i,x,j:longint;
begin
	for x:=1 to n do 
		if not p[x] then begin
			i:=e[x];
			while i<>0 do begin
				j:=h[i].y;
				b[j]:=false;
				i:=h[i].next;
			end;
		end;
end;
begin
	readln(n,m);
	for i:=1 to m do begin
		readln(x,y);
		add(y,x);
	end;
	readln(s,t);
	fillchar(b,sizeof(b),true);
	bfs(t,0);
	del;
	bfs(t,s);
	if p[s] then writeln(d[s]) else writeln(-1);
end.
