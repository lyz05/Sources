const	maxn=200;maxm=5000;
type	node=record
		y,next,col:longint;
	end;
var	i,j,k,m,n,q,tot,x,y,z:longint;
	e:array[1..maxn,1..2] of longint;
	h:array[1..maxm] of node;
	v:array[1..maxn] of boolean;
	flag:boolean;
procedure print(x:boolean);
begin
	if x then writeln(1) else writeln(0);
	halt;
end;
procedure add(x,y,col:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].col:=col;
	h[tot].next:=e[x,1];
	e[x,1]:=tot;
end;
begin
	//assign(input,'chess.in');reset(input);
	//assign(output,'chess.out');rewrite(output);

	fillchar(v,sizeof(v),true);
	readln(n,m);
	for i:=1 to m do begin
		readln(x,y,z);
		add(x,y,z);
		v[x]:=false;
	end;
	readln(q);
	for i:=1 to q do begin
		read(x);
		inc(e[x,2]);
	end;
	
	if q=1 then print(true);

	flag:=false;
	for i:=1 to n do begin
		//if v[i] then 
			if odd(e[i,2]) then flag:=not flag;
	end;
	print(flag);

	//close(input);close(output);
end.
