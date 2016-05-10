const	maxn=100000;
var	i,j,k,m,n,x,y,z,ans,l:longint;
	a:array[1..maxn] of longint;
function work(x,y,z:longint):boolean;
var	i:longint;
begin
	for i:=x to y do
		if a[i]<=0 then exit(false);
	for i:=x to y do
		dec(a[i],z);
        exit(true);
end;
procedure fix(x,y,z:longint);
var	i:longint;
begin
	for i:=x to y do
		if (a[i]<z) and (a[i]>0) then a[i]:=z;
end;
procedure add(x,y,z:longint);
var	i:longint;
begin
	for i:=x to y do
		if a[i]>0 then inc(a[i],z);
end;
begin
	assign(input,'road.in');reset(input);
	//assign(output,'road.out');rewrite(output);

	ans:=0;
	readln(n,m,l);
	for i:=1 to n do a[i]:=l;
	for i:=1 to m do begin
		readln(k,x,y,z);
		case k of
			1:if work(x,y,z) then inc(ans);
			2:add(x,y,z);
			3:fix(x,y,z);
		end;
	end;
	writeln(ans);

	close(input);close(output);
end.
