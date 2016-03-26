type sz=array[1..1000000,1..4] of longint;
     sz1=array[1..4] of longint;
var m,n,i,j,k,min,max,z:longint;
    a:sz;
    b:array[1..1000000] of longint;
procedure swap(var x,y:sz1);
var z:sz1;
begin
  z:=x;
  x:=y;
  y:=z;
end;
procedure qsort(var a1:sz;l,r:longint);
var m,i,j:longint;
begin
 m:=a1[(l+r) div 2,2];
 i:=l;
 j:=r;
 repeat
  while a1[i,2]<m do inc(i);
  while a1[j,2]>m do dec(j);
  if i<=j then begin
   swap(a1[i],a1[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
procedure dfs(k:longint);
var i:longint;
begin
	for i:=1 to n do
         if a[k,3]=0 then
          if a[k,1]=a[i,2] then begin
			b[z]:=a[k,1];
                        a[k,3]:=1;
			if b[z]=b[1] then break;
			inc(z);
			dfs(i);
		end else
		     if a[k,1]>a[i,2] then break;
end;
begin
	readln(n);
	for i:=1 to n do begin
		read(a[i,2]);
		a[i,1]:=i;
	end;
	qsort(a,1,n);
	for i:=1 to n do begin
		fillchar(b,sizeof(b),0);
		z:=2;
		b[1]:=a[i,2];
		dfs(i);

	end;
	writeln(min,' ',max);
end.
