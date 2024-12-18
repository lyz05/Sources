uses	math;
const	maxn=5000+5;
type	arr=array[0..maxn] of longint;
var	i,j,k,m,n,ans:longint;
	f:array[1.. maxn,0..maxn] of longint;
	a:arr;
procedure qsort(var a1:arr;l,r:longint);
var	m,i,j:longint;
begin
	m:=a1[(l+r) div 2];
	i:=l;j:=r;
	repeat
		while a1[i]>m do inc(i);
		while a1[j]<m do dec(j);
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
begin
	fillchar(f,sizeof(f),127);
	readln(n);
	for i:=1 to n do begin
		read(a[i]);
		//if i=1 then f[i,i]:=a[i] else f[i,i]:=f[i-1,i]+a[i];
	end;
	qsort(a,1,n);
	for i:=1 to n do
		if i=1 then f[i,i]:=a[i] else f[i,i]:=f[i-1,i-1]+a[i];
        //f[1,0]:=a[i];
	for i:=2 to n do begin
		for j:=0 to i do begin
                        if j=0 then f[i,j]:=f[i-1,j+1] else
                        f[i,j]:=min(f[i-1,j+1],f[i-1,j-1]+a[i]);
		end;
	end;
	ans:=maxlongint;
	for j:=0 to n do
		if f[n,j]<ans then ans:=f[n,j];
	writeln(ans);
end.
