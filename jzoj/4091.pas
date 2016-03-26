const	maxn=100000;
type	node=record
		next,y,st:longint;
	end;
	arr=array[0..maxn] of boolean;
var	i,j,k,m,n,tot,t,x,y:longint;
	a,e:array[0..maxn] of longint;
	h:array[1..12*maxn] of node;
	s:array[1..6*maxn] of longint;
	p1,p2:arr;
	flag:boolean;
procedure add(x,y,st:longint);
begin
	x:=x mod n;
	y:=y mod n;
	inc(tot);
	h[tot].y:=y;
	h[tot].next:=e[x];
	h[tot].st:=st;
	e[x]:=tot;
end;
procedure bfs(x,st:longint;var p:arr);
var	i,l,r:longint;
begin
	fillchar(p,sizeof(p),0);
	p[x]:=true;
	l:=1;
	r:=1;
	s[l]:=x;
	while l<=r do begin
		i:=e[s[l]];
		while i<>0 do begin
			if (h[i].st=st)and(not p[h[i].y]) then begin
				p[h[i].y]:=true;
				inc(r);
				s[r]:=h[i].y;
			end;
			i:=h[i].next;
		end;
		inc(l);
	end;
end;
begin
	assign(input,'4091.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(t);
	while t>0 do begin
		fillchar(a,sizeof(a),255);
		fillchar(e,sizeof(e),0);
		tot:=0;

		readln(n,m);
		for i:=1 to m do begin
			readln(x,y);
			a[x]:=y;
		end;
		for i:=0 to n-2 do begin
			for j:=i+1 to i+6 do begin
				if a[j]<>-1 then begin
					add(i,a[j],1);
					add(a[j],i,2);
				end else begin
					add(i,j,1);
					add(j,i,2);
				end;
			end;
		end;
		bfs(0,1,p1);
		bfs(n-1,2,p2);
		flag:=false;
		for i:=0 to n-1 do
			if p1[i] and (not p2[i]) then begin
				flag:=true;
				break;
			end;
		if flag then writeln('YES') else writeln('NO');

		dec(t);
	end;
end.
