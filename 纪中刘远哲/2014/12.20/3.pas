const	maxm=100000;maxn=50000;
type	arr=array[0..maxm,1..2] of longint;
var	i,j,m,n,totn,ans:longint;
	a:arr;
	h:array[1..maxn] of longint;
	p:array[1..maxn] of longint;
procedure qsort(var a1:arr;l,r:longint);
var m,i,j:longint;
begin
	m:=a1[(l+r) div 2,1];
	i:=l;j:=r;
	repeat
		while a1[i,1]<m do inc(i);
		while a1[j,1]>m do dec(j);
		if i<=j then begin
			a1[0]:=a1[i];
			a1[i]:=a1[j];
			a1[j]:=a1[0];
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(a1,l,j);
	if i<r then qsort(a1,i,r);
end;
procedure prepar;
var	i:longint;
begin
	for i:=1 to n do begin
		h[i]:=i;
		p[i]:=1;
	end;
	ans:=(n*(n-1))>>1;
end;
function getfather(x:longint):longint;
begin
	if h[x]<>x then begin
		h[x]:=getfather(h[x]);
		exit(h[x]);
	end else exit(x);
end;
procedure add(x,y:longint);
var	i,j:longint;
begin
	i:=getfather(x);
	j:=getfather(y);
	h[i]:=h[j];
	if i=j then exit;
	inc(p[j],p[i]);
	p[i]:=0;
end;
begin
	assign(input,'3.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	for i:=1 to m do begin
		readln(a[i,1],a[i,2]);
		//if a[i,1]>a[i,2] then swap(a[i,1],b[i,2]);
	end;
	//qsort(a,1,m);
	for i:=1 to n do begin
		prepar;
		for j:=1 to m do begin
			if (a[j,1]=i) or (a[j,2]=i) then continue;
			add(a[j,1],a[j,2]);
		end;
		for j:=1 to n do begin
			if j=i then continue;
			if p[j]<>0 then dec(ans,(p[j]*(p[j]-1))>>1);
		end;
		writeln(ans);
	end;
end.
