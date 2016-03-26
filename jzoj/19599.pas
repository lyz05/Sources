type    sz=array[0..100000,1..2] of longint;
        sz1=array[1..2] of longint;
var	n,m,l,r,max,i,j,k,z,x:longint;
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
	readln(n);
	for i:=1 to n do begin
		read(a[i,2]);
		a[i,1]:=i;
	end;

	qsort(a,1,n);
	readln(m);
	for i:=1 to m do begin
		readln(z,l,r);
		if z=2 then begin
			for j:=1 to n do
				if (a[j,1]<=r) and (a[j,1]>=l) then break;
			writeln(a[j,2]);
		end else begin
			j:=1;
			while a[j,1]<>l do inc(j);
                        x:=a[j,2];
                        a[j,2]:=r;
			a[0]:=a[j];
			if x<r then begin
				while a[j-1,2]<r do begin
					a[j]:=a[j-1];
					dec(j);
				end;
				a[j]:=a[0];
			end else begin
				while a[j+1,2]>r do begin
					a[j]:=a[j+1];
					inc(j);
				end;
				a[j]:=a[0];
			end;
		end;
	end;
end.
