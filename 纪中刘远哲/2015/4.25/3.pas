const	maxn=1000+5;maxm=1000+5;
var	i,j,k,n,m:longint;
	map:array[1..maxn,1..maxm] of char;
	u:array[0..maxn,1..maxn] of longint;
	ans:int64;
procedure prepar;
var	t:longint;
begin
	for j:=1 to m do 
		for i:=1 to n do begin 
			if map[i,j]='*' then t:=1 else t:=0;
			u[i,j]:=u[i-1,j]+t;
		end;
end;
procedure work;
var	x1,y1,x2,y2:longint;
begin
	ans:=0;
	for x1:=1 to n do 
	for y1:=1 to m do begin
		if map[x1,y1]='*' then continue;
		for x2:=x1 to n do
		for y2:=y1 to m do begin
			if u[x2,y2]-u[x1-1,y2]>0 then break;
			inc(ans);
		end;
	end;
end;
begin
	assign(input,'3.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	for i:=1 to n do begin
		for j:=1 to m do 
			read(map[i,j]);
		readln;
	end;
	prepar;
	work;
	writeln(ans);
end.
