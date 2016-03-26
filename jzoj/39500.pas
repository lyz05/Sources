type	sz=array[0..30] of longint;
var	m,n,p:longint;
	a,b,c:sz;
	ans:int64;
procedure swap(var x,y:longint);
var t:longint;
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
  while a1[i]>m do inc(i);
  while a1[j]<m do dec(j);
  if i<=j then begin
   swap(a1[i],a1[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
procedure next;
var	i:longint;
	flag:boolean;
	v:int64;
begin
	for i:=1 to (n div 2) do a[n-i+1]:=-a[i];
	for i:=n downto 1 do 
		if a[i]<0 then begin
			inc(a[i],10);
			dec(a[i-1]);
		end;	
	b:=a;
	qsort(b,1,n);
	for i:=1 to n do c[i]:=b[n-i+1];
	flag:=true;
	for i:=n downto 1 do begin
		b[i]:=b[i]-c[i];
		if b[i]<0 then begin
			inc(b[i],10);
			dec(b[i-1]);
		end;
		if b[i]<>a[i] then begin
			flag:=false;
			break;
		end;
	end;
	if flag then begin
		v:=0;
		for i:=1 to n do v:=(v*10+a[i]) mod p;
		ans:=(ans+(v*v) mod p) mod p;
	end;
end;
procedure dfs(dep,pre:longint);
var	i:longint;
begin
	if (dep>(n+1) div 2) then begin
		next;
		exit;
	end;
	for i:=pre downto 0 do begin
		a[dep]:=i;
		dfs(dep+1,i);
		a[dep]:=0;
	end;
end;
begin
	ans:=0;
	readln(n,p);
	dfs(1,9);
	writeln(ans);
end.
