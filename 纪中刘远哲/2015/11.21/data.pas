program B;
var	i,j,k,m:longint;
	n:int64;
begin
	randomize;
	n:=random(100)+1;
	n:=5;k:=random(n)+1;
	writeln(n,' ',k);
	for i:=1 to n-1 do begin
		writeln(i,' ',random(i-1)+1,' ',random(123456)+1);
	end;
end.
program A;
var	i,j,k,m:longint;
	n:int64;
begin
	randomize;
	n:=random(10)+1;
	writeln(n,' ',random(45)+1);
end.

program count;
var	i,j,k,m:longint;
	n:int64;
begin
	randomize;
	n:=random(1000000000000)-1000000000000+1+1000000000000;
	n:=1000000000000;
	writeln(n);
end.
program AA;
const	maxnn=100;
var	i,j,k,m,t,tmp,p:longint;
	a:array[1..maxnn] of boolean;
	n:int64;
begin
	randomize;
	n:=maxnn;
	k:=random(n*(n+1) div 2)+1;
	p:=random(10000)+1;
	writeln(n,' ',k,' ',p);
	for i:=1 to n do begin
		fillchar(a,sizeof(a),0);
		for j:=1 to n do begin
			t:=random(n)+1;
			while a[t] do t:=random(n)+1;
			a[t]:=true;
			write(t,' ');
		end;
		writeln;
	end;
end.

program B;
const	maxnn=10;
var	i,j,k,m,t,tmp:longint;
	n:int64;
begin
	randomize;
	writeln(random(20)+1,' ',random(n)+1,' ',
		random(3)+1,' ',random(1000)+1,' ',random(1000)+1,
		' ',random(1000000000));
end.
program A;
const	maxnn=10;
var	i,j,k,m,t,tmp:longint;
	n:int64;
begin
	randomize;
	n:=random(20)-20+200+1;
	writeln(n);
	for i:=1 to n do begin
		writeln(random(1000)-1000+3000+1,' ',
		random(1000)-1000+3000+1);
	end;

end.
program D;
const	maxnn=10;
var	i,j,k,m,t,tmp:longint;
	n:int64;
begin
	randomize;
	n:=random(100000)+1;
	writeln(n);
	for i:=2 to n do begin
		tmp:=random(i-1)+1;
		//while (tmp=i) do tmp:=random(n)+1;
		write(tmp,' ');
	end;
	writeln;
	for i:=1 to n do write(random(1000),' ');
	writeln;
end.
program A;
const	maxnn=10;
var	i,j,k,m,t,tmp:longint;
	n:int64;
begin
	randomize;
	t:=1000;
	writeln(t);
	for i:=1 to t do begin
		n:=random(100000000)-100000000+1000000000000;
		writeln(n);
	end;
end.

program B;
const	maxnn=10;
var	i,j,k,m,n,t,tmp:longint;
	a:array[1..maxnn] of boolean;
begin
	randomize;
	t:=10;
	writeln(t);
	for i:=1 to t do begin
		n:=random(10)+1;
		writeln(n);
		for j:=1 to n do 
		begin
			tmp:=random(maxnn)+1;
			//while a[tmp] do tmp:=random(maxnn)+1;
			//a[tmp]:=true;
			write(tmp,' ');
		end;
		writeln;
	end;
end.
program B;
const	a:array[0..1] of string=('BORROW','RETURN');
var	i,j,k,m,n,t:longint;
begin
	randomize;
	n:=300000;
	m:=300000;
	writeln(n,' ',m);
	for i:=1 to m do begin
		t:=random(2);
		writeln(a[t],' ',random(300000)+1,' ',random(1000000000)+1);
	end;
end.
program A;
var	i,j,k,m,n,t:longint;
begin
	randomize;
	n:=1000000;
	m:=1000000;
	writeln(n,' ',m);
	for i:=1 to m do writeln(random(n)+1,' ',random(n)+1);
end.
