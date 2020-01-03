program P3;
var	n,m,k,s:int64;
	i,j,T:longint;
	//a:array[1..20,1..20] of longint;
begin
	randomize;
	T := random(10);
	writeln(T);
	for i:=1 to T do begin
		n:=random(1000000000000)+1;
		m:=random(100000-n)+n+1;
		k:=random(1000000000000)+1;
		//n:=50000;m:=50000;
		writeln(n,' ',m,' ',k);	
	end;
end.

program P3291;
var	n,m,k,i,j,s:longint;
	a:array[1..20,1..20] of longint;
begin
	randomize;
	n:=random(50000)+1;
	m:=random(50000)+1;
	//n:=50000;m:=50000;
	for i:=1 to n do 
		write(chr(random(26)+ord('A')));
	writeln;
	for i:=1 to m do 
		write(chr(random(26)+ord('A')));
	writeln;
end.

program P1158;
var	n,m,k,i,j,s:longint;
	a:array[1..20,1..20] of longint;
begin
	randomize;
	n:=random(15)+1;
	writeln(n);
	for i:=1 to n do 
		writeln(random(100)+1,' ',random(100)+1,' ',random(1000000)+1);
end.
program P2206;
var	n,m,k,i,j,s:longint;
	a:array[1..20,1..20] of longint;
begin
	randomize;
	for n:=1 to 10000 do writeln(n);
end.
program P1164;
var	n,m,k,i,j,s:longint;
	a:array[1..20,1..20] of longint;
	z:int64;
begin
	randomize;
	z:=(1<<31)-1;
	writeln(random(z));
end.

program P2206;
var	n,m,k,i,j,s:longint;
	a:array[1..20,1..20] of longint;
begin
	randomize;
	n:=random(1000)+400000-1000+1;
	//n:=5;
	writeln(n);
	for i:=1 to n do begin
		write(random(1000000000),' ');
	end;
end.
program P1154;
var	n,m,k,i,j,s:longint;
	a:array[1..20,1..20] of longint;
begin
	randomize;
	n:=random(10)+1000-10+1;m:=random()
	n:=5;
	writeln(n);
	for i:=2 to n do begin
		writeln(i,' ',random(i-1)+1,' ',random(1000));
	end;
end.
program P1737;
var	n,m,k,i,j,s:longint;
	a:array[1..20,1..20] of longint;
begin
	randomize;
	n:=random(10)+5000-10+1;
	//n:=5;
	writeln(n);
	for i:=2 to n do begin
		writeln(i,' ',random(i-1)+1,' ',random(1000));
	end;
end.
program P1301;
var	n,m,k,i,j,s:longint;
	a:array[1..20,1..20] of longint;
begin
	randomize;
	n:=random(100)+10000-100+1;
	//n:=5;
	writeln(n);
	for i:=2 to n do begin
		writeln(i,' ',random(i-1)+1);
	end;
end.

program P1768;
var	n,m,k,i,j,s:longint;
	a:array[1..20,1..20] of longint;
begin
	randomize;
	n:=random(100)+1;m:=random(10)+1;
	//n:=10;m:=5;
	writeln(n,' ',m);
	for i:=1 to n do begin
		for j:=1 to m do begin
			if random(2)=0 then write('P') else write('H');
		end;
		writeln;
	end;
end.

program P1760;
var	n,m,k,i,j,s:longint;
	a:array[1..20,1..20] of longint;
begin
	randomize;
	n:=random(4)+4;
	//n:=5;m:=10;
	writeln(n);
	for i:=1 to n do begin
		for j:=i+1 to n do begin
			a[i][j]:=random(100)+1;
			a[j][i]:=a[i][j];
		end;
	end;
	for i:=1 to n do begin
		for j:=1 to n do write(a[i][j],' ');
		writeln;
	end;
end.


program P1244;
var	n,m,k,i,j:longint;
begin
	randomize;
	n:=random(1000)+1;
	m:=random(1000)+1;
	//n:=5;m:=10;
	writeln(n,' ',m);
	for i:=1 to n do begin
		writeln(random(1000000)+1,' ',random(1000000)+1);
	end;
	for i:=1 to m do writeln(random(n)+1,' ',random(n)+1);
end.


program C;
var	n,m,k,i,j:longint;
begin
	randomize;
	n:=random(1000)+1;
	m:=random(1000)+1;
	//n:=5;m:=10;
	writeln(n,' ',m);
	for i:=2 to n do begin
		writeln(i,' ',random(i-1)+1,' ',random(1000)+1);
	end;

end.

program B;
var	n,m,k,i,j,x,y,z:longint;
	a:array[1..100,1..100] of longint;
begin
	randomize;
	n:=random(100)+1;
	m:=n*(n-1) div 2-random(n);
	//n:=5;m:=8;
	writeln(n,' ',m);
	for i:=1 to m do begin
		x:=random(n)+1;y:=random(n)+1;z:=random(100)+1;
		while (x=y) or (a[x][y]<>0) do begin 
			x:=random(n)+1;y:=random(n)+1;z:=random(100)+1;
		end;
		a[x][y] := z;a[y][x] := z;
		writeln(x,' ',y,' ',z);
	end;
	k:=random(1000);
	//k:=2;
	writeln(k);
	for i:=1 to k do begin
		x:=random(n)+1;y:=random(n)+1;
		while (x=y) do begin x:=random(n)+1;y:=random(n)+1; end;
		writeln(x,' ',y);
	end;

end.
program A;
var	n,m,k,i,j:longint;
begin
	randomize;
	k:=random(5);
	for j:=1 to k do begin
		n:=random(10000)+1;
		m:=random(100000)+1;
		//n:=5;m:=10;
		writeln(n,' ',m);
		for i:=1 to m do begin
			writeln(random(n),' ',random(n),' ',random(10000)+1);
		end;
	end;
	writeln('0 0');
end.
