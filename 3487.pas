const	maxn=200000;oo=100000000;
var	i,j,n,size,last,t:longint;
	h:array[1..maxn] of longint;
	a:array[0..maxn,1..2] of longint;
	b:array[0..maxn] of longint;
	ch:char;
	ans:int64;
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
	assign(input,'3487.in');reset(input);
	//assign(output,'.out');rewrite(output);
	readln(n);
	for i:=1 to n do begin
		readln(ch,a[i,2]);
		if ch='c' then a[i,1]:=1 else a[i,1]:=2;
	end;
	
	for i:=1 to n-1 do begin
		if a[i,1]=1 then push(a[i,2])
		else begin
			t:=a[i,2]-1;
			while size>t do pop;
		end;
	end;
	ans:=0;
	for i:=1 to size do inc(ans,h[i]);
	writeln(ans);
	//close(input);close(output);
end.
