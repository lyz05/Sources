const maxr=75;maxc=maxr;
var 	i,j,k,m,n,r,c,ans,min:longint;
	map:array[1..maxr,1..maxc] of integer;
	f:array[1..4,1..4] of longint;
	x,y:array[0..4] of longint;
        ch:char;
function add(x1,x2,y1,y2:longint):longint;
var i,j:longint;
begin
	add:=0;
	for i:=x1 to x2 do
		for j:=y1 to y2 do inc(add,map[i,j]);
end;
begin
	//assign(input,'cake.in');reset(input);
	//assign(output,'cake.out');rewrite(output);

	readln(r,c);
	for i:=1 to r do begin
		for j:=1 to c do begin
			read(ch);
			map[i,j]:=ord(ch)-ord('0');
		if (j<=4) and (i<=4) then f[i,j]:=map[i,j];
		end;
		readln;
	end;
	ans:=0;
        x[4]:=r;y[4]:=c;
        x[1]:=0;
	while x[1]<r-3 do begin
	inc(x[1]);
        x[2]:=x[1];
	while x[2]<r-2 do begin
	inc(x[2]);
        x[3]:=x[2];
	while x[3]<r-1 do begin
	inc(x[3]);
        y[1]:=0;
	while y[1]<c-3 do begin
	inc(y[1]);
        y[2]:=y[1];
	while y[2]<c-2 do begin
	inc(y[2]);
        y[3]:=y[2];
	while y[3]<c-1 do
	begin
		inc(y[3]);
		min:=maxlongint;
		for i:=1 to 4 do
			for j:=1 to 4 do begin
				f[i,j]:=add(x[i-1]+1,x[i],y[j-1]+1,y[j]);
				if f[i,j]<min then min:=f[i,j];
			end;
		if min>ans then ans:=min;
	end;
	end;
	end;
	end;
	end;
	end;
	writeln(ans);
	
	//close(input);close(output);
end.
