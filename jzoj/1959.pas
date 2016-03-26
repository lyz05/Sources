type node=record
		l,r,i,j,x:longint;
	end;
var	n,m,i,j,x,y,z,pi:longint;
	a:array[1..100000] of longint;
	p:array[1..231072] of node;
function max(x,y:longint):longint;
begin
	if x>y then exit(x) else exit(y);
end;
procedure dfs(x:longint);
begin
	if p[x].i=p[x].j then p[x].x:=a[p[x].i]
	else begin
		inc(pi);
		p[x].l:=pi;
		p[pi].i:=p[x].i;
		p[pi].j:=(p[x].i+p[x].j) div 2;
		        dfs(pi);
		inc(pi);
		p[x].r:=pi;
		p[pi].i:=(p[x].i+p[x].j) div 2+1;
		p[pi].j:=p[x].j;
                        dfs(pi);
                p[x].x:=max(p[p[x].l].x,p[p[x].r].x);
	end;
end;
procedure init;
begin
     pi:=1;
	p[1].i:=1;p[1].j:=n;
	dfs(1);
end;
procedure change(y,z:longint);
var i,j,l,r,x:longint;
begin
	i:=p[y].i;j:=p[y].j;
	l:=p[y].l;r:=p[y].r;
	x:=p[y].x;
	if (z=i) and (z=j) then begin
                p[y].x:=a[z];
                exit;
        end;
	if (z>=p[l].i) and (z<=p[l].j) then change(l,z);
	if (z>=p[r].i) and (z<=p[r].j) then change(r,z);
	p[y].x:=max(p[l].x,p[r].x);
end;
function search(k,y,z:longint):longint;
var i,j,l,r,x:longint;
begin
	i:=p[k].i;j:=p[k].j;
	l:=p[k].l;r:=p[k].r;
	x:=p[k].x;
	if (i=y) and (j=z) then search:=x else begin
		if (y>=p[l].i) and (z<=p[l].j) then search:=search(l,y,z);
		if (y>=p[r].i) and (z<=p[r].j) then search:=search(r,y,z);
		if (y<=p[l].j) and (z>=p[r].i) then search:=max(search(l,y,p[l].j),search(r,p[r].i,z));
	end;
end;
begin
	readln(n);
        for i:=1 to n do readln(a[i]);
	init;
	readln(m);
	for i:=1 to m do begin
		readln(z,x,y);
		if z=1 then begin
			a[x]:=y;
			change(1,x);
		end else begin
			writeln(search(1,x,y));
		end;
	end;
end.
