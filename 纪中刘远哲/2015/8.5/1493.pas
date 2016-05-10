uses	math;
const	maxn=100+5;oo=2088533116;
var	i,j,k,m,n,x,y,z,ch:longint;
	a,map:array[1..maxn,1..maxn] of longint;
procedure work(x,y:longint);
var	i:longint;
begin
	for i:=1 to n-1 do 
		for j:=i+1 to n do begin
				map[i,j]:=min(map[i,j],map[i,x]+a[x,y]+map[y,j]);
		end;
end;
procedure swap(var x,y:longint);
var	t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
begin
	assign(input,'1493.in');reset(input);
	//assign(output,'.out');rewrite(output);
	
	fillchar(map,sizeof(map),124);
	fillchar(a,sizeof(a),124);
	readln(n,k);
	for i:=1 to n do map[i][i]:=0;
	for i:=1 to k do begin
		read(ch,x,y);
		if x>y then swap(x,y);
		if ch=1 then begin
			readln(z);
			if a[x,y]>z then begin
				a[x,y]:=z;
				work(x,y);
			end;
		end else begin
			readln;
			if map[x][y]=oo then writeln(-1) else writeln(map[x][y]);
		end;
	end;
	//close(input);close(output);
end.
