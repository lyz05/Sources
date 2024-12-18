const maxh=1048576;maxn=500001;
type node=record
		l,r,i,j,x:longint;
	end;
var	i,j,k,n,m,tot,minn:longint;
	a:array[1..maxn] of longint;
	h:array[1..maxh] of node;
	b:array[0..maxn] of longint;
function  min(x,y:longint):longint;
begin
        if x>y then exit(y) else exit(x);
end;
procedure dfs(x:longint);
begin
	if h[x].i=h[x].j then h[x].x:=a[h[x].i] else begin
		inc(tot);
		h[x].l:=tot;
		h[tot].i:=h[x].i;
		h[tot].j:=(h[x].i+h[x].j) div 2;
			dfs(tot);
		inc(tot);
		h[x].r:=tot;
		h[tot].i:=(h[x].i+h[x].j) div 2+1;
		h[tot].j:=h[x].j;
			dfs(tot);
		h[x].x:=min(h[h[x].l].x,h[h[x].r].x);
	end;
end;
function search(k,y,z:longint):longint;
var i,j,l,r,x:longint;
begin
	i:=h[k].i;j:=h[k].j;
	l:=h[k].l;r:=h[k].r;
	x:=h[k].x;
	if (i=y) and (j=z) then search:=x else begin
		if (y>=h[l].i) and (z<=h[l].j) then search:=search(l,y,z);
		if (y>=h[r].i) and (z<=h[r].j) then search:=search(r,y,z);
		if (y<=h[l].j) and (z>=h[r].i) then search:=min(search(l,y,h[l].j),search(r,h[r].i,z));
	end;
end;
procedure print(num,val:longint);
var i:longint;
begin
	writeln(num,' ',val);
	for i:=1 to num do write(b[i],' ');
	writeln;
	close(input);close(output);
        halt;
end;
begin
     assign(input,'pair.in');reset(input);
	assign(output,'pair.out');rewrite(output);
	readln(n);
	for i:=1 to n do read(a[i]);
	tot:=1;
	h[1].i:=1;h[1].j:=n;
	dfs(1);

	i:=1;j:=n;
	while i<=j do begin
		minn:=search(1,i,j);
		for k:=i to j+1 do
			if a[k] mod minn<>0 then break;
		if k=j+1 then begin
			inc(b[0]);
			b[b[0]]:=i;
		end;
		if j+1<=n then begin
			inc(i);inc(j);
		end else if b[0]=0 then begin
			dec(j);
			j:=1+(j-i);
			i:=1;
		end else print(b[0],j-i);
	end;
	
	close(input);close(output);
end.
