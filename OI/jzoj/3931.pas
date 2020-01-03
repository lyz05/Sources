const	maxn=200000+100;maxc=50;mo=10007;
type	node=record
		y:longint;
		next:longint;
	end;
var	n,i,tot,x,y:longint;
	w,g,max,m1,m2,sum,summ:array[1..maxn] of int64;
	h:array[1..2*maxn] of node;
	ans,ansn:int64;
procedure add(x,y:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].next:=g[x];
	g[x]:=tot;
end;
procedure solve(x:longint);
var	i,j:longint;
begin
	i:=g[x];
	while i<>0 do begin
		j:=h[i].y;
		sum[x]:=sum[x]+w[j];
		if w[j]>m1[x] then begin
			m2[x]:=m1[x];
			m1[x]:=w[j];
		end else if w[j]>m2[x] then m2[x]:=w[j];
		i:=h[i].next;
	end;
	i:=g[x];
	max[x]:=m1[x]*m2[x];
	while i<>0 do begin
		j:=h[i].y;
		summ[x]:=summ[x]+(sum[x]-w[j])*w[j];
		i:=h[i].next;
	end;
end;
begin
	readln(n);
	for i:=1 to n-1 do begin
		readln(x,y);
		add(x,y);
		add(y,x);
	end;
	for i:=1 to n do read(w[i]);
	
	for i:=1 to n do solve(i);
	for i:=1 to n do begin
		ans:=(ans+summ[i]) mod mo;
		if max[i]>ansn then ansn:=max[i];
	end;
	writeln(ansn,' ',ans);
end.
