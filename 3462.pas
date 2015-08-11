const	maxn=100000;
var	i,j,k,m,n:longint;
	a,c:array[1..maxn] of longint;
	ans:int64;
procedure swap(x,y:longint);
var	mid,i,t:longint;
begin
	mid:=(x+y)>>1;
	j:=y;
	for i:=x to mid do begin
		t:=a[i];
		a[i]:=a[j];
		a[j]:=t;
		dec(j);
	end;
end;
procedure msort(l,r:longint);
var	mid,i,j,k:longint;
begin
	if l=r then exit;
	mid:=(l+r)>>1;
	msort(l,mid);msort(mid+1,r);
	for i:=l to r do c[i]:=a[i];
	i:=l;j:=mid+1;
	for k:=l to r do begin
		if (i<=mid) and ((c[i]<c[j]) or (j>r)) then begin
			a[k]:=c[i];
			inc(i);
		end else begin
			a[k]:=c[j];
			inc(j);
			inc(ans,mid+1-i);//??
		end;
	end;
end;
procedure found;
var	i,j:longint;
begin
	for i:=1 to n-1 do 
		for j:=i+1 to n do 
			if a[i]>a[j] then inc(ans);
end;
begin
	assign(input,'3462.in');reset(input);

	ans:=0;
	readln(n);
	for i:=1 to n do read(a[i]);
	j:=1;
	for i:=1 to n-1 do begin
		if a[i]<a[i+1] then begin
			if (i-j+1)>=2 then begin 
				swap(j,i);
				inc(ans);
			end;
			j:=i+1;
		end;
	end;
	if (n-j+1)>=2 then begin
		swap(j,n);
		inc(ans);
	end;
	msort(1,n);
	writeln(ans);
end.
