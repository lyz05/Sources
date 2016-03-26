var i,j,k,m,n,tot:longint;
    x,y,xx,yy:array[0..4000] of longint;
    ans,x3,y3:int64;
procedure qsort(l,r:longint);
var mx,my,i,j:longint;
begin
 mx:=xx[(l+r) div 2];
 my:=yy[(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while mx*yy[i]>my*xx[i] do inc(i);
  while mx*yy[j]<my*xx[j] do dec(j);
  if i<=j then begin
   xx[0]:=xx[i];
   xx[i]:=xx[j];
   xx[j]:=xx[0];
   yy[0]:=yy[i];
   yy[i]:=yy[j];
   yy[j]:=yy[0];
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(l,j);
 if i<r then qsort(i,r);
end;
begin
	readln(n);
	for i:=1 to n do readln(x[i],y[i]);

	for i:=1 to n do begin
		tot:=0;
		for j:=1 to n do
			if (i<>j) and ((y[i]<y[j]) or ((y[i]=y[j]) and (x[j]>x[i]))) then begin
				inc(tot);
				xx[tot]:=x[j]-x[i];
				yy[tot]:=y[j]-y[i];
			end;
		if tot<2 then continue;
		qsort(1,tot);
		x3:=0;
		y3:=0;
		for j:=1 to tot do begin
			ans:=ans+y3*xx[j]-x3*yy[j];
			y3:=y3+yy[j];
			x3:=x3+xx[j];
		end;
	end;
	writeln(ans/2:0:1);
end.
