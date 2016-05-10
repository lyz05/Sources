const 	maxn=60000;maxt=10000;
var 	i,j,k,m,n,ti:longint;
	t,w:array[1..maxn] of longint;
	f:array[-1..maxt] of longint;
        p:array[1..maxn] of boolean;
procedure swap(var x,y:longint);
var t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure qsort(l,r:longint);
var m,i,j:longint;
begin
 m:=t[(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while t[i]>m do inc(i);
  while t[j]<m do dec(j);
  if i<=j then begin
	swap(t[i],t[j]);
	swap(w[i],w[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
begin
	//assign(input,'shooter.in');reset(input);
	//assign(output,'shooter.out');rewrite(output);

	readln(n);
	for i:=1 to n do begin
		readln(t[i],w[i]);
		if t[i]>ti then ti:=t[i];
	end;

	qsort(1,n);
	for i:=1 to n do begin
		
	end;
	writeln(ans);
	//close(input);close(output);
end.
