const	maxn=10000;maxm=100000;
type	node=record
		y,next:longint;
	end;
var	i,j,k,m,n,tot,x,y,q,ans:longint;
	a:array[1..maxn] of longint;
	p:array[0..maxn] of longint;
	h:array[1..2*maxm] of node;
	e:array[1..maxn] of longint;
	v:array[1..maxn] of boolean;
procedure add(x,y:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].next:=e[x];
	e[x]:=tot;
end;
procedure work(len:longint);
var	i:longint;
begin
	for i:=1 to len do begin
		inc(a[p[i]]);
	end;
end;
procedure dfs(deep,x,y:longint);
var	i:longint;
begin
	if deep>n then exit;
	if x=y then begin
		work(deep-1);
		inc(tot);
		exit;
	end;
	i:=e[x];
	while i<>0 do begin
		if v[h[i].y] then begin
			i:=h[i].next;
			continue;
		end;
		v[h[i].y]:=true;
		inc(p[0]);
		p[p[0]]:=h[i].y;
		dfs(deep+1,h[i].y,y);
		p[p[0]]:=0;
		dec(p[0]);
		v[h[i].y]:=false;
		i:=h[i].next;
	end;
end;
begin
	assign(input,'2.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	for i:=1 to m do begin
		readln(x,y);
		add(x,y);
		add(y,x);
	end;
	readln(q);
	for i:=1 to q do begin
		tot:=0;ans:=0;
                fillchar(a,sizeof(a),0);
		readln(x,y);
		v[x]:=true;
		dfs(1,x,y);
                v[x]:=false;
		for j:=1 to n do
			if a[j]=tot then inc(ans);
                dec(ans);
                writeln(ans);
	end;
end.
