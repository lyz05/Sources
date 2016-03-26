const maxn=50000;
type sz=array[1..maxn] of string
var 	i,j,k,m,n:longint;
	a,b:sz;
	s1,s2:string;
procedure swap(var x,y:string);
var t:string;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure qsort(var a1:sz;l,r:longint);
var m,i,j:longint;
begin
 m:=a1[(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while (a1[i]<m) do inc(i);
  while (a1[j]>m) do dec(j);
  if i<=j then begin
   swap(a1[i],a1[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
procedure search(var arr:sz;x:string;l,r:longint);
var mid,i:longint;
begin
	while l<r do begin
		mid:=(l+r) shr 1;
		if arr[mid]
	end;
end;
begin
	readln(n,q);
	for i:=1 to n do begin
		readln(a[i]);
		for j:=1 to length(a[i]) do b[i]:=a[i,j]+b[i];
	end;
	qsort(a,1,n);
	qsort(b,1,n);
	for i:=1 to q do begin
		readln(s1);
		readln(s2);
		search(a,s1,1,n);
	end;
end.
