const maxn=8000;
var	i,j,k,m,n,t,x,y,w:longint;
	map:array[1..maxn,1..maxn] of longint;
	p:array[1..maxn] of boolean;
function ltx(x,y:longint):boolean;
var k:longint;
begin
	ltx:=false;
	p[x]:=true;
	if x=y then begin
                ltx:=true;
                p[x]:=false;
                exit;
        end;
	for k:=1 to n do
		if (map[x,k]<>0) and not p[k] then begin
			if ltx(k,y) then ltx:=true;
		end;
	p[x]:=false;
end;
begin
	readln(n,m,t);
	for i:=1 to m do begin
		readln(x,y);
		inc(map[x,y]);
		inc(map[y,x]);
	end;
	for i:=1 to t do begin
		readln(w,x,y);
		x:=x xor m;y:=y xor m;
		if w=1 then begin
			dec(map[x,y]);
			dec(map[y,x]);
                        dec(m);
		end else begin
			if ltx(x,y) then writeln(1) else writeln(0);
		end;
	end;
end.
