const maxn=10000;maxk=15;
var 	i,j,n,m,k,t,tmp,min,x,y,z:longint;
	map:array[1..maxn,1..maxn] of integer;
	p:array[1..maxn] of boolean;
	num:array[1..maxk] of longint;
procedure dfs(deep,x:longint);
var i:longint;
begin
	if deep>n then exit;
	if x=n then begin
		if tmp<min then min:=tmp;
		exit;
	end;
	for i:=1 to n do begin
		if (map[x,i]<>0) and not p[i] then begin
			p[i]:=true;
			inc(tmp,map[x,i]);
				dfs(deep+1,i);
			dec(tmp,map[x,i]);
			p[i]:=false;
		end;
	end;
end;
procedure print(s:string);
begin
	writeln(s);
	halt;
end;
procedure print1(x,y:longint);
begin
	writeln(x,' ',y);
	halt;
end;
begin
        min:=maxlongint;
        readln(n,m,k,t);
	for i:=1 to m do begin
		readln(x,y,z);
		map[x,y]:=z;
		map[y,x]:=z;
	end;
	for i:=1 to k do read(num[k]);
	p[1]:=true;
	dfs(1,1);
	if min*2>t then print('-1');
	if k=0 then print1(0,min*2);

end.
