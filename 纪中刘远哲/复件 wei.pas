const 	maxn=500000;
type 	node=record
		x:longint;
		next:node;
	end;
	nod^=node;
var 	i,j,k,m,n:longint;
	a:array[0..maxn,1..3] of longint;
	p:array[1..maxn] of boolean;
	b,xl:array[0..maxn,1..50] of longint;
	//b:array[1..maxn] of nod;
procedure qsort(l,r:longint);
var i,j,m:longint;
begin
	i:=l;
	j;=r;
	m:=a[(l+r) div 2];
	repeat
		while a[i]<m do inc(i);
		while a[j]>m do dec(j);
		if i<=j then begin
			a[0]:=a[i];
			a[i]:=a[j];
			a[j]:=a[0];
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;
procedure fz(x,y,z:longint);
var i:longint;
begin
	for i:=b[x] to b[x+1]-1 do 
		if a[i,2]=y then a[i,3]:=z;
end;
procedure cut;
var i:longint;
begin
	for i:=1 to xl[maxt,0]-1 do begin
		fz(xl[maxt,i],xl[maxt,i+1],0);
		fz(xl[maxt,i+1],xl[maxt,i],0);
	end;
end;
procedure dfs(deep,x:longint);
var i,j:longint;
begin
	if deep>n then begin
		inc(tot);
		xl[0]:=xl[tot]];
		if tmp>max then begin
			max:=tmp;
			maxt:=tot;
		end;
		exit;
	end;
	for i:=b[x] to b[x+1]-1 do begin
		if not p[a[i,2]] then begin
			p[a[i,2]]:=true;
			inc(xl[0,0]);
			xl[xl[0,0],0]:=a[i,2];
				dfs(deep+1,a[i,2]);
			xl[xl[0,0],0]:=0;
			dec(xl[0,0]);
			p[a[i,2]]:=false;
		end;
	end;
end;
begin
	readln(n);
	for i:=1 to n-1 do begin
		readln(a[i,1],a[i,2],a[i,3]);
		a[i+n-1,1]:=a[i,2];
		a[i+n-1,2]:=a[i,1];
		a[i+n-1,3]:=a[i,3];
	end;
	qsort(1,n);
	k:=0;j:=0;
	for i:=1 to 2*n-2 do 
		if a[i,1]<>k then begin
			k:=a[i,1];
			j:=i;
			b[k]:=i-j;
		end;
	b[n]:=2*n-2+1;
	xl[0]:=1;xl[1]:=1;
	dfs(1,1);
	cut;
	for i:=1 to tot do begin
		
	end;
end.
