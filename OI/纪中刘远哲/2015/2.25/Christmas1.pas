const	maxn=100000;
var	i,j,m,n,x,y,z:longint;
	a:array[1..maxn,1..2] of longint;
	ch:char;
{procedure add;
var	i,x,y,z:longint;
	flag:boolean;
begin
	//if z=0 then flag:=false else flag:=true;
	for i:=x to y do begin
		inc(a[i,1],z);
		inc(a[i,2]);
	end;
end;
procedure maxx;
var	i,x,y,z,t:longint;
begin
	for i:=x to y do begin
		if z>a[i,1] then begin
			a[i,1]:=z;
			inc(a[i,2]);
		end;
	end;
end;}
{procedure quary;
var	x:longint;
begin
	readln(x);
	writeln(a[x,1],' ',a[x,2]);
end;}
begin
	assign(input,'input.txt');reset(input);
	//assign(output,'output.txt');rewrite(output);

	readln(n);
	for i:=1 to n do read(a[i,1]);
	readln(m);
	for j:=1 to m do begin
		read(ch);
		if ch='Q' then begin
			readln(x);
		end else readln(x,y,z);
		case ch of
			'A':begin
                                if z=0 then continue;
				for i:=x to y do begin
					inc(a[i,1],z);
					inc(a[i,2]);
				end;
			end;
			'M':begin
				for i:=x to y do begin
					if z>a[i,1] then begin
						a[i,1]:=z;
						inc(a[i,2]);
					end;
				end;
			end;
			'Q':begin

                                writeln(a[x,1],' ',a[x,2]);
                        end;
		end;
	end;
end.
