uses	math;
const	maxk=100000;
var	i,j,k,m,n,t:longint;
	a:array[0..maxk,1..3] of longint;
	b:array[0..maxk,1..2] of longint;
	h:array[0..262144] of longint;
procedure qsort1(l,r:longint);
var	m1,m2,i,j:longint;
begin
 m1:=a[(l+r)>>1,1];
 m2:=a[(l+r)>>1,2];
 i:=l;
 j:=r;
 repeat
  while (a[i,1]<m1) or ((a[i,1]=m1) and (a[i,2]<m2)) do inc(i);
  while (a[j,1]>m1) or ((a[j,1]=m1) and (a[j,2]>m2)) do dec(j);
  if i<=j then begin
   a[0]:=a[i];
   a[i]:=a[j];
   a[j]:=a[0];
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort1(l,j);
 if i<r then qsort1(i,r);
end;
procedure qsort2(l,r:longint);
var	m,i,j:longint;
begin
 m:=b[(l+r)>>1,1];
 i:=l;
 j:=r;
 repeat
  while (b[i,1]<m) do inc(i);
  while (b[j,1]>m) do dec(j);
  if i<=j then begin
   b[0]:=b[i];
   b[i]:=b[j];
   b[j]:=b[0];
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort2(l,j);
 if i<r then qsort2(i,r);
end;
function query(x,l,r,a,b:longint):longint;
var	mid:longint;
begin
	if (l=a) and (r=b) then begin
		exit(h[x]);
	end;
	mid:=(l+r)>>1;
	if mid<a then exit(query(x*2+1,mid+1,r,a,b));
	if b<=mid then exit(query(x*2,l,mid,a,b));
	exit(max(query(x*2,l,mid,a,mid),query(x*2+1,mid+1,r,mid+1,b)));
end;
procedure change(x,l,r,a,b:longint);
var	mid:longint;
begin
	if l=r then begin
		h[x]:=b;
		exit;
	end;
	mid:=(l+r)>>1;
	if a<=mid then change(x*2,l,mid,a,b) else change(x*2+1,mid+1,r,a,b);
	h[x]:=max(h[x*2],h[x*2+1]);
end;
begin
	//assign(input,'3947.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m,k);
	for i:=1 to k do begin
		readln(a[i,1],a[i,2],a[i,3]);
	end;
	qsort1(1,k);
	for i:=1 to k do begin
		b[i,1]:=a[i,2];
		b[i,2]:=i;
	end;
	qsort2(1,k);
	j:=0;
	b[0,1]:=-1;
	for i:=1 to k do begin
		if b[i,1]<>b[i-1,1] then inc(j);
		a[b[i,2],2]:=j;
	end;
	for i:=1 to k do begin
		t:=query(1,1,k,1,a[i,2])+a[i,3];
		change(1,1,k,a[i,2],t);
	end;
	writeln(query(1,1,k,1,k));
end.
