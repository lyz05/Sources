uses	math;
const	maxn=200000;oo=100000000;
var	i,j,k,m,n,size,tot,ans:longint;
	a:array[1..maxn] of char;
	b,c:array[1..maxn] of longint;
	h:array[1..maxn] of longint;
procedure swap(var x,y:longint);
var	t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure down(x:longint);
var	y:longint;
begin
	y:=2*x;
	while ((y<=size) and (h[x]>h[y])) or ((y+1<=size) and (h[x]>h[y+1])) do
	begin
		if (y+1<=size) and (h[y+1]<h[y]) then inc(y);
		swap(h[x],h[y]);
		x:=y;
		y:=2*x;
	end;
end;
procedure up(x:longint);
begin
	while (x>1) and (h[x]<h[x>>1]) do begin
		swap(h[x],h[x>>1]);
		x:=x>>1;
	end;
end;
procedure pop;
begin
	h[1]:=h[size];
	h[size]:=oo;
	dec(size);
	down(1);
end;
procedure push(x:longint);
var	i:longint;
begin
	inc(size);
	h[size]:=x;
	up(size);
end;
begin
	assign(input,'3940.in');reset(input);

	readln(n);
	for i:=1 to n-1 do readln(a[i],b[i]);
	c[n-1]:=oo;
	for i:=n-2 downto 1 do begin
		c[i]:=c[i+1];
		if a[i]='p' then c[i]:=min(c[i],b[i]-1);
	end;
        fillchar(h,sizeof(h),127);
	for i:=1 to n-1 do begin
		if a[i]='d' then push(b[i]);
		while size>c[i] do pop;
	end;
	while size<>0 do begin
		inc(tot);
		ans:=ans+h[1];
		pop;
	end;
	if tot>=b[n-1] then writeln(ans) else writeln(-1);
end.
