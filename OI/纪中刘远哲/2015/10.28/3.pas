const maxn=15000;
var	i,j,k,n,m,x,y,ans:longint;
	map:array[1..maxn,1..maxn] of boolean;
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
		if map[x,k] and not p[k] then begin
			if ltx(k,y) then ltx:=true;
		end;
	p[x]:=false;
end;
begin
	readln(n,m);
	for i:=1 to m do begin
		readln(x,y);
		map[x,y]:=true;
	end;
	ans:=0;
	for i:=1 to n-1 do
		for j:=i+1 to n do begin
			if ltx(i,j) and ltx(j,i) then inc(ans);
		end;
	writeln(ans);
end.
