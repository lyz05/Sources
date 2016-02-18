uses	math;
const	maxn=50002;
type	node=record
		y,next:longint;
	end;
var	i,j,k,m,n,tot,x,y,ans:longint;
	v,e,dep,fa:array[1..maxn] of longint;
	h:array[1..2*maxn] of node;
	a,a1,a2,b,c:array[0..maxn] of longint;
	flag:array[1..maxn] of boolean;
procedure add(x,y:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].next:=e[x];
	e[x]:=tot;
end;
procedure dfs(x:longint);
var	i:longint;
begin
	if flag[x] then exit;
	flag[x]:=true;
	i:=e[x];
	while i<>0 do begin
		if flag[h[i].y] then begin
			i:=h[i].next;
			continue;
		end;
		dep[h[i].y]:=dep[x]+1;
		fa[h[i].y]:=x;
		dfs(h[i].y);
		i:=h[i].next;
	end;
end;
procedure up(var x:longint;y:longint);
begin
	if odd(y) then begin
		inc(a1[0]);
		a1[a1[0]]:=x;
	end else begin
		inc(a2[0]);
		a2[a2[0]]:=x;
	end;
	x:=fa[x];
end;
procedure link;
var	i:longint;
begin
	for i:=1 to a1[0] do a[i]:=a1[i];
	a[0]:=a1[0];
	for i:=a2[0] downto 1 do begin
		inc(a[0]);
		a[a[0]]:=a2[i];
	end;
end;
procedure work(x,y:longint);
var	i:longint;
begin
	a1[0]:=0;a2[0]:=0;ans:=0;
	while dep[x]>dep[y] do up(x,1);
	while dep[x]<dep[y] do up(y,2);
	while x<>y do begin
		up(x,1);up(y,2);
	end;
	inc(a1[0]);
	a1[a1[0]]:=x;
	link;
	b[0]:=1000000007;c[a[0]+1]:=0;
	for i:=1 to a[0] do b[i]:=min(b[i-1],v[a[i]]);
	for i:=a[0] downto 1 do c[i]:=max(c[i+1],v[a[i]]);
	for i:=1 to a[0] do ans:=max(ans,c[i]-b[i]);
	{
	for i:=1 to a[0] do begin
		for j:=i+1 to a[0] do begin
			ans:=max(ans,v[a[j]]-v[a[i]]);
		end;
	end;
	}
end;
begin
	//assign(input,'1230.in');reset(input);
	//assign(output,'1230.out');rewrite(output);

	readln(m,n,T);
	for i:=1 to m do read(v[i]);
	for i:=1 to n-1 do begin
		readln(x,y);
		add(x,y);add(y,x);
		flag[x]:=true;flag[y]:=true;
	end;
	dep[1]:=1;fa[1]:=0;
	dfs(1);
	for i:=1 to T do begin
		readln(cas,x,y);
		if cas=0 then begin
			work(x,y);  
			writeln(ans);
		end else begin
			
		end;
	end;
end.
