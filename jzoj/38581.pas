var	n,m,i,j,k,t,xx:longint;
	a:array[0..100] of longint;
	p:array[0..100] of boolean;
        ans:qword;
procedure solve;
var     i,x:longint;
        tmp:qword;
begin
	x:=1;
	for i:=1 to a[0] do
		if p[i] then
			x:=x*a[i];
        if x<>1 then
                tmp:=((x+x*(xx div x))*(xx div x)) div 2;
	if odd(k) then dec(ans,tmp) else inc(ans,tmp);
end;
procedure dfs(deep,x:longint);
var i:longint;
begin
	if (x=0) or (deep>a[0]) then begin
                if x=0 then solve;
		exit;
	end else begin
		for i:=1 downto 0 do begin
			if i=1 then begin
				p[deep]:=true;
				dec(x);
				dfs(deep+1,x);
				inc(x);
				p[deep]:=false;
			end else dfs(deep+1,x);
		end;
	end;
end;
function ss(x:longint):boolean;
var i:longint;
begin
	if x<=1 then exit(false);
	for i:=2 to trunc(sqrt(x)) do
		if x mod i=0 then exit(false);
	exit(true);
end;
procedure fj(x:longint);
var i:longint;
begin
	 a[0]:=0;
         i:=2;
         while i<=x do
         begin
            while x mod i = 0 do
               begin
                   inc(a[0]);
                   a[a[0]]:=i;
                       x:=x div i;
                          end;
                            inc(i);
                             end;
          end;
function f(x:longint):qword;
var i,tmp:longint;
begin
	xx:=x;
	ans:=x*(x+1) div 2;
	fj(x);
	for i:=1 to a[0] do begin
                k:=i;
		dfs(1,i);
	end;
	f:=ans;
end;
function g(x:longint):qword;
var i:longint;
begin
	g:=0;
	for i:=1 to trunc(sqrt(x)) do begin
		if x mod i=0 then
			if x div i<>i then g:=g+f(i)+f(x div i)
				else g:=g+f(i);
	end;
end;
begin
	readln(t);
	for i:=1 to t do begin
		readln(n);
		writeln(g(n));
	end;
end.
