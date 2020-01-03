uses	math;
const	maxn=1000;
var	i,n,ans:longint;
	f,e,w,num,inf:array[0..maxn] of longint;
procedure swap(var x,y:longint);
var	t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure qsort(l,r:longint);
var	i,j,m:longint;
begin
	i:=l;
	j:=r;
	m:=e[(l+r) div 2];
	repeat
		while e[i]<m do inc(i);
		while e[j]>m do dec(j);
		if i<=j then begin
			swap(e[i],e[j]);
			swap(f[i],f[j]);
			swap(w[i],w[j]);
			swap(num[i],num[j]);	
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;
procedure work(x:longint);
var	i,minn:longint;
begin
	i:=x;
	minn:=maxlongint>>1;
	while i<>0 do begin
		minn:=min(minn,w[i]);
		i:=inf[f[i]];
	end;
	if minn<e[x] then exit;
	inc(ans);
	i:=x;
	while i<>0 do begin
		dec(w[i],e[x]);
		i:=inf[f[i]];
	end;
end;
begin
	assign(input,'1.in');reset(input);
	readln(n);
	for i:=1 to n do begin
		readln(f[i],e[i],w[i]);
		num[i]:=i;
	end;
	qsort(1,n);

	for i:=1 to n do inf[num[i]]:=i;
	ans:=0;
	for i:=1 to n do work(i);
	writeln(ans);
end.
