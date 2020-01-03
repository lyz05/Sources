const maxn=100000;
type node=record
		l,r,x:longint;
	end;
var	i,j,m,n,x,y,tot,ans:longint;
	a,b:array[0..maxn+10] of longint;
	h:array[1..maxn+10] of node;
	p:array[1..maxn] of boolean;
procedure add(x,fa,ch,k:longint);
begin
	if h[x].x=fa then begin
                inc(tot);
		if ch=0 then h[x].l:=tot else h[x].r:=tot;
                h[tot].x:=k;
	end else begin
		if h[x].l<>0 then add(h[x].l,fa,ch,k);
		if h[x].r<>0 then add(h[x].r,fa,ch,k);
	end;
end;
procedure zxbl(x:longint);
var i:longint;
begin
	if h[x].l<>0 then zxbl(h[x].l);
	inc(b[0]);
	b[b[0]]:=a[h[x].x];
	if h[x].r<>0 then zxbl(h[x].r);
end;
procedure change(x:longint);
var i:longint;
begin
	if b[x]>=b[x+1] then begin
		p[x]:=true;
		b[x]:=b[x+1]-1;
	end;
        if x=1 then exit;
	if b[x-1]>=b[x] then change(x-1);
end;
begin
     assign(input,'binary.in');reset(input);
	assign(output,'binary.out');rewrite(output);
	
	readln(n);
	for i:=1 to n do read(a[i]);
	h[1].x:=1;tot:=1;
	for i:=1 to n-1 do begin
		readln(x,y);
		add(1,x,y,i+1);
	end;
	zxbl(1);
	//for i:=1 to n do write(b[i],' ');
	//writeln;
     for i:=2 to n-1 do begin
		if (b[i-2]-b[i-1]>=2) and (b[i]<b[i-1]) then begin
			p[i]:=true;
			b[i]:=b[i-1]+1;
		end;
		if (b[i-2]-b[i-1]>=2) and (b[i]>b[i+1]) then begin
			p[i]:=true;
			b[i]:=b[i+1]-1;
		end;
	end;
	for i:=2 to n do begin
		if b[i-1]>=b[i] then change(i-1);
	end;
     ans:=0;
     for i:=1 to n do if p[i] then inc(ans);
     writeln(ans);
	
	close(input);close(output);
end.
