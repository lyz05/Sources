type    sz=array[1..100000,1..2] of longint;
        sz1=array[1..2] of longint;
var	n,m,l,r,max,i,j,k:longint;
	a:sz;
procedure swap(var x,y:sz1);
var t:sz1;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure qsort(var a1:sz;l,r:longint);
var m,i,j:longint;
begin
 m:=a1[(l+r) div 2,2];
 i:=l;
 j:=r;
 repeat
  while a1[i,2]>m do inc(i);
  while a1[j,2]<m do dec(j);
  if i<=j then begin
   swap(a1[i],a1[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
begin
	readln(n,m);
	for i:=1 to n do begin
		read(a[i,2]);
		a[i,1]:=i;
	end;
	
	qsort(a,1,n);
	for i:=1 to m do begin
		readln(l,r);
		for j:=1 to n do
			if (a[j,1]<=r) and (a[j,1]>=l) then break;
		writeln(a[j,2]);
	end;
end.
