const	maxm=10;
		maxa=500000;
type		arr=array[0..maxm] of longint;
		arr1=array[0..maxa] of longint;
var		i,j,k,m,n,len,x,z:longint;
		a:array[1..maxm,0..maxa] of longint;
		h,la:array[0..maxa] of longint;
		h1:array[0..maxa,0..maxm] of longint;
                y:arr;
procedure swap(var x,y:longint);
var t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure swap1(var x,y:arr);
var t:arr;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure qsort(var a1:arr1;l,r:longint);
var t,m,i,j:longint;
begin
 m:=a1[(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while a1[i]<m do inc(i);
  while a1[j]>m do dec(j);
  if i<=j then begin
   t:=a1[i];
   a1[i]:=a1[j];
   a1[j]:=t;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
procedure ss(x,y:longint);
begin
	swap(h[x],h[y]);
	swap(la[x],la[y]);
	swap1(h1[x],h1[y]);
end;
procedure up(x:longint);
begin
	while x>1 do begin
		if h[x]<h[x shr 1] then ss(x,x shr 1);
		x:=x shr 1;
	end;
end;
procedure down(x:longint);
var y:longint;
begin
	while (2*x<=len) and (h[2*x]<h[x]) or (2*x+1<=len) and (h[2*x+1]<h[x]) do begin
		y:=2*x;
		if (y+1<=len) and (h[y]>h[y+1]) then inc(y);
		ss(x,y);
		x:=y;
	end;
end;
{procedure build;
var i:longint;
begin
	len:=0;
	for i:=1 to n do h[i,1]:=a[i]*b[p[i]];
	len:=n;
	for i:=n shr 1 downto 2 do down(i);
end;}
begin
	fillchar(h,sizeof(h),$7f);
	readln(m,k);
	for i:=1 to m do begin
		read(a[i,0]);
		for j:=1 to a[i,0] do read(a[i,j]);
		qsort(a[i],1,a[i,0]);
	end;

	h[1]:=0;
	for i:=1 to m do begin
		h[1]:=h[1]+a[i,1];
		h1[1,i]:=1;
		la[1]:=1;
	end;

	len:=1;
	for i:=2 to k do begin
		x:=h[1];
		y:=h1[1];
		z:=la[1];
		h[1]:=maxlongint;
		down(1);
		for j:=z to m do
			if y[j]<a[j,0] then begin
				inc(len);
				h[len]:=x+(a[j,y[j]+1]-a[j,y[j]]);
				h1[len]:=y;
				inc(h1[len,j]);
				la[len]:=j;
				up(len);
			end;

	end;
	writeln(h[1]);
	{build;
	for i:=1 to n-1 do begin
		inc(p[h[1,2]]);
		h[1,1]:=a[h[1,2]]*b[p[h[1,2]]];
		down(1);
	end;
     writeln(h[1,1]);
	}
end.
