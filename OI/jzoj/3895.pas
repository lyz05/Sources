const maxn=500000;
type sz=array[1..maxn] of longint;
var	i,j,k,m,n,l,r,tot:longint;
	a:sz;
	p:array[1..maxn] of boolean;
	ans:array[1..2,1..maxn] of longint;
procedure swap(var x,y:longint);
var t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure qsort(l,r:longint);
var m1,m2,i,j:longint;
begin
 m1:=ans[1,(l+r) div 2];
 m2:=ans[2,(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while (ans[2,i]>m2) or ((ans[2,i]=m2) and (ans[1,i]<m1)) do inc(i);
  while (ans[2,j]<m2) or ((ans[2,j]=m2) and (ans[1,j]>m1)) do dec(j);
  if i<=j then begin
   swap(ans[1,i],ans[1,j]);
   swap(ans[2,i],ans[2,j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(l,j);
 if i<r then qsort(i,r);
end;
begin
	readln(n);
	for i:=1 to n do read(a[i]);

	for i:=1 to n do begin
		if p[i] then continue;
		p[i]:=true;
		l:=i-1;r:=i+1;
		while (l>=1) and (a[l] mod a[i]=0) do begin
                        p[l]:=true;
                        dec(l);
		end;
		while (r<=n) and (a[r] mod a[i]=0) do begin
                        p[r]:=true;
			inc(r);
		end;
		inc(tot);
		ans[1,tot]:=l+1;
		ans[2,tot]:=(r-1)-(l+1);
	end;

	qsort(1,tot);
	i:=2;
	while (ans[2,i]=ans[2,i-1]) and (i<=n) do inc(i);
	dec(i);
	writeln(i,' ',ans[2,1]);
	for j:=1 to i do write(ans[1,j],' ');
	writeln;
end.
