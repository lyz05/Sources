const	maxn=100000+2;maxm=500000+2;
type	node=record
		y,next:longint;
	end;
var	i,j,k,m,n,x,y,maxy,tot,tmp,ans:longint;
	e,v,p:array[1..maxn] of longint;
	h:array[1..maxm] of node;
procedure add(x,y:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].next:=e[x];
	e[x]:=tot;
end;
procedure dfs(dep:longint);
var	i,bak:longint;
	flag:boolean;
begin
	flag:=true;
	if dep>n then begin
		if tmp>ans then ans:=tmp;
		exit;
	end;
	i:=e[dep];
	while i<>0 do begin
		if h[i].y<=maxy then begin
			i:=h[i].next;
			continue;
		end;
		inc(tmp,v[dep]);inc(tmp,p[h[i].y]);
		bak:=maxy;maxy:=h[i].y;
		dfs(dep+1);
		maxy:=bak;
		dec(tmp,v[dep]);dec(tmp,p[h[i].y]);
		i:=h[i].next;
	end;
	if flag then begin
		flag:=false;
		dfs(dep+1);
	end;
end;
begin
	assign(input,'watchdogs.in');reset(input);
	assign(output,'watchdogs.out');rewrite(output);

	readln(n,m);
	for i:=1 to m do begin
		readln(x,y);
		add(x,y);
	end;
	for i:=1 to n do read(p[i]);
	for i:=1 to n do read(v[i]);

	dfs(1);
	writeln(ans);

	close(input);close(output);
end.
