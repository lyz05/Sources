type    sz=array[1..250000,1..3] of longint;
        sz1=array[1..3] of longint;
var	n,m,l,r,max,i,j,k,x1,y1,x2,y2:longint;
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
 m:=a1[(l+r) div 2,1];
 i:=l;
 j:=r;
 repeat
  while a1[i,1]>m do inc(i);
  while a1[j,1]<m do dec(j);
  if i<=j then begin
   swap(a1[i],a1[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
begin
	//assign(input,'1954.in');assign(output,'1954.out');
	//reset(input);rewrite(output);

	readln(n,m);
	for i:=1 to n do begin
		for j:=1 to n do begin
			k:=(i-1)*n+j;
			read(a[k,1]);
			a[k,2]:=i;
			a[k,3]:=j;
                end;
	end;

	qsort(a,1,n*n);
	for i:=1 to m do begin
		readln(x1,y1,x2,y2);
		for j:=1 to n*n do
			if (a[j,2]<=x2) and (a[j,2]>=x1) and (a[j,3]<=y2) and (a[j,3]>=y1) then break;
		writeln(a[j,1]);
	end;

	//close(input);close(output);
end.
