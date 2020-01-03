const	n=9;
var	i,j,k,m:longint;
	map:array[1..n,1..n] of integer;
	p:array[1..3,1..3,1..n] of boolean;
	pp:array[1..2,1..n,1..n] of boolean;
procedure printf(x:string);
begin
	writeln(x);
	readln;
	halt;
end;
procedure change(x,y:longint;z:boolean);
var	i,j:longint;
begin
	pp[1,x,map[x,y]]:=z;
	pp[2,y,map[x,y]]:=z;
	i:=x div 3;j:=y div 3;
	if x mod 3<>0 then inc(i);
	if y mod 3<>0 then inc(j);
	p[i,j,map[x,y]]:=z;
end;
function judge():boolean;
var	i,j,x,y:longint;
begin
	for x:=1 to 9 do 
	for y:=1 to 9 do begin 
		if pp[1,x,map[x,y]] then exit(false);
		if pp[2,y,map[x,y]] then exit(false);
		i:=x div 3;j:=y div 3;
		if x mod 3<>0 then inc(i);
		if y mod 3<>0 then inc(j);
		if p[i,j,map[x,y]] then exit(false);
		change(x,y,true);
	end;
	exit(true);
end;
begin
	assign(input,'1335.in');reset(input);
	
	readln(m);
	for k:=1 to m do begin
		fillchar(p,sizeof(p),0);fillchar(pp,sizeof(pp),0);
		for i:=1 to 9 do begin
			for j:=1 to 9 do begin
				read(map[i,j]);
			end;
			readln;
		end;
		readln;
		if (judge()) then writeln('Right')else writeln('Wrong');
	end;

end.

