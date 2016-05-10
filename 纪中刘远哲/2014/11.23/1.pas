const	maxn=100000;maxp=15;
	pri:array[1..maxp] of longint=(2,3,5,7,11,13,17,19,23,29,31,37,41,43,47);
var	i,j,kk,n,m,tmp,ans:longint;
	a:array[1..maxn] of longint;
	b:array[1..2,1..maxp] of longint;
function gcd(x,y:longint):longint;
var	i:longint;
begin
	while y<>0 do begin
		i:=x mod y;
		x:=y;
		y:=i;
	end;
	exit(x);
end;
function fj(x:longint):longint;
var	i:longint;
begin
	fj:=0;
	for i:=1 to maxp do
		while x mod pri[i]=0 do begin
			x:=x div pri[i];
			inc(fj);
		end;
	if x<>1 then inc(fj);
end;
function d(x,y:longint):longint;
var	t:longint;
begin
	t:=gcd(x,y);
	x:=x div t;
	y:=y div t;
	d:=fj(x)+fj(y);
end;
begin
        {for n:=1 to 100 do begin
        readln(i,j);
        writeln(d(i,j));
        end;   }

	readln(n);
	for i:=1 to n do read(a[i]);

	for i:=1 to n do begin
		tmp:=0;ans:=maxlongint-100;
		for j:=1 to n do begin
			if i=j then continue;
			tmp:=d(a[i],a[j]);
			if ans>tmp then begin
				ans:=tmp;
				kk:=j;
			end;
		end;
		writeln(kk);
	end;
end.
